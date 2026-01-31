#include <iostream>
#include <string>
#include "Nodo.h"

using namespace std;

// ---------- FUNCIONES DE LA LISTA ----------

// Verificar si un ID ya existe
bool existeId(Nodo* head, int id) {
    Nodo* aux = head;
    while (aux != NULL) {
        if (aux->id == id) return true;
        aux = aux->sig;
    }
    return false;
}

// Insertar paquete al inicio
void insertarInicio(Nodo*& head, Nodo*& tail, int id, string nombre, float peso) {
    Nodo* nuevo = new Nodo{id, nombre, peso, head, NULL};

    if (head == NULL) {
        head = tail = nuevo;
    } else {
        head->ant = nuevo;
        head = nuevo;
    }
}

// Insertar paquete al final
void insertarFinal(Nodo*& head, Nodo*& tail, int id, string nombre, float peso) {
    Nodo* nuevo = new Nodo{id, nombre, peso, NULL, tail};

    if (tail == NULL) {
        head = tail = nuevo;
    } else {
        tail->sig = nuevo;
        tail = nuevo;
    }
}

// Mostrar lista desde head hasta tail
void mostrarAdelante(Nodo* head) {
    if (head == NULL) {
        cout << "Lista vacia.\n";
        return;
    }

    Nodo* aux = head;
    while (aux != NULL) {
        cout << "[" << aux->id << "] "
             << aux->nombre << " - "
             << aux->peso << " kg\n";
        aux = aux->sig;
    }
}

// Mostrar lista desde tail hasta head
void mostrarAtras(Nodo* tail) {
    if (tail == NULL) {
        cout << "Lista vacia.\n";
        return;
    }

    Nodo* aux = tail;
    while (aux != NULL) {
        cout << "[" << aux->id << "] "
             << aux->nombre << " - "
             << aux->peso << " kg\n";
        aux = aux->ant;
    }
}

// Buscar paquete por ID
Nodo* buscarPorId(Nodo* head, int id) {
    Nodo* aux = head;
    while (aux != NULL) {
        if (aux->id == id) return aux;
        aux = aux->sig;
    }
    return NULL;
}

// Eliminar paquete por ID
bool eliminarPorId(Nodo*& head, Nodo*& tail, int id) {
    Nodo* act = buscarPorId(head, id);
    if (act == NULL) return false;

    // Un solo nodo
    if (act == head && act == tail) {
        head = tail = NULL;
    }
    // Eliminar head
    else if (act == head) {
        head = act->sig;
        head->ant = NULL;
    }
    // Eliminar tail
    else if (act == tail) {
        tail = act->ant;
        tail->sig = NULL;
    }
    // Nodo intermedio
    else {
        act->ant->sig = act->sig;
        act->sig->ant = act->ant;
    }

    delete act;
    return true;
}

// Contar cantidad de paquetes
int contarPaquetes(Nodo* head) {
    int contador = 0;
    while (head != NULL) {
        contador++;
        head = head->sig;
    }
    return contador;
}

// Liberar toda la memoria de la lista
void liberarLista(Nodo*& head, Nodo*& tail) {
    while (head != NULL) {
        Nodo* borrar = head;
        head = head->sig;
        delete borrar;
    }
    tail = NULL;
}
