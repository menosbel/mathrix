#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <iterator>
#include "header.h"
using namespace std;

void bienvenida(string &name, char calculadora[20], int pilas, int aux_pilas, int points, int round){
    pilas = 3;
    aux_pilas = 3;
    points = 0;
    round = 0;
    cout << endl;
    cout << "Ingresa tu nombre: ";
    cin >> name;
    cout << "Modelo favorito de calculadora: ";
    cin >> calculadora;
    system("cls");
    cout << "Hola, " << name << endl << endl;
    cout << "-----------------------------------" << endl;
    cout << "       Bienvenidx a MATHRIX        " << endl;
    cout << "-----------------------------------" << endl << endl;
    cout << "Let the game begin..." << endl << endl;
    system("pause");
}


void menu(){
    cout<< " "                    << endl;
    cout<<" MATHRIX"              << endl;
    cout<<" --------------------" << endl;
    cout<<" 1 - JUGAR"            << endl;
    cout<<" 2 - ESTADISTICAS"     << endl;
    cout<<" 3 - CREDITOS"         << endl;
    cout<<" --------------------" << endl;
    cout<<" 0 - SALIR"            << endl;
    cout<< " "                   << endl;
}


void obtener_mayor_puntaje(string nombre_mayor_puntaje, int mayor_puntaje){
    if (mayor_puntaje != 0){
        cout << "---------------------------------------------" << endl;
        cout << "   Mayor puntaje en la historia de MATHRIX   " << endl;
        cout << "---------------------------------------------" << endl << endl;
        cout << "Nombre: " << nombre_mayor_puntaje << "      Puntaje: " << mayor_puntaje << endl;
    } else {
        cout << "Nadie ha logrado hacer puntos en MATHRIX aun." << endl;
        cout << "Animate a intentarlo..." << endl << endl;
    }
    system("pause");
}


void creditos(){
    system("cls");
    cout << " Equipo - Los caballeros del Zoodiaco"     << endl;
    cout << " Los integrantes de este equipo son: "    << endl;
    cout << " * 25005 - Solange Giselle Marquesto"     << endl;
    cout << " * 24967 - Maria Belen Fernandez Navarro" << endl;
    cout << " * 24972 - Stefano Freddato"              << endl;
    cout << "" << endl;

    system("PAUSE");
    system("cls");
    menu();
}


int cargar_matrix(char matrix[6][6]){
    const char ab[11]= { "0123456789" };
    srand (time(NULL)); // Reboot Random Generator
    for(int x=1;x<=6;x++){
        for(int y=1;y<=6;y++){
            matrix[x][y] = ab[rand() % 10];
        }
    }
}


int mostar_matrix(char matrix[6][6],int pilas, int points, string name, int round){
    bool first = true;
    int line = 1;
    system("cls");
    cout<< " Jugador/a: " << name << endl;
    cout<< " Ronda: " << round << endl;
    cout<< " Pilas: "  << pilas << endl;
    cout<< " Puntos: " << points << endl;

    cout << "" << endl;
    cout << "   ____________________________" << endl;
    cout << "" << endl;

    for(int x=1;x<=6;x++){
        for(int y=1;y<=6;y++){
            if(y == 1){
                cout<<line<<" | "<<  matrix[x][y] << " ";
                line++;
           } else if (y>1 && y<6){
                cout<<" | "<<  matrix[x][y] << " ";
           } else {
                cout<<" | "<<  matrix[x][y] << " | ";
           }
        }
        cout<<endl;
    }
    cout << "   ____________________________" << endl;
    cout << "    1    2    3    4    5    6" << endl;
    cout << "" << endl;

}


int loading(){
 	int i = 0;
 	char load[26];
 	while(i < 25)
 	{
 		system("cls");
 		load[i++] = '#';
 		load[i] = '\0';

		printf("\n\nLOADING [%-25s]", load);
 		usleep(199900);
 	}

 system("cls");
 printf("\n");
}


