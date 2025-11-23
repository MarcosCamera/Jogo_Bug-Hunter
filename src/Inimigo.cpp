#include "Inimigo.hpp"

namespace Entidades
{
	namespace Personagens
	{

		Inimigo::Inimigo() :nivel_maldade(0){}
		Inimigo:: ~Inimigo() {}

		void Inimigo::setMaldade(int m)
		{
			nivel_maldade = m;
		}

		int Inimigo::getMaldade()
		{
			return nivel_maldade;
		}

		void Inimigo::operator++()
		{
			nivel_maldade++;
		}

		void Inimigo::operator--()
		{
			nivel_maldade--;
		}
	}
}