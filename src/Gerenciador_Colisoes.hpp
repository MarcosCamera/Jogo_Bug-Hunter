#pragma once
#include <vector>
#include <list>
#include <set>
#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Obstaculo.hpp"
#include "Projetil.hpp"

using namespace std;

namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        private:
            vector<Entidades::Personagens::Inimigo*> LIs;
            list<Entidades::Obstaculos::Obstaculo*> LOs;
            set<Entidades::Projetil*> LPs;
            Entidades::Personagens::Jogador* pJog1;
        
        public:
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();

        private:
            const bool verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2) const;
            void tratarColisoesJogsObstacs();
            void tratarColisoesJogsInimigs(); 
            void tratarColisoesJogsProjeteis();
            void tratarColisoesInimigsObstacs(); //nao estava no UML padrao
            void tratarColisoesInimigsProjeteis(); //nao estava no UML padrao
            void tratarColisoesObstacsProjeteis(); //nao estava no UML padrao
            //InimigsInimigs

        public:
            void incluirInimigo(Entidades::Personagens::Inimigo* pi);
            void incluirObstaculo(Entidades::Obstaculos::Obstaculo* po);
            void incluirProjetil(Entidades::Projetil* pj);
            void setJogador(Entidades::Personagens::Jogador* pJ);
            /*void incluirEntidade()*/   //fazer para incluir qualquer tipo de entidade e chamar as funçoes "tratar colisoes" (ou melhor nao?)
            void executar();
    };
}