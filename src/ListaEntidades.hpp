#pragma once
#include <iostream>
#include "Lista.hpp"
#include "Entidade.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Eventos.hpp"

namespace Entidades
{
    class Entidade;
}
using Iterador = Listas::Lista<Entidades::Entidade>::Iterador<Entidades::Entidade>;

namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista<Entidades::Entidade> LEs;
        Gerenciadores::Gerenciador_Eventos* pGe;

    public:
        ListaEntidades(Gerenciadores::Gerenciador_Eventos* ger); //usar gE como parametro; 
        ~ListaEntidades();

        Lista<Entidades::Entidade>* getLista();
        void incluir(Entidades::Entidade* pE);
        void percorrer();
        void limpar();
    };

}

