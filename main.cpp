#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "header.h"
using namespace std;
unsigned int microsecond = 1000000;
int accion = 99, coordenadaF = 0, coordenadaC = 0, desplazamiento;
int pilas = 3, aux_pilas = 3, points = 0;
char matrix[6][6];
char operacion = ' ';
int main()
{
    menu();
    while(accion != 0){
        pilas = 3;
        aux_pilas = 3;
        points = 0;
        cout<< "Indique la accion a realizar: ";
        cin >> accion;
        accion = validar_accion_a_realizar(accion)

        switch(accion){
            case 1:
                  cargar_matrix(matrix);
                  //loading(); Descomentar!!!!
                  mostar_matrix(matrix, pilas, points);

                  while (pilas > 0){
                        coordenadaF = ingresar_coordenadaF(coordenadaF);
                        coordenadaC = ingresar_coordenadaC(coordenadaC);

                        bool valid_movement = false;
                        while (!valid_movement){
                            char selected_number = matrix[coordenadaF][coordenadaC];
                            valid_movement = validar_numero_seleccionado(selected_number);
                            if (!valid_movement) {
                                cout << "Coordenada incorrecta" << endl;
                                coordenadaF = ingresar_coordenadaF(coordenadaF);
                                coordenadaC = ingresar_coordenadaC(coordenadaC);
                            }
                        }

                        system("cls");
                        mostar_matrix(matrix, pilas, points);

                        cout<< "Coordenada  seleccionada: " << coordenadaF <<" , " << coordenadaC << endl;
                        cout << endl;
                        cout<<"Hacia donde te queres desplazar?" << endl;
                        instruccion_de_movimiento();
                        cin>> desplazamiento;

                        desplazamiento = validar_movimiento(desplazamiento);
                        cout<<"Validando input..." << endl;
                        usleep(3 * microsecond);

                        pilas = validar_posiciones(coordenadaF,  coordenadaC,  desplazamiento,  pilas, matrix, points);

                        if(pilas == aux_pilas){
                            system("cls");
                            mostar_matrix(matrix,pilas,points);
                            cout<< "Coordenada  seleccionada: " << coordenadaF <<" , " << coordenadaC << endl;
                            cout << "Numero seleccionado: " << matrix[coordenadaF][coordenadaC] << endl;
                            string movimiento = traducir_movimiento(desplazamiento);
                            cout<< "Sentido de desplazamiento: " << movimiento << endl;
                            cout << endl;

                            instruccion_de_operacion();
                            cin>> operacion;
                            operacion = validar_operacion(operacion);
                            cout<< "Operacion elegida: " << operacion << endl;

                            cout<<"Validando operacion..." << endl;
                            usleep(3 * microsecond);

                            points = get_points(points, pilas, matrix, coordenadaF, coordenadaC, desplazamiento, operacion);

                        } else {
                            aux_pilas = pilas;
                            cout << "Tu movimiento no es valido. Perdiste una pila." << endl;
                        }

                        system("pause");
                        system("cls");
                        mostar_matrix(matrix,pilas,points);
                        menu();
                        cout<< "Indique la accion a realizar: ";
                        cin >> accion;
                  }

                  cout<<"PERDISTE :(" << endl;
                  // Fijarme cuantos puntos hizo y si entra en la lista de puntajes maximos
                  // Pedirle nombre y guardarlo
                  system("pause");
                  system("cls");
                  menu();
                  break;

           case 2: //Bloque de instrucciones 2;
                  break;
           case 3:
                  creditos();
                  break;

          }//end Switch
      }//end While
      system("cls");
      cout<< "Gracias por Jugar" << endl;
      system("pause");

}//end Main
