#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "pedido.h"
#define FALSE 0
#define TRUE 1
#define ACARGAR 0
#define PENDIENTE 1
#define COMPLETADO 2

typedef struct
{
 int id;
 char localidad[51];
}eLocalidad;

int igualarLocalidades(eCliente listaDeCliente[], int TAMCLIENTE, eLocalidad listaDeLocalidad[], int TAMLOCALIDAD);
void mostrarIdLocalidades(eCliente listaDeClientes[], int TAMCLIENTE, eLocalidad listaDeLocalidad[], int TAMLOCALIDAD);
int clientesPorLocalidad(eCliente listaDeClientes[], int TAMCLIENTE, eLocalidad listaDeLocalidad[], int TAMLOCALIDAD);



#endif
