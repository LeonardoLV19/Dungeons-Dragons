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
        // Inicializar la semilla para generar números aleatorios
        srand(static_cast<unsigned>(time(nullptr)));

        // Llena el calabozo con cuartos, cada uno con un monstruo aleatorio del catálogo
        for (int i = 0; i < 20; i++) {
            NodoLista<monstruo>* nodoMonstruo = catalogo.obtenerNodoMonstruoAleatorio(catalogoMonstruos);
            if (nodoMonstruo) {
                Cuarto cuarto(nodoMonstruo->info);  // Crea un cuarto con el monstruo aleatorio
                cuartos.insertarInicio(cuarto);
            }
        }
    }

    void imprimirCuartos() {
        cuartos.imprimir();
    }
};




#endif //PROYECTOFINALESTRUCTURADATOS_CALABOZO_H
