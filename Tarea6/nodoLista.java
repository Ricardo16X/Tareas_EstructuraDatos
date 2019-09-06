public class nodoLista {
	int codProducto;
	int stock;
	int min_stock;
	String codProveedor;
	nodoLista siguiente = null;

	public nodoLista() {
		// TODO Auto-generated constructor stub
	}

	public nodoLista(int _codProduct, int _stk, int _minstk, String _codProv) {
		// TODO Auto-generated constructor stub
		codProducto = _codProduct;
		stock = _stk;
		min_stock = _minstk;
		codProveedor = _codProv;
	}
}