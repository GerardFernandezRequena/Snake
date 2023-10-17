#include "Taulell.h"
#include <iostream>
using namespace std;

// Definición del constructor de la clase Taulell
Taulell::Taulell()
{
    // Inicialización de la variable "aSnake" de la clase Taulell con un puntero nulo (nullptr)
    Taulell::aSnake = nullptr;
}

Taulell::~Taulell()
{
    // En el destructor de la clase Taulell.

    // Borra la memoria asignada al puntero 'aSnake'.
    delete Taulell::aSnake;
}

// Esta es la definición de la función "getFiles" en la clase "Taulell".
int Taulell::getFiles()
{
    // En esta línea, estamos retornando el valor de la variable estática "files" de la clase "Taulell".
    return Taulell::files;
}

int Taulell::getColumnes()
{
    return Taulell::columnes; // Esta función devuelve el valor de la variable 'columnes' de la clase Taulell.
}

int Taulell::getnBonificadors()
{
    return Taulell::nBonificacions;  // Devuelve el valor de la variable estática nBonificacions en la clase Taulell.
}


void Taulell::inici(int quantes)
{
    // Establece la cantidad de bonificaciones en el tablero.
    Taulell::nBonificacions = quantes;

    // Crea un objeto Snake y lo almacena en aSnake.
    Taulell::aSnake = new Snake(quantes);

    // Itera 'quantes' veces para colocar las bonificaciones en el tablero.
    for (int i = 0; i < quantes; i++)
    {
        // Genera una fila aleatoria entre 1 y 8.
        int fila = 1 + (rand() % 8);

        // Genera una columna aleatoria entre 0 y 7.
        int columna = (rand() % 8);

        // Verifica si la celda en la fila y columna generadas ya contiene una bonificación.
        while (Taulell::contenidor[fila][columna] == 1)
        {
            // Si la celda ya contiene una bonificación, genera nuevas coordenadas aleatorias.
            fila = 1 + (rand() % 8);
            columna = (rand() % 8);
        }

        // Marca la celda en la fila y columna generadas como conteniendo una bonificación.
        Taulell::contenidor[fila][columna] = 1;
    }
}


void Taulell::visualitzar()
{
    // Capçalera del tablero
    cout << " " << " ";
    for(int i = 0; i < Taulell::columnes; i++)
    {
        cout << i; // Imprime el número de columna
    }

    cout << " \n"; // Nueva línea para la siguiente fila

    // Resto del tablero
    for(int i = 0; i < Taulell::files; i++)
    {
        cout << i << "|"; // Imprime el número de fila seguido de un "|"
        for(int j = 0; j < Taulell::columnes; j++)
        {
            if(Taulell::contenidor[i][j] == 1)
                cout << "&"; // Si el valor en la posición [i][j] es 1, imprime "&"
            else
            {
                bool comprovar = Taulell::aSnake->visualitza(i, j);
                if(comprovar == false)
                    cout << " "; // Si visualitza(i, j) devuelve false, imprime un espacio en blanco
            }
        }
        cout << "|\n"; // Cierra la fila con "|", luego agrega una nueva línea
    }
}


bool Taulell::movimentSerp(MyEnum::eDirection dir)
{
    // Comprova si la serp ha mort. Si ho és, retorna false.
    if (Taulell::aSnake->isDead())
    {
        return false;
    }

    // S'obté la nova posició de la serp seguint una direcció i les dimensions del taulell.
    int* novaPosicio = Taulell::aSnake->movimentSerp(dir, Taulell::getFiles(), Taulell::getColumnes());

    // Si el contingut a la nova posició és igual a 1, significa que hi ha una bonificació.
    if(Taulell::contenidor[novaPosicio[0]][novaPosicio[1]] == 1)
    {
        Taulell::contenidor[novaPosicio[0]][novaPosicio[1]] = 0; // Es marca la bonificació com a recollida (canviant el seu valor a 0).
        Taulell::nBonificacions--; // Es redueix la quantitat de bonificacions disponibles al taulell.
    }   else {
        // Si el contingut a la nova posició no és igual a 1, significa que no hi ha bonificació.
        Taulell::aSnake->doesntEat(); // S'executa el mètode "doesntEat" en la classe Snake (serp)
    }

    return true;

}

void Taulell::finalitzar()
{
    // Recorrem totes les files del tauler
    for (int i = 0;i<Taulell::files;i++)
    {
        // Recorrem totes les columnes del tauler
        for (int j = 0;j<Taulell::columnes;j++)
        {
            // Assignem 0 a cada casella del tauler, que pot representar una mena d'estat de reinici.
            Taulell::contenidor[i][j] = 0;
        }
    }
    // Cridem explícitament el destructor de la classe Snake per alliberar memòria.
    Taulell::aSnake->~Snake();
}
