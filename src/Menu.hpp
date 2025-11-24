#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Menu {
protected:
    sf::Font fonte;
    sf::Text titulo;
    std::vector<sf::Text> opcoes;
    int opcaoEscolhida;
    void desenharBase(sf::RenderWindow& window);
    sf::Texture texturaFundo;
    sf::Sprite spriteFundo;

public:
    Menu();
    virtual ~Menu() {}
    void desenharMenu(sf::RenderWindow& window); 
    void addOpcao(const sf::Text& opcao); 
    sf::Font& getFonte(); 
};
