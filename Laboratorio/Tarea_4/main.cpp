#include <iostream>

class nodoArbol
{
private:
    int dato = 0;
    nodoArbol *der = NULL;
    nodoArbol *izq = NULL;
public:
    nodoArbol();
    ~nodoArbol();
    int getDato(){
        return dato;
    }
    void setDato(int _dato){
        dato = _dato;
    }
    nodoArbol* get_Izq(){
        return izq;
    }
    void set_Izq(nodoArbol* nodo){
        izq = nodo;
    }
    nodoArbol* get_Der(){
        return der;
    }
    void set_Der(nodoArbol* nodo){
        der = nodo;
    }
};

nodoArbol::nodoArbol()
{
    dato = 0;
    izq = NULL;
    der = NULL;
}

nodoArbol::~nodoArbol()
{
}

class Arbol
{
private:
    nodoArbol* raiz;
    nodoArbol* trabajo;
public:
    Arbol();
    ~Arbol();

    nodoArbol* getRaiz(){
        return raiz;
    }

    void setRaiz(nodoArbol* nodo){
        raiz = nodo;
    }

    /*Método para insertar un nuevo valor al árbol*/
    nodoArbol* Insertar(int dato, nodoArbol* nodo){
        nodoArbol* temp = NULL;
        // Si no hay a quién insertar entonces creamos el nodo.
        if(nodo == NULL){
            temp = new nodoArbol();
            temp->setDato(dato);

            return temp;
        }
        // Si el dato es menor
        if (dato < nodo->getDato()){
            nodo->set_Izq(Insertar(dato, nodo->get_Izq()));
        }
        // Si el dato es mayor
        if(dato > nodo->getDato()){
            nodo->set_Der(Insertar(dato, nodo->get_Der()));
        }
        return nodo;
    }

    bool Buscar(int dato, nodoArbol* nodo){
        bool encontrado = false;
        // Si mi dato a buscar, es menor al dato actual
        // Busco en el subarbol izquierdo.
        if (dato < nodo->getDato()){
            Buscar(dato, nodo->get_Izq());
            /*Si mi dato a buscar, es mayor al dato actual
        busco en el sub arbol derecho*/
        }else if (dato > nodo->getDato())
        {
            Buscar(dato, nodo->get_Der());
            /*Si mi dato a buscar, es igual al dato actual
            entonces significa que he encontrado el valor
            o el nodo, por lo tanto encontrado es true*/
        }else if(dato == nodo->getDato()){
            encontrado = true;
        }
        /*retorno la variable encontrado
        que me indica si he encontrado en el arbol
        el valor ingresado*/
        return encontrado;
    }

    nodoArbol* Padre(int hijo, nodoArbol* nodo_raiz){
        if (hijo < nodo_raiz->getDato())
            {
                if (nodo_raiz->get_Izq()->getDato() == hijo)
                {
                    // He encontrado al padre
                    trabajo = nodo_raiz;
                }
                else
                {
                    Padre(hijo, nodo_raiz->get_Izq());
                }
            }
            else if (hijo > nodo_raiz->getDato())
            {
                if (nodo_raiz->get_Der()->getDato() == hijo)
                {
                    trabajo = nodo_raiz;
                }
                else
                {
                    Padre(hijo, nodo_raiz->get_Der());
                }
            }
            else if (nodo_raiz->getDato() == hijo)
            {
                return nodo_raiz;
            }
            return trabajo;
    }

    nodoArbol* Menor(nodoArbol* nodo){
        try
        {
            trabajo = nodo;
            if(trabajo == NULL){return trabajo;}
            /*Si tengo hijos a la izquierda, me voy a la izquierda*/
            if(trabajo->get_Izq() != NULL){ trabajo = Menor(trabajo->get_Izq()); }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return trabajo;
    }

    void Borrar(int dato, nodoArbol* nodo){
        /*En el procedimiento de borrar
        buscaremos el nodo para luego eliminarlo
        del arbol*/
        if (dato < nodo->getDato())
        {
            Borrar(dato, nodo->get_Izq());
        }else if(dato > nodo->getDato()){
            Borrar(dato, nodo->get_Der());
        }else{
            /*En este **else** hemos encontrado el nodo
            hay varios casos en los cuales tratar
            para eliminar un nodo.*/

            /*El primer caso tiene que ver con las hojas del arbol
            Si el dato se encuentra en una hoja
            Tanto su nodo hijo izquierdo, como nodo hijo derecho
            seran nulos*/
            if (nodo->get_Izq() == NULL && nodo->get_Der() == NULL)
            {
                /*Se utilizará el metodo padre, para enlazar nuevamente 
                los nodos anteriores a la hoja*/
                trabajo = Padre(dato, getRaiz());
                if (dato < trabajo->getDato())
                {
                    delete trabajo->get_Izq();
                }else{
                    delete trabajo->get_Der();
                }
                delete trabajo;
                trabajo = nullptr;
            }
            /*El segundo caso tiene que ver si se está borrando
            el hijo derecho de un nodo en un nivel intermedio*/
            else if(nodo->get_Der() != NULL && nodo->get_Izq() == NULL){
                trabajo = Padre(dato, getRaiz());
                if (dato < trabajo->getDato())
                {
                    trabajo->set_Izq(nodo->get_Der());
                }else{
                    trabajo->set_Der(nodo->get_Der());
                }
                delete trabajo;
                trabajo = nullptr;
            }
            /*Este tercer caso es similar al anterior, solo que esta vez
            se está eliminando el hijo izquierdo de un nodo en un nivel intermedio*/
            else if (nodo->get_Der() == NULL && nodo->get_Izq() != NULL)
            {
                trabajo = Padre(dato, getRaiz());
                if (dato > trabajo->getDato())
                {
                    trabajo->set_Der(nodo->get_Izq());
                }else{
                    trabajo->set_Izq(nodo->get_Izq());
                }
                delete trabajo;
                trabajo = nullptr;
            /*En este ultimo caso, borramos un nodo, pero este nodo tiene la particularidad
            de que tiene 2 hijos, por lo tanto se seguirá de una manera distinta
            a las anteriores.*/
            }else if (nodo->get_Izq() != NULL && nodo->get_Der() != NULL){
                // Se usará la funcion menor, para encontrar el valor menor, desde el sub arbol derecho del nodo a borrar.
                trabajo = Menor(nodo->get_Der());
                int menor = trabajo->getDato();
                Borrar(menor, nodo);
                nodo->setDato(menor);
                delete trabajo;
            }
        }
    }
};

Arbol::Arbol()
{
    raiz = NULL;
}

Arbol::~Arbol()
{
}



int main(int argc, char const *argv[])
{
    Arbol *arbol = new Arbol();
    nodoArbol *raiz = arbol->Insertar(6, NULL);
    arbol->setRaiz(raiz);
    
    return 0;
}
