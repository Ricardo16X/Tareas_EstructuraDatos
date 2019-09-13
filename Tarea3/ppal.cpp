#include <stdio.h>
#include <iostream>
#include <string>

struct actividad
{
    std::string accion = "";
    actividad *anterior = 0;
    actividad *siguiente = 0;
};

struct cabecera
{
    int numDia = 0;
    std::string dia = "";
    actividad *f_actividad = 0;

    cabecera *siguiente = 0;
} *primero = 0;

bool diaExiste(std::string dia, int *numDia);
bool cabeceraExiste(int dia);
cabecera *obtenerCabecera(int numDia);
void insertarCabecera(cabecera *nuevo);
void insertar(cabecera *temp, std::string accion);
void visualizar(cabecera *mirar);

int main(int argc, char const *argv[])
{
    /*CREACION DE CABECERAS Y ACTIVIDADES*/
    cabecera *nuevo = 0;

    int op = 0;
    std::string dia, accion;
    int numDia = 0;
    while (op != 3)
    {
        system("cls");
        std::cout << "1. INSERTAR" << std::endl;
        std::cout << "2. MOSTRAR" << std::endl;
        std::cout << "3. SALIR" << std::endl;
        fflush(stdin);
        std::cin >> op;
        switch (op)
        {
        case 1:
            std::cout << "INGRESE EL DIA EN minusculas SIN TILDE" << std::endl;
            fflush(stdin);
            std::getline(std::cin, dia, '\n');
            std::cout << "INGRESE LA ACTIVIDAD" << std::endl;
            fflush(stdin);
            std::getline(std::cin, accion, '\n');
            if (diaExiste(dia, &numDia))
            {
                if (!cabeceraExiste(numDia))
                {
                    nuevo = new cabecera();
                    nuevo->dia = dia;
                    nuevo->numDia = numDia;
                    insertarCabecera(nuevo);
                }
                insertar(obtenerCabecera(numDia), accion);
            }
            break;
        case 2:
            system("cls");
            std::cout << "1. INDIVIDUAL" << std::endl;
            std::cout << "2. TODA LA SEMANA" << std::endl;
            fflush(stdin);
            std::cin >> op;
            switch (op)
            {
            case 1:
                system("cls");
                std::cout << "INGRESE EL DIA DE LA SEMANA EN minusculas Y SIN TILDE" << std::endl;
                fflush(stdin);
                std::getline(std::cin, dia, '\n');
                if (diaExiste(dia, &numDia) && cabeceraExiste(numDia))
                {
                    visualizar(obtenerCabecera(numDia));
                }
                system("pause");
                break;
            case 2:
                system("cls");
                cabecera *temp = primero;
                while (temp != NULL)
                {
                    visualizar(temp);
                    std::cout << std::endl;
                    temp = temp->siguiente;
                }
                system("pause");
                break;
            }
            break;
        case 3:
            break;
        default:
            system("cls");
            std::cout << "\t\nOpcion Incorrecta, Elige una opcion del menu.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            system("pause");
            break;
        }
    }

    return 0;
}

bool diaExiste(std::string dia, int *numDia)
{
    if (dia == "lunes")
    {
        *numDia = 1;
        return true;
    }
    else if (dia == "martes")
    {
        *numDia = 2;
        return true;
    }
    else if (dia == "miercoles")
    {
        *numDia = 3;
        return true;
    }
    else if (dia == "jueves")
    {
        *numDia = 4;
        return true;
    }
    else if (dia == "viernes")
    {
        *numDia = 5;
        return true;
    }
    else if (dia == "sabado")
    {
        *numDia = 6;
        return true;
    }
    else if (dia == "domingo")
    {
        *numDia = 7;
        return true;
    }
    else
    {
        return false;
    }
}

bool cabeceraExiste(int dia)
{
    if (primero == NULL)
    {
        return false;
    }
    else
    {
        cabecera *temp = primero;
        while (temp != NULL)
        {
            if (dia == temp->numDia)
            {
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }
}

cabecera *obtenerCabecera(int numDia)
{
    cabecera *temp = primero;
    cabecera *retorno = 0;
    while (temp != NULL)
    {
        if (temp->numDia == numDia)
        {
            retorno = temp;
            break;
        }
        temp = temp->siguiente;
    }
    return retorno;
}

void insertarCabecera(cabecera *nuevo)
{
    cabecera *temp = primero;
    cabecera *anterior = 0;
    if (primero == NULL)
    {
        primero = nuevo;
    }
    else
    {
        while (temp->siguiente != NULL)
        {
            if (nuevo->numDia < temp->numDia)
            {
                if (temp == primero)
                {
                    nuevo->siguiente = primero;
                    primero = nuevo;
                    break;
                }
                else
                {
                    nuevo->siguiente = anterior->siguiente;
                    anterior->siguiente = nuevo;
                    break;
                }
            }
            anterior = temp;
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

void insertar(cabecera *temp, std::string accion)
{
    actividad *nuevo = new actividad();
    nuevo->accion = accion;

    if (temp->f_actividad == NULL)
    {
        temp->f_actividad = nuevo;
    }
    else
    {
        actividad *inicio = temp->f_actividad;
        while (inicio->siguiente != NULL)
        {
            inicio = inicio->siguiente;
        }
        inicio->siguiente = nuevo;
        nuevo->anterior = inicio;
    }
}

void visualizar(cabecera *mirar)
{
    actividad *inicio = mirar->f_actividad;
    std::cout << "ACTIVIDADES DEL DIA " << mirar->dia << std::endl;
    while (inicio != NULL)
    {
        std::cout << inicio->accion << std::endl;
        inicio = inicio->siguiente;
    }
}
