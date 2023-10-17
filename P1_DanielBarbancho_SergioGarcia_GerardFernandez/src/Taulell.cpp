#include "Taulell.h"
#include <iostream>
using namespace std;

Taulell::Taulell()
{
    Taulell::aSnake = nullptr;
}

Taulell::~Taulell()
{
    delete Taulell::aSnake;
}

int Taulell::getFiles()
{
    return Taulell::files;
}

int Taulell::getColumnes()
{
    return Taulell::columnes;
}

int Taulell::getnBonificadors()
{
    return Taulell::nBonificacions;
}

void Taulell::inici(int quantes)
{
    Taulell::nBonificacions = quantes;
    Taulell::aSnake = new Snake(quantes);

    for(int i = 0;i<quantes;i++)
    {
        int fila = 1 + (rand() % 8);
        int columna = (rand() % 8);
        while (Taulell::contenidor[fila][columna] == 1)
        {
            fila = 1 + (rand() % 8);
            columna = (rand() % 8);
        }
        Taulell::contenidor[fila][columna] = 1;
    }
}

void Taulell::visualitzar()
{
    // Capçalera del taulell
    cout << " " << " ";
    for(int i = 0; i<Taulell::columnes;i++)
    {
        cout << i;
    }

    cout << " \n";

    // Resta del taulell

    for(int i = 0;i<Taulell::files;i++)
    {
        cout << i << "|";
        for(int j = 0;j<Taulell::columnes;j++)
        {
            if(Taulell::contenidor[i][j] == 1) cout << "&";
            else
            {
                bool comprovar = Taulell::aSnake->visualitza(i, j);
                if(comprovar == false) cout << " ";
            }
        }
        cout << "|\n";
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
