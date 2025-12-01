#include "Projetil.hpp"

namespace Entidades
{
	 Projetil::Projetil(bool al, short int i, float posX, float posY) : 
        Entidade(sf::Vector2f(posX, posY)), ativo(true), aliado(al), impacto(i)
    {
		
    }
	Projetil::~Projetil()
	{
	}

	bool Projetil::getAliado()const
	{
		return aliado;
	}

	void Projetil::desativar()
	{
		ativo = false;
	}

	bool Projetil::getAtividade() const
   {
	return ativo;
   }
	
}