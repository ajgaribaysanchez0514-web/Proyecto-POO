#ifndef CUENTA_H
#define CUENTA_H

class Cuenta
{
public:
    static int N;
    int NoCuenta;
    double Saldo;

    Cuenta(double saldo);

    static void IncrementarN();
    void Depositar(double cantidad);
    void Retirar(double cantidad);
    double ConsultarSaldo();
    void Estado();
};

#endif