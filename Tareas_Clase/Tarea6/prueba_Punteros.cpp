#include <iostream>
#include <string>

struct elemento
{
    int dato;
    elemento *siguiente = 0;
    elemento(int _item)
    {
        dato = _item;
    }
};

struct contenedor
{
    std::string nombre;
    elemento *primerElemento = 0;
    // Puntero a si mismo.
    contenedor* izq = 0;
    contenedor* der = 0;
    contenedor(std::string _nombre)
    {
        nombre = _nombre;
    }
} *primerCont = 0;

void agregarContenedor(contenedor *cont, contenedor *raiz);
void agregarElemento(contenedor *cont, int item);
void mostrarContenedor(contenedor *cont);
void mostrarRaiz(contenedor*);

int main(int argc, char const *argv[])
{

    contenedor *nuevo = new contenedor("Contenedor 20");
    contenedor *nuevo2 = new contenedor("Contenedor 2");
    contenedor *nuevo3 = new contenedor("Contenedor 30");

    agregarContenedor(nuevo, primerCont);
    agregarContenedor(nuevo2, primerCont);
    agregarContenedor(nuevo3, primerCont);
    
    agregarElemento(nuevo,1);
    agregarElemento(nuevo,3);
    agregarElemento(nuevo,5);

    agregarElemento(nuevo2,1);
    agregarElemento(nuevo2,6);
    agregarElemento(nuevo2,9);
    agregarElemento(nuevo2,10);

    agregarElemento(nuevo3,10);
    agregarElemento(nuevo3,100);
    agregarElemento(nuevo3,1000);
    
    mostrarContenedor(nuevo);
    mostrarContenedor(nuevo2);
    mostrarContenedor(nuevo3);


    mostrarRaiz(primerCont);

    return 0;
}

/*Métodos para el contenedor*/
void agregarContenedor(contenedor *cont, contenedor *raiz)
{
    if (raiz == NULL)
    {
        // Si se llega al punto en dónde el nodo del arbol no
        // apunta a nada, allí se colocará la nueva imagen.
        if(primerCont == NULL)
        {
            primerCont = cont;
        }
        raiz = cont;
        std::cout << raiz->nombre << std::endl;
        std::cout << cont->nombre<<std::endl;
    }
    else if (cont->nombre.compare(raiz->nombre) > 0)
    {
        // Si el nombre de la nueva imagen es < al de la raiz, se coloca a
        // la izquierda de la raiz.
        agregarContenedor(cont, raiz->der);
    }
    else if (cont->nombre.compare(raiz->nombre) < 0)
    {
        // Si el nombre de la nueva imagen es > al de la raiz, se
        // coloca a la derecha de la raiz.
        agregarContenedor(cont, raiz->izq);
    }
}

void agregarElemento(contenedor *cont, int item)
{
    elemento* nuevoElemento = new elemento(item);
    if (cont->primerElemento == NULL)
    {
        cont->primerElemento = nuevoElemento;
    }
    else
    {
        elemento *primerItem = cont->primerElemento;
        while (primerItem->siguiente != NULL)
        {
            primerItem = primerItem->siguiente;
        }
        primerItem->siguiente = nuevoElemento;
    }
}

void mostrarContenedor(contenedor *cont)
{
    elemento *tempEle = cont->primerElemento;
    while (tempEle != NULL)
    {
        std::cout << "Dato -> " << tempEle->dato << std::endl;
        tempEle = tempEle->siguiente;
    }
}

void mostrarRaiz(contenedor* raiz){
    if (raiz != NULL)
    {
        mostrarRaiz(raiz->izq);
        std::cout << "* " << raiz->nombre << " " << std::endl;
        mostrarRaiz(raiz->der);
    }
}