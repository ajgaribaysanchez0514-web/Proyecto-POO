#ifndef INICIO_H
#define INICIO_H

#include <string>
#include "Banco.h"

class Inicio
{
public:
    Banco miBanco;

    void Titulo(std::string texto);
    void Limpiar();
    void Pausar();
    int LeerEntero();
    double LeerNumero();
    std::string LeerTexto(std::string pregunta);
    void CrearCuenta();
    void BorrarCuenta();
    void Depositar();
    void Retirar();
    void ConsultarSaldo();
    void MenuLista();
    void MenuCuenta();
    void EstadoDeCuenta();
    void Menu();
    void Ejecutar();
};

#endif
