//
// Created by leolo on 10/10/2023.
//

#ifndef PROYECTOFINALESTRUCTURADATOS_LISTADOBLELIGADA_H
#define PROYECTOFINALESTRUCTURADATOS_LISTADOBLELIGADA_H

#include <iostream>
using namespace std;

template <typename T>
class NodoLista {
public:
    T info;
    NodoLista<T>* next;
    NodoLista<T>* prev;

    NodoLista(T dato) : info(dato), next(nullptr), prev(nullptr) {}
};

template <typename T>
class ListaDL {
private:
    NodoLista<T>* head;
    NodoLista<T>* tail;

public:
    ListaDL() {
        head = nullptr;
        tail = nullptr;
    }

    bool insertarInicio(T dato) {
        NodoLista<T>* nuevoNodo = new(nothrow) NodoLista<T>(dato);

        if (!nuevoNodo) {
            return false;
        }

        if (!head) {
            head = nuevoNodo;
            tail = nuevoNodo;
        } else {
            nuevoNodo->next = head;
            head->prev = nuevoNodo;
            head = nuevoNodo;
        }

        return true;
    }

    void imprimir() {
        NodoLista<T>* NodoActual = head;

        while (NodoActual != nullptr) {
            cout << NodoActual->info << " ";
            NodoActual = NodoActual->next;
        }
        cout << endl;
    }

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

    NodoLista<T>* busquedaNodo(T dato) {
        NodoLista<T>* NodoActual = head;

        while (NodoActual != nullptr) {
            if (NodoActual->info == dato) {
                return NodoActual;
            }

            NodoActual = NodoActual->next;
        }

        return nullptr;
    }

    void destruirLista() {
        NodoLista<T>* NodoActual = head;

        while (NodoActual) {
            NodoLista<T>* eliminar = NodoActual;
            NodoActual = NodoActual->next;
            delete eliminar;
        }
        head = nullptr;
        tail = nullptr;
    }

    bool eliminar(T dato) {
        if (!head) {
            return false;
        }

        if (head->info == dato) {
            NodoLista<T>* temp = head->next;
            delete head;
            head = temp;

            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }

            return true;
        }

        NodoLista<T>* NodoActual = head->next;

        while (NodoActual) {
            if (NodoActual->info == dato) {
                NodoLista<T>* NodoAnterior = NodoActual->prev;
                NodoAnterior->next = NodoActual->next;
                if (NodoActual->next) {
                    NodoActual->next->prev = NodoAnterior;
                } else {
                    tail = NodoAnterior;
                }
                delete NodoActual;
                return true;
            }
            NodoActual = NodoActual->next;
        }

        return false;
    }

    bool eliminarHead() {
        if (!head) {
            return false;
        }

        NodoLista<T>* NodoActual = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete NodoActual;
        return true;
    }

    bool eliminarTail() {
        if (!tail) {
            return false;
        }

        if (head == tail) {
            delete tail;
            head = nullptr;
            tail = nullptr;
        } else {
            NodoLista<T>* temp = tail->prev;
            temp->next = nullptr;
            delete tail;
            tail = temp;
        }

        return true;
    }
};


#endif //PROYECTOFINALESTRUCTURADATOS_LISTADOBLELIGADA_H
