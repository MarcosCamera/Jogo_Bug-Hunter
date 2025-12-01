#pragma once
#include <vector>
#include <list>
#include <set>
#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Obstaculo.hpp"
#include "Projetil.hpp"
#include "Parede.hpp"
#include "Teia.hpp"


using namespace std;
using namespace Entidades; 
using namespace Obstaculos;
using namespace Personagens;

namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        private:
            static Gerenciador_Colisoes* pInstancia;

            Gerenciador_Colisoes();

            vector<Entidades::Personagens::Inimigo*> LIs;
            list<Entidades::Obstaculos::Obstaculo*> LOs;
            list<Entidades::Parede*>LPas;
            set<Entidades::Projetil*> LPs;
            std::list<Teia*> LTeias;                    
            Entidades::Personagens::Jogador* pJog1;
            Entidades::Personagens::Jogador* pJog2;

        
        public:
            
            ~Gerenciador_Colisoes();
            static Gerenciador_Colisoes* getInstancia();

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

            void tratarColisoesTeiasInimigos();         
            void tratarColisoesTeiasParedes(); 

            //InimigsInimigs

        public:
            void incluirInimigo(Entidades::Personagens::Inimigo* pi);
            void incluirObstaculo(Entidades::Obstaculos::Obstaculo* po);
            void incluirParede(Entidades::Parede* pp);
            void incluirProjetil(Entidades::Projetil* pj);
            void incluirTeia(Teia* pt);

            void removerInimigo(Entidades::Personagens::Inimigo* pi);
            void removerTeia(Teia* pt);

            void setJogador(Entidades::Personagens::Jogador* pJ);
            void setJogador(Entidades::Personagens::Jogador* pJ1, Entidades::Personagens::Jogador* pJ2);
            void executar();
    };
}
