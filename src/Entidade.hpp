#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.hpp"

namespace Entidades{
    class Entidade:public Ente
    {
        protected:
            sf::Vector2f pos;
            sf::Vector2f vel;
            sf::Vector2f acel; //faço um vetor aceleracao???
            const float gravidade;
            const float arrasto;
            const float velMovMax; //cada ente terá uma velocidade maxima para a qual pode acelerar atraves de mover
            bool direcao; //true se for pra direita e false se for pra esquerda. TRATAR EM OBSTACULIZAR
            bool chao; //se está pisando em algo
            //const float acelera; //conta a aceleração, desaceleração e gravidade
            //const float desacelera; //pode ser const para inicializar em classe herdada e nao ser mais alterada?

            sf::Texture textura;
 
            //toda entidade tem gravidade, mas algumas tem força externa agindo sobre e equilibram. 
            //implementar funçao contraForça. para algumas plataformas, ha uma força quando um objeto pisa sobre
            //todas funções de movimento estão em ente, pois alguns Obstáculos também possuem movimento
            //devo implementar em personagem?

        public:
            Entidade();
            Entidade(const std::string& caminhoSprite, sf::Vector2f posicao); //sobrecarga construtora
            virtual ~Entidade();

            void acelerar(); //incluir resistencia do ar
            void atualizaVel();


            //void setVel(sf::Vector2f velocidade);  //como ele é protected, nao é necessaria a funçao set, ou é?
            //void setPos(sf::Vector2f posicao);     //

            //sf::Vector2f getVel() const; //como ele é protected, nao é necessaria a funçao get, ou é?
            //sf::Vector2f getPos() const; //como ele é protected, nao é necessaria a funçao get, ou é?

            //void colidirParede(); //nao será necessario. será implementado em "Obstaculo" e usado no gerenciador de colisoes

            virtual void executar() = 0;
            virtual void salvar() = 0;
    };
}