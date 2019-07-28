import java.util.Scanner;

public class T2_Ejercicio1 {

	static int numeroBolsa = 0;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// Variables de lectura
		int opcion = 0;
		String entradaTeclado = "";
		Scanner lectura = new Scanner(System.in);

		// Variables de verificación
		int cantidad = 0;
		// Variable temporal para la bolsa, al operar sobre ella
		nodoBolsa temporal = null;
		// Creando la lista inicial de bolsas
		listaBolsa listitaBolsa = new listaBolsa();

		// ------------PRUEBAS-----------------
//		  listitaBolsa.bolsaVacia(new nodoBolsa()); 
//		  listitaBolsa.bolsaVacia(new nodoBolsa());
//		  listitaBolsa.bolsaVacia(new nodoBolsa()); 
//		  listitaBolsa.bolsaVacia(new nodoBolsa()); 
//		  listitaBolsa.bolsaVacia(new nodoBolsa());
//		  
//		  nodoBolsa bolsa1 = listitaBolsa.obtenerBolsa(1);
//		  System.out.println(listitaBolsa.esVacia(bolsa1));
//		  listitaBolsa.insertar(bolsa1, "Elemento 1");
//		  System.out.println(listitaBolsa.esVacia(bolsa1));
//		  listitaBolsa.insertar(bolsa1, "Elemento 2"); listitaBolsa.insertar(bolsa1,
//		  "Elemento 3");
//		 
//		  System.out.println(listitaBolsa.mostrarBolsas());
		// crear un menu inicial
		while (opcion != 3) {
			System.out.println(
					"Menu Inicial\n" + "1. Crear una nueva Bolsa\n" + "2. Elegir Bolsa\n" + "3. Salir Aplicacion");
			try {
				opcion = Integer.parseInt(lectura.nextLine()); 
			} catch (Exception e) {
				// TODO: handle exception
				System.out.println("Ingresa el número para seleccionar una opción.");
				opcion = 0;
			}
			// Verificando la opción elegida
			switch (opcion) {
			case 1:
				listitaBolsa.bolsaVacia(new nodoBolsa());
				System.out.println("Bolsa creada!\n");
				break;
			case 2:
				cantidad = listitaBolsa.cantidadBolsas();
				if (cantidad > 0) {
					opcion = 0;
					while (opcion <= 0 | opcion > cantidad) {
						System.out.println(listitaBolsa.mostrarBolsas());
						try {
							opcion = Integer.parseInt(lectura.nextLine());
							
						} catch (Exception e) {
							// TODO: handle exception
							System.out.println("Ingresa solamente numeros enteros. " + e.getMessage());
							opcion = 0;
						}
						
					}
					// Aqui paso como parámetro el numero de bolsa elegida
					temporal = listitaBolsa.obtenerBolsa(opcion);
					// Una vez obtenida la bolsa a trabajar,proceso a preguntar que desea hacer
					// Menu de acciones para la bolsa elegida
					opcion = 0;
					while (opcion != 5) {
						System.out.println("Menu Bolsa\n" + "1. Insertar\n" + "2. Contar Elementos\n"
								+ "3. Verificar si esta Vacio\n" + "4. Vaciar Bolsa\n" + "5. Regresar\n");
						try {
							opcion = Integer.parseInt(lectura.nextLine());
							
							switch (opcion) {
							case 1: // Basicamente todo lo pone en string, solo se pueden insertar "nombres de
									// elementos"
								System.out.println("Ingrese el nombre del elemento");
								try {
									entradaTeclado = lectura.next();
									lectura.nextLine();
									listitaBolsa.insertar(temporal, entradaTeclado);
								} catch (Exception e) {
									// TODO: handle exception
									System.out.println("Error :| " + e.getMessage());
								}
								break;
							case 2: // Contar Elementos
								if (!listitaBolsa.esVacia(temporal)) {
									System.out.println("Ingrese desde que numero de elemento empezar a contar");
									try {
										opcion = Integer.parseInt(lectura.nextLine());
										while (opcion < 0) {
											System.out.println(
													"Empiezo a contar desde 0\n" + "Ingresa un numero entero mayor a 0");
											opcion = lectura.nextInt();
											lectura.nextLine();
										}
										int cantidadElementos = listitaBolsa.cuantos(temporal, opcion);
										if (cantidadElementos == 0) {
											System.out.println("Este es el último elemento de la bolsa.\n"
													+ "Hay 0 elementos después de este.\n");
										} else if (cantidadElementos < 0) {
											System.out.println(
													"El numero ingresado es mayor, al numero de elementos en esta bolsa.\n"
															+ "Intenta con otro valor la proxima vez.\n");
										} else {
											System.out.println(
													"Hay " + cantidadElementos + " después del 'indice' ingresado.\n");
										}
									} catch (Exception e) {
										// TODO: handle exception
										System.out.println("Error :| " + e.getMessage());
									}
								}else {
									System.out.println("La bolsa está vacia.");
								}
								break;
							case 3: // Verificar si está vacio
								if (listitaBolsa.esVacia(temporal)) {
									System.out.println("La bolsa " + temporal.numero + " está vacío.\n");
								} else {
									System.out.println("La bolsa " + temporal.numero + " no está vacío.\n");
								}
								break;
							case 4:
								if (!listitaBolsa.esVacia(temporal)) {
									System.out.println("La bolsa " + temporal.numero + " se ha vaciado.");
									listitaBolsa.vaciarBolsa(temporal);
								}else {
									System.out.println("No se puede vaciar, algo que está vacio.\n");
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
				} else {
					System.out.println("No hay bolsas creadas!\n");
				}
				break;
			default:
				break;
			}
		}
		lectura.close();
	}

	static class listaBolsa {
		// La lista de bolsas contendrán bolsas
		// las bolsas serán los nodoBolsa
		nodoBolsa anclaBolsa;
		nodoBolsa trabajoBolsa;
		nodoElemento trabajoElemento;

		public listaBolsa() {
			// TODO Auto-generated constructor stub
			anclaBolsa = new nodoBolsa();
			anclaBolsa.siguienteBolsa = null;
			// Con esto digo que cada bolsa
			// contendrá una lista de elementos...
			anclaBolsa.listaElemento = new listaElemento();
		}

		/*--------------------METODOS DE LA TAREA--------------------*/
		// Método de comprobacion de bolsa vacia...
		public boolean esVacia(nodoBolsa bolsita) {
			try {
				trabajoElemento = bolsita.listaElemento.anclaElemento;
			} catch (Exception e) {
				// TODO: handle exception
				return true;
			}
			return trabajoElemento.siguientElemento == null;
		}

		// Método para crear una nueva bolsa y agregarla en la lista de bolsas.
		// Se comportará como una lista circular
		public void bolsaVacia(nodoBolsa bolsita) {
			trabajoBolsa = anclaBolsa;
			// Verifico que si el ancla apunta a nulo
			// Si apunta a nulo, entonces no hay ninguna bolsa...
			// La ultima bolsa será la primera
			if (trabajoBolsa.siguienteBolsa == null) {
				try {
					trabajoBolsa.siguienteBolsa = bolsita;
					trabajoBolsa.ultimaBolsa = bolsita;
					trabajoBolsa.ultimaBolsa.siguienteBolsa = anclaBolsa.siguienteBolsa;
					trabajoBolsa.ultimaBolsa = null;
				} catch (Exception e) {
					// TODO: handle exception
					System.out.println("Error al insertar Bolsa " + e.getMessage());
				}
			} else {
				do {
					trabajoBolsa = trabajoBolsa.siguienteBolsa;
					trabajoBolsa.ultimaBolsa = null;
				} while (trabajoBolsa.siguienteBolsa != anclaBolsa.siguienteBolsa);
				try {
					trabajoBolsa.siguienteBolsa = bolsita;
					trabajoBolsa.ultimaBolsa = bolsita;
					trabajoBolsa.ultimaBolsa.siguienteBolsa = anclaBolsa.siguienteBolsa;
					trabajoBolsa.ultimaBolsa = null;
				} catch (Exception e) {
					// TODO: handle exception
					System.out.println("Error al insertar Bolsa " + e.getMessage());
				}
			}
		}

		// Método para insertar un elemento en cierta bolsa
		// Los elementos en la lista de elementos, se comportan como una lista simple.
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
				} // Lo veo extraño devolver un objeto tipo Bolsa
				return bolsita;
			} else {
				return null;
			}
		}

		// Método que cuenta cuántos elementos hay después de n elemento
		public int cuantos(nodoBolsa bolsita, int indice) {
			return cuantosElementos(bolsita) - indice;
		}

		// Método que me servirá para vaciar una bolsa de sus elementos
		public void vaciarBolsa(nodoBolsa temporal) {
			// TODO Auto-generated method stub
			temporal.listaElemento.anclaElemento.siguientElemento = null;
		}

		/*-------------------------METODOS ADICIONALES-------------------------*/
		// Método que devuelve la bolsa con el "indice" indicado
		public nodoBolsa obtenerBolsa(int i) {
			// TODO Auto-generated method stub
			trabajoBolsa = anclaBolsa;
			nodoBolsa tempBolsa = null;
			do {
				trabajoBolsa = trabajoBolsa.siguienteBolsa;
				if (trabajoBolsa.numero == i) {
					tempBolsa = trabajoBolsa;
					break;
				}
			} while (trabajoBolsa.siguienteBolsa != anclaBolsa.siguienteBolsa);
			return tempBolsa;
		}

		// Método que me devuelve la cantidad de bolsas en la lista.
		public int cantidadBolsas() {
			// TODO Auto-generated method stub
			int bolsas = 0;
			trabajoBolsa = anclaBolsa;
			if (trabajoBolsa.siguienteBolsa != null) {
				do {
					trabajoBolsa = trabajoBolsa.siguienteBolsa;
					bolsas++;
				} while (trabajoBolsa.siguienteBolsa != anclaBolsa.siguienteBolsa);
			}
			return bolsas;
		}

		// Método que regresa un string para seleccionar una bolsa en el menu
		public String mostrarBolsas() {
			String cadena = "Elige una bolsa\n";
			int contador = 0;
			trabajoBolsa = anclaBolsa;
			do {
				trabajoBolsa = trabajoBolsa.siguienteBolsa;
				contador++;
				cadena += contador + ". Bolsa " + trabajoBolsa.numero + "\n";
			} while (trabajoBolsa.siguienteBolsa != anclaBolsa.siguienteBolsa);
			return cadena;
		}

		// Metodo que me regresa cuantos elementos tiene una bolsa
		private int cuantosElementos(nodoBolsa bolsita) {
			// TODO Auto-generated method stub
			// Variable contadora de elementos
			int contador = 0;
			// Recorre todos los elementos y los va contando.
			trabajoElemento = bolsita.listaElemento.anclaElemento;
			while (trabajoElemento.siguientElemento != null) {
				trabajoElemento = trabajoElemento.siguientElemento;
				contador++;
			}
			return contador;
		}
	}

	static class nodoBolsa {
		// cada nodoBolsa contendrá para si, un identificador numerico
		// cada bolsa tendra una lista de elementos
		int numero;
		nodoBolsa siguienteBolsa;
		nodoBolsa ultimaBolsa;
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
