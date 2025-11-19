#pragma once
#include "ListaEntidades.hpp"

//includes

namespace Gerenciadores
{
	class Gerenciador_Eventos
	{
	private:
		Lista<Entidade>* pLista;
		int posicaoJogadores;
		int posicaoFormigas;
		int posicaoGrilos;
		int posicaoLouvaDeus;
		int posicaoFolhas;
		int posicaoFormigueiros;
		int posicaoPlantaCarnivora;
		//listas de entidades
	public:
		Gerenciador_Eventos(Lista<Entidade>* p);
		~Gerenciador_Eventos();

		void percorreLista();
		void verificaEntidade(); //exclui
		void verificaDisparo();	 //LouvaDeus
		void verificaAlcance();  //formigas
		void atualizaMaldade();  //formigas
		void executar(); 
	};
}