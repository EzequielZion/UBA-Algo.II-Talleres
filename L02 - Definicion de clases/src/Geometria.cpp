#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int alto_;
        int ancho_;
};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho) {};
//Lo de recién es el CONSTRUCTOR: e indico después de los : cuánto tienen que valer las variables alto_ y ancho_

uint Rectangulo::alto() {
    return this->alto_;
    /*esto significa que cuando yo llamo Rectangulo.alto(), me va a devolver el valor de alto_
    que está definido en la instancia this de este objeto
     */
}
uint Rectangulo::ancho() {
    return this->ancho_;
}
float Rectangulo::area() {
    return ancho_*alto_;
}
// Ejercicio 2
class Elipse {
public:
    Elipse(uint a, uint b);
    uint r_a();
    uint r_b();
    float area();

private:
    int r_a_;
    int r_b_;
};
Elipse::Elipse(uint a, uint b) : r_a_(a), r_b_(b) {};
uint Elipse::r_a(){
    return this->r_a_;
}
uint Elipse::r_b(){
    return this->r_b_;
}
float Elipse::area(){
    float PI = 3.14;
    return this->r_a_*this->r_b_*PI;
}

// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    return this->r_.alto();
}

float Cuadrado::area() {
    return this->r_.area();
}

// Ejercicio 4
class Circulo {
public:
    Circulo(uint radio);
    uint radio();
    float area();

private:
    Elipse elipse_;
};

Circulo::Circulo(uint radio) : elipse_(radio, radio) {}
uint Circulo::radio(){
    return this->elipse_.r_a();
}
float Circulo::area(){
    return this->elipse_.area();
}

// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}

// Ejercicio 6
ostream& operator<<(ostream& os, Cuadrado c) {
    os << "Cuad(" << c.lado() << ")";
    return os;
}
ostream& operator<<(ostream& os, Circulo c) {
    os << "Circ(" << c.radio() << ")";
    return os;
}