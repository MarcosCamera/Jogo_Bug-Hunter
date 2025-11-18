#pragma once
#include "Fase.hpp"
#include "Grilo.hpp"
#include "Obstaculo.hpp" 

namespace Fases
{
    class Fase_Primeira : public Fase
    {
        private:
          const int maxFormigueiro;
          const int minFormigueiro;
          const int maxGrilo;
          const int minGrilo;
          
        
        protected:
          void criarInimMedios();
          void criarObstMedios();
          
        public:
           Fase_Primeira(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC, std::string caminho);
           ~Fase_Primeira();  
           
           void carregarFase(const std::string& caminho) override;
           void gerarFase(vector<vector<vector<int>>> mapa) override;
           void criarInimigos();
           void criarObstaculos();
    };
}
