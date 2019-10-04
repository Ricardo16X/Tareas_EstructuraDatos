import os


class nodo:
    def __init__(self, valor):
        self.dato = valor
        self.siguiente = None
        self.anterior = None


class lDoble:
    def __init__(self):
        self.ancla = None
        self.ultimo = None

    def insert(self, valor):
        if(self.ancla is None)
        nuevoNodo = nodo(valor)
        self.ancla = self.ultimo = nuevoNodo
        else:
            nuevoNodo = nodo(valor)
