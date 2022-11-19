#pragma once

#include "GameParameters.h"
#include "Button.h"

#define BUTTON_COLOR sf::Color(128, 128, 128)
#define BUTTON_SIZE sf::Vector2f(75, 75)

class MenuLayout
{
private:

	sf::Text txtGameSize;
	Button* btnSizeMore = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+1", sf::Vector2f(650, 100) };
	Button* btnSizeMore2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+10", sf::Vector2f(770, 100) };
	Button* btnSizeLess = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-1", sf::Vector2f(480, 100) };
	Button* btnSizeLess2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-10", sf::Vector2f(360, 100) };

	sf::Text txtDeltaTime;
	Button* btnDeltaTimeMore = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+0.01", sf::Vector2f(650, 250) };
	Button* btnDeltaTimeMore2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+0.1", sf::Vector2f(770, 250) };
	Button* btnDeltaTimeLess = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-0.01", sf::Vector2f(480, 250) };
	Button* btnDeltaTimeLess2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-0.1", sf::Vector2f(360, 250) };


	sf::Text txtRandomSpawnChance;
	Button* btnChanceMore = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+1", sf::Vector2f(650, 400) };
	Button* btnChanceMore2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+10", sf::Vector2f(770, 400) };
	Button* btnChanceLess = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-1", sf::Vector2f(480, 400) };
	Button* btnChanceLess2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-10", sf::Vector2f(360, 400) };

	sf::Text txtChanceSpawnAround;
	Button* btnChanceAroundMore = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+1", sf::Vector2f(650, 585) };
	Button* btnChanceAroundMore2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "+10", sf::Vector2f(770, 585) };
	Button* btnChanceAroundLess = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-1", sf::Vector2f(480, 585) };
	Button* btnChanceAroundLess2 = new Button{ BUTTON_SIZE, BUTTON_COLOR, "-10", sf::Vector2f(360, 585) };

	/*bool showFrameCount;
	sf::Text txtShowFrameCount;
	Button* btnShowFrameCountYes = new Button{ BUTTON_SIZE, BUTTON_COLOR, "NO", sf::Vector2f(450, 575) };
	Button* btnShowFrameCountNo = new Button{ BUTTON_SIZE, BUTTON_COLOR, "YES", sf::Vector2f(650, 575) };*/


	Button* btnNext = new Button{ sf::Vector2f(200, 75), BUTTON_COLOR, "NEXT", sf::Vector2f(500, 725) };

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

