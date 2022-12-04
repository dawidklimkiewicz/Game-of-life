#pragma once

#include "GameParameters.h"
#include "Button.h"

#define BUTTON_COLOR sf::Color(128, 128, 128)
#define BUTTON_SIZE sf::Vector2f(75, 75)

class MenuLayout
{
private:

	sf::Text txtGameSize;
	Button* btnSizeLess2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-10", sf::Vector2f(0, 0) };
	Button* btnSizeLess = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-1", sf::Vector2f(0, 0) };
	Button* btnSizeMore = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+1", sf::Vector2f(0, 0) };
	Button* btnSizeMore2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+10", sf::Vector2f(0, 0) };

	sf::Text txtDeltaTime;
	Button* btnDeltaTimeLess2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-0.1", sf::Vector2f(0, 0) };
	Button* btnDeltaTimeLess = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-0.01", sf::Vector2f(0, 0) };
	Button* btnDeltaTimeMore = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+0.01", sf::Vector2f(0, 0) };
	Button* btnDeltaTimeMore2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+0.1", sf::Vector2f(0, 0) };


	sf::Text txtRandomSpawnChance;
	Button* btnChanceLess2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-10", sf::Vector2f(0, 0) };
	Button* btnChanceLess = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-1", sf::Vector2f(0, 0) };
	Button* btnChanceMore = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+1", sf::Vector2f(0, 0) };
	Button* btnChanceMore2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+10", sf::Vector2f(0, 0) };

	sf::Text txtChanceSpawnAround;
	Button* btnChanceAroundLess2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-10", sf::Vector2f(0, 0) };
	Button* btnChanceAroundLess = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-1", sf::Vector2f(0, 0) };
	Button* btnChanceAroundMore = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+1", sf::Vector2f(0, 0) };
	Button* btnChanceAroundMore2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+10", sf::Vector2f(0, 0) };

	Button* btnNext = new Button{ sf::Vector2f(200, 75), BUTTON_COLOR, "NEXT", sf::Vector2f(0, 0) };

	//vector przyciskow
	std::vector<Button*> buttons = { btnSizeMore, btnSizeMore2, btnSizeLess, btnSizeLess2,
	btnDeltaTimeLess, btnDeltaTimeLess2, btnDeltaTimeMore, btnDeltaTimeMore2,
	btnChanceLess, btnChanceLess2, btnChanceMore, btnChanceMore2,
	btnChanceAroundLess, btnChanceAroundLess2, btnChanceAroundMore, btnChanceAroundMore2,
	btnNext };

public:
	~MenuLayout();

	void renderLayout(GameParameters* gameParameters, sf::RenderWindow* window);
	void buttonsClicked(GameParameters* gameParameters, sf::RenderWindow *window, sf::Event event);
};

