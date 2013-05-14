#include "game.h"

inline int GameObject::x() const {
	return _pX;
};

inline int GameObject::y() const {
	return _pY;
};

inline char GameObject::view() const {
	return _view;
};

void Column::step() {};

void Tavern::step() {};

void Walker::step() {
	
	//выбираем направление
	unsigned int d = rand() % 4;

	switch(d) {
		case NORTH: 
			_pY > 0 ? _pY-- : _pY++;
		break;
		case SOUTH: 
			_pY < Game::SQUARE_HEIGHT ? _pY++ : _pY--; 
		break;
		case WEST:
			_pX > 0 ? _pX-- : _pX++;
		break;
		default: _pX < Game::SQUARE_WIDTH ? _pX++ : _pX--;
	};

	std::cout << "X: " << _pX << ", Y: " << _pY << '\n';

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
	}
};

//придется воспользоваться указателями
void Game::removeGameObject(GameObject* obj) {
	if (_count_objects > 0) {
		for (unsigned int i = 0; i < MAX_GAME_OBJECTS; i++) {
			if (_objects[i] == obj) {
				_objects[i] = 0;
				_count_objects--;
				break;
			}
		}
	}
};

//пробегаемся по всем игровым объектам
void Game::cycle() {
	std::cout << "Cycle is run\n";

	if (_count_objects > 0) {

		for (int i = 0; i < SQUARE_WIDTH; i++) {
			for (int j = 0; j < SQUARE_HEIGHT; j++) {
				_buffer[i][j] = '.';
			}
		}

		for (unsigned int i = 0; i < MAX_GAME_OBJECTS; i++) {
			if (_objects[i] != NULL) {
				_objects[i]->step();

				int objX = _objects[i]->x();
				int objY = _objects[i]->y();

				_buffer[objX][objY] = _objects[i]->view();
			}
		}

		Game::render();

		std::cout << std::flush;

		std::this_thread::sleep_for(std::chrono::seconds(1));

		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			system("cls");
		#else
			system("clear");
		#endif

	}
};

void Game::render() {
	if (_count_objects > 0) {
		for (int i = 0; i < SQUARE_WIDTH; i++) {
			for (int j = 0; j < SQUARE_HEIGHT; j++) {
				std::cout << _buffer[i][j];
			}
			std::cout << '\n';
		}
		
	}	
};