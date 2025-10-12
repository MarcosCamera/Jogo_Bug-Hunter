#pragma once
template <class TE> class Elemento
{
   private:
       Elemento<TE> *pProx;
       TE* item;
   public:
       Elemento();
       ~Elemento();
       void setProx(Elemento<TE>* p);
       void setItem(TE* i);

       Elemento<TE>* getProx();
       TE* getItem();

};
template<class TE>
inline Elemento<TE> :: Elemento(){
    pProx = nullptr;
    item = nullptr;
}

template<class TE>
inline Elemento<TE> :: ~Elemento(){}

template<class TE>
inline void Elemento<TE> :: setProx(Elemento<TE> *p){pProx = p;}

template<class TE>
inline void Elemento<TE> :: setItem(TE* i){item =i;}

template<class TE>
inline Elemento<TE>* Elemento<TE> :: getProx(){return pProx;}

template<class TE>
 inline TE* Elemento<TE> :: getItem(){return item;}