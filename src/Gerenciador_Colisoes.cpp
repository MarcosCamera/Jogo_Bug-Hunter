#include "Gerenciador_Colisoes.hpp"
#include <iostream>

using namespace std;
using namespace sf;

namespace Gerenciadores
{
    //fazer jogador 2;

    Gerenciador_Colisoes::Gerenciador_Colisoes() :
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

    void Gerenciador_Colisoes::incluirInimigo(Entidades::Personagens::Inimigo* pi)
    {
        if (pi)
            LIs.push_back(pi);
        else
            cout << "Gerenciador_Colisoes::incluirInim(Inimigo* pi) -> ponteiro nulo" << endl;
    }

    void Gerenciador_Colisoes::incluirObstaculo(Entidades::Obstaculos::Obstaculo* po)
    {
        if (po)
            LOs.push_back(po);
        else
            cout << "Gerenciador_Colisoes::incluirObstaculo(Obstaculo* po) -> ponteiro nulo" << endl;
    }

    void Gerenciador_Colisoes::incluirProjetil(Entidades::Projetil* pj)
    {
        if (pj)
            LPs.insert(pj);
        else
            cout << "Gerenciador_Colisoes::incluirProjetil(Projetil* pj) -> ponteiro nulo" << endl;
    }

    void Gerenciador_Colisoes::setJogador(Entidades::Personagens::Jogador* pJ)
    {
        pJog1 = pJ;
    }

    const bool Gerenciador_Colisoes::verificarColisao(Entidades::Entidade* p1, Entidades::Entidade* p2) const
    {
        if (p1 && p2)
        {
            sf::FloatRect caixa1 = p1->getFig()->getGlobalBounds();
            sf::FloatRect caixa2 = p2->getFig()->getGlobalBounds();
            return caixa1.intersects(caixa2);
        }

        else {
            cout << "Gerenciador_Colisoes::verificarColisao(p1,p2) -> p1 ou p2, ou ambos NULL" << endl;
            return false;
        }
    }


    void Gerenciador_Colisoes::tratarColisoesJogsObstacs()
    {
        list<Entidades::Obstaculos::Obstaculo*>::iterator it;
        if (!pJog1)
        {
            cout << "Gerenciador_Colisoes::tratarColisoesJogsObstacs() -> pJog1 NULL" << endl;
            return;
        }

        pJog1->setChao(false); //vai dar true na funçao !!obstaculizar!! se estiver pisando em obstaculo.
        for (it = LOs.begin(); it != LOs.end(); it++)
        {
            if(*it) //padronizar
            {
                Entidades::Obstaculos::Obstaculo* pObst = *it;
                
                if (pObst && verificarColisao(pJog1, pObst)) // nao esta redundante?? ele verifica colisao aqui e em obstaculizar
                {
                    pObst->obstaculizar(pJog1); //tratar em obstaculizar os obstaculos de dano também. obstaculizar deve 
                }                               //ser implementada em cada tipo de obstaculo diferentemente.
            }
        }
    }


    void Gerenciador_Colisoes::tratarColisoesJogsInimigs()
    {
        vector<Entidades::Personagens::Inimigo*>::iterator it;

        if (!pJog1)
        {
            cout << "GerenciadorColisoes::coliJogsInimigo() -> pJog1 NULL" << endl;
            return;
        }
        if (!LIs.empty())
        {

            for (it = LIs.begin(); it != LIs.end(); it++)
            {
                Entidades::Personagens::Inimigo* pInim = *it;

                if (pInim && verificarColisao(pJog1, pInim))
                {
                    pJog1->colidir(pInim);
                }
            }
        }
    }

    void Gerenciador_Colisoes::tratarColisoesJogsProjeteis()
    {
        set<Entidades::Projetil*>::iterator it;

        if (!pJog1)
        {
            cout << "GerenciadorColisoes::coliJogsProjeteis() -> pJog1 NULL" << endl;
            return;
        }

        if (!LPs.empty())
        {

            for (it = LPs.begin(); it != LPs.end(); it++)
            {
                Entidades::Projetil* pProj = *it;

                if (pProj && !pProj->getAliado() && verificarColisao(pJog1, pProj))
                {
                    pProj->danificarPersonagem(static_cast<Entidades::Personagens::Personagem*>(pJog1)); 
                    pProj->desativar();
                }
            }
        }
    }

    void Gerenciador_Colisoes::tratarColisoesInimigsObstacs()
    {
        vector<Entidades::Personagens::Inimigo*>::iterator itIn;
        list<Entidades::Obstaculos::Obstaculo*>::iterator itObs;

        for (itIn = LIs.begin(); itIn != LIs.end(); itIn++)
        {
            Entidades::Personagens::Inimigo* pInim = *itIn;

            for (itObs = LOs.begin(); itObs != LOs.end(); itObs++)
            {
                Entidades::Obstaculos::Obstaculo* pObst = *itObs;

                if (pInim && pObst && verificarColisao(pInim, static_cast<Entidades::Entidade*>(pObst)))
                {
                    pObst->obstaculizar(pInim); //o obstaculizar personagem ou obstaculizar inimigos e jogadores (2 funçoes)?
                }
            }
        }
    }

    void Gerenciador_Colisoes::tratarColisoesInimigsProjeteis() //apenas para quando a aranha tiver projetil
    {
        vector<Entidades::Personagens::Inimigo*>::iterator itIn;
        set<Entidades::Projetil*>::iterator itPj;

        for (itIn = LIs.begin(); itIn != LIs.end(); itIn++)
        {
            Entidades::Personagens::Inimigo* pInim = *itIn;

            for (itPj = LPs.begin(); itPj != LPs.end(); itPj++)
            {
                Entidades::Projetil* pProj = *itPj;

                if (pInim && pProj && pProj->getAliado() && verificarColisao(pInim, pProj))
                {
                    pProj->danificarPersonagem(static_cast<Entidades::Personagens::Personagem*>(pInim));
                    pProj->desativar();
                }
            }

        }
    }

    void Gerenciador_Colisoes::tratarColisoesObstacsProjeteis()
    {
        list<Entidades::Obstaculos::Obstaculo*>::iterator itObs;
        set<Entidades::Projetil*>::iterator itPj;

        for (itObs = LOs.begin(); itObs != LOs.end(); itObs++)
        {
            Entidades::Obstaculos::Obstaculo* pObst = *itObs;

            for (itPj = LPs.begin(); itPj != LPs.end(); itPj++)
            {
                Entidades::Projetil* pProj = *itPj;
                if (pObst && pProj && verificarColisao(pObst, pProj))
                {
                    pProj->desativar();
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
}