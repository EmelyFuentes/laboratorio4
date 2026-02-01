#include <iostream>
#include <string>

using namespace std;

struct Nodo
{
    int id;
    string nombre;
    float peso;
    Nodo *sig;
    Nodo *ant;
};

// Prototipos
bool existeId(Nodo *head, int id);
void insertarInicio(Nodo *&head, Nodo *&tail, int id, string nombre, float peso);
void insertarFinal(Nodo *&head, Nodo *&tail, int id, string nombre, float peso);
void mostrarAdelante(Nodo *head);
void mostrarAtras(Nodo *tail);
Nodo *buscarPorId(Nodo *head, int id);
bool eliminarPorId(Nodo *&head, Nodo *&tail, int id);
void liberarLista(Nodo*& head, Nodo*& tail);

// ---------------- FUNCIONES ----------------

bool existeId(Nodo *head, int id)
{
    Nodo *aux = head;
    while (aux != NULL)
    {
        if (aux->id == id)
            return true;
        aux = aux->sig;
    }
    return false;
}

void insertarInicio(Nodo *&head, Nodo *&tail, int id, string nombre, float peso)
{
    Nodo *nuevo = new Nodo{id, nombre, peso, head, NULL};

    if (head == NULL)
    {
        head = tail = nuevo;
    }
    else
    {
        head->ant = nuevo;
        head = nuevo;
    }
}

void insertarFinal(Nodo *&head, Nodo *&tail, int id, string nombre, float peso)
{
    Nodo *nuevo = new Nodo{id, nombre, peso, NULL, tail};

    if (tail == NULL)
    {
        head = tail = nuevo;
    }
    else
    {
        tail->sig = nuevo;
        tail = nuevo;
    }
}

void mostrarAdelante(Nodo *head)
{
    if (head == NULL)
    {
        cout << "Lista vacia.\n";
        return;
    }

    Nodo *aux = head;
    while (aux != NULL)
    {
        cout << "[" << aux->id << "] "
             << aux->nombre << " - "
             << aux->peso << "kg\n";
        aux = aux->sig;
    }
}

void mostrarAtras(Nodo *tail)
{
    if (tail == NULL)
    {
        cout << "Lista vacia.\n";
        return;
    }

    Nodo *aux = tail;
    while (aux != NULL)
    {
        cout << "[" << aux->id << "] "
             << aux->nombre << " - "
             << aux->peso << "kg\n";
        aux = aux->ant;
    }
}

Nodo *buscarPorId(Nodo *head, int id)
{
    Nodo *aux = head;
    while (aux != NULL)
    {
        if (aux->id == id)
            return aux;
        aux = aux->sig;
    }
    return NULL;
}

bool eliminarPorId(Nodo *&head, Nodo *&tail, int id)
{
    Nodo *act = buscarPorId(head, id);
    if (act == NULL)
        return false;

    if (act == head && act == tail)
    {
        head = tail = NULL;
    }
    else if (act == head)
    {
        head = act->sig;
        head->ant = NULL;
    }
    else if (act == tail)
    {
        tail = act->ant;
        tail->sig = NULL;
    }
    else
    {
        act->ant->sig = act->sig;
        act->sig->ant = act->ant;
    }

    delete act;
    return true;
}

void liberarLista(Nodo*& head, Nodo*& tail) {
    while (head != NULL) {
        Nodo* borrar = head;
        head = head->sig;
        delete borrar;
    }
    tail = NULL;
}