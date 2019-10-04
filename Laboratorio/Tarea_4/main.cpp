#include <iostream>

class nodoArbol
{
private:
  int dato = 0;
  nodoArbol* der = NULL;
  nodoArbol* izq = NULL;

public:
  nodoArbol();
  ~nodoArbol();
  int getDato() { return dato; }
  void setDato(int _dato) { dato = _dato; }
  nodoArbol* get_Izq() { return izq; }
  void set_Izq(nodoArbol* nodo) { izq = nodo; }
  nodoArbol* get_Der() { return der; }
  void set_Der(nodoArbol* nodo) { der = nodo; }
};

nodoArbol::nodoArbol()
{
  dato = 0;
  izq = NULL;
  der = NULL;
}

nodoArbol::~nodoArbol() {}

class Arbol
{
private:
  nodoArbol* raiz;
  nodoArbol* trabajo;

public:
  Arbol();
  ~Arbol();
  bool encontrado = false;
  nodoArbol* getRaiz() { return raiz; }

  void setRaiz(nodoArbol* nodo) { raiz = nodo; }

  /*Método para insertar un nuevo valor al árbol*/
  nodoArbol* Insertar(int dato, nodoArbol* nodo)
  {
    nodoArbol* temp = NULL;
    // Si no hay a quién insertar entonces creamos el nodo.
    if (nodo == NULL) {
      temp = new nodoArbol();
      temp->setDato(dato);
      return temp;
    }
    // Si el dato es menor
    if (dato < nodo->getDato()) {
      nodo->set_Izq(Insertar(dato, nodo->get_Izq()));
    }
    // Si el dato es mayor
    if (dato > nodo->getDato()) {
      nodo->set_Der(Insertar(dato, nodo->get_Der()));
    }
    return nodo;
  }

  bool Buscar(int dato, nodoArbol* nodo)
  {
    if (dato < nodo->getDato()) {
      // Si mi dato a buscar, es menor al dato actual
      // Busco en el subarbol izquierdo.
      if (nodo->get_Izq() != NULL) {
        Buscar(dato, nodo->get_Izq());
      }
    } else if (dato > nodo->getDato()) {
      /*Si mi dato a buscar, es mayor al dato
      actual busco en el sub arbol derecho*/
      if (nodo->get_Der() != NULL) {
        Buscar(dato, nodo->get_Der());
      }
    } else if (dato == nodo->getDato()) {
      /*Si mi dato a buscar, es igual al dato actual
      entonces significa que he encontrado el valor
      o el nodo, por lo tanto encontrado es true*/
      encontrado = true;
      return encontrado;
    }
    /*retorno la variable encontrado
    que me indica si he encontrado en el arbol
    el valor ingresado*/
    return encontrado;
  }

  nodoArbol* Padre(int hijo, nodoArbol* nodo_raiz)
  {
    if (hijo < nodo_raiz->getDato()) {
      if (nodo_raiz->get_Izq()->getDato() == hijo) {
        // He encontrado al padre
        trabajo = nodo_raiz;
      } else {
        trabajo = Padre(hijo, nodo_raiz->get_Izq());
      }
    } else if (hijo > nodo_raiz->getDato()) {
      if (nodo_raiz->get_Der()->getDato() == hijo) {
        trabajo = nodo_raiz;
      } else {
        trabajo = Padre(hijo, nodo_raiz->get_Der());
      }
    } else if (nodo_raiz->getDato() == hijo) {
      return nodo_raiz;
    }
    return trabajo;
  }

