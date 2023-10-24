//
// Created by leolo on 10/10/2023.
//

/*
#ifndef PROYECTOFINALESTRUCTURADATOS_CALABOZO_H
#define PROYECTOFINALESTRUCTURADATOS_CALABOZO_H

#include <iostream>
#include <string>
#include "Catalogo.h"  // Asegúrate de incluir tu clase Catalogo

class Calabozo {
private:
    Catalogo catalogo;  // Agrega una instancia de la clase Catalogo

    ListaDL<monstruo> cuartos;  // Lista de cuartos en el calabozo

public:
    Calabozo(const Catalogo& catalogo) : catalogo(catalogo) {
        // Llenar la lista de cuartos con monstruos aleatorios
        for (int i = 0; i < 20; i++) {
            monstruo monstruoAleatorio;

            // Utiliza la función elegirMonstruoAleatorio del catálogo
            if (catalogo.obtenerMonstruoAleatorio(monstruoAleatorio)) {
                cuartos.insertarInicio(monstruoAleatorio);
            }
        }
    }
};



#endif //PROYECTOFINALESTRUCTURADATOS_CALABOZO_H
*/