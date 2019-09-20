#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class Lista {
   private:
      nodo nuevo = nodo();
   public:
      Lista();
      ~Lista();
      void insertar(int _dato) {
         if(nuevo.primero == NULL) {
            nuevo.primero = nuevo.ultimo = new nodo(_dato);
         } else {
            nodo* aux = nuevo.ultimo;
            aux->siguiente = new nodo(_dato);
            nuevo.ultimo = aux->siguiente;
         }
      }

      void mostrar() {
         nodo* aux = nuevo.primero;
         if(aux == NULL) {
            std::cout << "SIN DATOS" << std::endl;
         } else {
            while (aux != NULL) {
               std::cout << aux->getDato() << std::endl;
               aux = aux->siguiente;
            }
         }
      }

      void borrar() {
        nodo* aux = 0;
        while(nuevo.primero != NULL){
            aux = nuevo.primero;
            nuevo.primero = aux->siguiente;
            delete aux;
        }
      }
};

Lista::Lista() {
}

Lista::~Lista() {
}


#endif // LISTA_H
