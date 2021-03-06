#include "localidad.h"

///brief: iguala las localidades de cliente, con la de localidad
///param: lista de clientes, de localidad y sus tama?os
///
int igualarLocalidades(eCliente listaDeCliente[], int TAMCLIENTE, eLocalidad listaDeLocalidad[], int TAMLOCALIDAD)
{
	int rtn=-1;
	if(listaDeCliente!=NULL && listaDeCliente>0)
	{
		for(int i=0;i<TAMCLIENTE;i++)
		{
				strcpy(listaDeLocalidad[i].localidad,listaDeCliente[i].localidad);
				listaDeLocalidad[i].id=listaDeCliente[i].id;
				rtn=0;
		}
	}

	return rtn;
}





///BRIEF USADO SOLO PARA TESTEAR SI ANDABAN LAS COSAS
/// PARAM: LISTAS Y LOS TAMA?OS
void mostrarIdLocalidades(eCliente listaDeClientes[], int TAMCLIENTE, eLocalidad listaDeLocalidad[], int TAMLOCALIDAD)
{
	if(listaDeLocalidad!=NULL)
	{
		for (int i=0; i<TAMLOCALIDAD;i++)

			{
				printf("%s\n",listaDeLocalidad[i].localidad);

			}



	}
}


///brief: muestra clientes con sus localidades
///param: lista de clientes y localidades con sus tama?os
///
int clientesPorLocalidad(eCliente listaDeClientes[], int TAMCLIENTE, eLocalidad listaDeLocalidad[], int TAMLOCALIDAD)
{
	int rtn=-1;

	printf("\tClientes		Localidad\n\n");
	if(listaDeLocalidad!=NULL && listaDeLocalidad>0)
	{
		for (int i=0;i<TAMLOCALIDAD;i++)
		{

			if(listaDeClientes!=NULL && listaDeClientes>0)
			{
				for(int j=0;j<TAMCLIENTE;j++)
				{
					if(listaDeLocalidad[i].id==listaDeClientes[j].id)
					{

						printf("%14s \t%25s\n",listaDeClientes[j].name,listaDeLocalidad[i].localidad);
						rtn=0;
					}
				}
			}
		}
	}

	return rtn;

}





