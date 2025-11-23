#include "Fase_Primeira.hpp"
#include "Grilo.hpp"
#include "Formigueiro.hpp"    
#include "Obstaculo.hpp"
#include <cstdlib> 
#include <ctime>

namespace Fases
{

    Fase_Primeira::Fase_Primeira(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC, std::string caminho) :
        Fase(pGG, gC),
        maxFormigueiros(2),
        minFormigueiros(1),
        maxGrilos(2),
        minGrilos(1)
    {
        srand(static_cast<unsigned>(time(NULL)));
        carregarFase(caminho);
    }

    Fase_Primeira::~Fase_Primeira() {}

    void Fases::Fase_Primeira::criarParede(Entidades::Parede* pParede, int id_tile)
    {


        if (!pParede || id_tile == 0) return;

        const int TILE_SIZE = 32;
        const int TILES_PER_ROW = 16;
        const int FIRST_GID = 1;

        int local_id = id_tile - FIRST_GID;

        int tile_x_index = local_id % TILES_PER_ROW;
        int tile_y_index = local_id / TILES_PER_ROW;

        int tile_x_coord = tile_x_index * TILE_SIZE;
        int tile_y_coord = tile_y_index * TILE_SIZE;

        sf::IntRect areaTiled(
            tile_x_coord,
            tile_y_coord,
            TILE_SIZE,
            TILE_SIZE
        );

        pParede->getFig()->setTextureRect(areaTiled);
    }

    void Fase_Primeira::carregarFase(const std::string& caminho)
    {
        json mapa = lerArquivoJSON(caminho);

        vector<vector<vector<int>>> camadas = extrairCamadas(mapa);
        gerarFase(camadas);
        gC.executar();
        criarCenario();
    }

    void Fase_Primeira::gerarFase(vector<vector<vector<int>>> mapa)
    {
        if (mapa.empty() || mapa[0].empty() || mapa[0][0].empty())
        {
            cerr << "ERRO: dados do mapa incompletos ou vazios em gerarFase()" << endl;
            return;
        }

        const int larguraTiles = 32;//32 px
        const int alturaTiles = 32;

        for (size_t k = 0; k < mapa.size(); k++)
        {
            for (size_t i = 0; i < mapa[k].size(); i++)
            {
                for (size_t j = 0; j < mapa[k][i].size(); j++)
                {

                    int id_tile = mapa[k][i][j];

                    if (id_tile != 0)
                    {
                        float posX = j * larguraTiles;
                        float posY = i * alturaTiles;
                        criarEntidades(posX, posY, id_tile);
                    }
                }
            }
        }
    }



    void Fase_Primeira::criarEntidades(float posX, float posY, int n)
    {

        switch (n)
        {
        case 183:
        case 43:
        case 88:
        case 55:
        case 2:
        case 248:
        case 21:
        case 229:
        case 145:

        {
            Entidades::Parede* pTile = new Entidades::Parede(sf::Vector2f(posX, posY));
            if (pTile->getFig() == NULL) {
                cout << "ERRO: pFig da Parede é NULL" << endl;
                break;
            }
            if (!pParedeChao) {
                pParedeChao = pTile;
            }
            criarParede(pTile, n);//é preciso fazer essa gambiarra toda pq eu não estou pegando a imagem chao.png inteira, estou apenas pegando cada tile com ids diferentes

            pTile->setpGG(pGG);
            gC.incluirParede(pTile);
            lista_ents.incluir(static_cast<Entidades::Parede*>(pTile));
        }
        break;

        case 748: {
            cout << "jogador chamado" << endl;
            //cout<<posY<<endl;debug
            criarJogador();
        }
                break;

        case 751:

        {

            int chance = rand() % 2;//eu acho q a lógica está errada aqui para a criação aleatoria de instancias
            if (chance == 0) {
                cout << "formigas chamado" << endl;
                criarFormigas();
            }
        }

        break;

        case 752:
        {
            int chance = rand() % 2;
            if (chance == 0) {
                cout << "grilos" << endl;
                criarGrilos();
            }
        }
        break;

        case 425:
            cout << "folhas" << endl;
            criarFolhas();
            break;

        case 753:
        {
            int chance = rand() % 2;
            if (chance == 0) {
                cout << "formigueiros" << endl;
                criarFormigueiros();
            }
        }
        break;

        default:
            break;
        }
    }

    void Fase_Primeira::criarGrilos()
    {
        if (!pParedeChao)
        {
            cout << "grilos NULL" << endl;
            return;
        }
        int numGrilos = minGrilos + (rand() % (maxGrilos - minGrilos + 1));
        float y = pParedeChao->getFig()->getLocalBounds().height;


        //for(int i = 0; i < numGrilos ; i++) não estava funcionando fazer as instancias aleatorias assim

        float x = 100.f + static_cast<float>(rand() % static_cast<int>(larguraNivel - 200.f));

        //cout<<"chegou aqui"<<endl;
        Entidades::Personagens::Grilo* pInim = new Entidades::Personagens::Grilo(sf::Vector2f(x, y));
        cout << "criarGrilos()" << endl;
        if (pInim)
        {
            pInim->setpGG(pGG);
            float altura_inimigo = pInim->getFig()->getGlobalBounds().height;

            float y_corrigido = y - altura_inimigo;
            cout << y_corrigido << endl;
            pInim->getFig()->setPosition(x, y_corrigido);
            cout << "criarGrilos()->grilo nao é nulo" << endl;

        }
        else
            cout << "criarGrilos()->grilo NULL" << endl;

        lista_ents.incluir(static_cast<Entidades::Entidade*>(pInim));
        gC.incluirInimigo(pInim);
    }

    void Fase_Primeira::criarFormigueiros()
    {
        if (!pParedeChao)
        {
            cout << "NULL" << endl;
            return;
        }
        float y = pParedeChao->getPos().y;
        cout << "chega até aqui" << endl;
        float x = 100.f + static_cast<float>(rand() % static_cast<int>(larguraNivel - 200.f));
        Entidades::Obstaculos::Formigueiro* pForms = new Entidades::Obstaculos::Formigueiro(sf::Vector2f(x, y));
        if (pForms)
        {

            float altura_obstaculo = pForms->getFig()->getGlobalBounds().height;


            float y_corrigido = y - altura_obstaculo;

            cout << "y_corrigido " << y_corrigido << endl;
            pForms->getFig()->setPosition(x, y_corrigido);
            lista_ents.incluir(static_cast<Entidades::Entidade*>(pForms));
            gC.incluirObstaculo(pForms);


        }
        else
            cout << "criarFormigueiros, pForms NULL" << endl;
    }

    void Fase_Primeira::criarInimigos()
    {
        criarFormigas();
        criarGrilos();
    }

    void Fase_Primeira::criarObstaculos()
    {
        criarFolhas();
        criarFormigueiros();
    }

    void Fase_Primeira::criarCenario()
    {
        criarInimigos();
        criarObstaculos();
    }
}