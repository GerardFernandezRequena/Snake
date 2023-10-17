#include "../include/MyEnum.h"

    // Definición de la función 'toName' en la clase 'MyEnum', que toma un argumento 'dir' de tipo 'eDirection'.
    string MyEnum::toName(eDirection dir)
    {
        // Retorna el valor almacenado en el arreglo 'nameDir' en la posición 'dir'.
        // Esta función convierte el valor numérico 'dir' en una cadena de caracteres (nombre).
        return nameDir[dir];
    }


    string MyEnum::toSymbol(eDirection dir) // Definición de la función toSymbol que toma un argumento de tipo eDirection llamado dir y devuelve una cadena (string).
    {
        return symbolDir[dir]; // Devuelve el valor almacenado en el arreglo symbolDir en la posición correspondiente al valor de dir.
    }


    MyEnum::eDirection MyEnum::giveDirection(){
        int valor, min = 1; // Declara una variable 'valor' para almacenar la elección del usuario y 'min' como el valor mínimo permitido.
        cout << "Escull una direcció:" << endl; // Muestra un mensaje para que el usuario elija una dirección.
        for( int i = min; i <= length; i++) // Inicia un bucle que recorre todas las direcciones disponibles.
            cout << "\t" << i << " " << nameDir[i-1] << endl; // Muestra una lista numerada de direcciones.

        do{
            cout << "Especifica un valor dins de l'interval [" << min << ", " << length << "]" << endl; // Solicita al usuario que ingrese un valor dentro de un rango específico.
            cin >> valor; // Lee la entrada del usuario y la almacena en la variable 'valor'.
        } while (valor < min || valor > length); // Continúa solicitando la entrada del usuario hasta que se ingrese un valor válido.

        return eDirection(valor-1); // Devuelve la dirección elegida por el usuario (restando 1 para que coincida con el índice en el array 'nameDir').
    }


int* MyEnum::movement(MyEnum::eDirection dir) {
    static int pos[2];
    // Esta línea declara una matriz estática de enteros llamada 'pos' con 2 elementos.

    pos[0] = moveDir[0][dir];
    // Aquí, se asigna el valor de 'moveDir[0][dir]' al primer elemento de la matriz 'pos'.
    // Esto implica que 'pos[0]' almacenará el valor de 'moveDir[0][dir]'.

    pos[1] = moveDir[1][dir];
    // De manera similar, se asigna el valor de 'moveDir[1][dir]' al segundo elemento de la matriz 'pos'.
    // Esto implica que 'pos[1]' almacenará el valor de 'moveDir[1][dir]'.

    return pos;
    // Finalmente, la función devuelve un puntero al comienzo de la matriz 'pos'.
    // Esto permite acceder a los valores de 'pos' desde fuera de la función.
}
