#include <iostream>
#include <string>

using namespace std;

struct Nodo {
    int id;
    string nombre;
    float peso;
    Nodo* sig;
    Nodo* ant;
};

// Prototipo: Inserta un paquete al inicio
void insertarInicio(Nodo*& head, Nodo*& tail, int id, string nombre, float peso);

// Implementación
void insertarInicio(Nodo*& head, Nodo*& tail, int id, string nombre, float peso) {
    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->peso = peso;
    nuevo->sig = head;
    nuevo->ant = NULL;

    if (head == NULL) {
        head = tail = nuevo;
    } else {
        head->ant = nuevo;
        head = nuevo;
    }
}

int main() {
    // Solo para compilación
    return 0;
}