#pragma once
#include "Entidade.hpp" 
#include <SFML/Graphics.hpp>

namespace Entidades
{
    class Parede : public Entidade 
    {
    private:
        float altura; 

    public:
        Parede(sf::Vector2f posicao, sf::Vector2f dimensoes);
        virtual ~Parede();

        void executar() override;
        
        float getAltura() const { return altura; }
        

        
    };
}
