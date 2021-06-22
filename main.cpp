#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "header.h"
using namespace std;
unsigned int microsecond = 1000000;
int accion = 99, coordenadaF = 0, coordenadaC = 0, desplazamiento;
int pilas = 3, aux_pilas = 3, points = 0, round = 0;
char matrix[6][6];
char operacion = ' ';
char calculadora[20];
string name, nombre_mayor_puntaje = "None";
int mayor_puntaje=0;
int main()
{
    while(accion != 0){
        system("cls");
        menu();

        cout << "Indique la accion a realizar: ";
        cin >> accion;
        cout << endl << endl;
        accion = validar_accion_a_realizar(accion);

        if (accion == 1){
            system("cls");
            bienvenida(name, calculadora, pilas, aux_pilas, points, round);
        }

        switch(accion){
            case 1:
                cargar_matrix(matrix);
                //loading(); Descomentar!!!!


                while (pilas > 0){
                    round ++;
                    ingresar_coordenadas(coordenadaF, coordenadaC, matrix, pilas, points, name, round);

                    system("cls");
                    mostar_matrix(matrix, pilas, points, name, round);
                    cout<< "Coordenada  seleccionada: " << coordenadaF <<" , " << coordenadaC << endl;
                    cout << endl;

                    desplazamiento = ingresar_desplazamiento(coordenadaF,  coordenadaC,  desplazamiento);
                    usleep(1 * microsecond);
                    pilas = validar_posiciones(coordenadaF,  coordenadaC,  desplazamiento,  pilas, matrix);

                    if(pilas == aux_pilas){
                        system("cls");
                        mostar_matrix(matrix, pilas, points, name, round);
                        mostar_info_jugada(coordenadaF, coordenadaC, matrix, desplazamiento);
                        operacion = ingresar_operacion(operacion);
                        usleep(1 * microsecond);
                        points = get_points(points, pilas, matrix, coordenadaF, coordenadaC, desplazamiento, operacion);

                    } else {
                        aux_pilas = pilas;
                        cout << "Tu movimiento no es valido. Perdiste una pila." << endl << endl;
                    }

                    system("pause");
                    system("cls");
                    mostar_matrix(matrix, pilas, points, name, round);
                  }

                  cout<<"PERDISTE :(" << endl << endl;

                  if (points > mayor_puntaje){
                        nombre_mayor_puntaje = name;
                        mayor_puntaje = points;
                        cout << "Tu puntaje es el mejor que hemos visto en mucho tiempo." << endl;
                        cout << "Podras ver tu nombre en nuestras estadisticas." << endl;
                        cout << "Hasta que alguien te desplace..." << endl << endl;
                    }
                  system("pause");
                  break;

           case 2:
               obtener_mayor_puntaje(nombre_mayor_puntaje, mayor_puntaje);
               break;
           case 3:
                creditos();
                break;

          }//end Switch
      }//end While
      system("cls");
      cout << "-----------------------------------" << endl;
      cout<< "     Gracias por jugar a MATHRIX     " << endl;
      cout << "-----------------------------------" << endl;
      system("pause");

}//end Main
