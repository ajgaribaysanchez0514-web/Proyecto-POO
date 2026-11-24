#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona
{
public:
    std::string Nombre;
    std::string Direccion;
    std::string Telefono;

    Persona(std::string nombre, std::string direccion, std::string telefono);

    std::string ObtenerNombre();
    std::string ObtenerDireccion();
    std::string ObtenerTelefono();
    void ModificarNombre(std::string nombre);
    void ModificarDireccion(std::string direccion);
    void ModificarTelefono(std::string telefono);
    void Estado();
};

#endif