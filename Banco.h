#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <string>
#include "Lista.h"
using namespace std;

class Banco
{
public:
    Lista c;

    Banco()
    {
    }

    void CrearCuenta(string nombre, string direccion, string telefono, double saldo)
    {
        Cliente *nuevo = new Cliente(nombre, direccion, telefono, saldo);
        c.Crear(nuevo);
    }

    void BorrarCuenta(int noCuenta)
    {
        c.Borrar(noCuenta);
    }

    void Depositar(int noCuenta, double cantidad)
    {
        Cuenta *cuenta = c.ObtenerCuenta(noCuenta);
        if (cuenta != NULL)
        {
            cuenta->Depositar(cantidad);
        }
    }

    void Retirar(int noCuenta, double cantidad)
    {
        Cuenta *cuenta = c.ObtenerCuenta(noCuenta);
        if (cuenta != NULL)
        {
            cuenta->Retirar(cantidad);
        }
    }

    int ObtenerNoCuenta(string nombre)
    {
        return c.ObtenerNoCuenta(nombre);
    }

    double ObtenerSaldo(int noCuenta)
    {
        Cuenta *cuenta = c.ObtenerCuenta(noCuenta);
        if (cuenta != NULL)
        {
            return cuenta->ConsultarSaldo();
        }
        return -1; // no se encontró
    }

    void Estado()
    {
        cout << "Banco[";
        c.Estado();
        cout << "]" << endl;
    }
};

#endif