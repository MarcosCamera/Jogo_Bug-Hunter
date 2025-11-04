#pragma once
#include "Personagem.hpp"
#include "Jogador.hpp"



namespace Entidades::Personagens{
class Inimigo : public Personagem{
  protected:
     int nivel_maldade;
  public:
    Inimigo();
    virtual ~Inimigo();
    virtual void executar() = 0;
    virtual void mover() = 0;
    virtual void danificar(Jogador* p) = 0;
     
};
}