#pragma once
#include <vector>
#include <list>
#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Obstaculo.hpp"

using namespace std;
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;
using namespace Entidades;

namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        private:
         vector<Inimigo*>  LIs;
         list<Obstaculo*> LOs;
         Jogador* pJog1;
        
         public:
           Gerenciador_Colisoes();
           ~Gerenciador_Colisoes();

           void incluirInimigo(Inimigo* pi);
           void incluirObstaculo(Obstaculo* po);
           void setJogador(Jogador* pJ);
           void executar();

        private:
         const bool verificarColisao(Entidade* p1, Entidade* p2) const;
         
         void tratarColisoesJogsObstacs();
         void tratarColisoesJogsInimigs();
         void tratarColisoesInimigsObstacs();



    };
}