#include "anexo.h"
#define FALSE 0
#define TRUE 1
#define ACARGAR 0
#define PENDIENTE 1
#define COMPLETADO 2


///brief:carga un pedido por cliente
///param:listas de pedido y cliente, con sus tama?os
///
int cargarPedido(eCliente list[],ePedido listaPedidos[],int TAMCLIENTE, int TAMPEDIDO)
{
	int id;
	int idAUX=1;
	int rtn=-1;
	int auxiliarContador=0;
	if((list!=NULL && list>0) && (listaPedidos!=NULL && listaPedidos>0))
	{
		imprimirClientes(list, TAMCLIENTE);
		id=pedirEntero("Ingrese id del cliente: ", TAMCLIENTE);
		for (int i=0;i<TAMCLIENTE;i++)
		{
			if(list[i].id==id && list[i].isEmpty==FALSE)
			{
				for(int j=0;j<TAMPEDIDO;j++)
				{
					if(listaPedidos[j].estadoDelPedido==ACARGAR)
					{
						listaPedidos[j].id=id;
						listaPedidos[j].pedidoKg=pedirFloat("Ingrese cantidad de kilos totales que se recolectara del cliente (Impuesto var?a segun kg): ");
						listaPedidos[j].idPedido=idAUX;
						listaPedidos[j].estadoDelPedido=PENDIENTE;
						auxiliarContador++;
						break;
					}
					idAUX++;
				}
				rtn=0;

			}

		}
	}
	return rtn;
}


///brief: procesa el kg que tiene un pedido y lo divide entre dif tipos de plasticos
///param: lista de plastico, residuos, y sus tama?os
///
int procesarResiduos(ePedido listaDePedidos[],int TAMPEDIDO, eResiduos listaDeResiduos[], int TAMRESIDUOS)
{
	int rtn=-1;
	int idAuxiliar;
	float auxiliarKilos;

	if(listaDePedidos!=NULL && listaDePedidos>0)
	{
		imprimirPedidos(listaDePedidos, TAMPEDIDO);
		idAuxiliar=pedirEntero("Ingrese ID del pedido: ", TAMPEDIDO);
		for(int i=0;i<TAMPEDIDO;i++)
		{
			if(listaDePedidos[i].idPedido==idAuxiliar && listaDePedidos[i].estadoDelPedido==PENDIENTE)
			{
				listaDePedidos[i].idPedido=listaDeResiduos[i].idPedido;
				listaDeResiduos[i].PoliAltaKg=pedirFloatConMaximo("Ingrese kilaje de Polietileno de alta densidad: ",0,listaDePedidos[i].pedidoKg);
				auxiliarKilos=listaDePedidos[i].pedidoKg - listaDeResiduos[i].PoliAltaKg;
				listaDeResiduos[i].PoliBajaKg=pedirFloatConMaximo("Ingrese kilaje de Polietileno de baja densidad: ", 0, auxiliarKilos);
				auxiliarKilos=auxiliarKilos - listaDeResiduos[i].PoliBajaKg;
				listaDeResiduos[i].PoliKg=pedirFloatConMaximo("ingrese kilaje de Polipropileno: ", 0, auxiliarKilos);

				auxiliarKilos=auxiliarKilos - listaDeResiduos[i].PoliKg;
				auxiliarKilos=listaDePedidos[i].pedidoKg - auxiliarKilos;
				printf("Kilos reciclados: %2.f\n",auxiliarKilos);
				printf("El resto ser? desechado.\n");
				listaDePedidos[i].estadoDelPedido=COMPLETADO;
				rtn=0;

			}

		}
	}




	return rtn;
}

///brief: se usa junto con la funcion de imprimir pedidos, juntos, imprimen los pedidos segun posicion de la lista
///param: pedido
///
void mostrarUnicoPedido(ePedido pedido)
{
	printf("%2d 	\t%4.2f\n",pedido.idPedido,pedido.pedidoKg);
}

///brief: se usa junt ocon la funcion de arriba, imprimen pedidos segun posicion de lal ista
///param: lista de pedido y tama?o
///

int imprimirPedidos(ePedido list[], int tam)
{
	int rtn=-1;
	printf("ID-PEDIDO	KILOGRAMOS\n");
	for(int i=0; i<tam;i++)
	{
		if(list[i].estadoDelPedido==PENDIENTE)
		{
			mostrarUnicoPedido(list[i]);
			rtn=0;
		}
	}
	return rtn;
}



///brief: cuenta clientes pendientes dedicado para usarse en otra funcion
///param: lista de pedidos, tama?o pedido, y idcliente
///
int contadorClientesPendientes(ePedido listaDePedidos[],int TAMPEDIDO, int idCliente)
{
	int contador=0;

	if(listaDePedidos!=NULL && listaDePedidos>0)
	{
		for (int i=0;i<TAMPEDIDO;i++)
		{
			if(listaDePedidos[i].estadoDelPedido==PENDIENTE && (listaDePedidos[i].id==idCliente))
			{
				contador++;
			}
		}
	}
	return contador;
}

