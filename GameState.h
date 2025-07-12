#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameObject.h"
#include <vector>

class GameState {
private:
    std::vector<GameObject*> m_objects;  // Η συλλογή αντικειμένων παιχνιδιού

public:
    GameState();  // Κατασκευαστής
    void addObject(GameObject* object);  // Συνάρτηση για προσθήκη αντικειμένου
    void update(float dt);  // Συνάρτηση για ενημέρωση των αντικειμένων
    void draw();  // Συνάρτηση για σχεδίαση των αντικειμένων
};

#endif

