#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.hpp"

namespace Entidades
{
    class Personagem;
    class Projetil;
    class Obstaculo;
    class Parede;

    class Entidade:public Ente
    {
        protected:
            sf::Vector2f pos;
            sf::Vector2f vel;
            sf::Vector2f acel;
            const float gravidade;
            float normal; //força normal que anula gravidade
            const float arrasto;
            float velMovMax; //maxima velocidade para cada direção
            bool direcao; //true se for pra direita e false se for pra esquerda
            bool chao; //se está pisando em algo 
            //bool vivo//
            //sf::RectangleShape tamanhoVida;

        public:
            Entidade();
            virtual ~Entidade();

            void setChao(bool c);
            bool getChao()const;
            void mudaDir(); //mais seguro um setDir? porque as condições garantem a direção correta
            bool getDir()const;
            void setPos(sf::Vector2f novaPos);
            sf::Vector2f getPos()const;
            void setVel(sf::Vector2f novaVel);
            sf::Vector2f getVel()const;
            void acelerar(); 
            void atualizaVel(); //sobrecarregar essa função, para não precisar de set!!
            void atualizaPos();
            virtual void executar() = 0;
    };
}

