#ifndef BANCO_H
#define BANCO_H

#include <string>
#include "Lista.h"

class Banco
{
public:
    Lista c;

    Banco();

    void CrearCuenta(std::string nombre, std::string direccion, std::string telefono, double saldo);
    void BorrarCuenta(int noCuenta);
    void Depositar(int noCuenta, double cantidad);
    void Retirar(int noCuenta, double cantidad);
    int ObtenerNoCuenta(std::string nombre);
    double ObtenerSaldo(int noCuenta);
    void EstadoCuenta(int noCuenta);
    void Estado();
};

#endif