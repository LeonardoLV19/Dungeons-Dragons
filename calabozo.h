//
// Created by leolo on 10/10/2023.
//

#ifndef PROYECTOFINALESTRUCTURADATOS_CALABOZO_H
#define PROYECTOFINALESTRUCTURADATOS_CALABOZO_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "listaDobleLigada.h"
#include "monstruo.h"
#include "Catalogo.h"  // Asegúrate de incluir tu clase Catalogo

class Cuarto {
private:

    monstruo contenido;

public:
    Cuarto(const monstruo& m) : contenido(m) {}

    monstruo obtenerMonstruo() const {
        return contenido;
    }

    void establecerMonstruo(const monstruo& m) {
        contenido = m;
    }

    void imprimirMonstruo() const {
        std::cout << contenido;
    }

    friend std::ostream& operator<<(std::ostream& os, const Cuarto& cuarto) {
        os << cuarto.contenido;
        return os;
    }
};

class Calabozo {
private:
    ListaDL<Cuarto> cuartos;

public:
    Calabozo(Catalogo& catalogo, ListaDL<monstruo> catalogoMonstruos) {

        srand(static_cast<unsigned>(time(nullptr)));

        // Llenar el calabozo con cuartos
        for (int i = 0; i < 20; i++) {
            NodoLista<monstruo>* nodoMonstruo = catalogo.obtenerNodoMonstruoAleatorio(catalogoMonstruos);
            if (nodoMonstruo) {
                Cuarto cuarto(nodoMonstruo->info);  // Crea un cuarto con el monstruo aleatorio
                cuarto.establecerMonstruo(nodoMonstruo->info);
                cuartos.insertarInicio(cuarto);
            }
        }
    }

    void imprimirCuartos() {
        int numeroCuarto = 1;
        NodoLista<Cuarto>* nodoCuarto = cuartos.getHead();
        while (nodoCuarto) {
            cout << "Cuarto " << numeroCuarto << ": " << nodoCuarto->info.obtenerMonstruo().name << endl;
            numeroCuarto++;
            nodoCuarto = nodoCuarto->next;
        }
    }
};




#endif //PROYECTOFINALESTRUCTURADATOS_CALABOZO_H
