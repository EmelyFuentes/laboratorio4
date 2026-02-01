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

// Prototipo: Verifica si un ID ya existe en la lista
bool existeId(Nodo* head, int id);

// Implementación
bool existeId(Nodo* head, int id) {
    Nodo* aux = head;
    while (aux != NULL) {
        if (aux->id == id) return true;
        aux = aux->sig;
    }
    return false;
}

int main() {
    // Solo para compilación
    return 0;
}