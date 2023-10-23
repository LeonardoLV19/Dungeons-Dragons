//
// Created by leolo on 10/10/2023.
//
#ifndef PROYECTOFINALESTRUCTURADATOS_JUGADOR_H
#define PROYECTOFINALESTRUCTURADATOS_JUGADOR_H
#include <iostream>

using namespace std;

class jugador{
private:
    int vida;
public:
    bool nivel_Vida();
    jugador(int vida);
};

jugador :: jugador(int vida){
    this->vida = 100;
}

bool jugador ::nivel_Vida() {
    if(vida <= 0){
        return false;
    }
    return true;
}

#endif //PROYECTOFINALESTRUCTURADATOS_JUGADOR_H
