#include "Projetil.hpp"

namespace Entidades
{
	Projetil::Projetil(): Entidade(), ativo(true)
	{
		
	}

	Projetil::~Projetil()
	{
		if (pFig)
		{
			delete pFig;
			pFig = NULL;
		}
	}

	Projetil::salvar(){}

	Projetil::executar(){}
}