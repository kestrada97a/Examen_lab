#include "impuesto.h"

///brief:inicializa todos los impuestos en FALSE
///param: lista de impuesto y tamaño
///
int inicializarImpuesto(eImpuesto list[], int TAMIMPUESTO)
{
	int rtn = -1;
	if(list!=NULL)
	{
		for(int i=0;i<TAMIMPUESTO;i++)
		{
			list[i].isTaxed=FALSE;
			rtn=0;
		}
	}

	return rtn;
}

///brief: iguala id de pedido con id de impuesto
///param: lista de pedido, impuesto y sus tamaños
///
int idImpuesto(ePedido listaPedido[], int TAMPEDIDO, eImpuesto listaImpuesto[], int TAMIMPUESTO)
{
	int rtn=-1;
	if(listaPedido!=NULL && listaPedido>0)
	{
		for(int i=0;i<TAMPEDIDO;i++)
		{
			listaImpuesto[i].idPedido=listaPedido[i].idPedido;
			rtn=0;
		}
	}

	return rtn;
}

///brief: carga los datos que se toman en cuenta para agregarle el impuesto
///param: lista de impuesto, pedidos, y sus tamaños
///
int cargarImpuestosPorCaracteristicas(eImpuesto listaImpuesto[], int TAMIMPUESTO, ePedido listaPedido[], int TAMPEDIDO)
{
	int rtn=-1;

	int id;
	if(listaPedido!=NULL && listaImpuesto!=NULL)
	{
		imprimirIdPendientes(listaPedido, TAMPEDIDO);
		id=pedirEntero("Ingrese id a cargar: ", TAMPEDIDO);

		for(int i=0;i<TAMPEDIDO;i++)
		{
			if(id==listaPedido[i].idPedido && listaPedido[i].estadoDelPedido==PENDIENTE)
			{
				for(int j=0;j<TAMIMPUESTO;j++)
				{
					if(listaPedido[i].idPedido==listaImpuesto[j].idPedido)
					{
						pedirStringAlternativo("Ingrese Codigo Postal", listaImpuesto[j].codigoPostal, 0, 10);
						listaImpuesto[j].capCom=pedirEntero("Ingrese 1(capitalista), 2(comunista)", 2);

							if(listaImpuesto[j].capCom==CAPITALISTA && listaPedido[i].pedidoKg>600)
							{
								listaImpuesto[j].impuesto=22.5;
								listaImpuesto[j].isTaxed=TRUE;
							}
							else if(listaImpuesto[j].capCom==COMUNISTA && listaPedido[i].pedidoKg>600)
							{
								listaImpuesto[j].impuesto=55.3;
								listaImpuesto[j].isTaxed=TRUE;
							}
							else
							{
								listaImpuesto[j].impuesto=0;
								listaImpuesto[j].isTaxed=TRUE;
							}

						break;

					}

				}

			}

		}
	}

	return rtn;
}










///brief: par de funciones usadas como un auxiliar para testear si funcionaban las cosas
///param: lsita de impuesto, su tamaño
///
void mostrarUnicoImpuesto(eImpuesto impuesto)
{

	printf("%.2f\n",impuesto.impuesto);

}

void imprimirImpuestosConId(eImpuesto listaDeImpuesto[], int TAMIMPUESTO)
{
	if (listaDeImpuesto!=NULL)
	{
		for(int i=0;i<TAMIMPUESTO;i++)
		{
			if(listaDeImpuesto[i].isTaxed==TRUE)
			{
				mostrarUnicoImpuesto(listaDeImpuesto[i]);

			}
		}
	}
}



///brief: par de funciones testeadoras para ver si funcionaban las otras funciones
///param: lsita pedido y su tamaño
///
void mostrarUnicoIdPendiente(ePedido pedido)
{
	printf("ID PEDIDO\tKILOS\n");
	printf("%d\t\t%.2f\n",pedido.idPedido,pedido.pedidoKg);
}
void imprimirIdPendientes (ePedido listaDePedidos[], int TAMPEDIDO)
{
	if (listaDePedidos!=NULL)
	{
		printf("ID pedidos pendientes: \n");
		for(int i=0;i<TAMPEDIDO;i++)
		{
			if(listaDePedidos[i].estadoDelPedido==PENDIENTE)
			{
				mostrarUnicoIdPendiente(listaDePedidos[i]);

			}

		}
	}
}

///brief: version final para mostrar los pedidos con sus descripciones de impuesto
///param: lsita de pedidos, impuesto y sus tamaños
///
void mostrarImpuestoFULL (ePedido listaPedidos[], int TAMPEDIDO, eImpuesto listaImpuesto[], int TAMIMPUESTO)
{
	if(listaPedidos!=NULL && listaImpuesto!=NULL && listaPedidos>0 && listaImpuesto>0)
	{
		printf("ID PEDIDO\tKG PEDIDO\tIMPUESTO\n");
		for(int i=0;i<TAMPEDIDO;i++)
		{
			if(listaPedidos[i].estadoDelPedido==PENDIENTE)
			{
				for (int j=0;j<TAMIMPUESTO;j++)
				{
					if(listaImpuesto[j].idPedido==listaPedidos[i].idPedido && listaImpuesto[j].isTaxed==TRUE)
					{
						printf("%d\t\t%.2f\t\t%.2f\n",listaPedidos[i].idPedido,listaPedidos[i].pedidoKg,listaImpuesto[j].impuesto);
					}
				}
			}
		}
	}



}





