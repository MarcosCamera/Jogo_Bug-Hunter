#include "Fase.hpp"

using namespace std;


namespace Fases
{
    Fase::Fase(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC) :
        Ente(), gC(gC), pGG(pGG), lista_ents(), pJog1(NULL), maxInim(0), minInim(0)
    {

        Ente::setpGG(pGG);
    }

    Fase::~Fase()
    {
        lista_ents.limpar();
    }

    void Fase::executar()
    {
        criarCenario();

        Listas::Lista<Entidades::Entidade>* pLista = lista_ents.getLista();
        if (!pLista) return;
        Listas::Lista<Entidades::Entidade>::Iterador<Entidades::Entidade> it = pLista->getIterador();

        while (!it.end())
        {
            Entidades::Entidade* pEnt = it.getElemento();
            if (pEnt)
            {
                pEnt->executar();
                pEnt->desenhar();
            }
            it.proximo();
        }

        std::cout << "Posicao X: " << pJog1->getPos().x << "Posicao Y: " << pJog1->getPos().y << "\n";
    }

    json Fase::lerArquivoJSON(const std::string& caminho) {
        ifstream arquivo(caminho);
        if (!arquivo.is_open()) {
            cerr << "nao foi possivel abrir o arquivo JSON: " << caminho << endl;
            throw std::runtime_error("Nao foi possivel abrir o arquivo JSON: " + caminho);
        }
        json j;
        arquivo >> j;
        arquivo.close();
        return j;
    }

    vector<vector<vector<int>>> Fase::extrairCamadas(const json& mapa) {
        int altura = mapa["height"];
        int largura = mapa["width"];
        int numLayers = static_cast<int>(mapa["layers"].size());
        vector<vector<vector<int>>> camadas;

        for (int k = 0; k < numLayers; k++) {
            const auto& layer = mapa["layers"][k];

            if (layer["type"] != "tilelayer") {
                continue;
            }

            const auto& data = layer["data"];

            vector<vector<int>> camada2D(altura, vector<int>(largura));
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
                    camada2D[i][j] = data[i * largura + j];
                }
            }
            camadas.push_back(camada2D);
        }
        return camadas;
    }


    void Fase::criarFormigas(float posX, float posY)
    {
        Entidades::Personagens::Formiga* pInim = new Entidades::Personagens::Formiga(sf::Vector2f(posX, posY));
        if (pJog1) {
            pInim->setJogador(pJog1);
        }

        lista_ents.incluir(static_cast<Entidades::Entidade*>(pInim));
        gC.incluirInimigo(pInim);
    }

    void Fase::criarFolhas(float posX, float posY, int id_tile)
    {
        Entidades::Obstaculos::Folha* pPlat = new Entidades::Obstaculos::Folha(sf::Vector2f(posX, posY));
        lista_ents.incluir(static_cast<Entidades::Entidade*>(pPlat));
        gC.incluirObstaculo(pPlat);
    }

    void Fase::criarJogador(float posX, float posY)
    {

        if (pJog1) 
        {
            pJog1->getFig()->setPosition(sf::Vector2f(posX, posY)); //ao inves de corpo, pFig
        }
        else 
        {
            pJog1 = new Entidades::Personagens::Jogador(sf::Vector2f(posX, posY));
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog1));
            gC.setJogador(pJog1);
        }
    }

    void Fase::criarCenario()
    {
        //criarchao;
        criarObstaculos();
        criarInimigos();
    }
}