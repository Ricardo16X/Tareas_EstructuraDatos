public class T2_Ejercicio1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// Bolsa "Manejador"
		Bolsa elementoBolsa = new Bolsa();
		// Bolsa 1 tendrá contenido diferente
		Bolsa bolsa1 = new Bolsa();
		elementoBolsa.insertar(bolsa1, "Sandía");
		elementoBolsa.insertar(bolsa1, "Manzana");
		elementoBolsa.insertar(bolsa1, "Pera");
		elementoBolsa.insertar(bolsa1, "Piña");
		// Bolsa 2 tendrá contenido repetido
		Bolsa bolsa2 = new Bolsa();
		elementoBolsa.insertar(bolsa2, "Manzana");
		elementoBolsa.insertar(bolsa2, "Manzana");
		elementoBolsa.insertar(bolsa2, "Pera");
		elementoBolsa.insertar(bolsa2, "Pera");
		// Bolsa 3 no tendrá contenido
		Bolsa bolsa3 = new Bolsa();
		System.out.println("La bolsa está vacia? " + elementoBolsa.esVacia(bolsa3));
	}
	// Clase Bolsa
	static class Bolsa{
		// Elemento de la bolsa
		Object elemento;
		// Lista
		Elemento ancla;
		Elemento trabajo;
		// Constructor de Bolsa
		public Bolsa() {
			ancla = new Elemento();
			ancla.siguiente = null;
		}
		
		// Métodos de bolsa
		public boolean esVacia(Bolsa bolsita) {
			trabajo = bolsita.ancla;
			return trabajo.siguiente == null;
		}
		
		public int cuantos(Bolsa bolsita, Object elemento) {
			
			return 0;
		}
		
		public Bolsa insertar(Bolsa bolsita, Object elemento) {
			if (elemento != null) {
				Elemento tempElemento = new Elemento();
				trabajo = bolsita.ancla;
				while (trabajo.siguiente != null) {
					trabajo = trabajo.siguiente;
				}
				tempElemento.elemento = elemento;
				tempElemento.siguiente = null;
				trabajo.siguiente = tempElemento;
				// Lo veo extraño devolver un objeto tipo Bolsa
				return bolsita;
			}else {
				return null;
			}
		}
	}
	
	static class Elemento{
		private Object elemento;
		private Elemento siguiente;

		public Object getElemento() {
			return elemento;
		}

		public void setElemento(Object elemento) {
			this.elemento = elemento;
		}
	}
}
