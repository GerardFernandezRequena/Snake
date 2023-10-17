#include <iostream>
#include <string>
#include "../include/Position.h"

using namespace std;

#ifndef SNAKE_H
#define SNAKE_H


class Snake
{
  public:
    // Constructor de la clase Snake, recibe el número de bonificaciones.
    Snake(int nBonificacions);

    // Destructor de la clase Snake.
    ~Snake();

    // Método para visualizar la serpiente en una posición dada (fila, columna).
    bool visualitza(int row, int col) const;

    // Método para verificar si la serpiente contiene una posición (fila, columna) específica.
    bool contains(int row, int col);

    // Método para verificar si la serpiente está muerta.
    bool isDead();

    // Método para mover la serpiente en una dirección dada (newdir) desde una posición (nRow, nCol).
    int* movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol);

    // Método para indicar que la serpiente no ha comido una bonificación.
    void doesntEat();

  private:
    // Puntero a un array de objetos Position.
    Position *arrayPosition;

    // Longitud actual de la serpiente, inicializada en 3.
    int currentLength = 3;

    // Dirección actual de la serpiente, inicializada en Rigth (esto podría ser un error tipográfico, debería ser Right).
    MyEnum::eDirection currentDir = Rigth;
};


#endif // SNAKE_H
