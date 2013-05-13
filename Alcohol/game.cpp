#include <iostream>
#include <cstdlib>
#include "game.h"

void GameObject::step() {
	std::cout << "Object has step\n";
}

void Walker::step() {
	GameObject::step();
	//выбираем направление
	unsigned int d = rand() % 4;

	switch(d) {
		case NORTH: std::cout << "north\n"; break;
		case SOUTH: std::cout << "south\n"; break;
		case WEST: std::cout << "west\n"; break;
		default: std::cout << "east\n";
	};

};

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
		
		std::cout << "Added object #" << _count_objects << ", " << obj << "\n";
	}
};

//придется воспользоваться указателями
void Game::removeGameObject(GameObject* obj) {
	if (_count_objects > 0) {
		for (unsigned int i = 0; i < MAX_GAME_OBJECTS; i++) {
			if (_objects[i] == obj) {
				_objects[i] = 0;
				_count_objects--;
				std::cout << "Removed object #" << (i + 1) << "\n";
				break;
			}
		}
	}
};

//пробегаемся по всем игровым объектам
void Game::cycle() {
	std::cout << "Cycle is run\n";

	if (_count_objects > 0) {
		for (unsigned int i = 0; i < MAX_GAME_OBJECTS; i++) {
			if (_objects[i] != NULL) {
				_objects[i]->step();
			}
		}
	}
};