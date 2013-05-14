#pragma once

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

class GameObject {
protected:
	char _view;
	int _pX, _pY;
	
	GameObject(int x, int y, char view): _pX(x), _pY(y), _view(view) {};

public:
	virtual void step() = 0; //TODO: с виртуальными ф-иями надо будет разобраться.
							 //так мы указываем, что это будет чистая виртуальня ф-ия,
							 //она должна иметь реализацию в наследуемых классах
	virtual void collision(GameObject*) = 0;
	inline int x() const;
	inline int y() const;
	inline char view() const;
};

//наш уставший алкоголик
class Walker: public GameObject {
private:
	enum direction { NORTH, SOUTH, EAST, WEST };
	unsigned int _sleep;
public:
	Walker(): _sleep(0), GameObject(0, 0, 'D') {};
	void step() override;
	void collision(GameObject*) override;
};

//столб
class Column: public GameObject {
public:
	Column(): GameObject(7, 7, 'C') {};
	void step() override;
	void collision(GameObject*) override;
};

//трактир
class Tavern: public GameObject {
public:
	Tavern(): GameObject(0, 0, 'T') {};
	void step() override;
	void collision(GameObject*) override;
};

class Game {
private:
	static const int MAX_GAME_OBJECTS = 3; //так инициализируем константу, которая принадлежит классу
	unsigned int _count_objects; //счетчик игровых объектов
	GameObject* _objects[MAX_GAME_OBJECTS]; //содержит указатели на игровые объекты
	void _render();
	void _checkCollisions();
	unsigned int _game_counter;
public:
	static const int SQUARE_WIDTH = 15;
	static const int SQUARE_HEIGHT = 15;
private:
	char _buffer[SQUARE_WIDTH][SQUARE_HEIGHT];
public:
	Game(): _count_objects(0), _objects(), _game_counter(0) {}; //В конструкторе мы также обнуляем массив объектов
	void addGameObject(GameObject*); //аргумент - указатель на объект
	void removeGameObject(GameObject*); //аргумент - указатель на объект
	
	void cycle();
	void clr_console() const;
};