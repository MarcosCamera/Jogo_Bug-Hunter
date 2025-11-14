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
    LPs.clear();
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() 
{
    LIs.clear();
    LOs.clear();
    LPs.clear(); 
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

const bool Gerenciador_Colisoes::verificarColisao(Entidades::Entidade* p1, Entidades::Entidade* p2) const
{
    if(p1 && p2)
    { 
        sf::FloatRect caixa1 = p1->getFig()->getGlobalBounds();
        sf::FloatRect caixa2 = p2->getFig()->getGlobalBounds();
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

    pJog1->setChao(false); //vai dar true na funçao obstaculizar se estiver pisando em obstaculo.
    for(it = LOs.begin(); it != LOs.end(); it++)
    {
        Obstaculo* pObst = *it;
        //Entidades::Entidade aux = static_cast <Entidades::Entidade*> (pObst);
        if (pObst && verificarColisao(static_cast<Entidades::Entidade*>(pJog1), static_cast<Entidades::Entidade*>(pObst))) //static_cast <Entidade*> pObst ??
        {
            pObst->obstaculizar(pJog1); //tratar em obstaculizar os obstaculos de dano também. obstaculizar deve 
        }                               //ser implementada em cada tipo de obstaculo diferentemente.
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
        if (!it)
        {
            cout << "Ponteiro Nulo" << endl;
        }
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
            pProj->danificarJogador(pJog);//ainda nao implementada em Projetil. 
            //setar ativo para false 
        }
    }
}

void Gerenciador_Colisoes::tratarColisoesInimigsObstacs()
{
    vector<Inimigo*>::iterator itIn;
    list<Obstaculo*>::iterator itObs;

    for (itIn = LIs.begin(); itIn != LIs.end(); itIn++)
    {
        Inimigo* pInim = *itIn;

        for (itObs = LOs.begin(); itObs != LOs.end(); itObs++)
        {
            Obstaculo* Obst = *itObs;

            if (pInim && pObst && verificarColisao(pInim, pObst)
            {
                pObst->obstaculizar() //o obstaculizar personagem ou obstaculizar inimigos e jogadores (2 funçoes)?
            }
        }
    }
}

void Gerenciador_Colisoes::tratarColisoesInimigsProjeteis() //apenas para quando a aranha tiver projetil
{
    vector<Inimigo*>::iterator itIn;
    set<Projetil*>::iterator itPj;

    for (itIn = LIs.begin(); itIn != LIs.end(); itIn++)
    {
        Inimigo* pInim = *itIn;

        for (itPj = LPs.begin(); itPj != LPs.end(); itPj++)
        {
            Projetil* pProj = *itPj;

            if (pInim && pProj && verificarColisao(pInim, pProj)
            {
                //setar bool ativo para false 
            }
        }

    }
}

void Gerenciador_Colisoes::tratarColisoesObstacsProjeteis()
{
    list<Obstaculo*>::iterator itObs;
    set<Projetil*>::iterator itPj;

    for (itObs = LOs.begin(); itObs != LOs.end(); itObs++)
    {
        Obstaculo* pObst = *itObs;

        for (itPj = LPs.begin(); itPj != LPs.end(); itPj++)
        {
            Projetil* pProj = *itPj;
            if (pObst && pProj && verificarColisao(pObst, pProj))
            {
                //setar bool ativo para false se for de inimigo
                //se projetil for de aranha, o projetil fica estatico e muda a sprite
            }
        }
    }
}

void Gerenciador_Colisoes::executar() 
{
    tratarColisoesJogsObstacs();
    tratarColisoesJogsInimigs();
    tratarColisoesJogsProjeteis();
    tratarColisoesInimigsObstacs();
    tratarColisoesInimigsProjeteis();
    tratarColisoesObstacsProjeteis();
}