#include "Lista.h"
#include <iostream>
using namespace std;
Lista::Lista()
{
    p = 0;
}
void Lista::Crear(Cliente *c)
{
    if (p < 10)
    {
        l[p] = c;
        p++;
    }
    else
    {
        cout << "La lista está llena" << endl;
    }
}
void Lista::Borrar(int noCuenta)
{
    for (int i = 0; i < p; i++)
    {
        if (l[i]->c.NoCuenta == noCuenta)
        {
            delete l[i];
            for (int j = i; j < p - 1; j++)
            {
                l[j] = l[j + 1];
            }
            p--;
            return;
        }
    }
}
int Lista::ObtenerNoCuenta(string nombre)
{
    for (int i = 0; i < p; i++)
    {
        if (l[i]->ObtenerNombre() == nombre)
        {
            return l[i]->c.NoCuenta;
        }
    }
    return -1;
}
Cliente *Lista::ObtenerCliente(int noCuenta)
{
    for (int i = 0; i < p; i++)
    {
        if (l[i]->c.NoCuenta == noCuenta)
        {
            return l[i];
        }
    }
    return NULL;
}
Cuenta *Lista::ObtenerCuenta(int noCuenta)
{
    for (int i = 0; i < p; i++)
    {
        if (l[i]->c.NoCuenta == noCuenta)
        {
            return l[i]->ObtenerCuenta();
        }
    }
    return NULL;
}
void Lista::Estado()
{
    for (int i = 0; i < p; i++)
    {
        l[i]->Estado();
        if (i < p - 1)
        {
            cout << "," << endl
                 << " ";
        }
    }
}
