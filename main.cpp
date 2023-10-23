#include <iostream>
#include <string>
#include "Catalogo.h" // Include the header file for your Catalogo class

using namespace std;

int main() {
    Catalogo catalog("monsters.csv");
    vector<vector<string>> catalogoMonstruos;

    catalog.readCatalogo(catalogoMonstruos);
    catalog.printCatalogo(catalogoMonstruos);
    return 0;
}
