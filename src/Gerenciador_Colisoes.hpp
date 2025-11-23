#pragma once

#include <vector>
#include <list>
#include <set>
#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Obstaculo.hpp"
#include "Projetil.hpp"
#include "Parede.hpp"

using namespace std;

namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        private:
            vector<Entidades::Personagens::Inimigo*> LIs;
            list<Entidades::Obstaculos::Obstaculo*> LOs;
            list<Entidades::Parede*>LPas;
            set<Entidades::Projetil*> LPs;
            Entidades::Personagens::Jogador* pJog1;
            Entidades::Personagens::Jogador* pJog2;
        
        public:
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();

        private:
            const bool verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2) const;
            void tratarColisoesJogsObstacs();
            void tratarColisoesJogsInimigs(); 
            void tratarColisoesJogsProjeteis();
            void tratarColisoesInimigsObstacs();
            void tratarColisoesInimigsProjeteis();
            void tratarColisoesObstacsProjeteis();
            void tratarColisoesJogsParedes();
            void tratarColisoesInimigsParedes();
            void tratarColisoesProjeteisParedes();
            void tratarColisoesObstacsParedes();
            //InimigsInimigs

        public:
            void incluirInimigo(Entidades::Personagens::Inimigo* pi);
            void incluirObstaculo(Entidades::Obstaculos::Obstaculo* po);
            void incluirParede(Entidades::Parede* pp);
            void incluirProjetil(Entidades::Projetil* pj);
            void setJogador(Entidades::Personagens::Jogador* pJ);
            void setJogador(Entidades::Personagens::Jogador* pJ1, Entidades::Personagens::Jogador* pJ2);
            void executar();
    };
}