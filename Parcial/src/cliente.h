#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "general.h"


typedef struct
{
 int id;
 char name[51];
 char cuit[12];
 char direccion[51];
 char localidad[51];
 int isEmpty;
}eCliente;

int inicializarClientes(eCliente list[], int tam);
int addCliente(eCliente list[], int tam, int* idAutomatico);
void mostrarUnicoCliente(eCliente cliente);
int imprimirClientes(eCliente list[], int tam);
int modificarEmpleado(eCliente list[],int tam);
int removerCliente(eCliente list[], int tam, int id);
int removerClienteSeleccionado(eCliente list[], int tam);

































#endif
