#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "Persona.h"
#include "Cuenta.h"

class Cliente : public Persona
{
public:
    Cuenta c;

    Cliente(std::string nombre, std::string direccion, std::string telefono, double saldo);

    Cuenta *ObtenerCuenta();
    void Estado();
};

#endif