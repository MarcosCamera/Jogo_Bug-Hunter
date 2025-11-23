#pragma once
#include "ListaEntidades.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "Entidade.hpp"
#include "Personagem.hpp"
#include "SFML/Window.hpp"
#include "Projetil.hpp"
#include "Jogo.hpp"
#include "Jogador.hpp"

namespace Gerenciadores
{
	class Gerenciador_Eventos
	{
	private:
		Listas::ListaEntidades* pLista; //lista de entidades da fase
		Gerenciadores::Gerenciador_Colisoes* pGc;
		/*
		list<Entidades::Personagens::Formiga*> LInimForms;
		list<Entidades::Personagens::Grilo*> LInimGrs;
		list<Entidades::Personagens::LouvaDeus*> LInimLDs;
		list<Entidades::Obstaculos::Folha*> LObsFols;
		list<Entidades::Obstaculos::PlantaCarnivora*> LObsPCs;
		list<Entidades::Parede*>LPas;
		list<Entidades::Obstaculos::Formigueiro*> LObsForms;
		list<Entidades::Projetil*> LPs;
		*/
		Entidades::Personagens::Jogador* pJog1;
		Entidades::Personagens::Jogador* pJog2;
		int numeroFormigueiros;
		int numeroFormigas;

	public:
		Gerenciador_Eventos(Listas::ListaEntidades* lis, Gerenciadores::Gerenciador_Colisoes* gerCol);
		~Gerenciador_Eventos();
		/*
		void incluirFormigas();
		void incluirGrilos();
		void incluirLouvaDeus();
		void incluirFolhas();
		void incluirProjetil();
			*/

		//void atualizarMovimentos();
		//void atualizarTexturas();
		void setNumeroFormigueiros(int n);
		int getNumeroFormigueiros();
		void setNumeroFormigas(int n);
		int getNumeroFormigas();
		void verificaEntidade(Entidades::Entidade* ent);					//exclui e aumenta pontuação
		void verificaDisparo(Entidades::Personagens::Personagem* per);		//LouvaDeus e jogadores
		void criarProjetil(Entidades::Personagens::Personagem* per);
		void verificaAlcance(Entidades::Personagens::Formiga* pForm);		//formigas
		void atualizaMaldade(Entidades::Personagens::Formiga* pForm);		//formigas
		void atualizaLargura(Entidades::Obstaculos::Formigueiro* pForm);
		void comandarJogadores();											//Jogadores
		void percorrer(Entidades::Entidade* ent);
		void executar(); 
	};
}