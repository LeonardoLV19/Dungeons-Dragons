#include <iostream>
#include <cstdlib>
#include <ctime>
#include "calabozo.h"
#include "monstruo.h"
#include "Catalogo.h"

using namespace std;

int main() {
    // Crear un objeto Catalogo con el nombre del archivo CSV
    Catalogo catalogo("monsters.csv");
    // Crear una lista doblemente ligada para almacenar los monstruos
    ListaDL<monstruo> catalogoMonstruos;

    // Llenar el catálogo a partir del archivo CSV
    if(catalogo.crearCatalogo(catalogoMonstruos) == true){
        cout<<"cargado correctamente"<<endl;
    }

    Calabozo calabozo(catalogo, catalogoMonstruos);

    // Imprimir la información de los cuartos en el calabozo
    calabozo.imprimirCuartos();


    return 0;
}







