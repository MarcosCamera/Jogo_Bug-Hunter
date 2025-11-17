#include "Personagem.hpp"

namespace Entidades
{
	namespace Personagens
	{

		Personagem::Personagem() :Entidade(), num_vidas(0), impacto(0), disparar(false) {}

		Personagem::~Personagem() {}

		void Personagem::perdeVida(int i)
		{
			num_vidas -= i;
		}

		int Personagem::getVida()const
		{
			return num_vidas;
		}

		int Personagem::getImpacto()const
		{
			return impacto;
		}
	}
}