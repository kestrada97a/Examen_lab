/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "pedido.h"
#include "general.h"
#include "anexo.h"
#include "localidad.h"
#include "impuesto.h"
#define TAMCLIENTE 5 //100
#define TAMPEDIDO 1000 //1000
#define TAMRESIDUOS 1000
#define TAMLOCALIDAD 5
#define TAMIMPUESTO 1000
int main(void)
{
	setbuf(stdout,NULL);
	int automaticId=1;
	int auxiliarContadorClientes=0;
	float poliKilos=0;
	int opcion;
	eCliente listaDeClientes[TAMCLIENTE]={{1,"Pablo","12345678901","Calle 1","Villa 5",FALSE},
			{2,"Carlos","12345678930","Calle 2","Belgrano r.",FALSE},
			{3,"Ricardo","12345678940","Calle 3","Villa 1/11/14",FALSE},
			{4,"Rigoberta","13245678950","Calle 4","Vila La Paz",FALSE},
			{5,"Gerardo","13245698780","Calle 5","Puerto Madero",FALSE}};
	ePedido listaDePedidos [1000];
	eResiduos listaDeResiduos[1000];
	eLocalidad listaDeLocalidad[1000];
	eImpuesto listaDeImpuesto[1000];
	int flag=1;//-1;
	//inicializarClientes(listaDeClientes, TAMCLIENTE);
	inicializarResiduos(listaDeResiduos, TAMRESIDUOS);
	inicializarPedidos(listaDePedidos, TAMPEDIDO);
	idImpuesto(listaDePedidos, TAMPEDIDO, listaDeImpuesto, TAMIMPUESTO);




	do
	{
		menu();
		opcion=pedirEntero("Ingrese opcion: \n", 14);
		igualarLocalidades(listaDeClientes, TAMCLIENTE, listaDeLocalidad, TAMLOCALIDAD);

		switch(opcion)
	{
		case 1:
		addCliente(listaDeClientes, TAMCLIENTE, &automaticId);
		auxiliarContadorClientes=automaticId-1;

		flag=1;

		break;
		case 2:
		if (flag==1)
		{
			modificarEmpleado(listaDeClientes, TAMCLIENTE);

		}
		break;
		case 3:
		if(flag==1)
		{
			if(!removerClienteSeleccionado(listaDeClientes, TAMCLIENTE))
			{
				printf("Operacion Exitosa.\n");
			}
		}
		break;
		case 4:
		if (flag==1)
		{
			cargarPedido(listaDeClientes, listaDePedidos, TAMCLIENTE, TAMPEDIDO);
		}
		break;
		case 5:
		if(flag==1)
		{

			procesarResiduos(listaDePedidos, TAMPEDIDO, listaDeResiduos, TAMRESIDUOS);
		}
		break;
		case 6:
		if(flag==1)
		{
			imprimirClientesPendientes(listaDeClientes,listaDePedidos,TAMCLIENTE,TAMPEDIDO);
		}
		break;
		case 7:
	    if(flag==1)
		{

	    	imprimirPedidosPendientes(listaDePedidos, TAMPEDIDO, listaDeClientes, TAMCLIENTE);
		}
		break;

		case 8:
		if(flag==1)
		{
			imprimirPedidosProcesados(listaDePedidos, TAMPEDIDO, listaDeClientes, TAMCLIENTE, listaDeResiduos);
		}
		break;
		case 9:
		if(flag==1)
		{
			mostrarLocalidades(listaDeClientes, TAMCLIENTE, listaDePedidos, TAMPEDIDO);
			char localidad[51];
			pedirStringAlternativo("Ingrese localidad que desea examinar: ", localidad, 0, 51);
			printf("%s tiene %d pedido/s pendientes\n",localidad,contadorPendientesEnLocalidades(listaDeClientes, TAMCLIENTE, listaDePedidos, TAMPEDIDO, localidad));

		}
		break;
		case 10:
		if(flag==1)
		{
			poliKilos = contadorKilosPoli(listaDeResiduos, TAMRESIDUOS, listaDePedidos, TAMPEDIDO);
			float promedio= poliKilos/auxiliarContadorClientes;
			printf("El promedio de kilos de Polipropileno reciclado por cliente es: %.2f\n",promedio);
		}
		break;
		case 11:
		clientesPorLocalidad(listaDeClientes, TAMCLIENTE, listaDeLocalidad, TAMLOCALIDAD);
		break;
		case 12:
		cargarImpuestosPorCaracteristicas(listaDeImpuesto, TAMIMPUESTO, listaDePedidos, TAMPEDIDO);

			break;
		case 13:
			mostrarImpuestoFULL(listaDePedidos, TAMPEDIDO, listaDeImpuesto, TAMIMPUESTO);
			break;
	}
		if (opcion==14)
			{
			flag=-2;
			}
		if (flag==-1)
		{
			MensajeDeAlerta(flag, "Se ha cargado satisfactoriamente ", "Error. se debe cargar por lo menos un cliente primero.");
		}

	}while (opcion!=14);






	return EXIT_SUCCESS;

}
