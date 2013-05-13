#include <ctime>
#include "game.h"

using namespace std;

int main() {
	
	int a;

	cout << "Hello, world!\n";

	//Сеем зерно для функции rand()
	srand(time(NULL));

	Game game;

	Walker* w = new Walker();
	//Walker w;
	Tavern* t = new Tavern();
	Column* c = new Column();

	game.addGameObject(w);
	game.addGameObject(t);
	game.addGameObject(c);

	for (unsigned int i = 0; i < 200; i++) {
		game.cycle();	
	}
	

	cin >> a;

	delete w;
	delete t;
	delete c;

	return 0;
}