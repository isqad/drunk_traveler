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

void Tavern::collision(GameObject* obj) {};

void Column::collision(GameObject* obj) {};

void Walker::step() {
	
	//Если не спим
	if (_sleep == 0) {
		//выбираем направление
		unsigned int d = rand() % 4;

		switch(d) {
			case NORTH: 
				_pY > 0 ? _pY-- : _pY++;
			break;
			case SOUTH: 
				_pY < Game::SQUARE_HEIGHT - 1  ? _pY++ : _pY--; 
			break;
			case WEST:
				_pX > 0 ? _pX-- : _pX++;
			break;
			default: _pX < Game::SQUARE_WIDTH - 1 ? _pX++ : _pX--;
		};	
	} else {
		_sleep--;
	}
	

	//std::cout << "X: " << _pX << ", Y: " << _pY << '\n';

};

void Walker::collision(GameObject* obj) {
	char objType = obj->view();

	switch(objType) {
		case 'C': _sleep = 5; //засыпаем на 5 ходов
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
	//std::cout << "Game is run\n";
	std::cout << "Step # " << ++_game_counter << '\n';

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

		_checkCollisions();

		_render();

		std::cout << std::flush;

		std::this_thread::sleep_for(std::chrono::seconds(1));

		clr_console();

	}
};

void Game::_render() {
	for (int i = 0; i < SQUARE_WIDTH; i++) {
		for (int j = 0; j < SQUARE_HEIGHT; j++) {
			std::cout << _buffer[i][j];
		}
		std::cout << '\n';
	}	
};

void Game::_checkCollisions() {
	for (unsigned int i = 0; i < MAX_GAME_OBJECTS; i++) {
		if (_objects[i] != NULL) {
			for (unsigned int j = i + 1; j < MAX_GAME_OBJECTS; j++ ) {
				if (_objects[j] != NULL && _objects[j]->x() == _objects[i]->x() && _objects[j]->y() == _objects[i]->y()) {
					_objects[i]->collision(_objects[j]); //столкновение i с j
					_objects[j]->collision(_objects[i]); //столкновение j c i	
				}
			}
		}
	}
};

void Game::clr_console() const {
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
		system("cls");
	#else
		system("clear");
	#endif
};