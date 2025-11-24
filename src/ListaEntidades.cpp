#include "ListaEntidades.hpp"
#include "Entidade.hpp"
#include "Lista.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>
using namespace  std;

using Entidades::Entidade;
using namespace Listas;
using Iterador = Listas::Lista<Entidades::Entidade>::Iterador<Entidades::Entidade>;

    ListaEntidades::ListaEntidades() {}
    ListaEntidades::~ListaEntidades() 
    {
        LEs.limpar();
    }
    
    Lista<Entidades::Entidade>* ListaEntidades::getLista()
    {
        return &LEs;
    }

    void ListaEntidades::incluir(Entidade* pE)
    {
        if (pE)
        {
            LEs.incluir(pE);
        }
        else
         cout<<"ListaEntidades::incluir() -> Entidade* pE NULL"<<endl;
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

    void ListaEntidades::retirar(Entidades::Entidade* pE)
    {
        if (pE)
        {
            LEs.remove(pE);
        }
        else
        {
             cout<<"ListaEntidades::retirar() -> Entidade* pE NULL"<<endl;
        }
    }
