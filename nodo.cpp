#include <iostream>

using namespace std;


struct Nodo {
    int id;             // ID único del paquete
    string nombre;      // Nombre del paquete
    float peso;         // Peso del paquete
    Nodo* sig;          // Puntero al siguiente nodo
    Nodo* ant;          // Puntero al nodo anterior
};