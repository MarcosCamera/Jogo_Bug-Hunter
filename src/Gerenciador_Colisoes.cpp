#include "Gerenciador_Colisoes.hpp"
#include <iostream>

using namespace Gerenciadores;
using namespace std;
using namespace sf;

//fazer jogador 2;

Gerenciador_Colisoes::Gerenciador_Colisoes():
LIs(),
LOs(),
LPs(),
pJog1(NULL)
{
    LIs.clear();
    LOs.clear();
    LPs.clear(); //esta correto?
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {

    LIs.clear();
    LOs.clear();
    LPs.clear(); //esta correto?
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

void Gerenciador_Colisoes::incluirProjetil(Projetil* pj)
{
    if (pj)
        LPs.insert(pj);
    else
        cout << "Gerenciador_Colisoes::incluirProjetil(Projetil* pj) -> ponteiro nulo" << endl;
}

void Gerenciador_Colisoes :: setJogador(Jogador* pJ) 
{ 
  pJog1 = pJ;
}

const bool Gerenciador_Colisoes::verificarColisao(Entidade* p1, Entidade* p2) const
{
    if(p1 && p2)
    { 
        sf::FloatRect caixa1 = p1->getGlobalBounds(); 
        sf::FloatRect caixa2 = p2->getGlobalBounds();
        return caixa1.intersects(caixa2);
    }

    else {
      cout<<"Gerenciador_Colisoes::verificarColisao(p1,p2) -> p1 ou p2, ou ambos NULL"<<endl;
      return false;
    }
}


void Gerenciador_Colisoes::tratarColisoesJogsObstacs()
{
    list<Obstaculo*>::iterator it;
    if(!pJog1)
    {
      cout << "GerenciadorColisoes::tratarColisoesJogsObstacs() -> pJog1 NULL" << endl;
        return;
    }
    for(it = LOs.begin(); it != LOs.end(); it++)
    {
        Obstaculo* pObst = *it;

        if (pObst && verificarColisao(pJog1, pObst))
        {
            pObst->obstaculizar(pJog1);
        }
    }


}


void Gerenciador_Colisoes::tratarColisoesJogsInimigs()
{
   vector<Inimigo*>::iterator it;

    if(!pJog1)
    {
        cout << "GerenciadorColisoes::coliJogsInimigo() -> pJog1 NULL" << endl;
        return;
    }

    for(it = LIs.begin(); it != LIs.end(); it++)
    {
        Inimigo* pInim = *it;

        if(pInim && verificarColisao(pJog1, pInim))
        {
            pJog1->colidir(pInim);
        }
    }
    
}

void Gerenciador_Colisoes::tratarColisoesJogsProjeteis()
{
    set<Projetil*>::iterator it;

    if (!pJog1)
    {
        cout << "GerenciadorColisoes::coliJogsProjeteis() -> pJog1 NULL" << endl;
    }

    for (it = LPs.begin(); it != LIs.end(); it++)
    {
        Projetil* pProj = *it;

        if (pProj && verificarColisao(pJog1, pProj))
        {
            //faz o que;
        }
    }
}

void Gerenciador_Colisoes::tratarColisoesInimigsObstacs()
{
    vector<Inimigo*>::iterator itIn;
    list<Obstaculo*>::iterator itObs;

    for (itIn = LIs.begin(); itIn != LIs.end(); itIn++)
    {
        Inimigo* pInim = itIn;

        for (itObs = LOs.begin(); itObs != LOs.end(); itObs++)
        {
            Obstaculo* Obst = itIn;

            if (pInim && pObst && verificarColisao(pInim, pObst)
            {
                pObst->obstaculizar() //o obstaculizar personagem ou obstacularizar inimigos e jogadores (2 funçoes)?
            }
        }
    }
    //...
}

void Gerenciador_Colisoes::tratarColisoesInimigsProjeteis()
{
    vector<Inimigo*>::iterator itIn;
    set<Projetil*>::iterator itPj;

    for (itIn = LIs.begin(); itIn != LIs.end(); itIn++)
    {
        Inimigo* pInim = itIn;

        for (itPj = LPs.begin(); itPj != LPs.end(); itPj++)
        {
            Projetil* pProj = itPj;

            if (pInim && pProj && verificarColisao(pInim, pProj)
            {
                //faz o que ...   
            }
        }

    }
}

void Gerenciador_Colisoes::executar() {

    //tratar o resto das colisoes
    tratarColisoesJogsObstacs();
    tratarColisoesJogsInimigs();
}

