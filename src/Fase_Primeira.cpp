#include "Fase_Primeira.hpp"
#include "Grilo.hpp"
#include "Formigueiro.hpp"    
#include "Obstaculo.hpp"
#include <cstdlib> 
#include <ctime>
#include <iostream>     
#include <vector>       
#include <algorithm>    

using std::cout;
using std::endl;
using std::vector;


Fases::Fase_Primeira::Fase_Primeira(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC, std::string caminho) :
    Fase(pGG, gC), 
    maxFormigueiro(7),    
    minFormigueiro(3),
    maxGrilo(7),
    minGrilo(3)
{
    srand(static_cast<unsigned>(time(NULL)));
    carregarFase(caminho); 

    criarCenario();
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
                    
                    case 17: 
                    case 18:
                    case 19:
                    case 34:
                        criarPlataforma();
                        break;
                    case 309: 
                        cout<<"ok3"<<endl;
                        criarJogador(); 
                        break;

                    
                    case 332: 
                        criarFormigas();
                        break;
                    case 9:   
                        criarInimMedios();
                        break;
                    case 440: 
                        criarObstMedios();

                        break;

                    default:
                        break;
                }
            }
        }
    }
}


void Fases::Fase_Primeira::criarInimMedios() {
     int numInim = minInim + (rand() % (maxInim - minInim + 1));
     float y = pParedeChao->getPos().y;
     

    for(int i = 0; i < numInim ; i++)
    {
         float x = 100.f + static_cast<float>(rand() % static_cast<int>(larguraNivel - 200.f));

    
    Entidades::Personagens::Grilo* pInim = new Entidades::Personagens::Grilo(sf::Vector2f(x,y));
    if(pInim)
    {
           float altura_inimigo = pInim->getCorpo().getSize().y;
           float y_corrigido = y-altura_inimigo ;
           pInim->getCorpo().setPosition(x, y_corrigido);

    }
    if(pJog1) {
       pInim->setJogador(pJog1); 
    }

    lista_ents.incluir(static_cast<Entidade*>(pInim));
    gC.incluirInimigo(pInim);
   }
}

void Fases::Fase_Primeira::criarObstMedios() {
    
    if (!pParedeChao) return;
    
    const float groundY = pParedeChao->getPos().y; 
    
    const float alturaSprite = 50.0f; 
    
    const float obstaculoY = groundY - alturaSprite; 
    
    int numObstaculos = minPlat + rand() % (maxPlat - minPlat + 1);
    
    const float ESPACAMENTO_MINIMO = 150.0f; 

    std::vector<float> availablePositions;
    
    for (float x = 100.f; x < larguraNivel - 100.f; x += 50.f) {
      availablePositions.push_back(x);
    }

    for (size_t i = availablePositions.size() - 1; i > 0; --i) {
      int j = std::rand() % (i + 1); 
      float temp = availablePositions[i];
      availablePositions[i] = availablePositions[j];
      availablePositions[j] = temp;
    }

    std::vector<float> usedPositions;
    int createdObstaculos = 0;

    for (size_t i = 0; i < availablePositions.size() && createdObstaculos < numObstaculos; i++) {
        float x = availablePositions[i];
        bool positionValid = true;

        for (std::vector<float>::iterator it = usedPositions.begin(); it != usedPositions.end(); ++it) {
          if (fabs(x - *it) < ESPACAMENTO_MINIMO) {
            positionValid = false;
            break; 
          }
        }

        if (positionValid) {
          
          Entidades::Obstaculos::Plataforma *pPlat = 
                new Entidades::Obstaculos::Plataforma(sf::Vector2f(x, obstaculoY), 440);
          
          lista_ents.incluir(static_cast<Entidades::Entidade*>(pPlat));
          gC.incluirObstaculo(pPlat);
          
          usedPositions.push_back(x); 
          createdObstaculos++;
        }
    }
}

void Fases::Fase_Primeira::criarInimigos()
{  
   criarFormigas();
   criarInimMedios();

}

void Fases::Fase_Primeira::criarObstaculos()
{
    criarPlataforma();
    criarObstMedios();
    
}
