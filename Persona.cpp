#include "Persona.h"
#include <iostream>

using namespace std;

Persona::Persona(string nombre, string direccion, string telefono)
{
    Nombre = nombre;
    Direccion = direccion;
    Telefono = telefono;
}

string Persona::ObtenerNombre()
{
    return Nombre;
}

string Persona::ObtenerDireccion()
{
    return Direccion;
}

string Persona::ObtenerTelefono()
{
    return Telefono;
}

void Persona::ModificarNombre(string nombre)
{
    Nombre = nombre;
}

void Persona::ModificarDireccion(string direccion)
{
    Direccion = direccion;
}

void Persona::ModificarTelefono(string telefono)
{
    Telefono = telefono;
}

void Persona::Estado()
{
    cout << "nombre=" << Nombre << ", dirección=" << Direccion << ", teléfono=" << Telefono;
}
