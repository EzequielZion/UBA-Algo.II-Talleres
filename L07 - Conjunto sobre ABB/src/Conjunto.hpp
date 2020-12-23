#include "Conjunto.h"
#include <vector>

template <class T>
Conjunto<T>::Nodo::Nodo(const T& v) : valor(v), izq(nullptr), der(nullptr){
}


template <class T>
Conjunto<T>::Conjunto() : _raiz(nullptr), _cant(0) {
}

template <class T>
Conjunto<T>::~Conjunto() {
    destructorRecursivo(_raiz);
    _raiz = nullptr;
}

template <class T>
void Conjunto<T>::destructorRecursivo(Nodo* actual) {
    if(actual != nullptr){
        destructorRecursivo(actual->izq);
        destructorRecursivo(actual->der);
        delete actual;
   }
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const{
    bool res = false;
    if(this->cardinal() != 0){
        res = perteneceRecursivo(clave, _raiz);
    }
    return res;
}

template <class T>
bool Conjunto<T>::perteneceRecursivo(const T& clave, Nodo* nodoActual) const{
    bool res = false;
    if(nodoActual != nullptr) {
        if(nodoActual->valor == clave){
            res = true;
        }
        else{
            Nodo* izq = nodoActual->izq;
            Nodo* der = nodoActual->der;
            if(clave < nodoActual->valor){
                if(izq != nullptr){
                    res = perteneceRecursivo(clave, izq);
                }
            }
            else {
                if(der != nullptr){
                    res = perteneceRecursivo(clave, der);
                }
            }
        }
    }
    return res;
}


template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if(this->_cant == 0){
        _raiz = new Nodo(clave);
        this->_cant++;
    }
    else{
        if(!pertenece(clave)){
            insertarRecursivo(clave, _raiz);
            this->_cant++;
        }
    }
}

