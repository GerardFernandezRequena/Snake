#include <iostream>
#include <string>
#include "../include/Position.h"

using namespace std;

#ifndef SNAKE_H
#define SNAKE_H


class Snake
{
  public:
    // Constructor de la clase Snake, recibe el n�mero de bonificaciones.
    Snake(int nBonificacions);

    // Destructor de la clase Snake.
    ~Snake();

    // M�todo para visualizar la serpiente en una posici�n dada (fila, columna).
    bool visualitza(int row, int col) const;

    // M�todo para verificar si la serpiente contiene una posici�n (fila, columna) espec�fica.
    bool contains(int row, int col);

    // M�todo para verificar si la serpiente est� muerta.
    bool isDead();

    // M�todo para mover la serpiente en una direcci�n dada (newdir) desde una posici�n (nRow, nCol).
    int* movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol);

    // M�todo para indicar que la serpiente no ha comido una bonificaci�n.
    void doesntEat();

  private:
    // Puntero a un array de objetos Position.
    Position *arrayPosition;

    // Longitud actual de la serpiente, inicializada en 3.
    int currentLength = 3;

    // Direcci�n actual de la serpiente, inicializada en Rigth (esto podr�a ser un error tipogr�fico, deber�a ser Right).
    MyEnum::eDirection currentDir = Rigth;
};


#endif // SNAKE_H
