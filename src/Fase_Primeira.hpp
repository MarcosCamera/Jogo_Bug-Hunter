#pragma once
#include "Fase.hpp"
#include <algorithm>
#include <vector>
#include <string>

namespace Entidades 
{
    namespace Personagens { class Grilo; }
    namespace Obstaculos { class Obstaculo; }
    class Parede;
}

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
            void criarGrilos();
            void criarFormigueiros();
          
        public:
           Fase_Primeira(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC, std::string caminho);
           ~Fase_Primeira();  
           
           void criarParede(Entidades::Parede* pParede, int id_tile)override;
           void carregarFase(const std::string& caminho) override;
           void gerarFase(vector<vector<vector<int>>> mapa) override;
           void criarInimigos();
           void criarObstaculos();
           void criarCenario()override;
           void criarEntidades(float posX, float posY, int id_tile)override;
    };
}
