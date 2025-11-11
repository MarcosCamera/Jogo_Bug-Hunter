#include "Ente.hpp"
#include "Gerenciador_Colisoes"
#include "Gerenciador_Grafico"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
	Gerenciador_Grafico graf;
	Gerenciador_Colisoes colis;

	Jogador jog;
	Formiga form;
	Plataforma plat;

	plat.pFig->setPosition(0, 500);
	plat.setSize(800.f, 2.f);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		/*UPDATE*/

		jog.executar();
		form.executar();
		plat.executar();



		/*DRAW*/
		window.clear(Color::White);
		window.draw(jog.getSprite());
		window.draw(form.getSprite());
		window.draw(plat.getSprite())
		window.display();
	}
	return 0;
}