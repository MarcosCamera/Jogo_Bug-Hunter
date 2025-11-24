#pragma once
#include "Fase.hpp"
#include "Grilo.hpp"
#include "Obstaculo.hpp"
#include <algorithm>
#include <ctime>
#include "Formigueiro.hpp"    
#include <cstdlib> 

namespace Fases
{
    class Fase_Segunda : public Fase
    {
    private:


    protected:
        //criarCarnívoras()//não implementei essas ainda, estava testando a parede primeiro. mas é a mesma ideia das implementações dos outros inimigos e obstáculos
        //criarLouvaDeus()
    public:
        Fase_Segunda(Gerenciadores::Gerenciador_Grafico* pGG, Gerenciadores::Gerenciador_Colisoes& gC, std::string caminho);
        ~Fase_Segunda();

        void criarParede(Entidades::Parede* pParede, int id_tile)override;
        void carregarFase(const std::string& caminho) override;
        void gerarFase(vector<vector<vector<int>>> mapa) override;
        void criarInimigos()override;
        void criarObstaculos()override;
        void criarCenario()override;
        void criarEntidades(float posX, float posY, int id_tile)override;

    };
}