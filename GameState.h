#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameObject.h"
#include <vector>

class GameState {
private:
    std::vector<GameObject*> m_objects;  // � ������� ������������ ����������

public:
    GameState();  // �������������
    void addObject(GameObject* object);  // ��������� ��� �������� ������������
    void update(float dt);  // ��������� ��� ��������� ��� ������������
    void draw();  // ��������� ��� �������� ��� ������������
};

#endif

