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
    int row;
    int col;

public:
    Position();
    Position(int i, int j);
    void putData(int row, int col);
    int getRow() const;
    int getCol() const;
    void visualitza() const;
    void visualitza(MyEnum::eDirection dir) const;
    bool operator == (Position *altre) const;
    bool operator != (Position *altre) const;
};

#endif // POSITION_H
