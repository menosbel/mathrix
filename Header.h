#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
using namespace std;

void bienvenida(string &name, char calculadora[20], int &pilas, int &aux_pilas, int &points, int &round);
void menu();
int validar_accion_a_realizar(int accion);

void obtener_mayor_puntaje(string nombre_mayor_puntaje, int mayor_puntaje);
void creditos();

int cargar_matrix(char matrix[6][6]);
int mostar_matrix(char matrix[6][6], int pilas, int points, string name, int round);
int loading();

void ingresar_coordenadas(int &coordenadaF, int &coordenadaC, char matrix[6][6], int &pilas, int points, string name, int round);
int ingresar_coordenadaF(int coordenadaF);
int ingresar_coordenadaC(int coordenadaC);
int validar_coordenada(int coordenada);
bool validar_numero_seleccionado(int number);

int suma(int num1, int num2);
int resta(int num1, int num2);
int multiplicacion(int num1, int num2);
int division(int num1, int num2);
int resto(int num1, int num2);

int ingresar_desplazamiento(int coordenadaF,  int coordenadaC,  int desplazamiento);
void instruccion_de_desplazamiento();
void mostar_info_jugada(int coordenadaF, int coordenadaC, char matrix[6][6], int desplazamiento);
string traducir_desplazamiento(int desplazamiento);
int validar_movimiento(int desplazamiento);
int validar_posiciones(int coordenadax, int coordenaday, int desplazamiento, int pilas, char matrix[6][6]);

char ingresar_operacion(char operacion);
void instruccion_de_operacion();
char validar_operacion(char operacion);

int get_points(int points,int &pilas, char matrix[6][6],int coordenadaF, int coordenadaC, int desplazamiento, char operacion);

#endif // HEADER_H_INCLUDED
