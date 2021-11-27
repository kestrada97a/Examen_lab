#ifndef PEDIDO_H_
#define PEDIDO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "general.h"
#define PoliAltaDensidad 1
#define PoliBajaDensidad 2
#define Polipropilieno 3
#define ACARGAR 0
#define PENDIENTE 1
#define COMPLETADO 2

typedef struct
{
 int id;
 int idPedido;
 float pedidoKg;
 int estadoDelPedido;
}ePedido;


typedef struct
{
 int idPedido;
 int estadoDelResiduo;
 float PoliAltaKg;
 float PoliBajaKg;
 float PoliKg;
}eResiduos;




int inicializarPedidos(ePedido list[], int tam);
int inicializarResiduos(eResiduos list[], int tam);







#endif
