#include "ListaEntidades.hpp"

using namespace  std;

using Iterador = Listas::Lista<Entidades::Entidade>::Iterador<Entidades::Entidade>;

namespace Listas
{
    ListaEntidades::ListaEntidades() {}

    ListaEntidades::~ListaEntidades()
    {
        LEs.limpar();
    }

    Lista<Entidades::Entidade>* ListaEntidades::getLista()
    {
        return &LEs;
    }

    void ListaEntidades::incluir(Entidades::Entidade* pE)
    {
        if (pE)
        {
            LEs.incluir(pE);
        }
        else
            cout << "ListaEntidades::incluir() -> Entidade* pE NULL" << endl;
    }

    void ListaEntidades::percorrer()
    {

        Iterador it = LEs.getIterador();

        while (!it.end())
        {

            Entidades::Entidade* pEntidade = it.getElemento();
            if (pEntidade)
            {
                pEntidade->executar();
            }
            it.proximo();
        }
    }


    void ListaEntidades::limpar()
    {
        LEs.limpar();
    }
}