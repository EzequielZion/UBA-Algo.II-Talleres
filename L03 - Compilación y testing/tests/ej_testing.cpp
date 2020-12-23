#include "gtest-1.8.1/gtest.h"
#include "../src/Headers/Libreta.h"
#include "../src/Headers/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    int calculado = 15 + 7;
    int esperado = 22;
    EXPECT_EQ(calculado, esperado);


}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    float calculado_pot = pow(10, 2);
    float esperado_pot = 100;
    EXPECT_EQ(calculado_pot, esperado_pot);
}

//Ejercicio 6 /*Elevar al cuadrado = multiplicar el número por sí mismo*/
TEST(Aritmetica, potencia_general) {
    for (int i = -5; i <= 5; ++i)
    {
        EXPECT_EQ(i*i, pow(i,2));
    }
}

//Ejercicio 7
TEST(Diccionario, obtener)
{
    map<int, int> m;
    m.insert(make_pair(5, 10));
    EXPECT_EQ(m.at(5), 10);
}

//Ejercicio 8
TEST(Diccionario, definir)
{
    map<int, int> m;
    EXPECT_EQ(m.count(5), 0);
    m.insert(make_pair(5, 10));
    EXPECT_EQ(m.count(5), 1);
}

//Ejercicio 9
TEST(Truco, inicio)
{
    Truco truco;
    EXPECT_EQ(truco.puntaje_j1(),0);
    EXPECT_EQ(truco.puntaje_j2(),0);
}

//Ejercicio 10
TEST(Truco, buenas)
/*
 El jugador 1 no está en buenas.
• Al sumar 15 puntos al jugador 1, este sigue en malas.
• Al sumar 1 punto al jugador 1, ahora está en buenas.
• Al sumar 2 puntos al jugador 1, sigue en buenas
 */

{
    Truco truco;
    EXPECT_FALSE(truco.buenas(1));
    for (int i = 0; i < 15; ++i) {
        truco.sumar_punto(1);
    }
    EXPECT_FALSE(truco.buenas(1));
    truco.sumar_punto(1);
    EXPECT_TRUE(truco.buenas(1));
    truco.sumar_punto(1);
    truco.sumar_punto(1);
    EXPECT_TRUE(truco.buenas(1));
}