  nodoArbol* Menor(nodoArbol* nodo)
  {
    try {
      trabajo = nodo;
      if (trabajo == NULL) {
        return trabajo;
      }
      /*Si tengo hijos a la izquierda, me voy a la izquierda*/
      if (trabajo->get_Izq() != NULL) {
        trabajo = Menor(trabajo->get_Izq());
      }
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    return trabajo;
  }

  void Borrar(int dato, nodoArbol* nodo)
  {
    /*En el procedimiento de borrar
    buscaremos el nodo para luego eliminarlo
    del arbol*/
    if (dato < nodo->getDato()) {
      /*Si mi dato es inferior al dato actual
      entonces sere dirigido al sub arbol izquierdo*/
      Borrar(dato, nodo->get_Izq());
    } else if (dato > nodo->getDato()) {
      /*Si mi dato es superior al dato actual
      entonces sere dirigido al sub arbol derecho*/
      Borrar(dato, nodo->get_Der());
    } else {
      /*En este **else** hemos encontrado el nodo
      hay varios casos en los cuales tratar
      para eliminar un nodo.*/

      /*El primer caso tiene que ver con las hojas del arbol
      Si el dato se encuentra en una hoja
      Tanto su nodo hijo izquierdo, como nodo hijo derecho
      seran nulos*/
      if (nodo->get_Izq() == NULL && nodo->get_Der() == NULL) {
        /*Se utilizará el metodo padre, para buscar el padre de la
        hoja a eliminar.
        */
        trabajo = Padre(dato, getRaiz());
        if (dato < trabajo->getDato()) {
          /*En este paso estamos eliminando el hijo izquierdo del padre
          el cual seria una hoja izquierda al final del arbol*/
          delete trabajo->get_Izq();
        } else {
          /*En este paso estamos eliminando el hijo derecho del padre
          el cual seria una hoja derecho al final del arbol*/
          delete trabajo->get_Der();
        }
      }

      /*El segundo caso tiene que ver si se está borrando
      el hijo derecho de un nodo en un nivel intermedio*/
      else if (nodo->get_Der() != NULL && nodo->get_Izq() == NULL) {
        /*Obtengo el padre o la raiz del sub arbol*/
        trabajo = Padre(dato, getRaiz());
        if (dato < trabajo->getDato()) {
          /*Aqui establezco que mi nuevo hijo izquierdo
          será el nodo derecho del padre eliminado.*/
          trabajo->set_Izq(nodo->get_Der());
        } else {
          /*Aqui establezco que mi nuevo hijo derecho
          será el nodo derecho del padre eliminado.*/
          trabajo->set_Der(nodo->get_Der());
        }
      }
      /*Este tercer caso es similar al anterior, solo que esta vez
      se está eliminando el hijo izquierdo de un nodo en un nivel intermedio*/
      else if (nodo->get_Der() == NULL && nodo->get_Izq() != NULL) {
        trabajo = Padre(dato, getRaiz());
        if (dato > trabajo->getDato()) {
          /*Aqui establezco que mi nuevo hijo derecho
          será el nodo izquierdo del padre eliminado.*/
          trabajo->set_Der(nodo->get_Izq());
        } else {
          /*Aqui establezco que mi nuevo hijo izquierdo
          será el nodo izquierdo del padre eliminado.*/
          trabajo->set_Izq(nodo->get_Izq());
        }
        delete trabajo;
        trabajo = nullptr;

      }
      /*En este ultimo caso, borramos un nodo, pero este nodo tiene la
      particularidad de que tiene 2 hijos, por lo tanto se seguirá de una manera
      distinta a las anteriores.
      El proceso será reacomodar todos los nodos del arbol, de tal forma, que el
      arbol siga siendo binario de busqueda...s*/
      else if (nodo->get_Izq() != NULL && nodo->get_Der() != NULL) {
        // Se usará la funcion menor, para encontrar el valor menor, desde el
        // sub arbol derecho del nodo a borrar.
        trabajo = Menor(nodo->get_Der());
        // Aqui obtengo el dato menor del sub arbol de la raiz que se desea
        // eliminar
        int menor = trabajo->getDato();
        // Borro el nodo padre
        Borrar(menor, nodo);
        // El nodo actual, que se ha quedado después del borrado del padre
        // Obtendrá el valor del menor encontrado en el sub arbol anterior
        nodo->setDato(menor);
        delete trabajo;
      }
    }
  }

  void PreOrder(nodoArbol* raiz)
  {
    if (raiz != NULL) {
      std::cout << std::to_string(raiz->getDato()) << std::endl;
      PreOrder(raiz->get_Izq());
      PreOrder(raiz->get_Der());
    }
  }
};

Arbol::Arbol()
{
  raiz = NULL;
}

Arbol::~Arbol() {}

void p(std::string);

int
main(int argc, char const* argv[])
{
  Arbol arbol = Arbol();
  nodoArbol* raiz = 0;

  int op = 0;
  int dato = 0;
  while (op != 3) {
    p("1. Insertar");
    p("2. Borrar");
    p("3. Terminar");
    fflush(stdin);
    std::cin >> op;
    switch (op) {
      case 1:
        system("cls");
        p("Ingrese el dato a insertar: ");
        fflush(stdin);
        try {
          std::cin >> dato;
          if (raiz == NULL) {
            raiz = arbol.Insertar(dato, NULL);
            arbol.setRaiz(raiz);
          } else {
            arbol.Insertar(dato, raiz);
          }
          arbol.PreOrder(raiz);
        } catch (...) {
          p("verifica que el dato ingresado sea un numero:::");
          system("pause");
        }
        break;
      case 2:
        system("cls");
        if (raiz == NULL) {
          p("NO SE PUEDE BORRAR NADA ya que no hay elementos en el arbol.");
        } else {

          try {
            p("Ingresa el dato a borrar");
            fflush(stdin);
            std::cin >> dato;
            if (arbol.Buscar(dato, raiz) == true) {
              arbol.Borrar(dato, raiz);
              p("dato " + std::to_string(dato) +
                "ha sido borrado... del arbol");
              p("Datos en arbol: ");
              arbol.PreOrder(raiz);
              p("");
            } else {
              p("No se encontró el dato para ser borrado...");
            }
          } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
          }
        }
        break;
      case 3:
        break;
      default:
        p("Error en el ingreso de opcion.");
        break;
    }
  }

  p("datos en arbol final");
  arbol.PreOrder(raiz);
  system("pause");
  return 0;
}

void
p(std::string cadena)
{
  std::cout << cadena << std::endl;
}