int validar_accion_a_realizar(int accion){
    int acciones[4] = {1, 2, 3, 0};
    bool exists = std::find(std::begin(acciones), std::end(acciones), accion) != std::end(acciones);

    while(!exists){
        cout<<"Accion invalida. Ingrese otra: ";
        cin>>accion;
        exists = std::find(std::begin(acciones), std::end(acciones), accion) != std::end(acciones);
    }
    return accion;
}


void ingresar_coordenadas(int &coordenadaF, int &coordenadaC, char matrix[6][6], int &pilas, int points, string name, int round){
    mostar_matrix(matrix, pilas, points, name, round);
    coordenadaF = ingresar_coordenadaF(coordenadaF);
    coordenadaC = ingresar_coordenadaC(coordenadaC);

    bool valid_number = false;
    while (!valid_number){
        char selected_number = matrix[coordenadaF][coordenadaC];
        valid_number = validar_numero_seleccionado(selected_number);
        if (!valid_number) {
            cout << "No podes seleccionar una coordenada con una X. Perdes una pila" << endl << endl;
            pilas --;
            system("pause");
            system("cls");
            ingresar_coordenadas(coordenadaF, coordenadaC, matrix, pilas, points, name, round);
        }
    }
}


int ingresar_coordenadaF(int coordenadaF){
    cout<< "Ingrese la fila [1 al 6]"<< endl;
    cin>> coordenadaF;
    coordenadaF = validar_coordenada(coordenadaF);
    return coordenadaF;
}


int ingresar_coordenadaC(int coordenadaC){
    cout<< "Ingrese la columna [1 al 6]"<< endl;
    cin>> coordenadaC;
    coordenadaC = validar_coordenada(coordenadaC);
    return coordenadaC;
}


int validar_coordenada(int coordenada){
    while(coordenada<1 || coordenada>6){
      cout<< "Coordenada "<< coordenada << " fuera de rango" << endl;
      cout<< "Ingrese una nueva: "<< endl;
      cin>> coordenada;
    }
    return coordenada;
}


bool validar_numero_seleccionado(int number){
    if(number != 'X') {
        return true;
    } else if(number == 'X'){
        return false;
    }
}

void instruccion_de_desplazamiento(){
    cout<<"8 - Arriba"<<endl;
    cout<<"2 - Abajo"<<endl;
    cout<<"4 - Izquierda"<<endl;
    cout<<"6 - Derecha"<<endl;
}

int ingresar_desplazamiento(int coordenadaF,  int coordenadaC,  int desplazamiento){
    cout<<"Hacia donde te queres mover?" << endl;
    instruccion_de_desplazamiento();
    cin>> desplazamiento;
    desplazamiento = validar_movimiento(desplazamiento);
    cout<<"Validando input..." << endl;
    return desplazamiento;
}

char ingresar_operacion(char operacion){
    instruccion_de_operacion();
    cin>> operacion;
    operacion = validar_operacion(operacion);
    cout<< "Operacion elegida: " << operacion << endl;
    cout<<"Validando operacion..." << endl;
    return operacion;
}


void instruccion_de_operacion(){
    cout<<"Suma               -> +"<<endl;
    cout<<"Resta              -> -"<<endl;
    cout<<"Multiplicacion     -> *"<<endl;
    cout<<"Division(Cociente) -> /"<<endl;
    cout<<"Division(Resto)    -> %"<<endl;
}

string traducir_desplazamiento(int desplazamiento){
    switch(desplazamiento){
        case 8:
            return "Arriba";
        case 2:
            return "Abajo";
        case 4:
            return "Izquierda";
        case 6:
            return "Derecha";
    }
}

void mostar_info_jugada(int coordenadaF, int coordenadaC, char matrix[6][6], int desplazamiento){
    cout<< "Coordenada  seleccionada: " << coordenadaF <<" , " << coordenadaC << endl;
    cout << "Numero seleccionado: " << matrix[coordenadaF][coordenadaC] << endl;
    string desplazamiento_words = traducir_desplazamiento(desplazamiento);
    cout<< "Sentido de desplazamiento: " << desplazamiento_words << endl << endl;
}


