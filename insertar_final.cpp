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

// Prototipo: Inserta un paquete al final
void insertarFinal(Nodo*& head, Nodo*& tail, int id, string nombre, float peso);

// Implementación
void insertarFinal(Nodo*& head, Nodo*& tail, int id, string nombre, float peso) {
    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->peso = peso;
    nuevo->sig = NULL;
    nuevo->ant = tail;

    if (tail == NULL) {
        head = tail = nuevo;
    } else {
        tail->sig = nuevo;
        tail = nuevo;
    }
}

int main() {
    return 0;
}