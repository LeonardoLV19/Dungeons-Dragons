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
    const string   filename;
    char  delimiter;
public:
    Catalogo(const string& filename, char delimiter = ',') : filename(filename), delimiter(delimiter) {}

    bool readCatalogo(vector<vector<string>>& data) {
        ifstream file(filename);
        string line;

        if (!file.is_open()) {
            cerr << "No se pudo abrir el archivo" << endl;
            return false;
        }

        while(getline(file, line)){
            vector<string> row;
            stringstream ss(line);
            string cell;

            while (getline(ss, cell, delimiter)){
                row.push_back(cell);

            }
            data.push_back(row);
        }
        file.close();

        return true;
    }

    void printCatalogo(const vector<vector<string>>& data) {
        for (const vector<string>& row : data) {
            for (const string& cell : row) {
                cout << cell << ' ';
            }
            cout << endl;
        }
    }
};


//stringstream
#endif //PROYECTOFINALESTRUCTURADATOS_CATALOGO_H