///brief: imprime los clientes con pedidos pendientes
///param: lista de pedido, cliente, y sus tama?os
///
int imprimirClientesPendientes(eCliente listaDeClientes[], ePedido listaDePedidos[], int TAMCLIENTE, int TAMPEDIDO)
{
	int rtn=-1;
	int contador;
	printf("ID\tNOMBRE\t CUIT\t	DIRECCION\t    LOCALIDAD\tPEDIDOS PENDIENTES\n");
	for (int i=0;i<TAMCLIENTE;i++)
	{
			if(listaDeClientes[i].isEmpty==FALSE)
			{
				contador = contadorClientesPendientes(listaDePedidos,TAMPEDIDO,listaDeClientes[i].id);
				printf("%d\t%4s\t%12s\t%10s\t%10s\t%d\n",listaDeClientes[i].id,listaDeClientes[i].name,listaDeClientes[i].cuit,listaDeClientes[i].direccion,listaDeClientes[i].localidad,contador);
				rtn=0;
			}

	}
	return rtn;
}

///brief: imprime pedidos pendientes con sus ids
///param: lsita de pedidos, clientes, y sus tama?os
///

int imprimirPedidosPendientes(ePedido listaDePedidos[], int TAMPEDIDO, eCliente listaDeClientes[], int TAMCLIENTE)
{
	int rtn=-1;
	printf("CUIT\t	DIRECCION DEL CLIENTE\t	KG A RECOLECTAR\n");
	for(int i=0;i<TAMCLIENTE;i++)
	{
		if(listaDeClientes[i].isEmpty==FALSE)
		{
			for(int j=0;j<TAMPEDIDO;j++)
			{
				if (listaDePedidos[j].estadoDelPedido==PENDIENTE && listaDeClientes[i].id==listaDePedidos[j].id)
				{
					printf("%s\t%15s\t		%5.2f\n",listaDeClientes[i].cuit,listaDeClientes[i].direccion,listaDePedidos[j].pedidoKg);
					rtn=0;
				}
			}
		}
	}


	return rtn;
}

///brief: imprime pedidos procesados
///param: lista de pedidos, cleinte, residuo, y sus tama?os (sin el de residuo)
///
int imprimirPedidosProcesados(ePedido listaDePedidos[], int TAMPEDIDO, eCliente listaDeCLientes[], int TAMCLIENTE, eResiduos listaResiduos[])
{
	int rtn=-1;
	printf("CUIT\t	DIRECCION DEL CLIENTE\t Polietileno-Alta-Densidad\t	Polietileno-Baja-Densidad\t	Polipropileno\n");
	for(int i=0;i<TAMCLIENTE;i++)
	{
		if(listaDeCLientes[i].isEmpty==FALSE)
		{
			for (int j=0;j<TAMPEDIDO;j++)
			{
				if(listaDeCLientes[i].id==listaDePedidos[j].id && listaDePedidos[j].estadoDelPedido==COMPLETADO)
				{
					printf("%s\t%15s	%15.2f\t\t\t	%14.2f\t\t\t	%14.2f\n",listaDeCLientes[i].cuit,listaDeCLientes[i].direccion,listaResiduos[j].PoliAltaKg,listaResiduos[j].PoliBajaKg,listaResiduos[j].PoliKg);
					rtn=0;
				}
			}
		}
	}


	return rtn;
}

///brief: cuenta cuantos pedidos pendientes hay por  localidad
///param: lista de cliente, pedidos, sus tama?os, y el par localidad a buscar
///
int contadorPendientesEnLocalidades(eCliente listaDeClientes[], int TAMCLIENTE, ePedido listaDePedidos[], int TAMPEDIDO, char localidad[])
{
	int contadorLocalidad=0;
	if (listaDeClientes!=NULL && listaDeClientes>0)
	{
		for (int i=0;i<TAMCLIENTE;i++)
		{
			if(listaDePedidos!=NULL && listaDePedidos>0)
			{
				for (int j=0;j<TAMPEDIDO;j++)
				{
					if((strcmp(listaDeClientes[i].localidad,localidad)==0 && listaDePedidos[j].estadoDelPedido==PENDIENTE) && listaDeClientes[i].id==listaDePedidos[j].id)
					{
						contadorLocalidad++;
					}
				}
			}
		}
	}


	return contadorLocalidad;
}

///brief: muestra las localidades donde hay pedidos pendientes
///param:
///
void mostrarLocalidades(eCliente listaDeClientes[], int TAMCLIENTE, ePedido listaDePedidos[], int TAMPEDIDO)
{
	if(listaDeClientes!=NULL && listaDeClientes>0)
	{
		for (int i=0; i<TAMCLIENTE;i++)
			{
				if(listaDePedidos!=NULL && listaDePedidos>0)
				{
					for (int j=0;j<TAMPEDIDO;j++)
					{
						if(listaDePedidos[j].estadoDelPedido==PENDIENTE && listaDeClientes[i].id==listaDePedidos[j].id)
						{
							printf("%s\n",listaDeClientes[i].localidad);
						}
					}
				}
		}
	}
}

///brief: cuenta cuantos kilos de un plastico especifico(Politielitenoteno) hay
///param: lsita de residuos, pedidos, y sus tama?os
///
float contadorKilosPoli (eResiduos listaDeResiduos[], int TAMRESIDUOS, ePedido listaDePedidos[],int TAMPEDIDO)
{
	float rtn=0;
	float auxiliar=0;
	if(listaDePedidos!=NULL && listaDeResiduos!=NULL && listaDePedidos>0 && listaDeResiduos>0)
	{
		for (int i=0;i<TAMRESIDUOS;i++)
		{
			if(listaDePedidos[i].estadoDelPedido==COMPLETADO)
			{
				auxiliar=listaDeResiduos[i].PoliKg+rtn;
				rtn=auxiliar;
			}
		}
	}




	return rtn;
}


