#include "SistemaDeMensajes.h"
#if EJ >= 6
#include "Proxy2.h"
#else
#include "Proxy.h"
#endif

bool idValida(int id){
    bool res = false;
    if (id >=0 && id <4){
        res = true;
    }
    return res;
}

SistemaDeMensajes::SistemaDeMensajes() : _conns(), _proxies() {}

void SistemaDeMensajes::registrarJugador(int id, string ip){
    if(idValida(id)){
        if(registrado(id))
        {
            delete this->_conns[id];
        }
        ConexionJugador *conn = new ConexionJugador(ip);
        this->_conns[id] = conn;
    }
}

bool SistemaDeMensajes::registrado(int id) const {
    return this->_conns[id] != nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    if(registrado(id))
    {
        this->_conns[id]->enviarMensaje(mensaje);
    }
}

string SistemaDeMensajes::ipJugador(int id) const {
    if (registrado(id))
    {
        return this->_conns[id]->ip();
    }
}

void SistemaDeMensajes::desregistrarJugador(int id){
    if(idValida(id))
    {
        if(registrado(id))
        {
            delete this->_conns[id];
            this->_conns[id] = nullptr;
        }
    }
}

Proxy* SistemaDeMensajes::obtenerProxy(int id){
    //dado un id de jugador crea un proxy para este jugador y devuelva un puntero al mismo
    //AVISO: en el ejercicio 6 cambia la imlementación de obtenerProxy. En este archivo dejé
    // última, por lo que el ejercicio 4 probablemente corra mal
    if(this->_proxies[id] == nullptr)
    {
        ConexionJugador** con = &_conns[id];
        this->_proxies[id] = new Proxy(con); //new devuelve SIEMPRE un puntero y llama al constructor
    }
    return this->_proxies[id];
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (int i = 0; i < 4; ++i) {
        if (this->_conns[i] != nullptr)
        {
            delete this->_conns[i];
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (this->_proxies[i] != nullptr)
        {
            delete this->_proxies[i];
        }
    }
}

