import java.util.Scanner;

import jdk.internal.dynalink.beans.StaticClass;

public class T2_Ejercicio1 {

	static int numeroBolsa = 0;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// Variables de lectura
		int opcion = 0;
		String entradaTeclado = "";
		Scanner lectura = new Scanner(System.in);

		// Variables de verificaci�n
		int cantidad = 0;
		// Variable temporal para la bolsa, al operar sobre ella
		nodoBolsa temporal = null;
		// Creando la lista inicial de bolsas
		listaBolsa listitaBolsa = new listaBolsa();

		/*
		 * ------------PRUEBAS----------------- listitaBolsa.bolsaVacia(new
		 * nodoBolsa()); listitaBolsa.bolsaVacia(new nodoBolsa());
		 * listitaBolsa.bolsaVacia(new nodoBolsa()); listitaBolsa.bolsaVacia(new
		 * nodoBolsa()); listitaBolsa.bolsaVacia(new nodoBolsa());
		 * 
		 * nodoBolsa bolsa1 = listitaBolsa.obtenerBolsa(1);
		 * System.out.println(listitaBolsa.esVacia(bolsa1));
		 * listitaBolsa.insertar(bolsa1, "Elemento 1");
		 * System.out.println(listitaBolsa.esVacia(bolsa1));
		 * listitaBolsa.insertar(bolsa1, "Elemento 2"); listitaBolsa.insertar(bolsa1,
		 * "Elemento 3");
		 */

