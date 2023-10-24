// monstruo.h

#ifndef PROYECTOFINALESTRUCTURADATOS_MONSTRUO_H
#define PROYECTOFINALESTRUCTURADATOS_MONSTRUO_H

#include <iostream>
#include <string>

class monstruo {
public:
    std::string name;  // Nombre del monstruo
    float cr;         // Nivel de dificultad (challenging rating)
    std::string type;  // Tipo de creatura
    std::string size;       // Tamaño de la creatura
    int ac;           // Dificultad para golpear a la creatura (armor class)
    int hp;           // Vida de la criatura
    std::string align; // Comportamiento de la creatura

    // Constructor
    monstruo(const std::string& nombre, float challengingRating, const std::string& tipo,
             const std::string& tamano, int armorClass, int vida, const std::string& alineacion)
            : name(nombre), cr(challengingRating), type(tipo), size(tamano), ac(armorClass), hp(vida), align(alineacion) {}

    //Constructor por defecto
    monstruo() : cr(0), ac(0), hp(0) {}

    // Sobrecarga del operador de inserción para imprimir objetos monstruo
    friend std::ostream& operator<<(std::ostream& os, const monstruo& m) {
        os << "Name: " << m.name << "\n";
        os << "CR: " << m.cr << "\n";
        os << "Type: " << m.type << "\n";
        os << "Size: " << m.size << "\n";
        os << "AC: " << m.ac << "\n";
        os << "HP: " << m.hp << "\n";
        os << "Align: " << m.align << "\n";
        return os;
    }
};

#endif //PROYECTOFINALESTRUCTURADATOS_MONSTRUO_H
