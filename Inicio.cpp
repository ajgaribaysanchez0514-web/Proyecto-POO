#include <iostream>
#include "Banco.h"
using namespace std;

class Inicio {
public:
    void Titulo(string texto) {
        cout << "==================================================" << endl;
        cout << texto << endl;
        cout << "==================================================" << endl;
    }

    void Ejecutar() {
        Titulo("Paso 1: Crear el banco");
        Banco banco;
        cout << "Banco creado." << endl << endl;

        Titulo("Paso 2: Crear 2 cuentas");
        banco.CrearCuenta("Juan", "Laureles 30", "234", 10);
        banco.CrearCuenta("María", "Rejoneador 25", "637", 200);
        cout << "Cuentas creadas: Juan y María." << endl << endl;

        Titulo("Paso 3: Estado del banco");
        banco.Estado();
        cout << endl;

        Titulo("Paso 4: Depositar $350 a la cuenta 1");
        banco.Depositar(1, 350);
        cout << "Depósito realizado." << endl << endl;

        Titulo("Paso 5: Retirar $5 de la cuenta 2");
        banco.Retirar(2, 5);
        cout << "Retiro realizado." << endl << endl;

        Titulo("Paso 6: Estado del banco");
        banco.Estado();
        cout << endl;

        Titulo("Paso 7: Borrar la cuenta 1");
        banco.BorrarCuenta(1);
        cout << "Cuenta 1 borrada." << endl << endl;

        Titulo("Paso 8: Estado del banco");
        banco.Estado();
        cout << endl;

        Titulo("Paso 9: Número de cuenta de María");
        int noCuenta = banco.ObtenerNoCuenta("María");
        cout << "Número de cuenta de María: " << noCuenta << endl << endl;

        Titulo("Paso 10: Saldo de la cuenta de María");
        double saldo = banco.ObtenerSaldo(noCuenta);
        cout << "Saldo de la cuenta de María: $" << saldo << endl;
    }
};

int main() {
    Inicio inicio;
    inicio.Ejecutar();
    return 0;
}