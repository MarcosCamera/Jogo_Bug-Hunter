#include "Parede.hpp"
#include <iostream>
using namespace std;
namespace Entidades
{

    Parede::Parede():Entidade(sf::Vector2f(0.0f, 0.0f)), altura(32.0f)
    {

        chao = true;
        
        try 
        {
            const int id_tile = 1;
                
             setTexture("Textures/chao.png", sf::Vector2f(1.0f, 1.0f));
    
            int tilesetColunas = 16;  
            int tileSize = 32;       
            int tileIndex = id_tile - 1;//no tiled, os ids começam em 1, mas o programa usa 0-based. tiled id 1 -> id 0(pelo computador)
            
            int coluna = tileIndex % tilesetColunas;// ex: id 5 % 16 colunas = coluna 5
            int linha = tileIndex / tilesetColunas;// ex: id 5 / 16 colunas = linha 0
            
            sf::IntRect rectTextura(coluna * tileSize, linha * tileSize, tileSize, tileSize);//cria um retangulo da parte da textura q quero usar
            //posicao x = coluna*tamanho do tile, posicao y = linha*tamanho do tile, largura = tamanho do tile, altura = tamanho do tile. (tamanho = altura, é um quadrado)
            pFig->setTextureRect(rectTextura);

        }

        catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }
    }
	Parede::Parede(sf::Vector2f pos , int id_tile) : Entidade(pos), altura(32.0f)
	{
        chao = true;
        
        try 
        {
            
                
             setTexture("Textures/chao.png", sf::Vector2f(1.0f, 1.0f));
    
            int tilesetColunas = 16;  
            int tileSize = 32;       
            int tileIndex = id_tile - 1;//no tiled, os ids começam em 1, mas o programa usa 0-based. tiled id 1 -> id 0(pelo computador)
            
            int coluna = tileIndex % tilesetColunas;// ex: id 5 % 16 colunas = coluna 5
            int linha = tileIndex / tilesetColunas;// ex: id 5 / 16 colunas = linha 0
            
            sf::IntRect rectTextura(coluna * tileSize, linha * tileSize, tileSize, tileSize);//cria um retangulo da parte da textura q quero usar
            //posicao x = coluna*tamanho do tile, posicao y = linha*tamanho do tile, largura = tamanho do tile, altura = tamanho do tile. (tamanho = altura, é um quadrado)
            pFig->setTextureRect(rectTextura);

        }

        catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }
	}

	Parede::~Parede()
	{
		
	}

    void Parede::obstaculizar(Personagens::Personagem* p)
    {
        

        if (p)
        {
             
            sf::FloatRect intersec;
            sf::FloatRect personagemBounds = p->getFig()->getGlobalBounds();
            sf::FloatRect obstaculoBounds = this->getFig()->getGlobalBounds();

            if (personagemBounds.intersects(obstaculoBounds, intersec))
            {
                sf::Vector2f novaPos = p->getPos();
                if (intersec.width < intersec.height)                   //colisao horizontal
                {
                    if (personagemBounds.left < obstaculoBounds.left)   //na esquerda
                    {
                        novaPos.x -= intersec.width;
                    }
                    else                                                //na direita
                    {
                        novaPos.x += intersec.width;
                    }
                    p->mudaDir(); //talvez nao seja necessario o if seguinte?

                }
                else                                                    //colisao vertical
                {
                    if (personagemBounds.top < obstaculoBounds.top)     //em cima
                    {
                        novaPos.y -= intersec.height;
                    }
                    else                                                //embaixo
                    {
                         
                        novaPos.y += intersec.height;
                    }
                }

                p->setPos(novaPos);
            }
        }
    }
    
    const float Parede::getAltura() 
    {
       return altura;
    }
    void Parede::executar()
    {

    }

    void Parede::mover()
    {
        
    }
   
}
