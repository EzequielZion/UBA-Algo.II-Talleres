#ifndef CONEXIONJUGADOR_H
#define CONEXIONJUGADOR_H

#include "Internet.h"
#include <string>

using namespace std;

class ConexionJugador {
  public:
    ConexionJugador(string ip); //constructor
    void enviarMensaje(string mensaje);
    string ip() const;

  private:
    string _ip; //si tenés que enviarle un mensaje a un jugador, es a esta ip

    Internet* _internet = &Internet::internet();
    /* El & ANTES de algo indica que es una dirección donde se guarda ese algo.
     * En este caso tiene sentido porque estamos creando un puntero de
     * la clase Internet. Por qué estamos creando un puntero? Ni idea,
     * asumo que para ahorrar memoria pero la verdad idk
     * */
};

#endif
