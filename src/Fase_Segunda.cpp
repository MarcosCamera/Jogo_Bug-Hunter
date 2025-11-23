#include "Fase_Segunda.hpp"
#include "Grilo.hpp"
#include "Formigueiro.hpp"    
#include "Obstaculo.hpp"
#include <cstdlib> 
#include <ctime>

using namespace Entidades;
using namespace Entidades::Personagens; 
using namespace Entidades::Obstaculos;

using std::cout;
using std::endl;
using std::vector;
using namespace Entidades;

Fases::Fase_Segunda::Fase_Segunda(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC, std::string caminho) :
    Fase(pGG, gC)
{
    srand(static_cast<unsigned>(time(NULL)));
    carregarFase(caminho); 
}

Fases::Fase_Segunda::~Fase_Segunda() { }

void Fases::Fase_Segunda::carregarFase(const std::string& caminho)
{ 
    json mapa = lerArquivoJSON(caminho);
    vector<vector<vector<int>>> camadas = extrairCamadas(mapa);
    gerarFase(camadas);
    criarCenario();
}

void Fases::Fase_Segunda::gerarFase(vector<vector<vector<int>>> mapa)
{
   if (mapa.empty() || mapa[0].empty() || mapa[0][0].empty()) {
        cerr << "ERRO: em gerarFase (Fase_Segunda)" << endl;
        return;
    }
    
    const int larguraTiles = 32; 
    const int alturaTiles = 32;

    for (size_t k = 0; k < mapa.size(); k++) { 
        for (size_t i = 0; i < mapa[k].size(); i++) { 
            for (size_t j = 0; j < mapa[k][i].size(); j++) { 
                
                int id_tile = mapa[k][i][j];
                
                if (id_tile != 0) { 
                    float posX = j * larguraTiles;
                    float posY = i * alturaTiles;
                    criarEntidades(posX, posY, id_tile);
                }
            }
        }
    }
              
}




void Fases::Fase_Segunda::criarEntidades(float posX, float posY, int n) 
{
    
    
    
  switch (n) 
    {
        case 223: 
        case 190: 
        case 288: 
        case 289: 
        case 222:
            {
                Entidades::Parede* pTile = new Entidades::Parede(sf::Vector2f(posX, posY), n);
                
                criarParede(pTile, n);
                
                pTile->setpGG(pGG); 
                gC.incluirParede(pTile); 
                lista_ents.incluir(static_cast<Entidades::Parede*>(pTile));
            }
            break;
            
        case 297: 
             criarFormigas(); 
             break;
             
        case 298: 
             criarFolhas(); 
             break;
             
        default:
            break;
    }
}



 void Fases::Fase_Segunda:: criarParede(Entidades::Parede* pParede, int id_tile)
    {
       
    
    if (!pParede || id_tile == 0) return;
    
    const int TILE_SIZE = 32;
    const int TILES_PER_ROW = 16;
    const int FIRST_GID = 41;
    
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

void Fases::Fase_Segunda::criarInimigos()
{
   
   criarFormigas();
   


}

void Fases::Fase_Segunda::criarObstaculos()
{
  criarFolhas();
  
}
 void Fases::Fase_Segunda::criarCenario()
{       
    
        criarInimigos();
        criarObstaculos();
}
