#ifndef NODO_H
#define NODO_H


class nodo {
   private:
      int dato;
   public:
      nodo(int _dato);
      nodo();
      ~nodo();
      nodo* siguiente = 0;
      nodo* primero = 0;
      nodo* ultimo = 0;
      int getDato() {
         return dato;
      }
};

nodo::nodo(int _dato) {
   dato = _dato;
}
nodo::nodo() {

}

nodo::~nodo() {
}

#endif // NODO_H
