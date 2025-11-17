#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.hpp"

namespace Entidades
{
    class Personagem; //está correto fazer assim?
    class Projetil;
    class Obstaculo;
    class Parede;

    class Entidade:public Ente
    {
        protected:
            sf::Vector2f pos;
            sf::Vector2f vel;
            sf::Vector2f acel; //faço um vetor aceleracao???
            const float gravidade; //fazer velocidade terminal
            float normal; //força normal que anula gravidade
            const float arrasto;
            float velMovMax; //maxima velocidade para cada direção //deveria ser const?
            bool direcao; //true se for pra direita e false se for pra esquerda. TRATAR EM OBSTACULIZAR
            bool chao; //se está pisando em algo
            //ostream buffer; //para que serve???

        public:
            Entidade();
            //Entidade(const std::string& caminhoSprite, sf::Vector2f posicao); //sobrecarga construtora
            virtual ~Entidade();

            void setChao(bool c);
            bool getChao()const;
            bool getDir()const;
            sf::Vector2f getPos()const;
            void setPos(sf::Vector2f novaPos);
            void acelerar(); //incluir resistencia do ar
            void atualizaVel();
            void atualizaPos();
            virtual void executar() = 0;
            virtual void salvar() = 0;
    };
}