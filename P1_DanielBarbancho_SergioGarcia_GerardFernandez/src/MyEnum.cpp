#include "../include/MyEnum.h"

    // Definici�n de la funci�n 'toName' en la clase 'MyEnum', que toma un argumento 'dir' de tipo 'eDirection'.
    string MyEnum::toName(eDirection dir)
    {
        // Retorna el valor almacenado en el arreglo 'nameDir' en la posici�n 'dir'.
        // Esta funci�n convierte el valor num�rico 'dir' en una cadena de caracteres (nombre).
        return nameDir[dir];
    }


    string MyEnum::toSymbol(eDirection dir) // Definici�n de la funci�n toSymbol que toma un argumento de tipo eDirection llamado dir y devuelve una cadena (string).
    {
        return symbolDir[dir]; // Devuelve el valor almacenado en el arreglo symbolDir en la posici�n correspondiente al valor de dir.
    }


    MyEnum::eDirection MyEnum::giveDirection(){
        int valor, min = 1; // Declara una variable 'valor' para almacenar la elecci�n del usuario y 'min' como el valor m�nimo permitido.
        cout << "Escull una direcci�:" << endl; // Muestra un mensaje para que el usuario elija una direcci�n.
        for( int i = min; i <= length; i++) // Inicia un bucle que recorre todas las direcciones disponibles.
            cout << "\t" << i << " " << nameDir[i-1] << endl; // Muestra una lista numerada de direcciones.

        do{
            cout << "Especifica un valor dins de l'interval [" << min << ", " << length << "]" << endl; // Solicita al usuario que ingrese un valor dentro de un rango espec�fico.
            cin >> valor; // Lee la entrada del usuario y la almacena en la variable 'valor'.
        } while (valor < min || valor > length); // Contin�a solicitando la entrada del usuario hasta que se ingrese un valor v�lido.

        return eDirection(valor-1); // Devuelve la direcci�n elegida por el usuario (restando 1 para que coincida con el �ndice en el array 'nameDir').
    }


int* MyEnum::movement(MyEnum::eDirection dir) {
    static int pos[2];
    // Esta l�nea declara una matriz est�tica de enteros llamada 'pos' con 2 elementos.

    pos[0] = moveDir[0][dir];
    // Aqu�, se asigna el valor de 'moveDir[0][dir]' al primer elemento de la matriz 'pos'.
    // Esto implica que 'pos[0]' almacenar� el valor de 'moveDir[0][dir]'.

    pos[1] = moveDir[1][dir];
    // De manera similar, se asigna el valor de 'moveDir[1][dir]' al segundo elemento de la matriz 'pos'.
    // Esto implica que 'pos[1]' almacenar� el valor de 'moveDir[1][dir]'.

    return pos;
    // Finalmente, la funci�n devuelve un puntero al comienzo de la matriz 'pos'.
    // Esto permite acceder a los valores de 'pos' desde fuera de la funci�n.
}
