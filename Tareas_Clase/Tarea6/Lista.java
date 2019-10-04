public class Lista {
	nodoLista primero;

	public Lista() {
		// TODO Auto-generated constructor stub
		nodoLista listita = new nodoLista();
		listita.siguiente = null;
	}

	public void agregar(nodoLista nuevoNodo) {
		nodoLista tempLista = primero;
		if (tempLista == null) {
			tempLista = nuevoNodo;
		} else {
			while (tempLista.siguiente != null) {
				tempLista = tempLista.siguiente;
			}
			tempLista.siguiente = nuevoNodo;
		}
	}

	public void copiar(Lista original, Lista destino) {
		nodoLista tempLista = original.primero;
		/* Copiar los nodolista siempre y cuando stock < stock_min */
		while (tempLista != null) {
			if (tempLista.stock < tempLista.min_stock) {
				destino.agregar(tempLista);
			}
			tempLista = tempLista.siguiente;
		}
	}

	public void eliminar() {
		nodoLista temp = primero;
		nodoLista anterior = null;
		while (temp != null) {
			// Eliminar solo si el codigo de producto es > 100
			if (temp.codProducto > 100) {
				if (temp == primero) {
					primero = temp.siguiente;
					temp.siguiente = null;
				} else {
					anterior.siguiente = temp.siguiente;
					temp.siguiente = null;
				}
			}
			anterior = temp;
			temp = temp.siguiente;
		}
	}

	public void ver() {
		nodoLista temp = primero;
		while (temp != null) {
			System.out.println("---------------------------------");
			System.out.println("Cod. Producto = " + temp.codProducto);
			System.out.println("Stock = " + temp.stock);
			System.out.println("Min Stock = " + temp.min_stock);
			System.out.println("Cod. Proveedor = " + temp.codProveedor);
		}
	}
}