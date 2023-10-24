//
// Created by leolo on 10/10/2023.
//

#ifndef PROYECTOFINALESTRUCTURADATOS_CATALOGO_H
#define PROYECTOFINALESTRUCTURADATOS_CATALOGO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "listaDobleLigada.h"
#include "monstruo.h"

using namespace std;


class Catalogo {
private:
    const string filename;
    char delimiter;

public:
    Catalogo(const string& filename, char delimiter = ',') : filename(filename), delimiter(delimiter) {}

    bool crearCatalogo(ListaDL<monstruo>& catalogoMonstruos) {
        ifstream file(filename);
        string line;

        if (!file.is_open()) {
            cerr << "No se pudo abrir el archivo" << endl;
            return false;
        }

        // Leer la primera línea (encabezados) y descartarla
        getline(file, line);

        while (getline(file, line)) {
            stringstream ss(line);
            string cell;
            vector<string> row;

            while (getline(ss, cell, delimiter)) {
                row.push_back(cell);
            }

            if (row.size() >= 7) {
                // En el constructor asigno cada elemento con el atributo correspondiente
                monstruo nuevoMonstruo(
                        row[0],                    // Nombre
                        stof(row[1]),              // CR       stof (para números en punto flotante)
                        row[2],                    // Tipo
                        row[3],                    // Tamaño
                        stoi(row[4]),              // AC       stoi (para números enteros)
                        stoi(row[5]),              // HP
                        row[6]                     // Alineación
                );
                catalogoMonstruos.insertarInicio(nuevoMonstruo);
            }
        }

        file.close();

        return true;
    }
};


//stringstream
#endif //PROYECTOFINALESTRUCTURADATOS_CATALOGO_H