int validar_posiciones(int coordenadaF, int coordenadaC, int desplazamiento, int pilas, char matrix[6][6]){
    string value;
    int newF=0, newC=0, acum=0, acum_aux=0;
    bool good_move = true;
    value = matrix[coordenadaF][coordenadaC];

    switch (desplazamiento){
        case 8:
            newF = coordenadaF - 1;
            value = matrix[newF][coordenadaC];

            if(newF > 6 || newF < 1 || value == "X"){
                good_move = false;
            } else {
                newF = coordenadaF - 2;
                value = matrix[newF][coordenadaC];
                if( newF > 6 || newF < 1 || value == "X"){
                    good_move = false;
                }
            }

            if(!good_move){
                pilas--;
            }

            return pilas;
            break;

        case 2:
            newF = coordenadaF + 1;
            value = matrix[newF][coordenadaC];

            if(newF > 6 || newF < 1 || value == "X"){
                good_move = false;
            } else {
                newF = coordenadaF + 2;
                value = matrix[newF][coordenadaC];
                if(newF > 6 || newF < 1 || value == "X"){
                    good_move = false;
                }
            }

            if(!good_move){
                pilas--;
            }

            return pilas;
            break;

        case 4:
            newC = coordenadaC - 1;
            value = matrix[coordenadaF][newC];

            if(newC > 6 || newC < 1 || value == "X"){
                good_move = false;
            } else {
                newC = coordenadaC - 2;
                value = matrix[coordenadaF][newC];
                if(newC > 6 || newC < 1 || value == "X"){
                    good_move = false;
                }
            }

            if(!good_move){
                pilas--;
            }

            return pilas;
            break;

        case 6:
            newC = coordenadaC + 1;
            value = matrix[coordenadaF][newC];
            if(newC > 6 || newC < 1 || value == "X"){
                good_move = false;
            } else {
                newC = coordenadaC + 2;
                value = matrix[coordenadaF][newC];
                if(newC > 6 || newC < 1 || value == "X"){
                    good_move = false;
                }
            }

            if(!good_move){
                pilas--;
            }

            return pilas;
            break;
    }
}

int suma(int num1, int num2){
    int res;
    res = num1 + num2;
    return res;
}

int resta(int num1, int num2){
    int res;
    res = num1 - num2;
    return res;
}

int multiplicacion(int num1, int num2){
    int res;
    res = num1 * num2;
    return res;
}

int division(int num1, int num2){
    int res;
    res = num1 / num2;
    return res;
}

int resto(int num1, int num2){
    int res;
    res = num1 % num2;
    return res;
}


int do_the_math(int num1, int num2, char operacion){
    int res=0;
    switch(operacion){
        case '+':
            res = suma(num1, num2);
            break;
        case '-':
            res = resta(num1, num2);
            break;
        case '*':
            res = multiplicacion(num1, num2);
            break;
        case '/':
            res = division(num1, num2);
            break;
        case '%':
            res = resto(num1, num2);
            break;
    }
    return res;
}


