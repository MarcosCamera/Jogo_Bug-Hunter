#include "Fase.hpp"

using namespace std;

namespace Fases
{
    Fase::Fase(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC) :
        Ente(), gC(gC), pGG(pGG), lista_ents(NULL), pJog1(NULL), pJog2(NULL), pParedeChao(NULL), maxFormiga(6), minFormiga(3),
        maxFolha(4), minFolha(3), larguraNivel(608.0f), alturaNivel(800.0f)
    {

        Ente::setpGG(pGG);
    }

    Fase::~Fase()
    {
        lista_ents.limpar();
    }

    void Fase::executar()
    {
        Listas::Lista<Entidades::Entidade>* pLista = lista_ents.getLista();
        if (!pLista) return;
        Listas::Lista<Entidades::Entidade>::Iterador<Entidades::Entidade> it = pLista->getIterador();

        while (!it.end())
        {
            Entidades::Entidade* pEnt = it.getElemento();
            if (pEnt)
            {
                pEnt->executar();
                //pEnt->desenhar(); //mudou por causa da lógica da câmera
            }
            it.proximo();
        }

        gC.executar();
        if (pJog1)
        {
            std::cout << "Posicao X: " << pJog1->getPos().x << "Posicao Y: " << pJog1->getPos().y << "\n";


            pGG->moverCamera(NULL, pJog1, NULL); //move só de acordo com a visão do jogador 1 apenas.
        }

        it = pLista->getIterador();
        while (!it.end())
        {
            Entidades::Entidade* pEnt = it.getElemento();
            if (pEnt)
            {
                pEnt->desenhar();
            }
            it.proximo();
        }

        //std::cout << "Posicao X: " << pJog1->getPos().x << "Posicao Y: " << pJog1->getPos().y << "\n";
    }

    json Fase::lerArquivoJSON(const std::string& caminho)
    {
        ifstream arquivo(caminho);
        if (!arquivo.is_open())
        {
            cerr << "nao foi possivel abrir o arquivo JSON: " << caminho << endl;
            throw std::runtime_error("Nao foi possivel abrir o arquivo JSON: " + caminho);
        }
        json j;
        arquivo >> j;
        arquivo.close();
        return j;
    }

    vector<vector<vector<int>>> Fase::extrairCamadas(const json& mapa)
    {
        int altura = mapa["height"];
        int largura = mapa["width"];
        int numLayers = static_cast<int>(mapa["layers"].size());
        vector<vector<vector<int>>> camadas;

        for (int k = 0; k < numLayers; k++)
        {
            const auto& layer = mapa["layers"][k];

            if (layer["type"] != "tilelayer")
            {
                continue;
            }

            const auto& data = layer["data"];

            vector<vector<int>> camada2D(altura, vector<int>(largura));
            for (int i = 0; i < altura; i++)
            {
                for (int j = 0; j < largura; j++)
                {
                    camada2D[i][j] = data[i * largura + j];
                }
            }
            camadas.push_back(camada2D);
        }
        return camadas;
    }


    void Fase::criarFormigas()
    {
        if (!pParedeChao)
            return;
        float y_chao = pParedeChao->getPos().y;

        float x = 100.f + static_cast<float>(rand() % static_cast<int>(larguraNivel - 200.f));

        Entidades::Personagens::Formiga* pInim = new Entidades::Personagens::Formiga(sf::Vector2f(x, y_chao));
        float altura_inimigo = pInim->getFig()->getGlobalBounds().height;
        float y_corrigido = y_chao - altura_inimigo;

        pInim->getFig()->setPosition(x, y_corrigido);

        lista_ents.incluir(static_cast<Entidades::Entidade*>(pInim));
        gC.incluirInimigo(pInim);
    }

    void Fase::criarFolhas()
    {
        if (!pParedeChao)
            return;

        int numPlataformas = minFolha + rand() % (maxFolha - minFolha + 1);
        float y_chao = pParedeChao->getPos().y;
        for (int i = 0; i < numPlataformas; i++)
        {
            float x = 100.f + static_cast<float>(rand() % static_cast<int>(larguraNivel - 200.f));
            Entidades::Obstaculos::Folha* pFolha = new Entidades::Obstaculos::Folha(sf::Vector2f(x, y_chao));
            float altura_obstaculo = pFolha->getFig()->getGlobalBounds().height;
            float y_corrigido = y_chao - altura_obstaculo;

            pFolha->getFig()->setPosition(x, y_corrigido);
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pFolha));
            gC.incluirObstaculo(pFolha);
        }
    }

    void Fase::criarJogador()
    {

        if (pJog1)
        {
            pJog1->setChao(true); // vai ser true no primeiro frame
            pJog1->setVel(sf::Vector2f(0.0f, 0.0f));
            pJog1->getFig()->setPosition(sf::Vector2f(200.0f, 416.5)); //ao inves de corpo, pFig
            //std::cout << "Posicao X11111: " << pJog1->getPos().x << "Posicao Y11111: " << pJog1->getPos().y << "\n";

        }
        else
        {
            pJog1 = new Entidades::Personagens::Jogador(sf::Vector2f(200.0f, 416.5));
            // cout<<"posx jogador: "<<posX<<"posy jogador: "<<posY<<endl;
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog1));
            gC.setJogador(pJog1);
        }
        /*       //COMO FARIA PRO JOGADOR 2? na fase 2 ter essa mesma funçao mas com os 2 jogadores.
        if (pJog2)
        {
            pJog2->setChao(true); // vai ser true no primeiro frame
            pJog2->setVel(sf::Vector2f(0.0f, 0.0f));
            pJog2->getFig()->setPosition(sf::Vector2f(200.0f, 416.5)); //ao inves de corpo, pFig
            //std::cout << "Posicao X11111: " << pJog1->getPos().x << "Posicao Y11111: " << pJog1->getPos().y << "\n";
        }
        else
        {
            pJog2 = new Entidades::Personagens::Jogador(sf::Vector2f(200.0f, 416.5));
            // cout<<"posx jogador: "<<posX<<"posy jogador: "<<posY<<endl;
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog2));
            gC.setJogador(pJog2);
        }
        */
    }
}