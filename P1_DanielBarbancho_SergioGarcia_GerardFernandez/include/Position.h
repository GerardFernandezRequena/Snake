#include <iostream>
#include <string>
#include "../include/MyEnum.h"

using namespace std;
using namespace MyEnum;

#ifndef POSITION_H
#define POSITION_H


class Position
{
private:
    int row;  // Variable privada para almacenar la fila
    int col;  // Variable privada para almacenar la columna

public:
    Position();  // Constructor por defecto
    Position(int i, int j);  // Constructor que recibe una fila (i) y una columna (j)
    void putData(int row, int col);  // M�todo para establecer los valores de fila y columna
    int getRow() const;  // M�todo para obtener el valor de la fila de forma constante
    int getCol() const;  // M�todo para obtener el valor de la columna de forma constante
    void visualitza() const;  // M�todo para visualizar la posici�n
    void visualitza(MyEnum::eDirection dir) const;  // M�todo para visualizar la posici�n con una direcci�n espec�fica (MyEnum::eDirection)
    bool operator == (Position *altre) const;  // Sobrecarga del operador de igualdad (==) que compara con otro objeto Position
    bool operator != (Position *altre) const;  // Sobrecarga del operador de desigualdad (!=) que compara con otro objeto Position
};

#endif // POSITION_H
