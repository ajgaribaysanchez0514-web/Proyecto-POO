#include "Banco.h"
#include <iostream>
using namespace std;
    
Banco::Banco()
{
    
}
void Banco::CrearCuenta(string nombre, string direccion, string telefono, double saldo)
{
    Cliente *nuevo = new Cliente(nombre, direccion, telefono, saldo);
    c.Crear(nuevo);
}
void Banco::BorrarCuenta(int noCuenta)
{
    c.Borrar(noCuenta);
}
void Banco::Depositar(int noCuenta, double cantidad)
{
    Cuenta *cuenta = c.ObtenerCuenta(noCuenta);
    if (cuenta != NULL)
    {
        cuenta->Depositar(cantidad);
    }
}
void Banco::Retirar(int noCuenta, double cantidad)
{
    Cuenta *cuenta = c.ObtenerCuenta(noCuenta);
    if (cuenta != NULL)
    {
        cuenta->Retirar(cantidad);
    }
}
int Banco::ObtenerNoCuenta(string nombre)
{
    return c.ObtenerNoCuenta(nombre);
}

double Banco::ObtenerSaldo(int noCuenta)
{
    Cuenta *cuenta = c.ObtenerCuenta(noCuenta);
    if (cuenta != NULL)

    {
        return cuenta->ConsultarSaldo();
    }
    return -1;
}
void Banco::EstadoCuenta(int noCuenta)
{
    Cliente *cliente = c.ObtenerCliente(noCuenta);
    if (cliente != NULL)
    {
        cliente->Estado();
        cout << endl;
    }
    else
    {
        cout << "No existe esa cuenta." << endl;
    }
}
void Banco::Estado()
{
    cout << "Banco[";
    c.Estado();
    cout << "]" << endl;
}
