#include <iostream>
#include <string>
#include <cstdlib>
#include "Banco.h"
using namespace std;

class Inicio
{
public:
    Banco miBanco;
    void Titulo(string texto)
    {
        cout << "==================================================" << endl;
        cout << texto << endl;
        cout << "==================================================" << endl;
    }

    void Limpiar()
    {
        system("cls");
    }

    void Pausar()
    {
        string basura;
        cout << endl
             << "Presiona Enter para continuar...";
        getline(cin, basura);
    }

    int LeerEntero()
    {
        int n;
        cin >> n;
        if (cin.eof())
        {
            return 0;
        }
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            return -1;
        }
        cin.ignore(1000, '\n');
        return n;
    }

    double LeerNumero()
    {
        double n;
        cin >> n;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            return -1;
        }
        cin.ignore(1000, '\n');
        return n;
    }

    string LeerTexto(string pregunta)
    {
        string texto;
        cout << pregunta;
        getline(cin, texto);
        return texto;
    }

    void CrearCuenta()
    {
        if (miBanco.c.p >= 10)
        {
            cout << "El banco ya no puede abrir más cuentas." << endl;
            return;
        }
        string nombre = LeerTexto("Nombre: ");
        string direccion = LeerTexto("Dirección: ");
        string telefono = LeerTexto("Teléfono: ");
        cout << "Saldo inicial: $";
        double saldo = LeerNumero();
        if (saldo < 0)
        {
            cout << "El saldo inicial no es válido." << endl;
            return;
        }
        miBanco.CrearCuenta(nombre, direccion, telefono, saldo);
        cout << "Cuenta creada. Número de cuenta: " << Cuenta::N - 1 << endl;
    }

    void BorrarCuenta()
    {
        cout << "Número de cuenta a borrar: ";
        int noCuenta = LeerEntero();
        if (miBanco.c.ObtenerCuenta(noCuenta) == NULL)
        {
            cout << "No existe esa cuenta." << endl;
            return;
        }
        miBanco.BorrarCuenta(noCuenta);
        cout << "Cuenta " << noCuenta << " borrada." << endl;
    }

    void Depositar()
    {
        cout << "Número de cuenta: ";
        int noCuenta = LeerEntero();
        if (miBanco.c.ObtenerCuenta(noCuenta) == NULL)
        {
            cout << "No existe esa cuenta." << endl;
            return;
        }
        cout << "Cantidad a depositar: $";
        double cantidad = LeerNumero();
        if (cantidad <= 0)
        {
            cout << "La cantidad no es válida." << endl;
            return;
        }
        miBanco.Depositar(noCuenta, cantidad);
        cout << "Depósito realizado. Saldo actual: $" << miBanco.ObtenerSaldo(noCuenta) << endl;
    }

    void Retirar()
    {
        cout << "Número de cuenta: ";
        int noCuenta = LeerEntero();
        if (miBanco.c.ObtenerCuenta(noCuenta) == NULL)
        {
            cout << "No existe esa cuenta." << endl;
            return;
        }
        cout << "Cantidad a retirar: $";
        double cantidad = LeerNumero();
        if (cantidad <= 0)
        {
            cout << "La cantidad no es válida." << endl;
            return;
        }
        if (cantidad > miBanco.ObtenerSaldo(noCuenta))
        {
            cout << "Saldo insuficiente." << endl;
            return;
        }
        miBanco.Retirar(noCuenta, cantidad);
        cout << "Retiro realizado. Saldo actual: $" << miBanco.ObtenerSaldo(noCuenta) << endl;
    }

    void ConsultarSaldo()
    {
        cout << "Número de cuenta: ";
        int noCuenta = LeerEntero();
        if (miBanco.c.ObtenerCuenta(noCuenta) == NULL)
        {
            cout << "No existe esa cuenta." << endl;
            return;
        }
        cout << "Saldo de la cuenta " << noCuenta << ": $" << miBanco.ObtenerSaldo(noCuenta) << endl;
    }

    void MenuLista()
    {
        int opcion = -1;
        while (opcion != 0)
        {
            Limpiar();
            Titulo("LISTA DE CLIENTES");
            cout << "1. Ver la lista de clientes" << endl;
            cout << "2. Crear cuenta" << endl;
            cout << "3. Borrar cuenta" << endl;
            cout << "0. Regresar al menú principal" << endl;
            cout << "Opción: ";
            opcion = LeerEntero();
            cout << endl;

            switch (opcion)
            {
            case 1:
                miBanco.Estado();
                break;
            case 2:
                CrearCuenta();
                break;
            case 3:
                BorrarCuenta();
                break;
            case 0:
                break;
            default:
                cout << "Opción no válida." << endl;
            }
            if (opcion != 0)
            {
                Pausar();
            }
        }
    }

    void MenuCuenta()
    {
        int opcion = -1;
        while (opcion != 0)
        {
            Limpiar();
            Titulo("CUENTA");
            cout << "1. Depositar" << endl;
            cout << "2. Retirar" << endl;
            cout << "3. Consultar saldo" << endl;
            cout << "0. Regresar al menú principal" << endl;
            cout << "Opción: ";
            opcion = LeerEntero();
            cout << endl;

            switch (opcion)
            {
            case 1:
                Depositar();
                break;
            case 2:
                Retirar();
                break;
            case 3:
                ConsultarSaldo();
                break;
            case 0:
                break;
            default:
                cout << "Opción no válida." << endl;
            }
            if (opcion != 0)
            {
                Pausar();
            }
        }
    }

    void EstadoDeCuenta()
    {
        cout << "Número de cuenta: ";
        int noCuenta = LeerEntero();
        miBanco.EstadoCuenta(noCuenta);
    }

    void Menu()
    {
        int opcion = -1;
        while (opcion != 0)
        {
            Limpiar();
            Titulo("MENÚ PRINCIPAL");
            cout << "1. Lista" << endl;
            cout << "2. Cuenta" << endl;
            cout << "3. Estado de cuenta" << endl;
            cout << "4. Tutorial <- Ingresa aqui pra ver como funciona el banco" << endl;
            cout << "0. Salir" << endl;
            cout << "Opción: ";
            opcion = LeerEntero();
            cout << endl;

            switch (opcion)
            {
            case 1:
                MenuLista();
                break;
            case 2:
                MenuCuenta();
                break;
            case 3:
                EstadoDeCuenta();
                Pausar();
                break;
            case 4:
                Ejecutar();
                Pausar();
                break;
            case 0:
                cout << "Hasta luego." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                Pausar();
            }
        }
    }

    void Ejecutar()
    {
        int guardado = Cuenta::N;
        Cuenta::N = 1;

        Titulo("Paso 1: Crear el banco");
        Banco banco;
        cout << "Banco creado." << endl
             << endl;

        Titulo("Paso 2: Crear 2 cuentas");
        banco.CrearCuenta("Juan", "Laureles 30", "234", 10);
        banco.CrearCuenta("María", "Rejoneador 25", "637", 200);
        cout << "Cuentas creadas: Juan y María." << endl
             << endl;

        Titulo("Paso 3: Estado del banco");
        banco.Estado();
        cout << endl;

        Titulo("Paso 4: Depositar $350 a la cuenta 1");
        banco.Depositar(1, 350);
        cout << "Depósito realizado." << endl
             << endl;

        Titulo("Paso 5: Retirar $5 de la cuenta 2");
        banco.Retirar(2, 5);
        cout << "Retiro realizado." << endl
             << endl;

        Titulo("Paso 6: Estado del banco");
        banco.Estado();
        cout << endl;

        Titulo("Paso 7: Borrar la cuenta 1");
        banco.BorrarCuenta(1);
        cout << "Cuenta 1 borrada." << endl
             << endl;

        Titulo("Paso 8: Estado del banco");
        banco.Estado();
        cout << endl;

        Titulo("Paso 9: Número de cuenta de María");
        int noCuenta = banco.ObtenerNoCuenta("María");
        cout << "Número de cuenta de María: " << noCuenta << endl
             << endl;

        Titulo("Paso 10: Saldo de la cuenta de María");
        double saldo = banco.ObtenerSaldo(noCuenta);
        cout << "Saldo de la cuenta de María: $" << saldo << endl;

        Cuenta::N = guardado;
    }
};

int main()
{
    Inicio inicio;
    inicio.Menu();
    return 0;
}