#include "Menu.hpp"
#pragma once
#define NUM_LEADERBOARD 10 // o número máximo de posições desejado

class MenuRanking : public Menu
{
    private:
      int numPosicoes;
    public:
      MenuRanking();
      ~MenuRanking();
      int mostrar(sf::RenderWindow& window);
};
