#include<string>

using namespace std;

// Ejercicio 1: Pasar a templates
template <typename numero>
numero cuadrado(numero x) {
    return x * x;
}

// Ejercicio 2: Pasar a templates
template <class contenedor, class elem>
bool contiene(contenedor c, elem e) {
    for (int i = 0; i < c.size(); i++) {
        if (c[i] == e) {
            return true;
        }
    }
    return false;
}

// Ejercicio 3: Funcion es prefijo con un template contenedor
template <class contenedor>
bool esPrefijo(contenedor a, contenedor b) {
    bool res = true;
    if (a.size() < b.size())
    {
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] != b[i])
            {
                res = false;
            }
        }
    }
    else
    {
        res = false;
    }
    return res;
}

// Ejercicio 4: Función maximo con un template contenedor y uno elemento
template <class Contenedor, class Elem>
Elem maximo(Contenedor c)
{
    Elem max = c[0];
    for (int i = 1; i < c.size(); ++i)
    {
        if (c[i] > max)
        {
            max = c[i];
        }
    }
    return max;
}
