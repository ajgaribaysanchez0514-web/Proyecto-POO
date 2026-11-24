#include "Cuenta.h"
#include <iostream>

using namespace std;

int Cuenta::N = 1;

Cuenta::Cuenta(double saldo)
{
    NoCuenta = N;
    Saldo = saldo;
    IncrementarN();
}

void Cuenta::IncrementarN()
{
    N++;
}

void Cuenta::Depositar(double cantidad)
{
    Saldo = Saldo + cantidad;
}

void Cuenta::Retirar(double cantidad)
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

double Cuenta::ConsultarSaldo()
{
    return Saldo;
}

void Cuenta::Estado()
{
    cout << "Cuenta[noCuenta=" << NoCuenta << ", saldo=$" << Saldo << "]";
}
