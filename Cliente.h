#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include "Persona.h"
#include "Cuenta.h"
using namespace std;

class Cliente : public Persona
{
public:
    Cuenta c;

    Cliente(string nombre, string direccion, string telefono, double saldo)
        : Persona(nombre, direccion, telefono), c(saldo)
    {
    }

    Cuenta *ObtenerCuenta()
    {
        return &c;
    }

    void Estado()
    {
        cout << "Cliente[";
        Persona::Estado();
        cout << ", ";
        c.Estado();
        cout << "]";
    }
};

#endif