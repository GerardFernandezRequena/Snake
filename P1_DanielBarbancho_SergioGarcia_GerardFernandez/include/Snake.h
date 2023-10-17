#include <iostream>
#include <string>
#include "../include/Position.h"

using namespace std;

#ifndef SNAKE_H
#define SNAKE_H


class Snake
{
  public:
    Snake(int nBonificacions);
    ~Snake();
    bool visualitza(int row, int col) const;
    bool contains(int row, int col);
    bool isDead();
    int* movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol);
    void doesntEat();

  private:
    Position *arrayPosition;
    int currentLength = 3;
    MyEnum::eDirection currentDir = Rigth;
};

#endif // SNAKE_H
