import os

class Nodo:
    def __init__(self, valor):
        self.dato = valor
        self.siguiente = None
        self.anterior = None

class listaDoble:
    
    contadorResultados = 0

    def __init__(self):
        self.ancla = None

    def insertar_inicio(self, valor):
        if self.ancla is None:
            #Esto me quiere decir que es el primer dato
            nuevoNodo = Nodo(valor)
            self.ancla = nuevoNodo
            self.ancla.siguiente = None
        else:
            #OK entonces si hay datos
            nuevoNodo = Nodo(valor)
            viejo = self.ancla
            self.ancla = nuevoNodo
            viejo.anterior = self.ancla
            self.ancla.siguiente = viejo

    def insertar_final(self,valor):
        if self.ancla is None:
            #Esto me quiere decir que es el primer dato
            nuevoNodo = Nodo(valor)
            self.ancla = nuevoNodo
            self.ancla.siguiente = None
        else:
            temporal = self.ancla
            while temporal.siguiente is not None:
                temporal = temporal.siguiente
            
            nuevoNodo = Nodo(valor)
            nuevoNodo.siguiente = None
            temporal.siguiente = nuevoNodo
            nuevoNodo.anterior = temporal

    def insertar_pos(self, index, valor):
        temporal = self.ancla
        contador = 0
        anterior = None
        actual = None
        if index is 0:
            self.insertar_inicio(valor)
        else:
            while temporal.siguiente is not None:
                temporal = temporal.siguiente
                contador = contador + 1
            
            if contador is index:
                self.insertar_final(valor)
            elif index <= contador and index > 0:
                contador = 0
                temporal = self.ancla
                while temporal.siguiente is not None and contador is not index:
                    anterior = temporal
                    temporal = temporal.siguiente
                    contador = contador + 1
                    actual = temporal
                
                nuevoNodo = Nodo(valor)
                anterior.siguiente = nuevoNodo
                actual.anterior = nuevoNodo
                nuevoNodo.anterior = anterior
                nuevoNodo.siguiente = actual

    def obtener_pos(self, index):
        contador = 0
        temporal = self.ancla

        while temporal.siguiente is not None:
            temporal = temporal.siguiente
            contador = contador + 1
        
        if index >= 0 and index <= contador:
            contador = 0
            temporal = self.ancla
            while temporal.siguiente is not None and contador is not index:
                temporal = temporal.siguiente
                contador = contador + 1
            
            return temporal.dato

    def eliminar(self, index):
        contador = 0
        temporal = self.ancla
        anterior = None
        actual = None
        while temporal.siguiente is not None:
            anterior = temporal
            temporal = temporal.siguiente
            contador = contador + 1
        
        if index >= 0 and index <= contador:
            if index == 0:
                nuevoAncla = self.ancla.siguiente
                nuevoAncla.anterior = None
                self.ancla = nuevoAncla
            elif contador == index:
                anterior.siguiente = None
                temporal.anterior = None
            else:
                contador = 0
                temporal = self.ancla
                while temporal.siguiente is not None and contador is not index:
                    anterior = temporal
                    temporal = temporal.siguiente
                    contador = contador + 1
                    actual = temporal
                
                nuevoEnlace = actual.siguiente
                #Desenlazo a actual
                actual.anterior = None
                actual.siguiente = None
                #Enlazo anterior con el nuevo enlace, que es el siguiente del actual
                anterior.siguiente = nuevoEnlace
                nuevoEnlace.anterior = anterior

    def graficar(self):

        self.contadorResultados = self.contadorResultados + 1
        archivoNombre = "resultadoNo" + str(self.contadorResultados) + ".jpg"

        archivoNuevo = open("listaDoble.dot","w")
        archivoNuevo.write("digraph G{\n")
        archivoNuevo.write("rankdir = \"LR\"\n")
        archivoNuevo.write("node [shape = square];\n")
        temporal = self.ancla
        cadena = ""

        while temporal.siguiente is not None:
                cadena = cadena + str(temporal.dato) + " -> " + str(temporal.siguiente.dato) + "\n" + str(temporal.siguiente.dato) + " -> " + str(temporal.dato) + "\n"
                archivoNuevo.write(str(temporal.dato) + " -> " + str(temporal.siguiente.dato) + "\n")
                archivoNuevo.write(str(temporal.siguiente.dato) + " -> " + str(temporal.dato) + "\n")
                temporal = temporal.siguiente
        
        archivoNuevo.write("}")
        archivoNuevo.close()
        os.system("dot -Tjpg listaDoble.dot -o " + archivoNombre)