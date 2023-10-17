#include "Position.h"
#include <iostream>
using namespace std;

Position::Position()
{
    Position::row = -1;
    Position::col = -1;
}

Position::Position(int i, int j)
{
    Position::row = i;
    Position::col = j;
}

void Position::putData(int row, int col)
{
    Position::row = row;
    Position::col = col;
}

int Position::getRow() const
{
    return Position::row;
}

int Position::getCol() const
{
    return Position::col;
}

void Position::visualitza() const
{
    cout << "*";
}

void Position::visualitza(MyEnum::eDirection dir) const
{
    if (dir == Up) cout << "^";
    if (dir == Down) cout << "v";
    if (dir == Left) cout << "<";
    if (dir == Rigth) cout << ">";
}

bool Position::operator == (Position *altre) const
{
    if (this->col == altre->col && this->row == altre->row) return true;
    return false;
}

bool Position::operator != (Position *altre) const
{
    if (this->col != altre->col && this->row != altre->row) return true;
    return false;
}
