#include "Grilo.hpp"

namespace Entidades
{
	namespace Personagens
	{
		Grilo::Grilo(): Inimigo(), tamanhoSalto(0)
		{

		}
		Grilo::~Grilo()
		{
			if (pFig)
			{
				delete pFig;
				pFig = NULL;
			}
		}


		void Grilo::danificar(Jogador* pJog) //deve ser diferente para cada inimigo
		{
			pJog->perdeVida(impacto);
			if(nivel_maldade < 2) //salto aumenta conforme o nivel de maldade
				operator++();
		}

		void Grilo::mover() //usar timer para nao saltar instantaneamente
		{
			if (chao && timer >= 10)
			{
				if (direcao)
					vel.x = velMovMax;
				else
					vel.x = -velMovMax;
				vel.y = -static_cast<float>(tamanhoSalto) * static_cast<float>(nivel_maldade + 1);
				
				normal = - gravidade + vel.y; //força normal para cima
				timer = 0;
			}
			else
			{
				normal = 0;
			}
			timer++;

			acelerar();
			atualizaVel(); //antes ou depois das acelerações? Testar com ambas formas.
			atualizaPos();
		}

		void Grilo::salvar()
		{

		}

		void Grilo::executar()
		{
			mover();
		}
	}
}