#include "Fase.hpp"

Fase::Fase(Jogador* j, sf::RenderWindow* w){
   j1 = j;
   listaEntidades = new ListaEntidades();
   window = w;
   i1 = new Inimigo();
   i1->setWindow(window);
    inicializaElementos();
}
Fase::~Fase(){}

void Fase::inicializaElementos(){
   listaEntidades->LEs.push(j1);//coloca o jogador na lsita de entidaes
   listaEntidades->LEs.push(i1);//coloca o inimigo na lsita de entidaes

}