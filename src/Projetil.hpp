#pragma once

#include "Entidade.hpp"
#include "Personagem.hpp" 

namespace Entidades
{
	class Projetil : public Entidade
	{
	protected:
		bool ativo;
		bool aliado;

	public:
		Projetil(bool al, bool dir, sf::Vector2f(pos));
		~Projetil();

		bool getAliado()const;
		bool getAtividade()const;
		void desativar();
		void danificarPersonagem(Personagens::Personagem* pVitima);
		void mover();
		void executar();
	};
}