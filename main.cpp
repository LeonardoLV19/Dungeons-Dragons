#include <iostream>
#include <cstdlib>
#include <ctime>
#include "calabozo.h"
#include "monstruo.h"
#include "Catalogo.h"

using namespace std;

int main() {
    // Crear un objeto Catalogo
    Catalogo catalogo("monsters.csv");

    // Imprimir los cuartos
   
    Calabozo calabozo(catalogo);

    // Imprimir los cuartos
    calabozo.imprimirCuartos();

    return 0;
}








