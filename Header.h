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

void validar_accion_a_realizar(int accion);

int ingresar_coordenadaF(int coordenadaF);
int ingresar_coordenadaC(int coordenadaC);
int validar_coordenada(int coordenada);
bool validar_numero_seleccionado(int number);

int suma(int num1, int num2);
int resta(int num1, int num2);
int multiplicacion(int num1, int num2);
int division(int num1, int num2);
int resto(int num1, int num2);

int instruccion_de_movimiento();
string traducir_movimiento(char movimiento);
int validar_posiciones(int coordenadax, int coordenaday, int desplazamiento, int pilas,char matrix[6][6],int points);
int validar_movimiento(int desplazamiento);

int instruccion_de_operacion();
char validar_operacion(char operacion);

int get_points(int points,int &pilas, char matrix[6][6],int coordenadaF, int coordenadaC, int desplazamiento, char operacion);

#endif // HEADER_H_INCLUDED
