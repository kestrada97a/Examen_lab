/*
 * impuesto.h
 *
 *  Created on: 25 nov. 2021
 *      Author: brake
 */

#ifndef IMPUESTO_H_
#define IMPUESTO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "general.h"
#include "pedido.h"

#define FALSE 0
#define TRUE 1
#define CAPITALISTA 1
#define COMUNISTA 2

typedef struct
{
	int isTaxed;
	int idPedido;
	char codigoPostal[51];
	int capCom;
	float impuesto;
}eImpuesto;

int inicializarImpuesto(eImpuesto list[], int TAMIMPUESTO);
int idImpuesto(ePedido listaPedido[], int TAMPEDIDO, eImpuesto listaImpuesto[], int TAMIMPUESTO);
int cargarImpuestosPorCaracteristicas(eImpuesto listaImpuesto[], int TAMIMPUESTO, ePedido listaPedido[], int TAMPEDIDO);

void imprimirIdPendientes (ePedido listaDePedidos[], int TAMPEDIDO);
void mostrarUnicoIdPendiente(ePedido pedido);

void mostrarUnicoImpuesto(eImpuesto impuesto);
void imprimirImpuestosConId(eImpuesto listaDeImpuesto[], int TAMIMPUESTO);

void mostrarImpuestoFULL (ePedido listaPedidos[], int TAMPEDIDO, eImpuesto listaImpuesto[], int TAMIMPUESTO);
#endif /* IMPUESTO_H_ */
