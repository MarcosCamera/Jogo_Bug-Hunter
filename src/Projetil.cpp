#include "Projetil.hpp"

namespace Entidades
{
	Projetil::Projetil(bool al, bool dir, sf::Vector2f(pos), short int i): Entidade(), ativo(true), aliado(al), impacto(i)
	{
		direcao = dir;
		pFig->setPosition(pos);
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

	bool Projetil::getAtividade()const
	{
		return ativo;
	}

	void Projetil::desativar()
	{
		ativo = false;
	}

	void Projetil::danificarPersonagem(Personagens::Personagem* pVitima)
	{
		if (ativo)
		{
			pVitima->perdeVida(impacto);
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