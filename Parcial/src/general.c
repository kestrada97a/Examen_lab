#include "general.h"

///brief: pide entero con un maximo
///param: mensaje, maximo
///
int pedirEntero(char mensaje[], int maximo)
{
	int numeroIngresado;
	char term;
	printf("%s",mensaje);

	while((scanf("%d%c", &numeroIngresado, &term) != 2 || term != '\n')||(numeroIngresado<1 || numeroIngresado>maximo))
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}

///brief: pide float con un maximo y minimo
///param: mensaje, min, maximo
///
float pedirFloatConMaximo(char mensaje[], float min, float maximo)
{
	float numeroIngresado;
	char term;
	printf("%s",mensaje);

	while((scanf("%f%c", &numeroIngresado, &term) != 2 || term != '\n')||(numeroIngresado<min || numeroIngresado>maximo))
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}


///brief: pide float sin restricciones min max
///param: mensaje
///
float pedirFloat(char mensaje [])
{
	float numeroIngresado;
	char term;
	printf("%s",mensaje);
	while(scanf("%f%c", &numeroIngresado, &term) != 2 || term != '\n')
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}

///brief: pide un string
///param: mensaje, string auxiliar donde se guarda el string
///

void pedirString(char mensaje [], char stringAuxiliar[])
{
	int auxiliar;
	printf("%s \n",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringAuxiliar);
	auxiliar=ValidacionDeStrings(stringAuxiliar);
	UpperLower(stringAuxiliar);
	while(auxiliar==-1)
	{
		printf("Error. Reingrese solo letras: \n");
		fflush(stdin);
		scanf("%[^\n]",stringAuxiliar);
		auxiliar=ValidacionDeStrings(stringAuxiliar);
		UpperLower(stringAuxiliar);
	}
}

///brief: igual q la funcion de arriba pero con limites min max
///param: mensaje, string auxliar, min ,max
///
void pedirStringAlternativo(char mensaje [], char stringAuxiliar[], int min, int max)
{
	printf("%s \n",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringAuxiliar);
	while(strlen(stringAuxiliar)<min || strlen(stringAuxiliar)>max)
	{
		printf("Error. Reingrese\n");
		fflush(stdin);
		scanf("%[^\n]",stringAuxiliar);
		UpperLower(stringAuxiliar);
	}
	UpperLower(stringAuxiliar);
}


///brief: pide un string, pero que solo sean numeros
///param: mensaje, stringauxiliar, min ,max
///
void pedirStringAlternativoOnlyNumbers(char mensaje [], char stringAuxiliar[], int min, int max)
{
	printf("%s \n",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringAuxiliar);
	while(strlen(stringAuxiliar)<min || strlen(stringAuxiliar)>max)
	{
		printf("Error. Reingrese\n");
		fflush(stdin);
		scanf("%[^\n]",stringAuxiliar);
	}
	for(int i=0;i<stringAuxiliar[i];i++)
			{
				while(isalpha(stringAuxiliar[i])!=0 && isalnum(stringAuxiliar[i])!=0)
				{
					printf("Error. Reingrese\n");
					fflush(stdin);
					scanf("%[^\n]",stringAuxiliar);
				}
			}
}


///brief: escribe un mesnsaje normal y uno de alerta
///param: rtn, mensaje y mensaje de error
///

void MensajeDeAlerta(int rtn, char mensaje[], char mensajeError[])
{
	//char teclaIngresada;
	if(rtn>=0)
	{
		printf("%s\n",mensaje);
	}else {
		printf("%s\n",mensajeError);
	}
	/*printf("Presione una tecla para continuar.");
	fflush(stdin);
	scanf("%c",&teclaIngresada);
	printf("\n");*/
}

///brief: funcion auxiliar para usar dentro de los pedirString, valida los strings
///param: array
///
int ValidacionDeStrings(char array[])
{
	int rtn=0;
	for(int i=0;i<strlen(array);i++)
	{
		if(!(array[i]>=65 && array[i]<=90) && !(array[i]>=97 && array[i]<=122))
		{
			if(array[i]!=' ' || array[i-1]==' ')
			{
				rtn=-1;
				break;
			}
		}
	}
	return rtn;
}

///brief: funcion auxiliar, cambia de un lower case to upper case
///param: array
///
void UpperLower(char array[])
{
	char auxiliar[51];
	strcpy(auxiliar,array);
	strlwr(auxiliar);
	for(int i=0; i<strlen(auxiliar);i++)
	{
		auxiliar[0] = toupper(auxiliar[0]);
		break;
	}
	strcpy(array,auxiliar);
}

///brief: imprime el menu
///param:
///
void menu (void)
{
	printf("Menu: \n"
			"1. Alta cliente.\n"
			"2. Modificar datos de cliente: \n"
			"3. Baja de cliente. \n"
			"4. Crear pedido de recoleccion. \n"
			"5. Procesar residuos. \n"
			"6. Imprimir clientes. \n"
			"7. Imprimir pedidos pendientes. \n"
			"8. Imprimir pedidos procesados. \n"
			"9. Pedidos pendientes por localidad. \n"
			"10. Polipropileno reciclado por cliente. \n"
			"11. Lista clientes y su localidad. \n"
			"12. Despachar\n"
			"13. Ver impuestos finales\n"
			"14. Salir\n");


}


