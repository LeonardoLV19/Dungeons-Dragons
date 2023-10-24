#include <iostream>
#include <ctime>
#include "monstruo.h"
#include "Catalogo.h" // Asegúrate de incluir la clase Catalogo y las otras clases que necesites

using namespace std;

int main() {
    // Inicializar la semilla para generar números aleatorios
    srand(static_cast<unsigned>(time(nullptr)));

    // Crear un catálogo de monstruos
    Catalogo catalog("monsters.csv");
    ListaDL<monstruo> catalogoMonstruos;

    // Cargar el catálogo de monstruos desde el archivo
    if (!catalog.crearCatalogo(catalogoMonstruos)) {
        cerr << "No se pudo crear el catálogo de monstruos." << endl;
        return 1;
    }

    // Obtener un nodo aleatorio de la lista de monstruos
    NodoLista<monstruo>* nodoAleatorio = catalog.obtenerNodoMonstruoAleatorio(catalogoMonstruos);

    if (nodoAleatorio) {
        // Monstruo aleatorio se ha obtenido con éxito, ahora puedes acceder al monstruo desde el nodo
        monstruo monstruoAleatorio = nodoAleatorio->info;

        // Imprime el monstruo aleatorio
        cout << "Monstruo Aleatorio:" << endl;
        cout << monstruoAleatorio;
    } else {
        // El catálogo está vacío, no se pudo obtener un monstruo aleatorio
        cout << "El catálogo está vacío. No se pudo obtener un monstruo aleatorio." << endl;
    }

    return 0;
}



