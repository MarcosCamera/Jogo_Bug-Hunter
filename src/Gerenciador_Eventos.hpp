#pragma once
#include "ListaEntidades"

//includes

namespace Gerenciadores
{
	class Gerenciador_Eventos
	{
	private:
		Lista<Entidade>* pLista;
		//listas de entidades
	public:
		Gerenciador_Eventos(Lista<Entidade>* p);
		~Gerenciador_Eventos();

		void percorreLista();
		void verificaEntidade(); //exclui
		void verificaDisparo();
		void verificaAlcance(); //formigas
		void executar(); 
	};
}