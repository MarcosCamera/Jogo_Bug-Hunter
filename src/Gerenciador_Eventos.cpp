#include "Gerenciador_Eventos.hpp"
#include "ListaEntidades.hpp"
#include "Entidade.hpp"
#include "Personagem.hpp"
#include "SFML/Window.hpp"
#include "Projetil.hpp"
#include "Jogo.hpp"
#include "Jogador.hpp"
#include "Formiga.hpp"
#include "Formigueiro.hpp"


namespace Gerenciadores
{
	Gerenciador_Eventos::Gerenciador_Eventos(Listas::ListaEntidades* lis, Gerenciadores::Gerenciador_Colisoes* gerCol) :
		pLista(lis),
		pGc(gerCol),
		/*
		LInimForms(),
		LInimGrs(),
		LInimLDs(),
		LObsFols(),
		LObsPCs(),
		LPas(),
		LObsForms(),
		LPs(),
		*/
		pJog1(NULL),
		pJog2(NULL),
		numeroFormigueiros(0),
		numeroFormigas(0)
	{
		/*LInimForms.clear();
		LInimGrs.clear();
		LInimLDs.clear();
		LObsFols.clear();
		LObsPCs.clear();
		LPas.clear();
		LObsForms.clear();
		LPs.clear();
		*/
	}

	Gerenciador_Eventos::~Gerenciador_Eventos()
	{
		pLista = NULL;
		pGc = NULL;
		/*
		LInimForms.clear();
		LInimGrs.clear();
		LInimLDs.clear();
		LObsFols.clear();
		LObsPCs.clear();
		LPas.clear();
		LObsForms.clear();
		LPs.clear();
		*/
		pJog1 = NULL;
		pJog2 = NULL;
	}

	void Gerenciador_Eventos::setNumeroFormigueiros(int n)
	{
		numeroFormigueiros = n;
	}

	int Gerenciador_Eventos::getNumeroFormigueiros()
	{
		return numeroFormigueiros;
	}
	void Gerenciador_Eventos::setNumeroFormigas(int n)
	{
		numeroFormigas = n;
	}
	int Gerenciador_Eventos::getNumeroFormigas()
	{
		return numeroFormigas;
	}

	void Gerenciador_Eventos::verificaEntidade(Entidades::Entidade* ent)
	{
		if (ent)
		{
			Entidades::Personagens::Personagem* pers = dynamic_cast<Entidades::Personagens::Personagem*>(ent);
			Entidades::Obstaculos::Formigueiro* form = dynamic_cast<Entidades::Obstaculos::Formigueiro*>(ent);
			Entidades::Projetil* proj = dynamic_cast<Entidades::Projetil*>(ent);
			if (pers && pers->getVida() <= 0)
			{
				Entidades::Personagens::Inimigo* inim = dynamic_cast<Entidades::Personagens::Inimigo*>(pers);
				if (inim)
				{
					if (pJog1)
					{
						pJog1->operator++(); //pontuação
					}
					if (pJog2)
					{
						pJog2->operator++();
					}
				}

				pLista->remover(pers);
			}
			else if (form && !form->getAtividade())
			{
				if (pJog1)
				{
					pJog1->operator++(); //pontuação
				}
				if (pJog2)
				{
					pJog2->operator++();
				}

				pLista->remover(form);
			}
			else if (proj && !proj->getAtividade())
			{
				pLista->remover(proj);
			}
		}
	}

	void Gerenciador_Eventos::verificaDisparo(Entidades::Personagens::Personagem* per)
	{
		if (per->getDisparo())
		{
			criarProjetil(per);
			per->setDisparo(false);
		}
	}

	void Gerenciador_Eventos::criarProjetil(Entidades::Personagens::Personagem* per)
	{
		Entidades::Personagens::Inimigo* inim = dynamic_cast<Entidades::Personagens::Inimigo*>(per);
		Entidades::Personagens::Jogador* jog = dynamic_cast<Entidades::Personagens::Jogador*>(per);

		if (inim)
		{
			Entidades::Projetil* pProj = new Entidades::Projetil(false, inim->getDir(), inim->getPos(), inim->getImpacto());
			pLista->incluir(pProj);
			pGc->incluirProjetil(pProj);
		}
		else if (jog)
		{
			Entidades::Projetil* pProj = new Entidades::Projetil(true, jog->getDir(), jog->getPos(), jog->getImpacto());
			pLista->incluir(pProj);
			pGc->incluirProjetil(pProj);
		}
	}

	void Gerenciador_Eventos::verificaAlcance(Entidades::Personagens::Formiga* pForm)
	{
		if (pForm)
		{
			float distJog1 = pForm->verificaAlcance(pJog1);
			float distJog2 = pForm->verificaAlcance(pJog2);

			if (distJog1 <= distJog2 && distJog1 <= pForm->getRaio())
			{
				pForm->seguir(pJog1);
			}
			else if (distJog2 <= distJog1 && distJog2 <= pForm->getRaio())
				pForm->seguir(pJog2);
		}
	}

	void Gerenciador_Eventos::atualizaMaldade(Entidades::Personagens::Formiga* pForm)
	{
		if (pForm)
		{
			pForm->setMaldade(numeroFormigueiros); //maldade das formigas depende do número de formigueiros
		}
	}

	void Gerenciador_Eventos::atualizaLargura(Entidades::Obstaculos::Formigueiro* pForm)
	{
		if (pForm)
		{
			pForm->setLargura(static_cast<float>(numeroFormigas));
		}
	}

	void Gerenciador_Eventos::comandarJogadores()
	{
		if (pJog1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				pJog1->controlar('A');
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				pJog1->controlar('D');
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				pJog1->controlar('W');
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				pJog1->controlar('S');
			}

			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				pJog1->controlar('Z'); //zera vel x
			}
		}

		if (pJog2)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				pJog2->controlar('A');
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				pJog2->controlar('D');
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				pJog2->controlar('W');
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				pJog2->controlar('S');
			}

			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				pJog2->controlar('Z'); //zera vel x
			}
		}
	}

	void Gerenciador_Eventos::percorrer(Entidades::Entidade* ent)
	{
		Entidades::Personagens::Personagem* pers = dynamic_cast<Entidades::Personagens::Personagem*>(ent);
		Entidades::Obstaculos::Obstaculo* obs = dynamic_cast<Entidades::Obstaculos::Obstaculo*>(ent);
		Entidades::Projetil* proj = dynamic_cast<Entidades::Projetil*>(ent);
		Entidades::Parede* par = dynamic_cast<Entidades::Parede*>(ent);


		if (pers)
		{
			verificaDisparo(pers);

			Entidades::Personagens::Formiga* form = dynamic_cast<Entidades::Personagens::Formiga*>(pers);
			if (form)
			{
				verificaAlcance(form);
				atualizaMaldade(form);
				numeroFormigas++;
			}
		}
		else if (obs)
		{
			Entidades::Obstaculos::Formigueiro* form = dynamic_cast<Entidades::Obstaculos::Formigueiro*>(obs);
			if (form)
			{
				atualizaLargura(form);
				numeroFormigueiros++;
			}

		}
		else if (proj)
		{

		}
		else if (par)
		{

		}

		verificaEntidade(ent);
	}

	void Gerenciador_Eventos::executar()
	{
		comandarJogadores();
	}
}