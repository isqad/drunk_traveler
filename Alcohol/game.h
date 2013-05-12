#pragma once

class GameObject {
public:
	void step();
};

//��� �������� ���������
class Walker: public GameObject {};

class Game {
private:
	static const int MAX_GAME_OBJECTS = 3; //��� �������������� ���������, ������� ����������� ������
	unsigned int _count_objects; //������� ������� ��������
	GameObject* _objects[MAX_GAME_OBJECTS]; //�������� ��������� �� ������� �������
	
public:
	Game(): _count_objects(0), _objects() {
	};
	void addGameObject(GameObject*); //�������� - ��������� �� ������
	void removeGameObject(GameObject*); //�������� - ��������� �� ������
	void cycle();
};