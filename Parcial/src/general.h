#ifndef GENERAL_H_
#define GENERAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int pedirEntero(char mensaje[], int maximo);
float pedirFloat(char mensaje []);
float pedirFloatConMaximo(char mensaje[], float min, float maximo);
void pedirString(char mensaje [], char stringAuxiliar[]);
void pedirStringAlternativo(char mensaje [], char stringAuxiliar[], int min, int max);
void MensajeDeAlerta(int rtn, char mensaje[], char mensajeError[]);
int ValidacionDeStrings(char array[]);
void UpperLower(char array[]);
void menu (void);
void subMenu(void);

void pedirStringAlternativoOnlyNumbers(char mensaje [], char stringAuxiliar[], int min, int max);
#endif
