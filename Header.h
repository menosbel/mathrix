#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
using namespace std;

int menu();
int creditos();
int cargar_matrix(char matrix[6][6]);
int mostar_matrix(char matrix[6][6],int pilas, int points);
int loading();

int ingresar_coordenadax(int coordenadax);
int validar_movimientox(int coordenadax);
int ingresar_coordenaday(int coordenaday);
int validar_movimientoy(int coordenaday);
bool validar_numero_seleccionado(int number);

int instruccion_de_movimiento();
int validar_posiciones(int coordenadax, int coordenaday, int desplazamiento, int pilas,char matrix[6][6],int points);
int get_points(int points,char matrix[6][6],int coordenadax, int coordenaday, int desplazamiento);
int validar_movimiento(int desplazamiento);
char validar_operacion(char operacion);
int instruccion_de_operacion();

#endif // HEADER_H_INCLUDED
