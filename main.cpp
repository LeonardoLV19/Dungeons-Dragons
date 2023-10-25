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

    // Crear una lista doblemente ligada para almacenar los monstruos
    ListaDL<monstruo> catalogoMonstruos;

    // Llenar el catálogo
    if(catalogo.crearCatalogo(catalogoMonstruos) == true){
        cout<<"cargado correctamente"<<endl;
    }

    Calabozo calabozo(catalogo, catalogoMonstruos);

    // Imprimir los cuartos
    calabozo.imprimirCuartos();


    return 0;
}







