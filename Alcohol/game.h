#pragma once

#include <iostream>
#include <cstdlib>


class GameObject {
protected:
	char _view;
	int _pX, _pY;
	
	GameObject(int x, int y, char view): _pX(x), _pY(y), _view(view) {};

public:
	virtual void step() = 0; //TODO: с виртуальными ф-иями надо будет разобраться.
	virtual char view() = 0; //так мы указываем, что это будет чистая виртуальня ф-ия,
							 //она должна иметь реализацию в наследуемых классах
};

//наш уставший алкоголик
class Walker: public GameObject {
private:
	enum direction { NORTH, SOUTH, EAST, WEST };
	unsigned int _sleep;
public:
	Walker(): _sleep(0), GameObject(0, 0, 'D') {};
	void step() override;
	char view() override;
};

//столб
class Column: public GameObject {
public:
	Column(): GameObject(7, 7, 'C') {};
	void step() override;
	char view() override; 
};

//трактир
class Tavern: public GameObject {
public:
	Tavern(): GameObject(-1, -1, 'T') {};
	void step() override;
	char view() override;
};

class Game {
private:
	static const int MAX_GAME_OBJECTS = 3; //так инициализируем константу, которая принадлежит классу
	unsigned int _count_objects; //счетчик игровых объектов
	GameObject* _objects[MAX_GAME_OBJECTS]; //содержит указатели на игровые объекты
	void render();
public:
	static const int SQUARE_WIDTH = 15;
	static const int SQUARE_HEIGHT = 15;
private:
	char _buffer[SQUARE_WIDTH][SQUARE_HEIGHT];
public:
	Game(): _count_objects(0), _objects() {}; //В конструкторе мы также обнуляем массив объектов
	void addGameObject(GameObject*); //аргумент - указатель на объект
	void removeGameObject(GameObject*); //аргумент - указатель на объект
	
	void cycle();
};