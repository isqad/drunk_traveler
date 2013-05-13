#pragma once

class GameObject {
public:
	virtual void step(); //TODO: с виртуальными ф-иями надо будет разобраться.
};

//наш уставший алкоголик
class Walker: public GameObject {
private:
	enum direction { NORTH, SOUTH, EAST, WEST };
	unsigned int sleep;
public:
	Walker(): sleep(0) {};
	void step();
};

class Game {
private:
	static const int MAX_GAME_OBJECTS = 3; //так инициализируем константу, которая принадлежит классу
	unsigned int _count_objects; //счетчик игровых объектов
	GameObject* _objects[MAX_GAME_OBJECTS]; //содержит указатели на игровые объекты
	
public:
	Game(): _count_objects(0), _objects() {}; //В конструкторе мы также обнуляем массив объектов
	void addGameObject(GameObject*); //аргумент - указатель на объект
	void removeGameObject(GameObject*); //аргумент - указатель на объект
	void cycle();
};