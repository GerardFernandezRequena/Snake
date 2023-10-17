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
    const static int files = 8;  // Definimos una constante est�tica 'files' con valor 8 para el n�mero de filas en el tablero.
    const static int columnes = 8;  // Definimos una constante est�tica 'columnes' con valor 8 para el n�mero de columnas en el tablero.
    int contenidor[files][columnes];  // Matriz 'contenidor' para representar el tablero de juego con 'files' filas y 'columnes' columnas.
    int nBonificacions;  // Variable para almacenar la cantidad de bonificaciones en el tablero.
    Snake *aSnake;  // Puntero a un objeto de tipo Snake para representar la serpiente en el tablero.

 public:
    Taulell();  // Constructor de la clase Taulell.
    ~Taulell();  // Destructor de la clase Taulell.
    static int getFiles();  // M�todo est�tico para obtener el n�mero de filas del tablero.
    static int getColumnes();  // M�todo est�tico para obtener el n�mero de columnas del tablero.
    int getnBonificadors();  // M�todo para obtener la cantidad de bonificaciones en el tablero.
    void inici(int quantes);  // M�todo para iniciar el juego con un n�mero espec�fico de bonificaciones.
    void visualitzar();  // M�todo para mostrar visualmente el estado actual del tablero.
    bool movimentSerp(MyEnum::eDirection dir);  // M�todo para mover la serpiente en una direcci�n espec�fica.
    void finalitzar();  // M�todo para finalizar el juego.
};

#endif // TAULELL_H
