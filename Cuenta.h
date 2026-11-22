#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
using namespace std;

class Cuenta
{
public:
    static int N;
    int NoCuenta;
    double Saldo;

    Cuenta(double saldo)
    {
        NoCuenta = N;
        Saldo = saldo;
        IncrementarN();
    }

    static void IncrementarN()
    {
        N++;
    }

    void Depositar(double cantidad)
    {
        Saldo = Saldo + cantidad;
    }

    void Retirar(double cantidad)
    {
        if (cantidad <= Saldo)
        {
            Saldo = Saldo - cantidad;
        }
        else
        {
            cout << "Saldo insuficiente" << endl;
        }
    }

    double ConsultarSaldo()
    {
        return Saldo;
    }

    void Estado()
    {
        cout << "Cuenta[noCuenta=" << NoCuenta << ", saldo=$" << Saldo << "]";
    }
};

int Cuenta::N = 1;

#endif