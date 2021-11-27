#include "pedido.h"

///brief: inicializa los pedidos en A CARGAR
///param: lista y tamaño
///

int inicializarPedidos(ePedido list[], int tam)
{

		int rtn=-1;
		if(list!=NULL && tam>0)
		{
		for(int i=0;i<tam;i++)
		{
			list[i].estadoDelPedido=ACARGAR;
			rtn=0;
		}
		}
		return rtn;

}

///brief: inicializa los residuos en PENDIENTE
///param: lista y tamaño
///

int inicializarResiduos(eResiduos list[], int tam)
{
	int rtn=-1;
	if(list!=NULL && tam>0)
	{
		for (int i=0;i<tam;i++)
		{
			list[i].estadoDelResiduo=PENDIENTE;
			rtn=0;
		}
	}


	return rtn;
}





