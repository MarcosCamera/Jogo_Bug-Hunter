#include "Menu.hpp"
#pragma once
#define N_LEADERBOARD 10 // Use o número máximo de posições desejado

class MenuRanking : public Menu
{
    private:
      int nPosicoes;
    public:
      MenuRanking();
      ~MenuRanking();
      int mostrar(sf::RenderWindow& window);
};