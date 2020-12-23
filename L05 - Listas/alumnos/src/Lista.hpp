#include "Lista.h"

Lista::Lista() : _primero(nullptr), _ultimo(nullptr), _size(0){}

Lista::Nodo::Nodo() : next(nullptr), prev(nullptr) {}


Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    this->vaciarLista();
}

Lista& Lista::operator=(const Lista& aCopiar){
    //hace que se le pueda asignar otros valores a una lista existente
    if(this->_size != 0)
    {
        this->vaciarLista();
    }
    this->_size = 0;
    for (int i = 0; i < aCopiar._size; ++i)
    {
        this->agregarAtras(aCopiar.iesimo(i));
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* n = new Nodo();
    n->data = elem;
    if(this->_size == 0)
    {
        this->_ultimo = n;
    }
    else
    {
        this->_primero->prev = n;
        n->next = this->_primero;
    }
    this->_primero = n;
    this->_size++;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* n = new Nodo();
    n->data = elem;
    if(this->_size == 0)
    {
        this->_primero = n;
    }
    else
    {
        this->_ultimo->next = n;
        n->prev = this->_ultimo;
        this->_ultimo = n;
    }
    this->_ultimo = n;
    this->_size++;
}

void Lista::eliminar(Nat i) {
    Nodo* elementoAEliminar = this->_primero;
    if (this->_size > i)
    {
        for (int j = 0; j < i; ++j) {
            elementoAEliminar = elementoAEliminar->next;
        }

        Nodo* anteriorAlEliminado = elementoAEliminar->prev;
        Nodo* siguienteAlElimando = elementoAEliminar->next;

        if (anteriorAlEliminado != nullptr) //por si estoy eliminando el primero
        {
            anteriorAlEliminado->next = siguienteAlElimando;
        }
        if (siguienteAlElimando != nullptr) //por si estoy eliminando el último
        {
            siguienteAlElimando->prev = anteriorAlEliminado;
        }
        if(i==0)
        {
            this->_primero = siguienteAlElimando;
        }
        if(i = this->_size-1)
        {
            this->_ultimo = anteriorAlEliminado;
        }
        this->_size--;
        delete elementoAEliminar;
    }
}

int Lista::longitud() const {
    return this->_size;
}

const int& Lista::iesimo(Nat i) const {
    int j = 0;
    Nodo* aux = this->_primero;
    while(aux != nullptr && j != i){
        aux = aux->next;
        j++;
    }
    return aux->data;
}

int& Lista::iesimo(Nat i) {
    int j = 0;
    Nodo* aux = this->_primero;
    while(aux != nullptr && j != i){
        aux = aux->next;
        j++;
    }
    int& res = aux->data;
    return res;
}

void Lista::mostrar(ostream& o) {
    // Completar
}

void Lista::vaciarLista()
{
    Nodo* n = this->_primero;
    while(n != nullptr)
    {
        n = n->next;
        delete this->_primero;
        this->_primero = n;
    }
    this->_ultimo = nullptr;
    delete this->_ultimo;
}
