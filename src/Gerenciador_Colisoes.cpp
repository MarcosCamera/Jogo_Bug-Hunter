#include "Gerenciador_Colisoes.hpp"
#include <iostream>

using namespace Gerenciadores;
using namespace std;
using namespace sf;

Gerenciador_Colisoes::Gerenciador_Colisoes():
LIs(),
LOs(),
pJog1(NULL)
{
    LIs.clear();
    LOs.clear();

}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {

    LIs.clear();
    LOs.clear();
    pJog1 = NULL;
}

void Gerenciador_Colisoes::incluirInimigo(Inimigo* pi)
{
  if(pi)
    LIs.push_back(pi);
  else 
    cout << "Gerenciador_Colisoes::incluirInim(Inimigo* pi) -> ponteiro nulo" << endl;
}

void Gerenciador_Colisoes::incluirObstaculo(Obstaculo* po)
{
  if(po)
    LOs.push_back(po);
  else
      cout << "Gerenciador_Colisoes::incluirObstaculo(Obstaculo* po) -> ponteiro nulo" << endl;
}
void Gerenciador_Colisoes :: setJogador(Jogador* pJ) 
{ 
  pJog1 = pJ;
}

const bool Gerenciador_Colisoes::verificarColisao(Entidade* p1, Entidade* p2) const
{
    if(p1 && p2)
    { 
        sf::FloatRect caixa1 = p1->getCorpo().getGlobalBounds(); 
        sf::FloatRect caixa2 = p2->getCorpo().getGlobalBounds();
        return caixa1.intersects(caixa2);
    }

    else {
      cout<<"Gerenciador_Colisoes::verificarColisao(p1,p2) -> p1 ou p2, ou ambos NULL"<<endl;
      return false;
    }
}
