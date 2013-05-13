#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

//размеры поля
const int SQUARE_WIDTH = 15;
const int SQUARE_HEIGHT = 15;

int main() {
	
	int a;

	cout << "Hello, world!\n";

	//Сеем зерно для функции rand()
	srand(time(NULL));

	Game game;

	Walker* x = new Walker();

	game.addGameObject(x);

	game.cycle();

	cin >> a;

	return 0;
}