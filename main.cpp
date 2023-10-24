#include <iostream>
#include <string>
#include "Catalogo.h" // Include the header file for your Catalogo class

using namespace std;

int main() {
    // Crear un objeto Catalogo con el nombre del archivo CSV
    Catalogo catalogo("monsters.csv");

    // Crear una lista doblemente ligada para almacenar los monstruos
    ListaDL<monstruo> catalogoMonstruos;

    // Llenar el catálogo a partir del archivo CSV
    catalogo.crearCatalogo(catalogoMonstruos);

    // Imprimir el catálogo de monstruos
    catalogoMonstruos.imprimir();

    return 0;
}
