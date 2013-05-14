#include <ctime>
#include "game.h"

using namespace std;

int main() {
	
	int a;

	//Сеем зерно для функции rand()
	srand(time(NULL));

	Game game;

	Walker* w = new Walker();
	Tavern* t = new Tavern();
	Column* c = new Column();

	game.addGameObject(c);
	game.addGameObject(t);
	game.addGameObject(w);

	game.clr_console();

	for (unsigned int i = 0; i < 200; i++) {
		game.cycle();	
	}
	
	cout << "End game\n";
	cout << "Enter any number for exit: ";
	cin >> a;

	delete w;
	delete t;
	delete c;

	return 0;
}