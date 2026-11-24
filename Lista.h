#ifndef LISTA_H
#define LISTA_H

#include <string>
#include "Cliente.h"

class Lista
{
public:
    Cliente *l[10];
    int p;

    Lista();

    void Crear(Cliente *c);
    void Borrar(int noCuenta);
    int ObtenerNoCuenta(std::string nombre);
    Cliente *ObtenerCliente(int noCuenta);
    Cuenta *ObtenerCuenta(int noCuenta);
    void Estado();
};

#endif