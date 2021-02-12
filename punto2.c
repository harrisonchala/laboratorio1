/*Desarrolladores: Harrison Rodriguez Chala & Brayam Fernando Suarez & David Gaitan Leon 		
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define TAM 50
#define L 6


void promedio(int[],int,float*);// Calcula y muestra el promedio de un vector de enteros
void desviacion_estandar(int[],int,int);// Calcula y muestra la desviacion estandar de un vector entero, teniendo el promedio
void mostrar_num(int[],int); // muestra los numeros de un vector
void pidedatos(char[TAM], int *, int *); //Pide la cadena de 5 numeros separados por punto y coma
void saca_num_cadena(char[TAM], int[L], int); //separa los numeros de la cadena y los guarda en un vector de enteros
void maximo_minimo(int [L], int); // Halla el máximo y mínimo de un vector de enteros
void compara_arreglos( int [L], int [L], int ,int ); // Compara 2 vectores de enteros , posición por posición y  tambien la suma, diciendo si es mayor, igual o menor.

int main(void)
{
	int opc=0, len=0, cant_num=0, cant_num2=0, vector_numeros[L], vector_numeros2[L];
	float prom=0;
	char cadena_con_pc[TAM] ; // cadena con punto y coma
	printf("\n\tBienvenido");

	do
	{
		printf("\n\n MENU \n\n");
		printf("1. Ingresar Valores. \n");
		printf("2. Mostrar promedio. \n");
		printf("3. Mostrar desviacion estandar. \n");
		printf("4. Mostrar valores maximo y minimo. \n");
		printf("5. Mostrar todo. \n");
		printf("6. Ingresar nuevos datos. \n");
		printf("7. Comparar arreglos. \n");
		printf("8. Salir \n\n");
		printf("\n\nSeleccione una opcion del 1 al 8 \n");
		scanf("%d",&opc);
		getchar();
		switch (opc)
			{
			case 1:
				printf("\n\t1. Ingresar valores.");
				pidedatos(&cadena_con_pc[TAM], & len, &cant_num);
				saca_num_cadena(&cadena_con_pc[TAM], &vector_numeros[L], len);

			break;
			case 2:
				printf("\n\t2. Mostrar promedio.");
				promedio(&vector_numeros[L],cant_num,&prom);
			break;
			case 3:
				printf("\n\t3. Mostrar desviacion estandar.");
				desviacion_estandar(&vector_numeros[L],cant_num,prom);
			break;
			case 4:
		        printf("\n\t4. Mostrar valores maximo y minimo.");
				maximo_minimo(&vector_numeros[L],cant_num);
			break;
			case 5:
		    	printf("\n\t5. Mostrar todo.");
			mostrar_num(&vector_numeros[L], cant_num);
		    	promedio(&vector_numeros[L],cant_num,&prom);
		    	desviacion_estandar(&vector_numeros[L],cant_num,prom);
		    	maximo_minimo(&vector_numeros[L],cant_num);
			break;
			case 6:
				printf("\n\t6. Ingresar nuevos datos");
				pidedatos(&cadena_con_pc[TAM], & len, &cant_num2);
				saca_num_cadena(&cadena_con_pc[TAM], &vector_numeros2[L], len);
			break;
			case 7:
				printf("\n\t7. Comparar arreglos");
				compara_arreglos( &vector_numeros[L], &vector_numeros2[L], cant_num, cant_num2);
			break;
			case 8:
				printf("\n\t8.Salir");
		        printf("\nHasta luego vuelva pronto\n");
			break;
			default:
				printf("\n\t ERROR\n");
		        }

	}while(opc != 8);


}



void pidedatos(char cadena_con_pc[TAM], int *len, int *n)
{
	int cont=0, cant=0, pc=0;
	do
	{
		printf("\n\n Ingrese cantidad de numeros(maximo %d)\n\n", L);
		scanf("%d", n);
	}while(*n<=1 || *n>L );

	do
	{
		pc=0;
		printf("Ingrese %d numeros cualesquiera, separados cada uno por un punto y coma\n\n",*n);
		scanf("%s", cadena_con_pc);
		*len=strlen(cadena_con_pc);
		for (cont=0;cont <*len; cont++)
		{
			if(cadena_con_pc[cont]==';') pc=pc+1;
		}
	}
	while( pc!= *n-1);
	printf("\nLos numeros ingresados son: %s\n\n", cadena_con_pc);
}


void saca_num_cadena(char cadena[TAM], int numeros[L], int len)
{
	int cont=0, cont1=0, cont2=0,cont3=0, direccion=0, val=0;
	char string_num[10];
	
	for(cont=0; cont<=len; cont++)
	{

		if(cadena[cont]==59 || cadena[cont]=='\0')
		{
			for(cont1=0; cont1<cont-direccion; cont1++)
			{
				string_num[cont1]=cadena[cont1+direccion];
			}
  			string_num[cont1]='\0';
			direccion=cont+1;
			val=atoi(string_num);
			numeros[cont2]=val;
			cont2++;
		}
	}
}



void promedio (int num[],int n,float *prom)
{
	int i;
	float sum;
	//suma de los valores
	for(i=0;i<n;i++)
        {
        	sum=sum+num[i];
        }
	//operacion de del promedio
	*prom=(sum/n);
	printf("\nEl promedio de los numeros es %.3f\n",*prom);
}
void desviacion_estandar (int num[],int n,int prom)
{
	int i;
	float s1=0,ds=0,s2=0;
	for(i=0;i<n;i++)
        {
                s1=s1+(num[i]-prom)*(num[i]-prom);
        }
	s2=(s1/n);
	ds=sqrt(s2);
	printf("\nLa desviacion estandar %.3f\n",ds);
}

void mostrar_num (int num[],int n)
{
	int i;
	printf("\nLos valores que se ingresaron son:\n");
        for(i=0;i<n;i++)
        {
                printf("\t %d,",num[i]);
        }
}


void maximo_minimo(int numeros[L], int n)
{
	int i=0, min=0, max=0;
	printf("\nLos valores maximo y minimo de los datos ingresados son: \n");
	min=numeros[0];
	max=numeros[0];
	for (i = 1;i < n; i++)
	{
		if(numeros[i] <  min) min=numeros[i];
		if(numeros[i] > max) max=numeros[i];
	}
	printf("Minimo: %d \n", min);
	printf("Maximo: %d \n", max);
}


void compara_arreglos( int vector1[L], int vector2[L], int cant_num,int cant_num2)
{
	int cont=0, suma1=0, suma2=0, min=0;
	min=cant_num;
	if(min>cant_num2) min=cant_num2;
	for(cont=0; cont<cant_num; cont++)
	{
		suma1=suma1+vector1[cont];
	}
	for(cont=0; cont<cant_num2;cont++)
	{
		suma2=suma2+vector2[cont];
	}
	for(cont=0; cont<min; cont++) 
	{
			if(vector1[cont]<vector2[cont]){
				printf("\n\nEl valor en la posicion %d del primer arreglo es menor al  valor del segundo arreglo (%d %c %d)", cont, vector1[cont], 60, vector2[cont]);
			}
			else if (vector1[cont]==vector2[cont]){
				 printf("\n\nEl valor en la posicion %d del primer arreglo es igual al  valor del segundo arreglo (%d %c %d)", cont, vector1[cont], 61, vector2[cont]);
			}
			else printf("\n\nEl valor en la posicion %d del primer arreglo es mayor al  valor del segundo arreglo (%d %c %d)", cont, vector1[cont], 62, vector2[cont]);
	}
	if(suma1>suma2) {
		printf("\n\n\nLa suma de los valores del primer arreglo (%d) es mayor que la del segundo arreglo(%d)", suma1, suma2);
	}
	else if(suma1==suma2){
		printf("\n\n\nLa suma de los valores del primer arreglo (%d) es igual que la del segundo arreglo(%d)", suma1, suma2);
	}
	else printf("\n\n\nLa suma de los valores del primer arreglo (%d) es menor que la del segundo arreglo(%d)", suma1, suma2);
}
