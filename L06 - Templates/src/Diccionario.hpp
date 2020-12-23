#include <cassert>
#include "Diccionario.h"
#include <vector>

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Diccionario() {}

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template<class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k)
        {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template<class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}

template<class Clave, class Valor>
std::vector<Clave> Diccionario<Clave,Valor>::claves() const
{
    std::vector<Clave> vRes;

    for (int i = 0; i < _asociaciones.size(); ++i)
    {
        vRes.push_back(_asociaciones[i].clave);
    }

    for (int i = 0; i < vRes.size(); ++i)
    {
        Clave min = vRes[i];
        int minJ = i;
        for (int j = i; j < vRes.size(); ++j)
        {
            if(min > vRes[j])
            {

                min = vRes[j];
                minJ = j;
            }
        }
        Clave Aux = vRes[i];
        vRes[i] = min;
        vRes[minJ] = Aux;
    }
    return vRes;
}