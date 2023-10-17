#include <iostream>
#include <string>
using namespace std;

#ifndef PRACTICA1_MYENUM_H
#define PRACTICA1_MYENUM_H


namespace MyEnum
{
    // Definición de un enumerador llamado eDirection con 4 valores posibles.
    enum eDirection { Up, Down, Left, Rigth };

    // Arreglo de cadenas de texto que corresponden a los nombres de las direcciones.
    const string nameDir[] = { "Up", "Down", "Left", "Rigth" };

    // Arreglo de cadenas de texto que corresponden a los símbolos de las direcciones.
    const string symbolDir[] = { " ^", " v", " <", " >" };

    // Constante que almacena el número de direcciones, que en este caso es 4.
    const int length = 4;

    // Matriz bidimensional que define los movimientos en las filas y columnas.
    // Cada fila representa un movimiento en las filas (row) y en las columnas (col).
    const int moveDir[2][length] = {
        -1, 1, 0, 0, // Movimientos en las filas (row)
        0, 0, -1, 1  // Movimientos en las columnas (col)
    };

    // Declaración de una función llamada toName que convierte una dirección en su nombre.
    string toName(eDirection dir);

    // Declaración de una función llamada toSymbol que convierte una dirección en su símbolo.
    string toSymbol(eDirection dir);

    // Declaración de una función llamada giveDirection que retorna una dirección.
    eDirection giveDirection();

    // Declaración de una función llamada movement que retorna un puntero a un arreglo de movimientos.
    int* movement(eDirection dir);
};



#endif // PRACTICA1_MYENUM_H
