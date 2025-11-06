#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.hpp"

namespace Entidades{
    class Entidade:public Ente
    {
        protected:
            sf::Vector2f pos;
            sf::Vector2f vel;
            //sf::Vector2f acel; //faço um vetor aceleracao???
            //bool direcao
            //bool piso //se está pisando em algo
            //const float velMax;  //implementar
            //const float acelera;
            //const float desacelera; //pode ser const para inicializar em classe herdada e nao ser mais alterada?
            //const float gravidade;
 
            //toda entidade tem gravidade, mas algumas tem força externa agindo sobre e equilibram. 
            //implementar funçao contraForça. para algumas plataformas, ha uma força quando um objeto pisa sobre
            sf::Texture textura;

        public:
            Entidade();
            Entidade(const std::string& caminhoSprite, sf::Vector2f posicao); //sobrecarga construtora
            virtual ~Entidade();

            virtual void executar() = 0;
            virtual void salvar() = 0;

            //void setVel(sf::Vector2f velocidade);  //como ele é protected, nao é necessaria a funçao set, ou é?
            void setPos(sf::Vector2f posicao);

            sf::Vector2f getVel() const; //como ele é protected, nao é necessaria a funçao get, ou é?
            sf::Vector2f getPos() const; //como ele é protected, nao é necessaria a funçao get, ou é?

            //void colidirParede(); //nao será necessario. será implementado em "Obstaculo" e usado no gerenciador de colisoes
            //void acelerar()
            //void cair();  //usa gravidade
            //void desacelerar(); //tudo que estiver em movimento, desacelera. Resistencia do ar/atrito
    };
}