#include <SFML/Graphics.hpp>
using namespace sf;
#define Max_main_menu 3

class Menuu
{
public:
	Menuu(float width, float height);

	void draw(sf::RenderWindow& window);

	void moveUp();

	void moveDown();

	~Menuu();
private:
	int mainmenuselsected;//???? ??? ???? ????? ?????
	Font font;
	Text mainmenu[Max_main_menu];
	Text namegame;

};