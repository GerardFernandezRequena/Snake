#include <iostream>
#include "../include/MyEnum.h"
#include "../include/Taulell.h"

using namespace std;
using namespace MyEnum;

int demanarValor(int min, int max)
{
    string valorBonificacions;
    cout << "Introdueix un valor entre el interval [1,8]\n";
    cin >> valorBonificacions;

    for(int i=0;i<valorBonificacions.length();i++)
    {
        if(isdigit(valorBonificacions[i]) == false)
        {
            cout << "El valor introduit no es un numero enter \n";
            return demanarValor(min, max);
        }
    }

    int valorBonificacionsInt = stoi(valorBonificacions);

    if (valorBonificacionsInt <= max && valorBonificacionsInt >= min) return valorBonificacionsInt;
    else
    {
        cout << "El valor introduit no esta dintre del rang requirit \n";
        return demanarValor(min, max);
    }
}

bool TornarJugar(Taulell *tau)
{
    tau->finalitzar();
    tau->~Taulell();

    string respostaUsuari;
    cout << "Vols tornar a jugar? (s/n)";
    cin >> respostaUsuari;

    if (respostaUsuari == "n")
    {
        cout << "Adeu!";
        return false;
    }
    return true;
}

int main()
{
    bool partida = true;
    while (partida == true)
    {
        Taulell *taula;
        int valor = demanarValor(1,8);
        taula->inici(valor);

        taula->visualitzar();
        MyEnum::eDirection direction = MyEnum::giveDirection();
        bool moviment = taula->movimentSerp(direction);

        while(moviment == true)
        {
            taula->visualitzar();
            direction = MyEnum::giveDirection();
            moviment = taula->movimentSerp(direction);
            if (taula->getnBonificadors() == 0) moviment = false;
        }
        partida = TornarJugar(taula);
    }

    return 0;
}
