template <typename T>
string_map<T>::string_map() : _raiz(nullptr), _size(0){}

template <typename T>
string_map<T>::Nodo::Nodo() : siguientes(256, nullptr), definicion(nullptr) {}

template<typename T>
string_map<T>::Nodo::Nodo(const Nodo* nodoACopiar) : siguientes(256, nullptr), definicion(nullptr){
    if(nodoACopiar->definicion != nullptr){
        T* significado = new T(*(nodoACopiar->definicion));
        /*En este caso 'this' refiere al Nodo que estoy creando,
         *ya que es una función que está dentro del struct.
         *Señalo esto porque originalmente hice un
         * Nodo nuevoNodo = new Nodo(), pero como no había forma de
         * vincular 'nuevoNodo' con lo que hace este constructor,
         * rompía todo lmao
         * */
        this->definicion = significado;
    }
    for (int i = 0; i < nodoACopiar->siguientes.size(); ++i) {
        if(nodoACopiar->siguientes[i] != nullptr){
            this->siguientes[i] = new Nodo(nodoACopiar->siguientes[i]);
        }
    }
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() {
    *this = aCopiar;
} // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    _size = d._size;
    destructorRecursivo(_raiz);
    if(d._raiz != nullptr){
        _raiz = new Nodo(d._raiz);
    }
}

template <typename T>
string_map<T>::~string_map(){
    if(_raiz != nullptr){
        destructorRecursivo(_raiz);
        _raiz = nullptr;
        _size = 0;
    }
}

template <typename T>
void string_map<T>::destructorRecursivo(Nodo* nodoActual){
    if(nodoActual != nullptr){
        for (int i = 0; i < nodoActual->siguientes.size(); ++i) {
            if(nodoActual->siguientes[i] != nullptr){
                destructorRecursivo(nodoActual->siguientes[i]);
                nodoActual->siguientes[i] = nullptr;
            }
        }
        if(nodoActual->definicion != nullptr){
            delete nodoActual->definicion;
        }
        delete nodoActual;
    }
}

template <typename T>
void string_map<T>::insert(const pair<string, T>& tupla) {
    string clave = tupla.first;
    T* significado = new T(tupla.second);
    if(_raiz == nullptr){
        _raiz = new Nodo();
    }
    if (clave != "") {
        insertoRecursivo(_raiz, clave, significado);
    }
}

template <typename T>
void string_map<T>::insertoRecursivo(Nodo* nodoActual, string& clave, T* significado) {
    if(clave != "") {
        char c = clave[0];
        if (nodoActual->siguientes[int(c)] == nullptr) {
            nodoActual->siguientes[int(c)] = new Nodo();
        }
        Nodo* nodoSiguiente = nodoActual->siguientes[int(c)];
        string claveAEnviar = clave.erase(0, 1);
        insertoRecursivo(nodoSiguiente, claveAEnviar, significado);
    }
    else if(nodoActual->definicion == nullptr){
        nodoActual->definicion = significado;
        this->_size++;
    }
    else{
        delete nodoActual->definicion;
        nodoActual->definicion = significado;
    }
}

template <typename T>
int string_map<T>::count(const string& clave) const {
    int res = 0;
    if (_raiz != nullptr) {
        Nodo *nodoActual = _raiz;
        for (int i = 0; i < clave.size(); ++i) {
            char c = clave[i];
            if (nodoActual->siguientes[int(c)] != nullptr) {
                nodoActual = nodoActual->siguientes[int(c)];
            } else {
                return 0;
            }
        }
        if (nodoActual->definicion != nullptr) {
            res = 1;
        }
    }
    return res;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    if (count(clave) == 1) {
        Nodo* nodoActual = _raiz;
        for (int i = 0; i < clave.size(); ++i) {
            char c = clave[i];
            nodoActual = nodoActual->siguientes[int(c)];
        }
        return nodoActual->definicion;
    }
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    if (count(clave) == 1) {
        Nodo* nodoActual = _raiz;
        for (int i = 0; i < clave.size(); ++i) {
            char c = clave[i];
            nodoActual = nodoActual->siguientes[int(c)];
        }
        return *(nodoActual->definicion);
    }
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    if (count(clave) == 1) {
        string claveAux = clave;
        eraseRecursivo(_raiz, claveAux);
        _size--;
    }
}

