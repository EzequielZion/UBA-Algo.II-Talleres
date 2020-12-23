#include "Proxy2.h"

Proxy::Proxy(ConexionJugador** conn) : _conn(conn) {}

void Proxy::enviarMensaje(string msg) {
    ConexionJugador con = **_conn;
    con.enviarMensaje(msg);
}
