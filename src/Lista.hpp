#pragma once
#include <iostream>


using namespace std;

namespace Listas
{

    template <class TL>
    class Lista
    {
    public:
    
        template <class TE>
        class Elemento
        {
        private:
            
            Elemento<TE>* pProx;
            TE* pInfo;
        public:
            Elemento():pProx(NULL),pInfo(NULL){}
            Elemento(TE* p) : pProx(NULL), pInfo(p) {}
            ~Elemento() {}

            /*void incluir(TE * p)
            {
               
            }*///pq??
            void setProx(Elemento<TE>* pE)
            {
                pProx = pE;
            }
            Elemento <TE>* const getProximo()
            {
                return pProx;
            }

            void setInfo(TE* pInfo) 
            { 
                this->pInfo = pInfo; 
            }

            TE* getInfo() const
            {
                return pInfo;
            }

        };
        template <class TI>
        class Iterador
        {
        private:
            Elemento<TI>* pAtual; 
        public:
            Iterador(Elemento<TI>* p = NULL) : pAtual(p) {}
            ~Iterador() {}
            bool end() 
            { 
                return (pAtual == NULL); 
            }

            TI* getElemento() 
            { 
              if(pAtual)
                return pAtual->getInfo();
              else
              {
                cout<<"TI* getElemento -> pAtual NULL"<<endl;
                return NULL;
              }
            }

            void proximo()
            {
                if (pAtual)
                {
                    pAtual = pAtual->getProximo();
                }
            }
        };

        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;

    public:
        Lista();
        ~Lista();
        void incluir(TL*p);
        void limpar();
        Iterador<TL> getIterador();
    private:
        Elemento<TL>* getPrimElem() const;
        Elemento<TL>* getUltimoElem() const;
    };
     template <class TL>
     Lista<TL>::Lista() :pPrimeiro(NULL),pUltimo(NULL){}

    template <class TL>
     Lista<TL>::~Lista()
    {
        limpar();
    }

    template <class TL>
    void Lista<TL>::incluir(TL* p)
    {
        if (p!=NULL) 
        {
        Elemento<TL>* pAux= NULL;
        pAux = new Elemento<TL>(p);

        if (pPrimeiro == NULL)
        {
            pPrimeiro = pAux;
        }
        else
        {
            pUltimo->setProx(pAux);
            
        }
        pUltimo = pAux;

       }
        else
          cout<<"Ponteiro nulo"<< endl;
    }
    template <class TL>
    void Lista<TL>::limpar()
    {
        Elemento<TL>* pAux = NULL;
        while (pPrimeiro)
        {
            pAux = pPrimeiro;
            pPrimeiro = pPrimeiro->getProximo();
            delete pAux;
            pAux = NULL;
        }
        pPrimeiro = NULL;
        pUltimo = NULL;
    }

    template <class TL>
    Lista<TL>::Elemento<TL>* Lista<TL>::getPrimElem() const
    {
        return pPrimeiro;
    }

    template <class TL>
    Lista<TL>::Elemento<TL>* Lista<TL>:: getUltimoElem() const
    {
        return pUltimo;
    }

    template <class TL>
    Lista<TL>::Iterador<TL> Lista<TL>::getIterador()
    {
         return Iterador<TL>(pPrimeiro);
    }

 };