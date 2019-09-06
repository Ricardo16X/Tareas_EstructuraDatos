#include <iostream>
#include <string>

// Métodos de recorrido
int indice_real_iterativo(int dimension[], int coordenada[], int tamano);
int indice_real_recursivo(int dimension[], int coordenada[], int tamano);

int main(int argc, char const* argv[]) {
  /*
  Calculo 1
  */
  int dimensiones[] = {9, 9};
  int coordenadas[] = {7, 5};
  // Iterativo
  int resultado_ITERACION_1 =
      indice_real_iterativo(dimensiones, coordenadas, sizeof(dimensiones) / sizeof(dimensiones[0]));
  std::cout << "INDICE (ITERATIVO) = ";
  std::cout << resultado_ITERACION_1 << std::endl;
  // Recursivo
  int resultado_RECURSIVO_1 =
      indice_real_recursivo(dimensiones, coordenadas, sizeof(dimensiones) / sizeof(dimensiones[0]));
  std::cout << "INDICE (RECURSIVO) = ";
  std::cout << resultado_RECURSIVO_1 << std::endl;
  /*
  Calculo 2
  */
  int dimensiones2[] = {6, 20};
  int coordenadas2[] = {4, 10};
  // Iterativo
  int resultado_ITERACION_2 =
      indice_real_iterativo(dimensiones2, coordenadas2, sizeof(dimensiones2) / sizeof(dimensiones2[0]));
  std::cout << "INDICE 2 (ITERATIVO) = ";
  std::cout << resultado_ITERACION_2 << std::endl;
  // Recursivo
  int resultado_RECURSIVO_2 =
      indice_real_recursivo(dimensiones2, coordenadas2, sizeof(dimensiones2) / sizeof(dimensiones2[0]));
  std::cout << "INDICE 2 (RECURSIVO) = ";
  std::cout << resultado_RECURSIVO_2 << std::endl;
  /*
   Calculo 3
   */
  int dimensiones3[] = {7, 5, 4};
  int coordenadas3[] = {3, 2, 3};
  // Iterativo
  int resultado_ITERACION_3 =
      indice_real_iterativo(dimensiones3, coordenadas3, sizeof(dimensiones3) / sizeof(dimensiones3[0]));
  std::cout << "INDICE 3 (ITERATIVO) = ";
  std::cout << resultado_ITERACION_3 << std::endl;
  // Recursivo
  int resultado_RECURSIVO_3 =
      indice_real_recursivo(dimensiones3, coordenadas3, sizeof(dimensiones3) / sizeof(dimensiones3[0]));
  std::cout << "INDICE 3 (RECURSIVO) = ";
  std::cout << resultado_RECURSIVO_3 << std::endl;
  /*
   Calculo 4
   */
  int dimensiones4[] = {10, 5, 25};
  int coordenadas4[] = {7, 1, 14};
  // Iterativo
  int resultado_ITERACION_4 =
      indice_real_iterativo(dimensiones4, coordenadas4, sizeof(dimensiones4) / sizeof(dimensiones4[0]));
  std::cout << "INDICE 4 (ITERATIVO) = ";
  std::cout << resultado_ITERACION_4 << std::endl;
  // Recursivo
  int resultado_RECURSIVO_4 =
      indice_real_recursivo(dimensiones4, coordenadas4, sizeof(dimensiones4) / sizeof(dimensiones4[0]));
  std::cout << "INDICE 4 (RECURSIVO) = ";
  std::cout << resultado_RECURSIVO_4 << std::endl;
  /*
   Calculo 5
   */
  int dimensiones5[] = {25, 25, 25, 25};
  int coordenadas5[] = {24, 24, 24, 24};
  // Iterativo
  int resultado_ITERACION_5 =
      indice_real_iterativo(dimensiones5, coordenadas5,  sizeof(dimensiones5) / sizeof(dimensiones5[0]));
  std::cout << "INDICE 5 (ITERATIVO) = ";
  std::cout << resultado_ITERACION_5 << std::endl;
  // Recursivo
  int resultado_RECURSIVO_5 =
      indice_real_recursivo(dimensiones5, coordenadas5,  sizeof(dimensiones5) / sizeof(dimensiones5[0]));
  std::cout << "INDICE 5 (RECURSIVO) = ";
  std::cout << resultado_RECURSIVO_5 << std::endl;
  std::cout << std::endl;
  system("pause");
  return 0;
}

// Se utilizan arrays de inicio, para poder acceder a los elementos N[k] e i[k]
int indice_real_iterativo(int dimension[], int coordenada[], int tamano) {
  // Se inicia una variable i_k que me indicará el acumulado del indice final.
  int i_k = 0;
  // Instrucción try catch, por si algo malo sucede. 
  try {
    // Si el tamano inicial es 1, me indica que la dimensión es 1
    // por lo tanto se retornará i[0] que es equivalente a coordenada[0] 
    if (tamano == 1) {
      return coordenada[0];
    } else {
      // Si la dimensión > 1, entonces iremos acumulando el indice real 
      // capturando primero i_0 que es = coordenada[0]
      i_k = coordenada[0];
      // Iteramos sobre el tamaño de dimensión
      // Ya que es la que nos indica, cuántas veces se repite la acumulación del indice.
      // Se inicia desde 1, ya que para dimensión mayor que 1
      // La ecuación de indice real para dimensión 2 inicia con = (i_0)*(N1) + i_1
      for (int i = 1; i < tamano; i++) {
        i_k = (i_k * dimension[i]) + coordenada[i];
      }
    }
  } catch (const std::exception& e) {
    // Captura de algún error.
    std::cerr << e.what() << '\n';
  }
  // Retorna el indice real acumulado siguiendo la ecuación (Dimension_n-1)*Dimension[n] + coordenada[n]
  // en dado caso la dimensión sea > 1
  return i_k;
}
// Se utilizan arrays de inicio, para poder acceder a los elementos N[k] e i[k]
int indice_real_recursivo(int dimensiones[], int coordenadas[], int tamano) {
  // Se utiliza i_k para acumular los valores para el indice real.
  int i_k = 0;
  // Si el tamano es igual a 0, retornaremos los 
  if (tamano == 0) {
    return i_k;
  } else {
    // Se reduce el "tamano" de la dimension para poder llegar al estado base, que me retornará
    // el valor acumulado de i_k
    tamano = tamano - 1;
    // indice_real_recursivo(...) equivale a i_k-1
    i_k = (indice_real_recursivo(dimensiones, coordenadas, tamano)) * dimensiones[tamano] + coordenadas[tamano];
    /*Luego de cumplirse de que tamano == 0
    se retornará el valor de i_k anterior, y se multiplicará por dimension[tamano - 1] + coordenada[tamano - 1]
    se guardará en i_k y se volverá a multiplicar dimensiones[tamano-2] + coordenada[tamano-2] etc.
    Para poder cumplir que i_k inicial == i_0 sea siempre coordenada[0]
    */

   /*Como ejemplo se usará Dimension[4,4], Coordenada[0,2] 
    tamano = 2
    ######---INICIO---#######
    tamano != 0     # tamano = 2
      i_k = indice_real_recursivo(..., tamano = 1)
    ###---2 pasada---###
    tamano != 0     # tamano = 1
      i_k = indice_real_recursivo(..., tamano = 0)
    ###---3 pasada---###
    tamano == 0     # tamano = 0
      RETORNO i_k
      primer i_k = 0
      i_k = i_k-1*N[1] + i[1]
      i_k = i[1] = 2
      i_k = 2
      SE RETORNA i_k que es = 2
   */
  }
}
