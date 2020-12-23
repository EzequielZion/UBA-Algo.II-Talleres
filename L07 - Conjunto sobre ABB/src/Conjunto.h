#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto
{
public:
    Conjunto();

    ~Conjunto();

    void insertar(const T&);

    bool pertenece(const T&) const;

    void remover(const T&);

    const T& siguiente(const T& elem);

    const T& minimo() const;

    const T& maximo() const;

    unsigned int cardinal() const;

    void mostrar(std::ostream&) const;

private:
    struct Nodo
    {
        Nodo(const T& v);
        T valor;
        Nodo* izq;
        Nodo* der;
    };
    Nodo* _raiz;
    unsigned int _cant;
    void destructorRecursivo(Nodo* actual);
    void insertarRecursivo(const T& clave, Nodo* actual);
    bool perteneceRecursivo(const T& clave, Nodo* nodoActual) const;
    Nodo* devolverNodo(const T& clave, Nodo* nodoActual);
    Nodo* devolverPredecesorInmediato(Nodo* nodoActual);
    Nodo* devolverNodoPadre(const T& clave, Nodo* nodoActual);
    vector<T*> conjAVector(Nodo* nodoRecibido);
    int ordenoVectorYDevuelvoIndice(vector<T*>& vecRecibido, const T& clave);

};

template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
    c.mostrar(os);
    return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_