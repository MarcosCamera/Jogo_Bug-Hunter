#include "Gerenciador_Colisoes.hpp"
#include <iostream>

using namespace std;
using namespace sf;

namespace Gerenciadores
{
    //tratar multiplas colisões;

    Gerenciador_Colisoes::Gerenciador_Colisoes() :
        LIs(),
        LOs(),
        LPas(),
        LPs(),
        pJog1(NULL),
        pJog2(NULL)
    {
        LIs.clear();
        LOs.clear();
        LPas.clear();
        LPs.clear();
    }

    Gerenciador_Colisoes::~Gerenciador_Colisoes()
    {
        LIs.clear();
        LOs.clear();
        LPas.clear();
        LPs.clear();
        pJog1 = NULL;
        pJog2 = NULL;
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

    void Gerenciador_Colisoes::incluirParede(Entidades::Parede* pp)
    {
        if (pp)
            LPas.push_back(pp);
        else
            cout << "Gerenciador_Colisoes::incluirParede(Parede* pp) -> ponteiro nulo" << endl;
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

    void Gerenciador_Colisoes::setJogador(Entidades::Personagens::Jogador* pJ1, Entidades::Personagens::Jogador* pJ2)
    {
        pJog1 = pJ1;
        pJog2 = pJ2;
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

        if (pJog1)
        {
            pJog1->setChao(false); //vai dar true na funçao obstaculizar
            for (it = LOs.begin(); it != LOs.end(); it++)
            {
                if(*it)
                {
                    Entidades::Obstaculos::Obstaculo* pObst = *it;
                
                    if (pObst && verificarColisao(pJog1, pObst)) // nao esta redundante?? ele verifica colisao aqui e em obstaculizar
                    {
                        pObst->obstaculizar(pJog1);
                    }
                }
            }
        }

        if (pJog2)
        {
            pJog2->setChao(false);
            for (it = LOs.begin(); it != LOs.end(); it++)
            {
                if (*it)
                {
                    Entidades::Obstaculos::Obstaculo* pObst = *it;

                    if (pObst && verificarColisao(pJog2, pObst)) 
                    {
                        pObst->obstaculizar(pJog2);
                    }
                }
            }
        }
    }

    void Gerenciador_Colisoes::tratarColisoesJogsInimigs()
    {
        vector<Entidades::Personagens::Inimigo*>::iterator it;

        if (pJog1)
        {
            if (!LIs.empty())
            {

                for (it = LIs.begin(); it != LIs.end(); it++)
                {
                    if (*it)
                    {
                        Entidades::Personagens::Inimigo* pInim = *it;

                        if (pInim && verificarColisao(pJog1, pInim))
                        {
                            pJog1->colidir(pInim);
                        }
                    }
                }
            }
        }

        if (pJog2)
        {
            if (!LIs.empty())
            {

                for (it = LIs.begin(); it != LIs.end(); it++)
                {
                    if (*it)
                    {
                        Entidades::Personagens::Inimigo* pInim = *it;

                        if (pInim && verificarColisao(pJog2, pInim))
                        {
                            pJog1->colidir(pInim);
                        }
                    }
                }
            }
        }
    }

    void Gerenciador_Colisoes::tratarColisoesJogsProjeteis()
    {
        set<Entidades::Projetil*>::iterator it;

        if (pJog1)
        {
            if (!LPs.empty())
            {

                for (it = LPs.begin(); it != LPs.end(); it++)
                {
                    if (*it)
                    {
                        Entidades::Projetil* pProj = *it;

                        if (pProj && !pProj->getAliado() && verificarColisao(pJog1, pProj))
                        {
                            pProj->danificarPersonagem(pJog1); 
                            pProj->desativar();
                        }
                    }
                }
            }
        }

        if (pJog2)
        {
            if (!LPs.empty())
            {

                for (it = LPs.begin(); it != LPs.end(); it++)
                {
                    if (*it)
                    {
                        Entidades::Projetil* pProj = *it;

                        if (pProj && !pProj->getAliado() && verificarColisao(pJog2, pProj))
                        {
                            pProj->danificarPersonagem(pJog2);
                            pProj->desativar();
                        }
                    }
                }
            }
        }
    }

    void Gerenciador_Colisoes::tratarColisoesInimigsObstacs()
    {
        vector<Entidades::Personagens::Inimigo*>::iterator itIn;
        list<Entidades::Obstaculos::Obstaculo*>::iterator itObs;
        bool aterrado = false; //retorna true ao final

        for (itIn = LIs.begin(); itIn != LIs.end(); itIn++)
        {
            if (*itIn)
            {
                Entidades::Personagens::Inimigo* pInim = *itIn;

                pInim->setChao(false); //obstaculizar set verdadeiro depois
                for (itObs = LOs.begin(); itObs != LOs.end(); itObs++)
                {
                    if (*itObs)
                    {
                        Entidades::Obstaculos::Obstaculo* pObst = *itObs;

                        if (pInim && pObst && verificarColisao(pInim, pObst))
                        {
                            pObst->obstaculizar(pInim);
                        }
                    }
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
            if (*itIn)
            {
                Entidades::Personagens::Inimigo* pInim = *itIn;

                for (itPj = LPs.begin(); itPj != LPs.end(); itPj++)
                {
                    if (*itPj)
                    {
                        Entidades::Projetil* pProj = *itPj;

                        if (pInim && pProj && pProj->getAliado() && verificarColisao(pInim, pProj))
                        {
                            pProj->danificarPersonagem(pInim);
                            pProj->desativar();
                        }
                    }
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
            if (*itObs)
            {
                Entidades::Obstaculos::Obstaculo* pObst = *itObs;

                for (itPj = LPs.begin(); itPj != LPs.end(); itPj++)
                {
                    if (*itPj)
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
        }
    }

    void Gerenciador_Colisoes::tratarColisoesJogsParedes()
    {
        list<Entidades::Parede*>::iterator it;

        if (pJog1)
        {
            pJog1->setChao(false); //vai dar true na funçao obstaculizar
            for (it = LPas.begin(); it != LPas.end(); it++)
            {
                if (*it)
                {
                    Entidades::Parede* pPar = *it;

                    if (pPar && verificarColisao(pJog1, pPar))
                    {
                        pPar->obstaculizar(pJog1); 
                    }
                }
            }
        }

        if (pJog2)
        {
            pJog2->setChao(false); //vai dar true na funçao obstaculizar
            for (it = LPas.begin(); it != LPas.end(); it++)
            {
                if (*it)
                {
                    Entidades::Parede* pPar = *it;

                    if (pPar && verificarColisao(pJog2, pPar))
                    {
                        pPar->obstaculizar(pJog2);
                    }
                }
            }
        }
    }

    void Gerenciador_Colisoes::tratarColisoesInimigsParedes()
    {
        vector<Entidades::Personagens::Inimigo*>::iterator itIn;
        list<Entidades::Parede*>::iterator itPar;

        for (itIn = LIs.begin(); itIn != LIs.end(); itIn++)
        {
            if (*itIn)
            {
                Entidades::Personagens::Inimigo* pInim = *itIn;

                pInim->setChao(false);
                for (itPar = LPas.begin(); itPar != LPas.end(); itPar++)
                {
                    if (*itPar)
                    {
                        Entidades::Parede* pPar = *itPar;

                        if (pInim && pPar && verificarColisao(pInim, pPar))
                        {
                            pPar->obstaculizar(pInim);
                        }
                    }
                }
            }
        }
    }

    void Gerenciador_Colisoes::tratarColisoesProjeteisParedes()
    {
        list<Entidades::Parede*>::iterator itPar;
        set<Entidades::Projetil*>::iterator itPj;

        for (itPar = LPas.begin(); itPar != LPas.end(); itPar++)
        {
            if (*itPar)
            {
                Entidades::Parede* pPar = *itPar;

                for (itPj = LPs.begin(); itPj != LPs.end(); itPj++)
                {
                    if (*itPj)
                    {
                        Entidades::Projetil* pProj = *itPj;
                        if (pPar && pProj && verificarColisao(pPar, pProj))
                        {
                            pProj->desativar();
                            //setar bool ativo para false se for de inimigo
                            //se projetil for de aranha, o projetil fica estatico e muda a sprite
                        }
                    }
                }
            }
        }
    }

    void Gerenciador_Colisoes::tratarColisoesObstacsParedes()
    {
        list<Entidades::Obstaculos::Obstaculo*>::iterator itObs;
        list<Entidades::Parede*>::iterator itPar;

        for (itObs = LOs.begin(); itObs != LOs.end(); itObs++)
        {
            if (*itObs)
            {
                Entidades::Obstaculos::Obstaculo* pObs = *itObs;

                pObs->setChao(false);
                for (itPar = LPas.begin(); itPar != LPas.end(); itPar++)
                {
                    if (*itPar)
                    {
                        Entidades::Parede* pPar = *itPar;

                        if (pObs && pPar && verificarColisao(pObs, pPar))
                        {
                            pPar->obstaculizar(pObs);
                        }
                    }
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
        tratarColisoesJogsParedes();
        tratarColisoesInimigsParedes();
        tratarColisoesProjeteisParedes();
        tratarColisoesObstacsParedes();
    }
}