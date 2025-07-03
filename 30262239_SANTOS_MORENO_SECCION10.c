#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxima_cadena 999

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int n, i, c, j, respuesta;
	
	printf("INGRESE LA CANTIDAD DE LIBROS QUE DESEA REGISTRAR: ");
	scanf("%d", &n);
	
	char busqueda[maxima_cadena];
	char TITULO[n][maxima_cadena];
	char AUTOR[n][maxima_cadena];
	char GENERO[n][maxima_cadena];
	char ISBN[n][maxima_cadena];
	float PRECIO[n];
	int STOCK[n];
	float GANANCIA[n];
	int encontrado = 0;
	
	//Ingresos usuario.
	
	for(i=0; i<n; i++){
		
		printf("INGRESE EL TITULO: ");
		scanf(" %[^\n]s", TITULO[i]);
        for (j = 0; TITULO[i][j] != '\0'; j++) {
            TITULO[i][j] = toupper(TITULO[i][j]);
        }
		
		printf("INGRESE EL AUTOR: ");
		scanf(" %[^\n]s", AUTOR[i]);
        for (j = 0; AUTOR[i][j] != '\0'; j++) {
            AUTOR[i][j] = toupper(AUTOR[i][j]);
        }
		
		printf("INGRESE EL GENERO: ");
		scanf(" %[^\n]s", GENERO[i]);
        for (j = 0; GENERO[i][j] != '\0'; j++) {
            GENERO[i][j] = toupper(GENERO[i][j]);
        }
        
		do {
			
			printf("INGRESE EL ISBN: ");
			scanf("%s", ISBN[i]);
			
		}while(strlen(ISBN[i]) != 10);
		
		do {
			
			printf("INGRESE EL PRECIO UNITARIO: ");
			scanf("%f", &PRECIO[i]);
		
		}while(PRECIO[i] < 0);

		printf("INGRESE EL STOCK: ");
		scanf("%d", &STOCK[i]);
		
		GANANCIA[i] = PRECIO[i]*STOCK[i];
		printf("%f\n", GANANCIA[i]);
	}
	
	//Tabla, filas y columnas:
	
	printf("%-20s %-20s %-20s %-20s %-10s %-10s %-10s\n", "TITULO", "AUTOR", "GENERO", "ISBN", "P.U.", "STOCK", "GANANCIA");
	
	for(i = 0; i<n; i++){
		printf("%-20s %-20s %-20s %-20s %-10.2f %-10d %-10.2f\n", TITULO[i], AUTOR[i], GENERO[i], ISBN[i], PRECIO[i], STOCK[i], GANANCIA[i]);
	}
	//Profe lo de verde y rojo lo busque de varias maneras pero me dañaba lo que ya tenia hecho para implementarlo:(
	
	//Filtro de busqueda:
	
		printf("\nINGRESE SU BUSQUEDA (TITULO, AUTOR, GENERO, ISBN)(EN MAYUSCULA POR FAVOR): ");
		while ((c = getchar()) != '\n' && c != EOF);
		fgets(busqueda, maxima_cadena, stdin);
		busqueda[strcspn(busqueda, "\n")] = '\0';
	
	if (strlen(busqueda) == 0) {
        printf("NO SE INGRESO NINGUNA BUSQUEDA.\n");
    }else {
        printf("RESULTADO: \n", busqueda);
    }
    
	for (i = 0; i < n; i++) {
		
    	if (strstr(TITULO[i], busqueda) != NULL || strstr(AUTOR[i], busqueda) != NULL || strstr(GENERO[i], busqueda) != NULL || strstr(ISBN[i], busqueda) != NULL){
    	
        printf("%-20s %-20s %-20s %-20s %-10.2f %-10d %-10.2f\n", TITULO[i], AUTOR[i], GENERO[i], ISBN[i], PRECIO[i], STOCK[i], GANANCIA[i]);
        encontrado = 1;
        }
    }

        if (!encontrado) {
            printf("\nNo se encontro tu busqueda");
        }

	return 0;
	}
