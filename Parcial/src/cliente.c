#include "cliente.h"
#define TRUE 1
#define FALSE 0

///brief: inicializa clientes
///param:	lista y el temaño
///
int inicializarClientes(eCliente list[], int tam)
{
	int rtn=-1;
	if(list!=NULL && tam>0)
	{
	for(int i=0;i<tam;i++)
	{
		list[i].isEmpty=TRUE;
		rtn=0;
	}
	}
	return rtn;
}

///brief:agrega un cliente a la lista
///param: lista, tamaño, y el puntero de idautomatico
///
int addCliente(eCliente list[], int tam, int* idAutomatico)
{
	int rtn=-1;
	int auxID;
	int posicionACargar=-1;
	auxID=*idAutomatico;

	if (list != NULL && list > 0)
	{
		for (int i=0;i<tam;i++)
		{
			if (list[i].isEmpty==TRUE)
			{
				posicionACargar=i;
				break;
			}

		}

		if (posicionACargar!=-1)
		{
			list[posicionACargar].id=auxID;
			pedirString("Ingrese nombre del cliente: ", list[posicionACargar].name);
			pedirStringAlternativoOnlyNumbers("Ingrese CUIT: ", list[posicionACargar].cuit, 11, 11);
			pedirStringAlternativo("Ingrese dirección: ", list[posicionACargar].direccion, 0,99999);
			pedirString("Ingrese localidad: ", list[posicionACargar].localidad);

			auxID++;
			list[posicionACargar].isEmpty=FALSE;
			rtn=0;
			*idAutomatico = auxID;

		}
	}
	return rtn;
}

///brief: muestra un unico cliente con su descripcion, usado junto con otra funcion
///param: cliente
///
void mostrarUnicoCliente(eCliente cliente)
{
	printf("%1d %11s %18s \t%s 	%17s\n",cliente.id, cliente.name, cliente.cuit, cliente.direccion, cliente.localidad);
}

///brief: imprime la descripcion de un cliente en sus posiciones se usa junto a la funcion de arriba
///param: lista y tamaño
///
int imprimirClientes(eCliente list[], int tam)
{
	int rtn=-1;
	printf("ID	NOMBRE		CUIT	       DIRECCION		LOCALIDAD\n");
	for(int i=0; i<tam;i++)
	{
		if(list[i].isEmpty==FALSE)
		{
			mostrarUnicoCliente(list[i]);
			rtn=0;
		}
	}
	return rtn;
}

///brief: modifica un empleado de la lista
///param: lista y tamaño
///

int modificarEmpleado(eCliente list[],int tam)
{
	int subMenu;
	int id;
	int rtn=-1;
	if (list!=NULL && list>0)
	{
		imprimirClientes(list, tam);
		id=pedirEntero("Ingrese ID del cliente que desea modificar: ", tam);
		for (int i=0;i<tam;i++)
		{
			if(list[i].id==id && list[i].isEmpty==FALSE)
			{
				printf("Que desea modificar: \n"
						"1. Cambiar Direccion.\n"
						"2. Cambiar Localidad.\n");
				subMenu=pedirEntero("Ingrese opcion: ", 2);
				switch(subMenu)
				{
				case 1:
					pedirStringAlternativo("Ingrese direccion: ", list[i].direccion,1,51);
					break;
				case 2:
					pedirStringAlternativo("Ingrese localidad: ", list[i].localidad,1,51);
					break;
				}
				rtn=0;
				break;
			}
		}
	}
	return rtn;
}

///brief:es para remover un cliente se usa junto con la funcion de abajo, basicamente setea el estado en Empty
///param: lista tamaño, id a remover
///
int removerCliente(eCliente list[], int tam, int id)
{
	int retorno =-1;
	if (list != NULL && tam >0 && id>0)
	{
		for (int i=0;i<tam;i++)
		{
			if(list[i].id==id && list[i].isEmpty ==FALSE)
			{
				list[i].isEmpty = TRUE;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

///brief: remueve cliente selecionado
///param: lista y tamaño
///

int removerClienteSeleccionado(eCliente list[], int tam)
{
	int rtn=-1;
	int idBaja;
	int msjError;
	if(list != NULL && tam>0)
	{
		if(!imprimirClientes(list, tam))
		{
			idBaja= pedirEntero("Ingrese el id del empleado que desea remover: \n", 9999);
		}
		if (!removerCliente(list, tam, idBaja))
		{
			msjError=0;
			rtn=0;
		}
		MensajeDeAlerta(msjError, "Se elimino el ID\n", "Error - no se pudo eliminar el cliente\n ");
	}
	return rtn;

}
