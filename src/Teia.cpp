#include "Teia.hpp"
#include "Inimigo.hpp"
#include <iostream>

namespace Entidades {
    

     Teia::Teia() :Projetil(true, 1, 0, 0), tempoVida(3.0f), tempoAtual(0.0f), atingiuInimigo(false)
    {
        try {
            setTexture("Textures/Spider Sprite Sheet.png", sf::Vector2f(1.0f, 1.0f));
            if (pFig) {
                sf::FloatRect bounds = pFig->getLocalBounds();
                pFig->setOrigin(bounds.width/2, bounds.height / 2);
                pFig->setPosition(0, 0); 
                this->pos = sf::Vector2f(0, 0);
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Erro ao carregar textura da teia: " << e.what() << std::endl;
        }
    }

    
    Teia::Teia(sf::Vector2f pos) : Projetil(true, 10, pos.x, pos.y), tempoVida(3.0f), tempoAtual(0.0f), atingiuInimigo(false)
    {
        try {
            setTexture("Textures/Spider Sprite Sheet.png", sf::Vector2f(1.0f, 1.0f));
            if (pFig) {
                sf::FloatRect bounds = pFig->getLocalBounds();
                pFig->setOrigin(bounds.width/2, bounds.height / 2);
                pFig->setPosition(pos);
                this->pos = pos;
                
            
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Erro ao carregar textura da teia: " << e.what() << std::endl;
        }
    }

        Teia::~Teia() {}

        void Teia::executar() 
        {

         if (ativo && !atingiuInimigo && tempoAtual < tempoVida) {
                mover();
            }
          
              

        }

         void Teia::danificarPersonagem(Personagens::Personagem* pVitima) 
        {
            if (pVitima && ativo) {
               pVitima->perdeVida(1);
               this->desativar();
                atingiuInimigo = true;
            }
        }


       
        void Teia::mover()
        {
             if (!atingiuInimigo) {
                pos.x += vel.x;
                //vel.y += 0.05f; 
                //pos.y += vel.y;
                
                if (getFig()) {
                    getFig()->setPosition(pos);
                }
                
                
            }
            
        }
    
}
