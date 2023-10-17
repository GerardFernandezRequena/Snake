#include <iostream>
#include <string>
using namespace std;

#ifndef PRACTICA1_MYENUM_H
#define PRACTICA1_MYENUM_H


namespace MyEnum
{
    // Definici�n de un enumerador llamado eDirection con 4 valores posibles.
    enum eDirection { Up, Down, Left, Rigth };

    // Arreglo de cadenas de texto que corresponden a los nombres de las direcciones.
    const string nameDir[] = { "Up", "Down", "Left", "Rigth" };

    // Arreglo de cadenas de texto que corresponden a los s�mbolos de las direcciones.
    const string symbolDir[] = { " ^", " v", " <", " >" };

    // Constante que almacena el n�mero de direcciones, que en este caso es 4.
    const int length = 4;

    // Matriz bidimensional que define los movimientos en las filas y columnas.
    // Cada fila representa un movimiento en las filas (row) y en las columnas (col).
    const int moveDir[2][length] = {
        -1, 1, 0, 0, // Movimientos en las filas (row)
        0, 0, -1, 1  // Movimientos en las columnas (col)
    };

    // Declaraci�n de una funci�n llamada toName que convierte una direcci�n en su nombre.
    string toName(eDirection dir);

    // Declaraci�n de una funci�n llamada toSymbol que convierte una direcci�n en su s�mbolo.
    string toSymbol(eDirection dir);

    // Declaraci�n de una funci�n llamada giveDirection que retorna una direcci�n.
    eDirection giveDirection();

    // Declaraci�n de una funci�n llamada movement que retorna un puntero a un arreglo de movimientos.
    int* movement(eDirection dir);
};



#endif // PRACTICA1_MYENUM_H
