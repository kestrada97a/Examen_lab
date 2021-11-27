#ifndef ANEXO_H_
#define ANEXO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




#include "general.h"
#include "cliente.h"
#include "pedido.h"
#include "localidad.h"

int cargarPedido(eCliente list[],ePedido listaPedidos[],int TAMCLIENTE, int TAMPEDIDO);
void mostrarUnicoPedido(ePedido pedido);
int imprimirPedidos(ePedido list[], int tam);
int procesarResiduos(ePedido listaDePedidos[],int TAMPEDIDO, eResiduos listaDeResiduos[], int TAMRESIDUOS);



int contadorClientesPendientes(ePedido listaDePedidos[],int TAMPEDIDO, int idCliente);
int imprimirClientesPendientes(eCliente listaDeClientes[], ePedido listaDePedidos[], int TAMCLIENTE, int TAMPEDIDO);
int imprimirPedidosPendientes(ePedido listaDePedidos[], int TAMPEDIDO, eCliente listaDeClientes[], int TAMCLIENTE);
int imprimirPedidosProcesados(ePedido listaDePedidos[], int TAMPEDIDO, eCliente listaDeCLientes[], int TAMCLIENTE, eResiduos listaResiduos[]);
int contadorPendientesEnLocalidades(eCliente listaDeClientes[], int TAMCLIENTE, ePedido listaDePedidos[], int TAMPEDIDO, char localidad[]);
void mostrarLocalidades(eCliente listaDeClientes[], int TAMCLIENTE, ePedido listaDePedidos[], int TAMPEDIDO);
float contadorKilosPoli (eResiduos listaDeResiduos[], int TAMRESIDUOS, ePedido listaDePedidos[],int TAMPEDIDO);
#endif /* ANEXO_H_ */
