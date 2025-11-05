#include "Jogador.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>
using namespace std;

using namespace Entidades::Personagens;

Jogador::Jogador():Personagem(), pontos(0)
{
//... setar posiçao padrao na fase.
}
Jogador::~Jogador() {}

/*colidir?*/ Jogador::colidir(){}//...

void Jogador::executar()
{
   mover();
}

void Jogador::salvar(){}//...

void Jogador::mover()
{
  //posição mouse
   sf::Vector2i posMouse = sf::Mouse::getPosition(*pGG->getWindow());
   setPos(static_cast<float>(posMouse.x), static_cast<float>(posMouse.y));
}


