/*#include "Ente.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Formiga.hpp" // Adicionado para garantir tipo completo
#include "Jogador.hpp"
#include "Folha.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace Gerenciadores;
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;
using namespace sf;

int main()
{
	Gerenciador_Grafico graf;
	Gerenciador_Colisoes colis;

	Jogador jog;
	Formiga form(&jog);
	Folha plat1;
	Folha plat2;
	Folha plat3;

	Ente* eJog = &jog; //ta certo? ao inves de fazer static cast???
	Ente* eForm = &form;
	Ente* ePlat1 = &plat1;
	Ente* ePlat2 = &plat2;
	Ente* ePlat3 = &plat3;

	jog.setTexture("Texturas/aranha.png", sf::Vector2f(0.03f, 0.03f));
	form.setTexture("Texturas/formiga.png", sf::Vector2f(0.03f, 0.03f));
	plat1.setTexture("Texturas/Folha.png", sf::Vector2f(100.f, 100.f));
	plat2.setTexture("Texturas/Folha.png", sf::Vector2f(1.f, 1.f));
	plat3.setTexture("Texturas/Folha.png", sf::Vector2f(1.f, 1.f));
	//sf::RectangleShape r(Vector2f(jog.getFig()->getGlobalBounds().width, jog.getFig()->getGlobalBounds().height));
	//r.setFillColor(Color::Blue);

	plat1.setPos(sf::Vector2f(0, 500));
	plat2.setPos(sf::Vector2f(0, 480));
	plat3.setPos(sf::Vector2f(400, 480));
	form.setPos(sf::Vector2f(200, 450));
	

	colis.setJogador(&jog);
	colis.incluirInimigo(&form);
	colis.incluirObstaculo(&plat1);
	colis.incluirObstaculo(&plat2);
	colis.incluirObstaculo(&plat3);

	while (graf.abertaJanela())
	{
		Event event;
		while (graf.getWindow().pollEvent(event))
		{
			if (event.type == Event::Closed)
				graf.fecharJanela();
		}

		/*UPDATE*

		colis.executar(); //deve ser primeiro?
		jog.executar();
		form.executar();
		plat1.executar();
		plat2.executar();
		plat3.executar();

		//r.setPosition(Vector2f(jog.getPos().x, jog.getPos().y));

		/*DRAW*
		graf.getWindow().clear(Color::White);
		graf.desenharEnte(eJog);
		graf.desenharEnte(eForm);
		graf.desenharEnte(ePlat1);
		graf.desenharEnte(ePlat2);
		graf.desenharEnte(ePlat3);
		//graf.desenharRect(r);
		graf.getWindow().display();
	}
	return 0;
}*/

#include "Jogo.hpp"

int main()
{
	Jogo jogo;
	jogo.executar();
	return 0;
}