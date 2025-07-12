#include "GameState.h"

GameState::GameState() {
    
}

void GameState::addObject(GameObject* object) {
    m_objects.push_back(object); 
}

void GameState::update(float dt) {
    // Ενημέρωση όλων των αντικειμένων στη συλλογή
    for (auto& obj : m_objects) {
        obj->update(); 
    }
}

void GameState::draw() {
    // Σχεδίαση όλων των αντικειμένων στη συλλογή
    for (auto& obj : m_objects) {
        obj->draw();
    }
}