template <class T>
void Conjunto<T>::insertarRecursivo(const T& clave, Nodo* actual) {
    if(clave > actual->valor){
        if(actual->der == nullptr){
            actual->der = new Nodo(clave);
        }else{
            Nodo* proxNodo = actual->der;
            insertarRecursivo(clave, proxNodo);
        }
    }
    else {
        if(actual->izq == nullptr){
            actual->izq = new Nodo(clave);
        }else{
            Nodo* proxNodo = actual->izq;
            insertarRecursivo(clave, proxNodo);
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    /*Hay 3 casos:
        1. Clave es hoja
        2. Clave tiene un hijo
        3. Clave tiene 2 hijos
     */
    if(pertenece(clave)){
        Nodo* nodoAEliminar = devolverNodo(clave, _raiz);
        Nodo* nodoPadre = devolverNodoPadre(nodoAEliminar->valor, _raiz);

        //Caso 1: es una hoja
        if(nodoAEliminar->izq == nullptr && nodoAEliminar->der == nullptr){
            if(nodoAEliminar != _raiz) {
                if (nodoPadre->izq == nodoAEliminar) {
                    nodoPadre->izq = nullptr;
                } else {
                    nodoPadre->der = nullptr;
                }
                delete nodoAEliminar;
            }
            else {
                delete _raiz;
                _raiz = nullptr;
            }
        }
        //Caso 2.1: tiene un hijo a la izquierda
        else if(nodoAEliminar->izq != nullptr && nodoAEliminar->der == nullptr){
            if(nodoAEliminar != _raiz) {
                if (nodoPadre->izq == nodoAEliminar) {
                    nodoPadre->izq = nodoAEliminar->izq;
                } else {
                    nodoPadre->der = nodoAEliminar->izq;
                }
            }
            else{
                _raiz = nodoAEliminar->izq;
            }
            delete nodoAEliminar;
        }
        //Caso 2.2: tiene un hijo a la derecha
        else if(nodoAEliminar->izq == nullptr && nodoAEliminar->der != nullptr){
            if(nodoAEliminar != _raiz) {
                if (nodoPadre->izq == nodoAEliminar) {
                    nodoPadre->izq = nodoAEliminar->der;
                } else {
                    nodoPadre->der = nodoAEliminar->der;
                }
            }
            else{
                _raiz = nodoAEliminar->der;
            }
            delete nodoAEliminar;
        }
        //Caso 3: tiene dos hijos
        else {
            /*Encontrar el predecesor inmediato de nodoAEliminar,
             * que es el maximo del sub-arbol izq. Al ser el máximo,
             * sólo puede tener un hijo a la izquierda, y de ser
             * el caso lo reacomodo
            */

            Nodo* predecesorInmediato = devolverPredecesorInmediato(nodoAEliminar->izq);
            Nodo* nodoPadrePredInmediato = devolverNodoPadre(predecesorInmediato->valor, _raiz);
            nodoAEliminar->valor = predecesorInmediato->valor;

            /*Si predecesorInmediato tiene un hijo, tengo que reacomodarlo.
             * Como sé que sólo puede tenerlo a la izquierda, hago que lo que
             * apunta a nodoAEliminar apunte a predecesorInmediato->izq. Si es
             * una hoja, es nullptr.
             * */

            if(nodoPadrePredInmediato == nodoAEliminar) {
                nodoAEliminar->izq = predecesorInmediato->izq;
            }
            else {
                nodoPadrePredInmediato->der = predecesorInmediato->izq;
            }
            delete predecesorInmediato;
        }
        this->_cant--;
    }
}

template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::devolverNodo(const T& clave, Nodo* nodoActual) {
    Nodo* nodoADevolver = nullptr;
    Nodo* izq = nodoActual->izq;
    Nodo* der = nodoActual->der;

    if(nodoActual->valor == clave){
        nodoADevolver = nodoActual;
    }
    else {
        if(clave < nodoActual->valor) {
            if (izq != nullptr) {
                nodoADevolver = devolverNodo(clave, izq);
            }
        }
        else if (der != nullptr) {
            nodoADevolver = devolverNodo(clave, der);
        }
    }
    return nodoADevolver;
}

template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::devolverPredecesorInmediato(Nodo* nodoActual) {
    Nodo* pred = nodoActual;
    while (pred->der != nullptr){
        pred = pred->der;
    }
    return pred;
}

template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::devolverNodoPadre(const T& clave, Nodo* nodoActual) {
    Nodo* nodoADevolver = nullptr;
    if(nodoActual != nullptr) {
        if(clave < nodoActual->valor) {
            if (nodoActual->izq != nullptr) {
                if (nodoActual->izq->valor == clave) {
                    nodoADevolver = nodoActual;
                } else {
                    nodoADevolver = devolverNodoPadre(clave, nodoActual->izq);
                }
            }
        }
        else if (clave > nodoActual->valor){
            if (nodoActual->der != nullptr) {
                if (nodoActual->der->valor == clave) {
                    nodoADevolver = nodoActual;
                } else {
                    nodoADevolver = devolverNodoPadre(clave, nodoActual->der);
                }
            }
        }
    }
    return nodoADevolver;
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    if (pertenece(clave)) {
        vector<T*> vConjunto = conjAVector(_raiz);
        int i = ordenoVectorYDevuelvoIndice(vConjunto, clave);
        if(i < vConjunto.size()-1){
            return *vConjunto[i+1];
        }
    }
    else
    {
        return clave;
    }
}

template <class T>
vector<T*> Conjunto<T>::conjAVector(Nodo* nodoRecibido) {
    vector<T*> vecADevolver;
    if(nodoRecibido != nullptr){
        vecADevolver.push_back(&nodoRecibido->valor);
        vector<T*> vecIzq = conjAVector(nodoRecibido->izq);
        vector<T*> vecDer = conjAVector(nodoRecibido->der);
        for (int i = 0; i < vecIzq.size(); ++i) {
            vecADevolver.push_back(vecIzq[i]);
        }
        for (int i = 0; i < vecDer.size(); ++i) {
            vecADevolver.push_back(vecDer[i]);
        }
    }
    return vecADevolver;
}

template <class T>
int Conjunto<T>::ordenoVectorYDevuelvoIndice(vector<T*>& vecRecibido, const T& clave) {
    int res = 0;
    if (vecRecibido.size() > 0) {
        for (int i = 0; i < vecRecibido.size()-1; ++i)
        {
            int indiceMinimo = i;
            T* minimo = vecRecibido[indiceMinimo];
            for (int j = i; j < vecRecibido.size(); ++j)
            {
                if(*minimo > *vecRecibido[j]){
                    minimo = vecRecibido[j];
                    indiceMinimo = j;
                }
            }
            T* aux = vecRecibido[i];
            vecRecibido[i] = vecRecibido[indiceMinimo];
            vecRecibido[indiceMinimo] = aux;
            //Como sé que ya está ordenado, puedo saber el índice de la clave
            if(*vecRecibido[i] == clave){
                res = i;
            }
        }
    }
    return res;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* actual = _raiz;
    while (actual->izq != nullptr){
        actual = actual->izq;
    }
    return actual->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = _raiz;
    while (actual->der != nullptr){
        actual = actual->der;
    }
    return actual->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    int res = this->_cant;
    return res;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