		// crear un menu inicial
		while (opcion != 3) {
			System.out.println(
					"Menu Inicial\n" + "1. Crear una nueva Bolsa\n" + "2. Elegir Bolsa\n" + "3. Salir Aplicacion");
			opcion = lectura.nextInt();
			// Verificando la opci�n elegida
			switch (opcion) {
			case 1:
				listitaBolsa.bolsaVacia(new nodoBolsa());
				break;
			case 2:
				cantidad = listitaBolsa.cantidadBolsas();
				if (cantidad > 0) {
					opcion = 0;
					while (opcion <= 0 | opcion > cantidad) {
						System.out.println(listitaBolsa.mostrarBolsas());
						opcion = lectura.nextInt();
					}
					// Aqui paso como par�metro el numero de bolsa elegida
					temporal = listitaBolsa.obtenerBolsa(opcion);
					// Una vez obtenida la bolsa a trabajar,proceso a preguntar que desea hacer
					// Menu de acciones para la bolsa elegida
					opcion = 0;
					while (opcion != 4) {
						System.out.println("Menu Bolsa\n" + "1. Insertar\n" + "2. Contar Elementos\n"
								+ "3. Verificar Vacio\n" + "4. Regresar");
						try {
							opcion = lectura.nextInt();
							switch (opcion) {
							case 1:
								// Basicamente, solo se pueden insertar Strings
								System.out.println("Ingrese el nombre del elemento");
								try {
									entradaTeclado = lectura.next();
									listitaBolsa.insertar(temporal, entradaTeclado);
								} catch (Exception e) {
									// TODO: handle exception
									System.out.println("Error :| " + e.getMessage());
								}
								break;
							case 2:
								System.out.println("Ingrese nombre de elemento a contar");
								try {
									entradaTeclado = lectura.next();
									listitaBolsa.cuantos(temporal, entradaTeclado);
								} catch (Exception e) {
									// TODO: handle exception
									System.out.println("Error :| " + e.getMessage());
								}
								break;
							case 3:
								if (listitaBolsa.esVacia(temporal)) {
									System.out.println("La bolsa " + temporal.numero + " est� vac�o.\n");
								} else {
									System.out.println("La bolsa " + temporal.numero + " no est� vac�o.\n");
								}
								break;
							default:
								break;
							}
						} catch (Exception e) {
							// TODO: handle exception
							System.out.println("Error :| " + e.getMessage());
						}
					}
				}
				break;
			default:
				break;
			}
		}
	}

	static class listaBolsa {
		// La lista de bolsas contendr�n bolsas
		// las bolsas ser�n los nodoBolsa
		nodoBolsa anclaBolsa;
		nodoBolsa trabajoBolsa;
		nodoElemento trabajoElemento;

		public listaBolsa() {
			// TODO Auto-generated constructor stub
			anclaBolsa = new nodoBolsa();
			anclaBolsa.siguienteBolsa = null;
			// Con esto digo que cada bolsa
			// contendr� una lista de elementos...
			anclaBolsa.listaElemento = new listaElemento();
		}

		/*--------------------METODOS DE LA TAREA--------------------*/
		// M�todo de comprobacion de bolsa vacia...
		public boolean esVacia(nodoBolsa bolsita) {
			try {
				trabajoElemento = bolsita.listaElemento.anclaElemento;
			} catch (Exception e) {
				// TODO: handle exception
				return true;
			}
			return trabajoElemento.siguientElemento == null;
		}

		// M�todo para crear una nueva bolsa y agregarla en la lista de bolsas.
		public void bolsaVacia(nodoBolsa bolsita) {
			trabajoBolsa = anclaBolsa;
			while (trabajoBolsa.siguienteBolsa != null) {
				trabajoBolsa = trabajoBolsa.siguienteBolsa;
			}
			try {
				bolsita.siguienteBolsa = null;
				trabajoBolsa.siguienteBolsa = bolsita;
			} catch (Exception e) {
				// TODO: handle exception
				System.out.println("Error al insertar Bolsa " + e.getMessage());
			}
		}

		// M�todo para insertar un elemento en cierta bolsa
		public nodoBolsa insertar(nodoBolsa bolsita, Object elemento) {
			if (elemento != null & bolsita != null) {
				try {
					nodoElemento tempElemento = new nodoElemento();
					trabajoElemento = bolsita.listaElemento.anclaElemento;
					while (trabajoElemento.siguientElemento != null) {
						trabajoElemento = trabajoElemento.siguientElemento;
					}
					tempElemento.elemento = elemento;
					tempElemento.siguientElemento = null;
					trabajoElemento.siguientElemento = tempElemento;
				} catch (Exception e) {
					// TODO: handle exception
					System.out.println("Error, " + e.getMessage());
				} // Lo veo extra�o devolver un objeto tipo Bolsa
				return bolsita;
			} else {
				return null;
			}
		}

		// M�todo que cuenta cu�ntos elementos de "cierto tipo" hay en la bolsa
		public int cuantos(nodoBolsa bolsita, Object elemento) {
			// Contador
			int contador = 0;
			// El objeto elemento lo comparar� con elementos string
			// ejemplo elemento.toString() con cada elemento de bolsita
			trabajoElemento = bolsita.listaElemento.anclaElemento;
			while (trabajoElemento.siguientElemento != null) {
				trabajoElemento = trabajoElemento.siguientElemento;
				// Si el "elemento" de la bolsa, coincide con el "elemento" por par�metro
				// Aumentar� en 1 el contador de elementos coincidentes.
				if (trabajoElemento.elemento.toString().equalsIgnoreCase(elemento.toString())) {
					contador++;
				}
			}
			return contador;
		}

		/*-------------------------METODOS ADICIONALES-------------------------*/
		// M�todo que devuelve la bolsa con el "indice" indicado
		public nodoBolsa obtenerBolsa(int i) {
			// TODO Auto-generated method stub
			trabajoBolsa = anclaBolsa;
			nodoBolsa tempBolsa = null;
			while (trabajoBolsa.siguienteBolsa != null) {
				trabajoBolsa = trabajoBolsa.siguienteBolsa;
				if (trabajoBolsa.numero == i) {
					tempBolsa = trabajoBolsa;
					break;
				}
			}
			return tempBolsa;
		}

		// M�todo que me devuelve la cantidad de bolsas en la lista.
		public int cantidadBolsas() {
			// TODO Auto-generated method stub
			int bolsas = 0;
			trabajoBolsa = anclaBolsa;
			while (trabajoBolsa.siguienteBolsa != null) {
				trabajoBolsa = trabajoBolsa.siguienteBolsa;
				bolsas++;
			}
			return bolsas;
		}

		// M�todo que regresa un string para seleccionar una bolsa en el menu
		public String mostrarBolsas() {
			String cadena = "Elige una bolsa\n";
			int contador = 0;
			trabajoBolsa = anclaBolsa;
			while (trabajoBolsa.siguienteBolsa != null) {
				trabajoBolsa = trabajoBolsa.siguienteBolsa;
				contador++;
				cadena += contador + ". Bolsa " + contador + "\n";
			}
			return cadena;
		}
	}

	static class nodoBolsa {
		// cada nodoBolsa contendr� para si, un identificador numerico
		// cada bolsa tendra una lista de elementos
		int numero;
		nodoBolsa siguienteBolsa;
		listaElemento listaElemento;

		public nodoBolsa() {
			// TODO Auto-generated constructor stub
			numero = numeroBolsa++;
			listaElemento = new listaElemento();
		}
	}

	static class listaElemento {
		nodoElemento anclaElemento;
		nodoElemento trabajoElemento;

		public listaElemento() {
			// TODO Auto-generated constructor stub
			anclaElemento = new nodoElemento();
			anclaElemento.siguientElemento = null;
		}
	}

	static class nodoElemento {
		Object elemento;
		nodoElemento siguientElemento;
	}
}