template <typename T>
bool string_map<T>::eraseRecursivo(Nodo* nodoActual, string claveRecibida) {
    /*El 'nodoActual' es siempre el de la letra que falta de la claveRecibida,
     *o sea, si la claveRecibida que quiero eliminar es 'casa' y mi claveRecibida actual
     *es 'sa', eso significa que estoy en el nodo de la primera 'a'
     */

    bool eliminarEsteNodo;
    bool eliminarNodoSiguiente;
    string clavePreModificacion = claveRecibida;
    int cantHijos = cantidadHijos(nodoActual);

    if (cantHijos == 0) {
        delete nodoActual->definicion;
        eliminarEsteNodo = true;
    }
    else if (cantHijos == 1) {
        /*Siempre que todos los nodos mantengan esta condición o
         * la anterior, puedo eliminar este nodo y los de abajo.
         */
        if (claveRecibida == "") //Es el último nodo?
        {
            delete nodoActual->definicion;
            nodoActual->definicion = nullptr;
            eliminarEsteNodo = false; /*o sea, no eliminar este nodo ya que se eliminó la palabra pero
            era un prefijo de otra (casa-casar)*/
        } else {
            int indice = int(claveRecibida[0]);
            string claveAEnviar = claveRecibida.erase(0, 1);
            Nodo* nodoAEnviar = nodoActual->siguientes[indice];
            eliminarEsteNodo = eraseRecursivo(nodoAEnviar, claveAEnviar);
            eliminarNodoSiguiente = eliminarEsteNodo;
        }
    } else if (cantHijos > 1) {
        /*Si termina la palabra acá, eliminar sólo el valor pero NO EL NODO
        Si no termina la palabra acá, seguir buscando y NO ELIMINO ESTE NODO
       ni los siguientes*/
        if (claveRecibida == "") //Es el último nodo?
        {
            delete nodoActual->definicion;
            nodoActual->definicion = nullptr;
            eliminarEsteNodo = false; /*o sea, no eliminar este nodo ya que se eliminó la palabra pero
            era un prefijo de otras palabras (casa-casar)*/
        } else {
            int indice = int(claveRecibida[0]);
            string claveAEnviar = claveRecibida.erase(0, 1);
            Nodo* nodoAEnviar = nodoActual->siguientes[indice];
            eliminarNodoSiguiente = eraseRecursivo(nodoAEnviar, claveAEnviar);
            eliminarEsteNodo = false;
        }
    }

    if (nodoActual != _raiz) {
        if (clavePreModificacion.size() > 0 && eliminarNodoSiguiente) {
            int indice = int(clavePreModificacion[0]);
            delete nodoActual->siguientes[indice];
            nodoActual->siguientes[indice] = nullptr;
        }
    }
    else{ /*Si estoy en la raíz y quiero eliminar casona, si 'c' sigue teniendo un hijo
         * significa que no tengo que borrar el primer nodo, ya que es padre
         * de una u otras palabras más
         * */
        if(cantidadHijos(_raiz->siguientes[clavePreModificacion[0]]) == 0){
            delete _raiz->siguientes[clavePreModificacion[0]];
            _raiz->siguientes[clavePreModificacion[0]] = nullptr;
        }
    }

    return eliminarEsteNodo;
}


template <typename T>
int string_map<T>::cantidadHijos(Nodo* nodoActual) {
    int res = 0;
    for (int i = 0; i < nodoActual->siguientes.size(); ++i) {
        if(nodoActual->siguientes[i] != nullptr){
            res++;
        }
    }
    return res;
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _size == 0;
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}