#pragma once
#include "Fase.hpp"
#include "Grilo.hpp"
#include "Obstaculo.hpp"
#include <algorithm>

namespace Fases
{
    class Fase_Primeira : public Fase
    {
        private:
          const int max;
          const int min;
          std::vector<sf::Vector2f> formigaSpawnPoints;
          std::vector<sf::Vector2f> griloSpawnPoints;
          std::vector<sf::Vector2f> formigueiroSpawnPoints;
        
        protected:
          void criarInimMedios(float posX, float posY);
          void criarObstMedios(float posX, float posY, int id_tile);
          
        public:
           Fase_Primeira(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC, std::string caminho);
           ~Fase_Primeira();  
           
           void carregarFase(const std::string& caminho) override;
           void gerarFase(vector<vector<vector<int>>> mapa) override;
           void criarInimigos();
           void criarObstaculos();
           void criarFolha(float posX, float posY);
    };
}
