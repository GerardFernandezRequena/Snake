#include <iostream>
#include <string>
#include "../include/Snake.h"
#include "../include/MyEnum.h"
using namespace std;
using namespace MyEnum;

#ifndef TAULELL_H
#define TAULELL_H


class Taulell
{
 private:
    const static int files = 8;
    const static int columnes = 8;
    int contenidor[files][columnes];
    int nBonificacions;
    Snake *aSnake;

 public:
    Taulell();
    ~Taulell();
    static int getFiles();
    static int getColumnes();
    int getnBonificadors();
    void inici(int quantes);
    void visualitzar();
    bool movimentSerp(MyEnum::eDirection dir);
    void finalitzar();
};

#endif // TAULELL_H
