#include "Projetil.hpp"

namespace Entidades
{
	Projetil::Projetil(Personagens::Personagem* pAt): Entidade(), ativo(true), aliado(false)
	{
		pAtirador = pAt;
		direcao = pAtirador->getDir();
		pFig->setPosition(pAt->getPos());
		// da problema ter ponteiro de atirador se ele for eliminado?
	}

	Projetil::~Projetil()
	{
		if (pFig)
		{
			delete pFig;
			pFig = NULL;
		}
	}

	bool Projetil::getAliado()const
	{
		return aliado;
	}

	void Projetil::desativar()
	{
		ativo = false;
	}

	void Projetil::danificarPersonagem(Personagens::Personagem* pVitima)
	{
		if (ativo)
		{
			pVitima->perdeVida(pAtirador->getImpacto());
			ativo = false;
		}
	}

	void Projetil::mover()
	{
		if (direcao)
		{
			vel.x = velMovMax;
		}
		else
			vel.x = -velMovMax;
		vel.y = -velMovMax/10;

		acelerar();
	}

	void Projetil::executar(){}
}