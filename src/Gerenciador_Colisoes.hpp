#pragma once
#include <vector>
#include <list>
#include <set>
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
            vector<Inimigo*> LIs;
            list<Obstaculo*> LOs;
            set<Projetil*> LPs;
            Jogador* pJog1;
        
        public:
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();

            void incluirInimigo(Inimigo* pi);
            void incluirObstaculo(Obstaculo* po);
            void incluirProjetil(Projetil* pj);
            void setJogador(Jogador* pJ);
            /*void incluirEntidade()*/   //fazer para incluir qualquer tipo de entidade e chamar as funçoes "tratar colisoes" (ou melhor nao?)
            void executar();

        private:
            const bool verificarColisao(Entidade* pe1, Entidade* pe2) const;
         
            void tratarColisoesJogsObstacs();
            void tratarColisoesJogsInimigs(); 
            void tratarColisoesJogsProjeteis();
            void tratarColisoesInimigsObstacs(); //nao estava no UML padrao
            void tratarColisoesInimigsProjeteis(); //nao estava no UML padrao
            void tratarColisoesObstacsProjeteis(); //nao estava no UML padrao
            //InimigsInimigs
    };
}