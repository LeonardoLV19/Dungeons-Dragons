//
// Created by leolo on 10/10/2023.
//

#ifndef PROYECTOFINALESTRUCTURADATOS_LISTALIGADA_H
#define PROYECTOFINALESTRUCTURADATOS_LISTALIGADA_H
#include <iostream>
using namespace std;

template <typename T>
class NodoLista {
public:
    T                   info;
    NodoLista<T>       *next;

    NodoLista(T dato) : info(dato), next(nullptr) {}
};


template <typename T>
class Lista {
private:
    NodoLista<T>* head;

public:
    Lista() {
        head = nullptr;
    }

    // Análisis de complejidad: O(1)
    bool insertarInicio(T dato) {
        NodoLista<T>* nuevoNodo = new(nothrow) NodoLista<T>(dato);

        if (!nuevoNodo) {
            return false;
        }
        nuevoNodo->next = head;
        head = nuevoNodo;
        return true;
    }

    // Análisis de complejidad: O(n)
    void imprimir() {
        NodoLista<T>* NodoActual = head;

        while (NodoActual != nullptr) {
            cout << NodoActual->info << " ";
            NodoActual = NodoActual->next;
        }
        cout << endl;
    }

    // Análisis de complejidad: O(n)
    bool busqueda(T dato) {
        NodoLista<T>* NodoActual = head;

        while (NodoActual != nullptr) {
            if (NodoActual->info == dato) {
                return true;
            }
            NodoActual = NodoActual->next;
        }

        return false;
    }

    // Análisis de complejidad: O(n)
    NodoLista<T>* busquedaNodo(T dato) {
        NodoLista<T>* NodoActual = head;

        while (NodoActual != nullptr) {
            if (NodoActual->info == dato) {
                return NodoActual;
            }

            NodoActual = NodoActual->next;
        }

        return nullptr; // Regresa nullptr si no hay nada
    }

    // Análisis de complejidad: O(n)
    void destruirLista() {
        NodoLista<T>* NodoActual = head;

        while (NodoActual) {
            NodoLista<T>* eliminar = NodoActual;
            NodoActual = NodoActual->next;
            delete eliminar;
        }
        head = nullptr;
    }

    // Análisis de complejidad: O(n)
    bool eliminar(T dato) {
        if (!head) {
            return false;
        }

        if (head->info == dato) {
            NodoLista<T>* temp = head->next;
            delete head;
            head = temp;
            return true;
        }

        NodoLista<T>* NodoAnterior = head;
        NodoLista<T>* NodoActual = head->next;

        while (NodoActual) {
            if (NodoActual->info == dato) {
                NodoAnterior->next = NodoActual->next;
                delete NodoActual;
                return true;
            }
            NodoAnterior = NodoActual;
            NodoActual = NodoActual->next;
        }

        return false;
    }

    // Análisis de complejidad: O(1)
    bool eliminarHead() {
        if (!head) {
            return false;
        }

        NodoLista<T>* NodoActual = head;
        head = head->next;
        delete NodoActual;
        return true;
    }

    // Análisis de complejidad: O(n)
    bool eliminarTail() {
        if (!head) {
            return false;
        }

        if (!head->next) { // Cuando solo hay un nodo en la lista
            delete head;
            head = nullptr;
            return true;
        }

        NodoLista<T>* NodoActual = head;
        NodoLista<T>* NodoAnterior = nullptr;

        while (NodoActual->next != nullptr) {
            NodoAnterior = NodoActual;
            NodoActual = NodoActual->next;
        }


        delete NodoActual;
        NodoAnterior->next = nullptr;
        return true;
    }
};

#endif //PROYECTOFINALESTRUCTURADATOS_LISTALIGADA_H
