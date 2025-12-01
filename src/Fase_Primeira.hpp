#pragma once
#include "Fase.hpp"
#include "Grilo.hpp"
#include "Obstaculo.hpp" 

namespace Fases
{
    class Fase_Primeira : public Fase
    {
        private:
          const int maxFormigueiros;
          const int minFormigueiros;
          const int maxGrilos;
          const int minGrilos;
          
        
        protected:
          void criarGrilos(sf::Vector2f pos);
          void criarFormigueiros();
          
        public:
           Fase_Primeira(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC, std::string caminho);
           ~Fase_Primeira();  
           
           void gerarFase(const std::string& caminho);
           void criarInimigos();
           void criarObstaculos();
           void criarCenario();
           void criarEntidades(sf::Vector2f pos, int id_tile, const std::string& camada);
           void criarParede(sf::Vector2f pos, int id_tile);
    };
}
