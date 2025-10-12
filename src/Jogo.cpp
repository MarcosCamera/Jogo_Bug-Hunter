#include "Jogo.hpp"
Jogo::Jogo():window(sf::VideoMode(400,400), "Jogo"){
    jogador1 = new Jogador();
   jogador1->setWindow(&window);
   fase1 = new Fase(jogador1, &window);
   LEs = fase1->getListaEntidades();

   Executar();//jogo, como se fosse a principal, e na principal, tem que chamar os métodos na construtora
}

Jogo::~Jogo(){}

void Jogo::Executar(){
    while (window.isOpen())
    {
        // Verifica todos os eventos da janela que foram disparados desde a última iteração
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Evento de "fechar" solicitado (ex: clicar no "X")
            if (event.type == sf::Event::Closed)
                window.close();
        }
        jogador1->move();
        window.clear(sf::Color::Black);
        for(int i =0; i<LEs ->LEs.getLen();i++){
            Entidade* temp =LEs->LEs.getItem(i);
            temp->draw();
        }
        
        window.display();
    }
}