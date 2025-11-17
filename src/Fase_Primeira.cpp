#include "Fase_Primeira.hpp"
#include "Grilo.hpp"
#include "Formigueiro.hpp"    
#include "Obstaculo.hpp"

Fases::Fase_Primeira::Fase_Primeira(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC, std::string caminho) :
    Fase(pGG, gC), 
    maxIni(10),    
    minIni(3)
{
    carregarFase(caminho); 
}

Fases::Fase_Primeira::~Fase_Primeira() { }

void Fases::Fase_Primeira::carregarFase(const std::string& caminho)
{
    
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
                   
                    case 913:
                        criarPlataforma(posX, posY, id_tile);
                        cout<<"oi"<<endl;
                        break;
                    
                    case 649:
                        criarFormigas(posX, posY); 
                        break;
                    case 871: 
                        criarInimMedios(posX, posY); 
                        break;
                    
                    
                    case 91:
                        criarJogador(posX, posY); 
                         break;
                        
                    case 305: 
                        criarObstMedios(posX, posY, id_tile);
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
