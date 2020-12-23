#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s)
{
    vector<int> sinRepetidos;
    set<int> setS;
    for (int i = 0; i < s.size(); ++i)
    {
        setS.insert(s[i]);
    }
    for (auto i : setS)
    {
        sinRepetidos.push_back(i);
    }
    return sinRepetidos;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> sinRepetidos;
    set<int> setS;
    for (int i = 0; i < s.size(); ++i)
    {
        setS.insert(s[i]);
    }
    for (auto i : setS)
    {
        sinRepetidos.push_back(i);
    }
    return sinRepetidos;
    return vector<int>();
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) { //intersección de elementos
    bool res = true;
    vector<int> aSinRep = quitar_repetidos(a);
    vector<int> bSinRep = quitar_repetidos(b);
    if (aSinRep.size() == bSinRep.size())
    {
        for (int i = 0; i < aSinRep.size(); ++i)
        {
            bool esta = false;
            for (int j = 0; j < aSinRep.size(); ++j)
            {
                if (aSinRep[i] == bSinRep[j])
                {
                    esta = true;
                }
            }
            if (!esta)
            {
                res = false;
                i = aSinRep.size();
            }
        }
    }
    else
    {
        res = false;
    }

    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    bool res = true;
    set<int> setA;
    set<int> setB;
    for (int i = 0; i < a.size(); ++i)
    {
        setA.insert(a[i]);
    }
    for (int i = 0; i < b.size(); ++i)
    {
        setB.insert(b[i]);
    }

    for (int i = 0; i < b.size(); ++i)
    {
        if(setA.count(b[i]) == 0)
        {
            res = false;
        }
    }
    for (int i = 0; i < a.size(); ++i)
    {
        if(setB.count(a[i]) == 0)
        {
            res = false;
        }
    }
    return res;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) { //recibo una secuencia, y asocio ese número a su cantidad de apariciones
    map<int, int> res;
    vector<int> sSinRep = quitar_repetidos(s);
    for (int i = 0; i < sSinRep.size(); ++i)
    {
        int cantApariciones = 0;
        for (int j = 0; j < s.size(); ++j)
        {
            if(sSinRep[i] == s[j])
            {
                cantApariciones++;
            }
        }
        res[sSinRep[i]] = cantApariciones;
    }

    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) { //si hay repetidos SE VAN TODOS, no es que queda uno solo
    vector<int> res;
    map<int, int> dicc = contar_apariciones(s);
    for (int i = 0; i < s.size(); ++i)
    {
        if (dicc[s[i]] == 1)
        {
            res.push_back(s[i]);
        }
    }

    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) { 
    set<int> res;
    for (int i : a)
    {
        if (b.count(i) == 1)
            res.insert(i);
    }

    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) { //Las claves son el dígito menos significativo de un número
    vector<int> sSinRep = quitar_repetidos(s);
    map<int, set<int>> res;
    for (int i = 0; i < sSinRep.size(); ++i)
    {
        int clave = sSinRep[i]%10;
        if (res.count(clave) == 0)
        {
            set<int> set;
            res[clave] = set;
        }

        res[clave].insert(sSinRep[i]);
    }

    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    for (int i = 0; i < str.size(); ++i)
    {
        char charATraducir = str[i];
        bool hayClave = false;
        for (int j = 0; j < tr.size(); ++j)
        {
            char clave = tr[j].first;
            if(charATraducir == clave)
            {
                hayClave = true;
                res.push_back(tr[j].second);
            }
        }
        if (!hayClave)
        {
            res.push_back(charATraducir);
        }
    }

    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    bool res = false;
    set<set<LU>> grupos;
    for (int i = 0; i < s.size(); ++i) //inserta todos los grupos de los mails en un conjunto grupos
    {
        grupos.insert(s[i].libretas());
    }
    for (auto grupo : grupos)
    {
       vector<LU> vectorAux;
       for(auto i : grupo)
       {
           vectorAux.push_back(i);
       }

       for(auto grupoAux : grupos)
       {
           if (grupo != grupoAux)
           {
               for (int i = 0; i < vectorAux.size(); ++i)
               {
                   if(grupoAux.count(vectorAux[i]) == 1)
                   {
                       //hay un integrante en un grupo que no le corresponde
                       res = true;
                       return res;
                   }
               }
           }
       }
    }

    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) { //Devuelve un diccionario que asocia a cada grupo el último mail (con adjuntos)
  map<set<LU>, Mail> res;
  //Fecha = unsigned int cuyo número más grande es la fecha más reciente
  map<set<LU>, vector<Mail>> mailsDelGrupo;
  for (int i = 0; i < s.size(); ++i)
  {
      if (s[i].adjunto())
      {
          set<LU> grupo = s[i].libretas();
          mailsDelGrupo[grupo].push_back(s[i]);
      }
  }

  map<set<LU>, vector<Mail>>::iterator it;
  for (it = mailsDelGrupo.begin(); it != mailsDelGrupo.end(); it++)
  {
      int cantMails = it->second.size();
      int fechaUltimoMail = it->second[0].fecha();
      Mail ultimoMail = it->second[0];
      for (int i = 0; i < cantMails; ++i)
      {
          if (fechaUltimoMail < it->second[i].fecha())
          {
              fechaUltimoMail = it->second[i].fecha();
              ultimoMail = it->second[i];
          }
      }
      res[it->first] = ultimoMail;
  }

  return res;
}
