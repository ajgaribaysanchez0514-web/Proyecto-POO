#include "Cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente(string nombre, string direccion, string telefono, double saldo)
    : Persona(nombre, direccion, telefono), c(saldo)
{
}

Cuenta *Cliente::ObtenerCuenta()
{
    return &c;
}

void Cliente::Estado()
{
    cout << "Cliente[";
    Persona::Estado();
    cout << ", ";
    c.Estado();
    cout << "]";
}