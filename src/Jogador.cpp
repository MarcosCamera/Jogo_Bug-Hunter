#include "Jogador.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>
using namespace std;

using namespace Entidades::Personagens;

Jogador::Jogador() : Personagem(), pontos(0)
{
  if (!tex.loadFromFile("Textures/spider.png")) {
        cout<< "ERRO: Nao foi possivel carregar a textura da aranha!" << endl;
  }
  pFig->setTexture(tex);
  pFig->setScale(0.03f, 0.03f);
  setPos(1.0f, 1.0f);
}

Jogador::~Jogador() {}

void Jogador::executar()
{
   mover();
   desenhar();
}

void Jogador::mover()
{
  //posição mouse
   sf::Vector2i posMouse = sf::Mouse::getPosition(*pGG->getWindow());
   setPos(static_cast<float>(posMouse.x), static_cast<float>(posMouse.y));
}


