#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12 te mando un n° de mes y me devolvés la cant de días
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    int mes();
    int dia();
    bool operator==(Fecha o);
    void incrementar_dia();

  private:
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia){};
int Fecha::mes()
{
    return this->mes_;
}
int Fecha::dia()
{
    return this->dia_;
}

bool Fecha::operator==(Fecha o) {
    bool res = false;
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    if(igual_dia and igual_mes)
    {
        res = true;
    }
    return res;
}

void Fecha::incrementar_dia() {
    uint cantDias = dias_en_mes(this->mes_);
    if(this->dia_ < cantDias){
        this->dia_++;
    }
    else
    {
        this->mes_++;
        this->dia_ = 1;
    }
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() <<"/"<< f.mes();
    return os;
}

// Ejercicio 11, 12

// Clase Horario
class Horario{
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator==(Horario o);
    bool operator<(Horario h);

private:
    uint hora_;
    uint min_;
};

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min) {};
uint Horario::hora(){
    return this->hora_;
}
uint Horario::min(){
    return this->min_;
}
bool Horario::operator==(Horario o) {
    bool res = false;
    bool igual_hora = this->hora() == o.hora();
    bool igual_min = this->min() == o.min();
    if(igual_hora and igual_min)
    {
        res = true;
    }
    return res;
}
ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() <<":"<< h.min();
    return os;
}
bool Horario::operator<(Horario h) {
    bool res = false;
    if (this->hora() < h.hora())
    {
        res = true;
    }
    else if(this->hora() == h.hora() && this->min() < h.min())
    {
        res = true;
    }
    return res;
}

// Ejercicio 13

class Recordatorio{
public:
    Recordatorio(Fecha f, Horario h, string m);
    Fecha fecha();
    Horario horario();
    string mensaje();
private:
    Fecha fecha_;
    Horario horario_;
    string mensaje_;
};

Recordatorio::Recordatorio(Fecha f, Horario h, string m) : fecha_(f), horario_(h), mensaje_(m){}
Fecha Recordatorio::fecha() {
    return this->fecha_;
}
Horario Recordatorio::horario() {
    return this->horario_;
}
string Recordatorio::mensaje() {
    return this->mensaje_;
}
ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje() <<" @ "<< r.fecha() << " " <<r.horario();
    return os;
}


// Ejercicio 14
class Agenda {
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();
private:
    Fecha hoy_;
    list<Recordatorio> recordatorios_;
};

Agenda::Agenda(Fecha fecha_inicial) : hoy_(fecha_inicial){}
void Agenda::agregar_recordatorio(Recordatorio rec) {
    recordatorios_.push_back(rec);
}
void Agenda::incrementar_dia() {
    this->hoy_.incrementar_dia();
}
list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list<Recordatorio> res;
    vector<Recordatorio> vAux;
    for(auto r : this->recordatorios_)
    {
        if(r.fecha() == this->hoy())
        {
            vAux.push_back(r);
        }
    }
    //ordeno cronológicamente
    if(vAux.size()>0)
    {
        for (int i = 0; i < vAux.size(); ++i)
        {
            for (int j = vAux.size()-1; j > 0; --j)
            {
                if (vAux[j].horario()<vAux[i].horario()) //uno de más adelante es más chico, lo cambio
                {
                    Recordatorio Aux = vAux[i];
                    vAux[i] = vAux[j];
                    vAux[j] = Aux;
                }

            }
        }
        for (int i = 0; i < vAux.size(); ++i)
        {
            res.push_back(vAux[i]);
        }
    }
    return res;
}
Fecha Agenda::hoy() {
    return this->hoy_;
}


ostream& operator<<(ostream& os, Agenda a) {
    list<Recordatorio> recordatoriosHoy = a.recordatorios_de_hoy();
    os << a.hoy() << "\n" << "=====" << endl;
    for(auto r : recordatoriosHoy)
    {
       os << r.mensaje() <<" @ "<< r.fecha() << " " <<r.horario() << "\n";
    }

    return os;
}