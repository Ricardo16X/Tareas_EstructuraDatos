#include <stdio.h>
#include <math.h>

int main(){
    // Variables
    long int numero;
    int i = 0;
    int j = 0;
    int k = 0;
    /*Criba de Eratóstenes*/
    printf("Determinar todos los numeros primos detras de un numero natural dado.\n");
    printf("Ingrese un numero natural\n");
    // Solicito el número
    scanf("%i", &numero);
    // Evaluo las posibilidades de error
    if(numero > 2 && (numero % 2 == 0 || numero % 3 == 0 || numero % 5 == 0 || numero % 7 == 0)){
        int arrayNumeros[numero];
        // Almacenamiento de los números
        for(i = 2; i <= numero; i++){
            arrayNumeros[i - 2] = i;
        }
        // Aplicando 'Criba de Eratóstenes'
        for(k = 2; k < sqrt(numero) ; k++){
        	for(i = k; i < numero; i++){
        		if(arrayNumeros[i] != 0){
        			// Marco los números compuestos con 0
        			if(arrayNumeros[i] % k == 0){
        				arrayNumeros[i] = 0;
					}
				}
			}
		}
		// Mostrando el resultado
		printf("\n--- Lista de numeros primos ---\n");
		for(i = 0; i < numero; i++){
			if(arrayNumeros[i] != 0){
				printf("%d ,",arrayNumeros[i]);
			}
		}
    }else{
	    printf("Asegurate de ingresar un numero > 0 y que sea entero.");
	}
    return 0;
}
