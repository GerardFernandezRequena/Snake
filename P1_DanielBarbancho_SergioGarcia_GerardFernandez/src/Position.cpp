#include "Position.h"
#include <iostream>
using namespace std;

Position::Position()
{
    // Constructor de la clase "Position"

    Position::row = -1;
    Position::col = -1;
    // Establece los valores iniciales de "row" y "col" en -1
}

// Definición del constructor de la clase Position con dos parámetros enteros: i y j
Position::Position(int i, int j)
{
    // Asigna el valor de i al atributo "row" de la instancia de la clase Position
    Position::row = i;

    // Asigna el valor de j al atributo "col" de la instancia de la clase Position
    Position::col = j;
}


void Position::putData(int row, int col)
{
    // La función putData recibe dos argumentos: row y col, que representan la fila y la columna.
    Position::row = row;  // Establece el valor de la variable miembro "row" de la clase Position con el valor de "row" proporcionado.
    Position::col = col;  // Establece el valor de la variable miembro "col" de la clase Position con el valor de "col" proporcionado.
}


int Position::getRow() const
{
    // La función "getRow" se define como una función miembro de la clase "Position".
    // Esta función se declara como constante con "const" al final, lo que significa
    // que no modificará ningún miembro de la clase.

    return Position::row;
    // La función devuelve el valor de la variable estática "row" de la clase "Position".
    // La notación "Position::row" se utiliza para acceder a una variable miembro estática
    // de la clase "Position". En este caso, devuelve el valor de la variable "row" para
    // el objeto en el que se llama la función "getRow".
}


int Position::getCol() const
{
    // Esta función devuelve la columna (atributo 'col') de la instancia actual de la clase Position.
    return Position::col;
}


void Position::visualitza() const
{
    // Esta función se encarga de mostrar un asterisco en la salida estándar (pantalla).
    // El 'void' significa que la función no devuelve ningún valor.
    // 'Position::' indica que esta función es parte de la clase Position.

    cout << "*"; // Imprime un asterisco en la pantalla.
}


void Position::visualitza(MyEnum::eDirection dir) const
{
    // Comprobamos si la dirección es "Arriba" (Up)
    if (dir == Up)
        cout << "^"; // Si es "Arriba", imprime el símbolo "^" en la consola

    // Comprobamos si la dirección es "Abajo" (Down)
    if (dir == Down)
        cout << "v"; // Si es "Abajo", imprime el símbolo "v" en la consola

    // Comprobamos si la dirección es "Izquierda" (Left)
    if (dir == Left)
        cout << "<"; // Si es "Izquierda", imprime el símbolo "<" en la consola

    // Comprobamos si la dirección es "Derecha" (Right)
    if (dir == Right)
        cout << ">"; // Si es "Derecha", imprime el símbolo ">" en la consola
}

bool Position::operator==(Position *altre) const
{
    // Comprueba si las columnas y las filas de 'this' y 'altre' son iguales.
    if (this->col == altre->col && this->row == altre->row) {
        // Si son iguales, devuelve 'true' para indicar que las posiciones son iguales.
        return true;
    }
    // Si las columnas o las filas no son iguales, devuelve 'false' para indicar que las posiciones son diferentes.
    return false;
}

// Esta función es una sobrecarga del operador "!=" para la clase Position.
bool Position::operator != (Position *altre) const
{
    // Comprueba si la columna de la instancia actual (this) es diferente de la columna de la posición "altre".
    // También verifica si la fila de la instancia actual (this) es diferente de la fila de la posición "altre".
    if (this->col != altre->col && this->row != altre->row)
    {
        // Si ambas condiciones son verdaderas, significa que las posiciones no son iguales y devuelve "true".
        return true;
    }

    // Si alguna de las condiciones no se cumple, es decir, las posiciones son iguales, devuelve "false".
    return false;
}
