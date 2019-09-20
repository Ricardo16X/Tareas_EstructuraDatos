#include <iostream>
#include <string>
#include <stdlib.h>
#include "Lista.h"
#include "nodo.h"

int main(int argc, char const *argv[]) {
   Lista listita = Lista();
   listita.insertar(1);
   listita.insertar(2);
   listita.insertar(3);
   listita.insertar(4);
   listita.insertar(5);

   listita.mostrar();

   listita.borrar();

   listita.mostrar();

   system("pause");
   return 0;
}
