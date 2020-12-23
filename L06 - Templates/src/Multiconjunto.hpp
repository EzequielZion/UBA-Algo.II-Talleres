#include "Diccionario.hpp"
#include <iterator>

template<class T>
class Multiconjunto {
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x) const;
    bool operator<=(Multiconjunto<T> contenedor) const;
private:
    Diccionario<T, int> _d;
};

template<class T>
Multiconjunto<T>::Multiconjunto() : _d()
{
}

template<class T>
void Multiconjunto<T>::agregar(T x)
{
    if(_d.def(x))
    {
        _d.definir(x, _d.obtener(x)+1);
    }
    else
    {
        _d.definir(x, 1);
    }
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) const
{
    int res = 0;
    if(_d.def(x))
    {
        res = _d.obtener(x);
    }
    return res;
}

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> contenedor) const
{
    //Acá hay un multiconjunto que es contenedor y un multiconjunto que es contenido
    //Yo veo si mi multiconjunto (this) está contenido en el contenedor
    bool res = true;

    std::vector<T> clavesContenedor = contenedor._d.claves();
    std::vector<T> clavesMias = this->_d.claves();

    int cantClavesMias = clavesMias.size();
    int cantClavesContenedor = clavesContenedor.size();

    int cantClavesMiasEnContenedor = 0;
    for (int i = 0; i < cantClavesMias; ++i)
    {
        for (int j = 0; j < cantClavesContenedor; ++j)
        {
            if(clavesMias[i] == clavesContenedor[j])
            {
                cantClavesMiasEnContenedor++;
                j = cantClavesContenedor;
            }
        }
    }
    if(cantClavesMias == cantClavesMiasEnContenedor)
    {
        for (int i = 0; i < cantClavesMias; ++i)
        {
            if(this->ocurrencias(clavesMias[i]) > contenedor.ocurrencias(clavesMias[i]))
            {
                res = false;
                i = cantClavesMias;
            }
        }
    }
    else
    {
        res = false;
    }

    return res;
}
