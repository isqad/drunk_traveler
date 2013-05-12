#include <iostream>
#include "game.h"

using namespace std;

void GameObject::step() {
	cout << "Object has step\n";
}

void Game::addGameObject(GameObject* obj) {
	if (_count_objects < MAX_GAME_OBJECTS) {
		//проверка на уникальность
		if (_count_objects > 0) {
			for (unsigned int i = 0; i < MAX_GAME_OBJECTS; i++) {
				if (_objects[i] == obj) {
					return;
				}
			}
		}
		//сначала присваиваем в элемент массива объект, затем счетчик увеличиваем
		_objects[_count_objects++] = obj;
		
		cout << "Added object #" << _count_objects << ", " << obj << "\n";
	}
};

//придется воспользоваться указателями
void Game::removeGameObject(GameObject* obj) {
	if (_count_objects > 0) {
		for (unsigned int i = 0; i < MAX_GAME_OBJECTS; i++) {
			if (_objects[i] == obj) {
				_objects[i] = 0;
				_count_objects--;
				cout << "Removed object #" << (i + 1) << "\n";
				break;
			}
		}
	}
};

//пробегаемся по всем игровым объектам
void Game::cycle() {
	cout << "Cycle is run\n";

	if (_count_objects > 0) {
		for (unsigned int i = 0; i < MAX_GAME_OBJECTS; i++) {
			if (_objects[i] != 0) {
				GameObject obj = *_objects[i];
				obj.step();
			}
		}
	}
};