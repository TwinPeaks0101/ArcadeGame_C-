#include "GameState.h"

GameState::GameState() {
    
}

void GameState::addObject(GameObject* object) {
    m_objects.push_back(object); 
}

void GameState::update(float dt) {
    // ��������� ���� ��� ������������ ��� �������
    for (auto& obj : m_objects) {
        obj->update(); 
    }
}

void GameState::draw() {
    // �������� ���� ��� ������������ ��� �������
    for (auto& obj : m_objects) {
        obj->draw();
    }
}
