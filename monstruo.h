//
// Created by leolo on 10/10/2023.
//

#ifndef PROYECTOFINALESTRUCTURADATOS_MONSTRUO_H
#define PROYECTOFINALESTRUCTURADATOS_MONSTRUO_H

#include <iostream>
#include <string>

class monstruo {
public:
    std::string name;  // Nombre del monstruo
    float cr;         // Nivel de dificultad (challenging rating)
    std::string type;  // Tipo de creatura
    float size;       // Tamaño de la creatura
    int ac;           // Dificultad para golpear a la creatura (armor class)
    int hp;           // Vida de la criatura
    std::string align; // Comportamiento de la creatura

    // Constructor
    monstruo(const std::string& nombre, float challengingRating, const std::string& tipo,
             float tamano, int armorClass, int vida, const std::string& alineacion)
            : name(nombre), cr(challengingRating), type(tipo), size(tamano), ac(armorClass), hp(vida), align(alineacion) {}
};

#endif //PROYECTOFINALESTRUCTURADATOS_MONSTRUO_H
