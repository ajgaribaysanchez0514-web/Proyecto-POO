#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
using namespace std;

class Persona
{
public:
    string Nombre;
    string Direccion;
    string Telefono;

    Persona(string nombre, string direccion, string telefono)
    {
        Nombre = nombre;
        Direccion = direccion;
        Telefono = telefono;
    }

    string ObtenerNombre()
    {
        return Nombre;
    }

    string ObtenerDireccion()
    {
        return Direccion;
    }

    string ObtenerTelefono()
    {
        return Telefono;
    }

    void ModificarNombre(string nombre)
    {
        Nombre = nombre;
    }

    void ModificarDireccion(string direccion)
    {
        Direccion = direccion;
    }

    void ModificarTelefono(string telefono)
    {
        Telefono = telefono;
    }

    void Estado()
    {
        cout << "nombre=" << Nombre << ", dirección=" << Direccion << ", teléfono=" << Telefono;
    }
};

#endif