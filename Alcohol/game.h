#pragma once

class GameObject {
public:
	void step();
};

//наш уставший алкоголик
class Walker: public GameObject {};

class Game {
private:
	static const int MAX_GAME_OBJECTS = 3; //так инициализируем константу, которая принадлежит классу
	unsigned int _count_objects; //счетчик игровых объектов
	GameObject* _objects[MAX_GAME_OBJECTS]; //содержит указатели на игровые объекты
	
public:
	Game(): _count_objects(0), _objects() {
	};
	void addGameObject(GameObject*); //аргумент - указатель на объект
	void removeGameObject(GameObject*); //аргумент - указатель на объект
	void cycle();
};