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
// funcion extra
bool editarPaquete(Nodo *head, int id);

int contarPaquetes(Nodo *head);
void liberarLista(Nodo *&head, Nodo *&tail);

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

bool editarPaquete(Nodo *head, int id)
{
    Nodo *p = buscarPorId(head, id);
    if (p == NULL)
        return false;

    cout << "Nuevo nombre: ";
    cin.ignore();
    getline(cin, p->nombre);

    cout << "Nuevo peso: ";
    cin >> p->peso;

    return true;
}

int contarPaquetes(Nodo *head)
{
    int c = 0;
    while (head != NULL)
    {
        c++;
        head = head->sig;
    }
    return c;
}

void liberarLista(Nodo *&head, Nodo *&tail)
{
    while (head != NULL)
    {
        Nodo *borrar = head;
        head = head->sig;
        delete borrar;
    }
    tail = NULL;
}

int main()
{
    Nodo *head = NULL;
    Nodo *tail = NULL;

    int op, id;
    string nombre;
    float peso;

    do
    {
        cout << "\n--- SISTEMA DE PAQUETES ---\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar adelante\n";
        cout << "4. Mostrar atras\n";
        cout << "5. Buscar por ID\n";
        cout << "6. Eliminar por ID\n";
        cout << "7. Contar paquetes\n";
        cout << "8. Editar paquete (PARTE EXTRA)\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
        case 2:
            cout << "ID: ";
            cin >> id;
            if (existeId(head, id))
            {
                cout << "ID repetido.\n";
                break;
            }
            cout << "Nombre: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Peso: ";
            cin >> peso;

            if (op == 1)
                insertarInicio(head, tail, id, nombre, peso);
            else
                insertarFinal(head, tail, id, nombre, peso);
            break;

        case 3:
            mostrarAdelante(head);
            break;

        case 4:
            mostrarAtras(tail);
            break;

        case 5:
            cout << "ID que desea buscar: ";
            cin >> id;
            if (buscarPorId(head, id))
                cout << "Se ha encontrado el paquete\n";
            else
                cout << "No existe.\n";
            break;

        case 6:
            cout << "ID que desea  eliminar: ";
            cin >> id;
            if (eliminarPorId(head, tail, id))
                cout << "Eliminado.\n";
            else
                cout << "No encontrado.\n";
            break;

        case 7:
            cout << "Total paquetes: " << contarPaquetes(head) << endl;
            break;

        case 8:
            cout << "ID que desea editar: ";
            cin >> id;
            if (editarPaquete(head, id))
                cout << "Se ha editado correctamente.\n";
            else
                cout << "No se ha encontrado.\n";
            break;
        }

    } while (op != 0);

    liberarLista(head, tail);
    return 0;
}