public class tarea {
	public static void main(String[] args) {
		Lista listaCopia = new Lista();
		Lista listaOriginal = new Lista();
		listaOriginal.agregar(new nodoLista(2, 1000, 200, "prov2"));
		listaOriginal.agregar(new nodoLista(789, 20, 200, "prov3"));
		listaOriginal.agregar(new nodoLista(32782, 900, 200, "prov4"));
		listaOriginal.agregar(new nodoLista(21, 110, 200, "prov5"));
		listaOriginal.agregar(new nodoLista(101, 1000, 200, "prov6"));
		

		listaOriginal.copiar(listaOriginal, listaCopia);
		listaOriginal.ver();
		listaCopia.ver();

		listaOriginal.eliminar();
		listaCopia.eliminar();

		listaOriginal.ver();
		listaCopia.ver();
	}
}