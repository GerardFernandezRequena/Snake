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
    const static int files = 8;  // Definimos una constante estática 'files' con valor 8 para el número de filas en el tablero.
    const static int columnes = 8;  // Definimos una constante estática 'columnes' con valor 8 para el número de columnas en el tablero.
    int contenidor[files][columnes];  // Matriz 'contenidor' para representar el tablero de juego con 'files' filas y 'columnes' columnas.
    int nBonificacions;  // Variable para almacenar la cantidad de bonificaciones en el tablero.
    Snake *aSnake;  // Puntero a un objeto de tipo Snake para representar la serpiente en el tablero.

 public:
    Taulell();  // Constructor de la clase Taulell.
    ~Taulell();  // Destructor de la clase Taulell.
    static int getFiles();  // Método estático para obtener el número de filas del tablero.
    static int getColumnes();  // Método estático para obtener el número de columnas del tablero.
    int getnBonificadors();  // Método para obtener la cantidad de bonificaciones en el tablero.
    void inici(int quantes);  // Método para iniciar el juego con un número específico de bonificaciones.
    void visualitzar();  // Método para mostrar visualmente el estado actual del tablero.
    bool movimentSerp(MyEnum::eDirection dir);  // Método para mover la serpiente en una dirección específica.
    void finalitzar();  // Método para finalizar el juego.
};

#endif // TAULELL_H
