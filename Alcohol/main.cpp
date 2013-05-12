#include <iostream>
#include "game.h"

using namespace std;

//размеры поля
const int SQUARE_WIDTH = 15;
const int SQUARE_HEIGHT = 15;

int main() {
	
	int a;

	cout << "Hello, world!\n";

	Game game;

	Walker x;

	game.addGameObject(&x);

	game.cycle();

	cin >> a;

	return 0;
}