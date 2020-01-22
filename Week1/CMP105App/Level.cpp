#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	
	// ----- Rectangles --------------------------------

		// Blue Rectangle
			rectBlue.setSize(sf::Vector2f(20, 20));
			rectBlue.setPosition(300, 300);
			rectBlue.setFillColor(sf::Color::Blue);

			sf::Vector2f halfSizeB = rectBlue.getSize();
			halfSizeB.x /= 2.0f;
			halfSizeB.y /= 2.0f;

			rectBlue.setOrigin(halfSizeB);

		// Green Rectangle
			rectGreen.setSize(sf::Vector2f(40, 40));
			rectGreen.setPosition(300, 300);
			rectGreen.setFillColor(sf::Color::Green);

			sf::Vector2f halfSizeG = rectGreen.getSize();
			halfSizeG.x /= 2.0f;
			halfSizeG.y /= 2.0f;

			rectGreen.setOrigin(halfSizeG);

		// Red Rectangle
			rectRed.setSize(sf::Vector2f(60, 60));
			rectRed.setPosition(300, 300);
			rectRed.setFillColor(sf::Color::Red);

			sf::Vector2f halfSizeR = rectRed.getSize();
			halfSizeR.x /= 2.0f;
			halfSizeR.y /= 2.0f;

			rectRed.setOrigin(halfSizeR);

		// Magenta Rectangle
			rectMagenta.setSize(sf::Vector2f(40, 40));
			rectMagenta.setPosition(1100, 600);
			rectMagenta.setFillColor(sf::Color::Magenta);

			sf::Vector2f halfSizeM = rectMagenta.getSize();
			halfSizeM.x /= 2.0f;
			halfSizeM.y /= 2.0f;

			rectMagenta.setOrigin(halfSizeM);


	// ----- Circles -----------------------------------
		circle.setFillColor(sf::Color::Blue);
		circle.setOutlineColor(sf::Color::Red);
		circle.setOutlineThickness(4);
		circle.setRadius(50);
		circle.setPosition(550,300);

	// ----- Text --------------------------------------
		sf::Vector2f textPos;
		textPos.x = 600.0f;
		textPos.y = 5.0f;

		if (!font.loadFromFile("font/arial.ttf")) {
			std::cout << "ERROR LOADING FONT, PLS FIX :3" << std::endl;
		}

		text.setFont(font);
		text.setString("Hello World!");
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::Blue);
		text.setPosition(textPos);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	rectMagenta.setPosition((pos.x - 100), (pos.y - 50));
}

// Render level
void Level::render()
{
	beginDraw();

	// Render Shapes
	window->draw(circle);
	window->draw(rectRed);
	window->draw(rectGreen);
	window->draw(rectBlue);
	window->draw(rectMagenta);

	// Render Text
	window->draw(text);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}