int get_points(int points, int &pilas, char matrix[6][6], int coordenadaF, int coordenadaC, int desplazamiento, char operacion){
    int newCoor=0, newCoorRes=0, acum = 0 , num1=0, num2=0, result=0, res;
    string value;
    acum = points;
    num1 = matrix[coordenadaF][coordenadaC] - '0';

    switch (desplazamiento){
        case 8: // arriba
            newCoor=coordenadaF - 1;
            num2 = matrix[newCoor][coordenadaC] - '0';

            newCoorRes=coordenadaF - 2;
            result = matrix[newCoorRes][coordenadaC] - '0';
            res = do_the_math(num1, num2, operacion);
            cout << num1 << " " << operacion << " " << num2 << " = " << result << endl;

            if (result == res){
                matrix[coordenadaF][coordenadaC] = 'X';
                matrix[newCoor][coordenadaC] = 'X';
                matrix[newCoorRes][coordenadaC] = 'X';
                points = acum + num1 + num2 + result;
                int points_round;
                points_round = points - acum;
                cout << "El resultado es correcto. Sumaste " << points_round << " puntos!" << endl << endl;
            } else {
                cout << "Resultado incorrecto. Perdiste una pila" << endl << endl;
                pilas --;
            }

            return points;
            break;

        case 2: // abajo
            newCoor=coordenadaF + 1;
            num2 = matrix[newCoor][coordenadaC] - '0';

            newCoorRes=coordenadaF + 2;
            result = matrix[newCoorRes][coordenadaC] - '0';
            res = do_the_math(num1, num2, operacion);
            cout << num1 << " " << operacion << " " << num2 << " = " << result << endl;

            if (result == res){
                matrix[coordenadaF][coordenadaC] = 'X';
                matrix[newCoor][coordenadaC] = 'X';
                matrix[newCoorRes][coordenadaC] = 'X';
                points = acum + num1 + num2 + result;
                int points_round;
                points_round = points - acum;
                cout << "El resultado es correcto. Sumaste " << points_round << " puntos!" << endl << endl;
            } else {
                cout << "Resultado incorrecto. Perdiste una pila." << endl << endl;
                pilas --;
            }

            return points;
            break;

        case 4: // izquierda
            newCoor = coordenadaC - 1;
            num2 = matrix[coordenadaF][newCoor] - '0';

            newCoorRes = coordenadaC - 2;
            result = matrix[coordenadaF][newCoorRes];
            res = do_the_math(num1, num2, operacion);
            cout << num1 << " " << operacion << " " << num2 << " = " << result << endl;

            if (result == res){
                matrix[coordenadaF][coordenadaC] = 'X';
                matrix[coordenadaF][newCoor] = 'X';
                matrix[coordenadaF][newCoorRes] = 'X';
                points = acum + num1 + num2 + result;
                int points_round;
                points_round = points - acum;
                cout << "El resultado es correcto. Sumaste " << points_round << " puntos!" << endl << endl;
            } else {
                cout << "Resultado incorrecto. Perdiste una pila." << endl << endl;
                pilas --;
            }

            return points;
            break;

        case 6: // derecha
            newCoor = coordenadaC + 1;
            num2 = matrix[coordenadaF][newCoor] - '0';

            newCoorRes = coordenadaC + 2;
            result = matrix[coordenadaF][newCoorRes] - '0';
            res = do_the_math(num1, num2, operacion);
            cout << num1 << " " << operacion << " " << num2 << " = " << result << endl;

            if(result == res){
                matrix[coordenadaF][coordenadaC] = 'X';
                matrix[coordenadaF][newCoor] = 'X';
                matrix[coordenadaF][newCoorRes] = 'X';
                points = acum + num1 + num2 + result;
                int points_round;
                points_round = points - acum;
                cout << "El resultado es correcto. Sumaste " << points_round << " puntos!" << endl << endl;
            } else {
                cout << "Resultado incorrecto. Perdiste una pila." << endl << endl;
                pilas --;
            }

            return points;
            break;
    }
}


int validar_movimiento(int desplazamiento){
    int desplazamientos[4] = {8,4,2,6};
    bool exists = std::find(std::begin(desplazamientos), std::end(desplazamientos), desplazamiento) != std::end(desplazamientos);

    while(!exists){
        cout << "Ingrese una direccion de desplazamiento valida: ";
        cin >> desplazamiento;
        cout << endl;
        exists = std::find(std::begin(desplazamientos), std::end(desplazamientos), desplazamiento) != std::end(desplazamientos);
     }
    return desplazamiento;
}


char validar_operacion(char operacion){
    int operaciones[5] = {'+','-','%','/','*'};
    bool exists = std::find(std::begin(operaciones), std::end(operaciones), operacion) != std::end(operaciones);

    while(!exists){
        cout<<"Ingrese nuevamente la operacion" << endl;
        cin>>operacion;
        exists = std::find(std::begin(operaciones), std::end(operaciones), operacion) != std::end(operaciones);
    }
    return operacion;
}
