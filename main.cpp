#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "header.h"
using namespace std;
unsigned int microsecond = 1000000;
int accion = 99, coordenadax = 0, coordenaday = 0, desplazamiento;
int pilas = 3, aux_pilas = 3, points = 0;
char matrix[6][6];
char operacion = ' ';
int main()
{
    menu();
    while(accion != 0){
        cout<< "Indique la accion a realizar: ";
        cin >> accion;

        switch(accion){
            case 1: //Bloque de instrucciones 1;
                  cargar_matrix(matrix);
                  //loading(); Descomentar!!!!
                  mostar_matrix(matrix,pilas,points);

                  while (pilas > 0){
                        coordenadax = ingresar_coordenadax(coordenadax);
                        coordenaday = ingresar_coordenaday(coordenaday);

                        bool valid_movement = false;
                        while (!valid_movement){
                            char selected_number = matrix[coordenadax][coordenaday];
                            valid_movement = validar_numero_seleccionado(selected_number);
                        }

                        system("cls");
                        mostar_matrix(matrix,pilas,points);

                        //Ingreso posicion matrix en Y
                        cout<< "Coordenada  seleccionada: " << coordenadax <<" , " << coordenaday << endl;
                        cout<<"Ingrese direccion de desplazamiento" << endl;
                        instruccion_de_movimiento();
                        cin>> desplazamiento;

                        desplazamiento = validar_movimiento(desplazamiento);
                        cout<<"Validando input..." << endl;

                        usleep(3 * microsecond);

                        pilas = validar_posiciones(coordenadax,  coordenaday,  desplazamiento,  pilas, matrix, points);

                        if(pilas == aux_pilas){
                            system("cls");
                            mostar_matrix(matrix,pilas,points);
                            cout<< "Coordenada  seleccionada: " << coordenadax <<" , " << coordenaday << endl;
                            cout<< "Sentido de desplazamiento: " << desplazamiento << endl;
                            instruccion_de_operacion();
                            cin>> operacion;
                            operacion = validar_operacion(operacion);
                            cout<< "Operacion elegida: " << operacion << endl;
                            points = get_points(points, matrix, coordenadax, coordenaday, desplazamiento);

                        } else {
                            aux_pilas = pilas;
                        }

                        system("pause");
                        system("cls");
                        mostar_matrix(matrix,pilas,points);
                        menu();
                        cout<< "Indique la accion a realizar: ";
                        cin >> accion;
                  }

                  cout<<"PERDISTE :(" << endl;
                  system("pause");
                  system("cls");
                  menu();
                  break;

           case 2: //Bloque de instrucciones 2;
                  break;
           case 3: //Bloque de instrucciones 3;
                  creditos();
                  break;

          }//end Switch
      }//end While
      system("cls");
      cout<< "Gracias por Jugar" << endl;
      system("pause");

}//end Main
