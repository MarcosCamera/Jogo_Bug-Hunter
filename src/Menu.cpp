#include "Menu.hpp"
#include  <iostream>
Menu::Menu() : opcaoSelecionada(0) {
    if (!fonte.loadFromFile("dungeon-mode.ttf")) { 
        std::cerr << "ERRO: não foi possível carregar a fonte" << std::endl;
    }
    if (texturaFundo.loadFromFile("../Textures/fundomenu.png")) {
        spriteFundo.setTexture(texturaFundo);
        spriteFundo.setScale(800.0f / texturaFundo.getSize().x, 608.0f / texturaFundo.getSize().y);
    }
    else {
        std::cerr << "ERRO: não foi possível carregar o fundo do menu" << std::endl;
    }
}


void Menu::desenharBase(sf::RenderWindow& window) {
    window.setView(window.getDefaultView());
    window.draw(spriteFundo);
    for (auto& t : opcoes)
        window.draw(t);
}

void Menu::desenharMenu(sf::RenderWindow& window) {
    desenharBase(window); 
}

void Menu::addOpcao(const sf::Text& opcao) {
    opcoes.push_back(opcao); 
}

sf::Font& Menu::getFonte()
{ 
    return fonte;

}