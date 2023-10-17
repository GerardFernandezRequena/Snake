#include "../include/MyEnum.h"

    string MyEnum::toName( eDirection dir)
    {
        return nameDir[dir];
    }

    string MyEnum::toSymbol( eDirection dir)
    {
        return symbolDir[dir];
    }

    MyEnum::eDirection MyEnum::giveDirection(){
        int valor, min = 1;
        cout << "Escull una direccio:" << endl;
        for( int i = min; i <= length; i++)
            cout << "\t" << i << " " << nameDir[i-1] << endl;

        do{
            cout << "Especifica un valor dins de l'interval [" << min << ", " << length << "]" << endl;
            cin >> valor;
        } while (valor < min || valor > length);

        return eDirection(valor-1);
    }

    int* MyEnum::movement(MyEnum::eDirection dir) {
        static int pos[2];
        pos[0] = moveDir[0][dir];
        pos[1] = moveDir[1][dir];
        return pos;
    }
