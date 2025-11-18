#include "Fase_Primeira.hpp"
#include "Grilo.hpp"
#include "Formigueiro.hpp"    
#include "Obstaculo.hpp"
#include <cstdlib> 
#include <ctime>

Fases::Fase_Primeira::Fase_Primeira(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC, std::string caminho) :
    Fase(pGG, gC), 
    max(10),    
    min(3)
{
    srand(static_cast<unsigned>(time(NULL)));
    carregarFase(caminho); 
    criarCenario();
}

Fases::Fase_Primeira::~Fase_Primeira() { }

void Fases::Fase_Primeira::carregarFase(const std::string& caminho)
{ 
    formigaSpawnPoints.clear();
    griloSpawnPoints.clear();
    formigueiroSpawnPoints.clear();
    
    json mapa = lerArquivoJSON(caminho);
    vector<vector<vector<int>>> camadas = extrairCamadas(mapa);
    gerarFase(camadas);
}

void Fases::Fase_Primeira::gerarFase(vector<vector<vector<int>>> mapa)
{
   float tileWidth = 32.0f;
    float tileHeight = 32.0f;

    for (size_t k = 0; k < mapa.size(); k++) { 
        for (size_t i = 0; i < mapa[k].size(); i++) { 
            for (size_t j = 0; j < mapa[k][i].size(); j++) { 
                
                int id_tile = mapa[k][i][j];
                if (id_tile == 0) {
                    continue;
                }

                float posX = j * tileWidth;
                float posY = i * tileHeight;


                switch(id_tile)
                {
                    case 17: 
                    case 18:
                    case 19:
                    case 34:
                        criarPlataforma(posX, posY, id_tile);
                        break;
                    case 309: 
                        cout<<"ok3"<<endl;
                        criarJogador(posX, posY); 
                        break;

                    
                    case 333: 
                    case 334:
                        formigaSpawnPoints.push_back(sf::Vector2f(posX, posY));
                        break;
                    case 9:   
                        griloSpawnPoints.push_back(sf::Vector2f(posX, posY));
                        break;
                    case 279: 
                        formigueiroSpawnPoints.push_back(sf::Vector2f(posX, posY));
                        break;

                    

                    default:
                        break;
                
                }
            }
        }
    }
}



void Fases::Fase_Primeira::criarInimMedios(float posX, float posY) {
    Entidades::Personagens::Grilo* pInim = new Entidades::Personagens::Grilo(sf::Vector2f(posX, posY));
    if(pJog1) {
       pInim->setJogador(pJog1); 
           

    }

    lista_ents.incluir(static_cast<Entidade*>(pInim));
    gC.incluirInimigo(pInim);
}

void Fases::Fase_Primeira::criarObstMedios(float posX, float posY, int id_tile) {
    Entidades::Obstaculos::Formigueiro* pEsp = new Entidades::Obstaculos::Formigueiro(sf::Vector2f(posX, posY));
    lista_ents.incluir(static_cast<Entidade*>(pEsp));
    gC.incluirObstaculo(pEsp);
}

void Fases::Fase_Primeira::criarInimigos()
{
   
    if (!formigaSpawnPoints.empty()) {
        std::random_shuffle(formigaSpawnPoints.begin(), formigaSpawnPoints.end());
        int numFormigas = min + (rand() % (max - min + 1)); 
        if (numFormigas > formigaSpawnPoints.size()) {
            numFormigas = formigaSpawnPoints.size();
        }

        for (int i = 0; i < numFormigas; i++) {
            sf::Vector2f pos = formigaSpawnPoints[i];
            criarFormigas(pos.x, pos.y);
        }
    }

    if (!griloSpawnPoints.empty()) {
        std::random_shuffle(griloSpawnPoints.begin(), griloSpawnPoints.end());
        int numGrilos = min + (rand() % (max - min + 1)); 
        
        if (numGrilos > griloSpawnPoints.size()) {
            numGrilos = griloSpawnPoints.size();
        }

        for (int i = 0; i < numGrilos; i++) {
            sf::Vector2f pos = griloSpawnPoints[i];
            criarInimMedios(pos.x, pos.y);
        }
    }


}

void Fases::Fase_Primeira::criarObstaculos()
{
   if (!formigueiroSpawnPoints.empty()) {
        std::random_shuffle(formigueiroSpawnPoints.begin(), formigueiroSpawnPoints.end());
        int numObstaculos = min + (rand() % (max - min + 1));

        if (numObstaculos > formigueiroSpawnPoints.size()) {
            numObstaculos = formigueiroSpawnPoints.size();
        }

        for (int i = 0; i < numObstaculos; i++) {
            sf::Vector2f pos = formigueiroSpawnPoints[i];
            criarObstMedios(pos.x, pos.y, 279); // 279 é id do formigueiro
        }
    }
}
