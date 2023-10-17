#include <iostream>
#include "../include/MyEnum.h"
#include "../include/Taulell.h"

using namespace std;
using namespace MyEnum;

int demanarValor(int min, int max)
{
    string valorBonificacions; // Declaraci�n de una variable de cadena para almacenar la entrada del usuario
    cout << "Introdueix un valor entre el interval [1,8]\n"; // Muestra un mensaje al usuario
    cin >> valorBonificacions; // Lee la entrada del usuario y la almacena en valorBonificacions

    // Verifica si cada car�cter de la cadena es un d�gito
    for(int i=0; i < valorBonificacions.length(); i++)
    {
        if(isdigit(valorBonificacions[i]) == false) // Si no es un d�gito
        {
            cout << "El valor introduit no es un numero enter \n"; // Muestra un mensaje de error
            return demanarValor(min, max); // Llama recursivamente a la funci�n para volver a solicitar la entrada
        }
    }

    int valorBonificacionsInt = stoi(valorBonificacions); // Convierte la cadena a un entero

    // Verifica si el valor entero est� dentro del rango especificado
    if (valorBonificacionsInt <= max && valorBonificacionsInt >= min)
        return valorBonificacionsInt; // Devuelve el valor si es v�lido
    else
    {
        cout << "El valor introduit no esta dintre del rang requirit \n"; // Muestra un mensaje de error
        return demanarValor(min, max); // Llama recursivamente a la funci�n para volver a solicitar la entrada
    }
}

bool TornarJugar(Taulell *tau)
{
    // Llama al m�todo 'finalitzar' del objeto apuntado por 'tau'.
    tau->finalitzar();

    // Invoca el destructor del objeto 'Taulell' apuntado por 'tau'.
    tau->~Taulell();

    // Declara una variable llamada 'respostaUsuari' de tipo 'string' para almacenar la respuesta del usuario.
    string respostaUsuari;

    // Muestra un mensaje en la consola pidiendo la respuesta del usuario.
    cout << "Vols tornar a jugar? (s/n)";

    // Lee la respuesta del usuario desde la entrada est�ndar y la almacena en 'respostaUsuari'.
    cin >> respostaUsuari;

    // Comprueba si la respuesta del usuario es igual a "n".
    if (respostaUsuari == "n")
    {
        // Si la respuesta es "n", muestra un mensaje de despedida y devuelve 'false'.
        cout << "Adeu!";
        return false;
    }

    // Si la respuesta no es "n", devuelve 'true' para indicar que el usuario quiere volver a jugar.
    return true;
}


int main()
{
    bool partida = true; // Variable que controla si la partida est� en curso.

    while (partida == true) // Bucle principal del juego que se ejecuta mientras la partida est� en curso.
    {
        Taulell *taula; // Crear un puntero a un objeto de la clase Taulell (tablero del juego).
        int valor = demanarValor(1,8); // Llamar a una funci�n para solicitar un valor entre 1 y 8.
        taula->inici(valor); // Iniciar el tablero con el valor seleccionado.

        taula->visualitzar(); // Mostrar el tablero en pantalla.
        MyEnum::eDirection direction = MyEnum::giveDirection(); // Obtener una direcci�n de movimiento desde una enumeraci�n.
        bool moviment = taula->movimentSerp(direction); // Mover la serpiente en la direcci�n especificada.

        while(moviment == true) // Bucle interno que se ejecuta mientras la serpiente puede seguir movi�ndose.
        {
            taula->visualitzar(); // Mostrar el tablero en pantalla nuevamente.
            direction = MyEnum::giveDirection(); // Obtener una nueva direcci�n de movimiento.
            moviment = taula->movimentSerp(direction); // Intentar mover la serpiente en la nueva direcci�n.

            if (taula->getnBonificadors() == 0) // Comprobar si no quedan bonificadores en el tablero.
                moviment = false; // Si no quedan bonificadores, detener el movimiento de la serpiente.
        }

        partida = TornarJugar(taula); // Llamar a una funci�n para determinar si se debe jugar otra partida.
    }

    return 0; // Salir del programa con c�digo de retorno 0.
}

