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



int menu()
{
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

int creditos(){
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


int mostar_matrix(char matrix[6][6],int pilas, int points){
    bool first = true;
    int line = 1;
    system("cls");
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
    int acciones[5] = {1, 2, 3, 0};
    bool exists = std::find(std::begin(acciones), std::end(acciones), accion) != std::end(acciones);

    while(!exists){
        cout<<"Accion invalida. Ingrese otra: ";
        cin>>operacion;
        bool exists = std::find(std::begin(acciones), std::end(acciones), accion) != std::end(acciones);
    }
    return accion;
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
    } else {
        return false;
    }
}

int instruccion_de_movimiento(){
    cout<<"8 - Arriba"<<endl;
    cout<<"2 - Abajo"<<endl;
    cout<<"4 - Izquierda"<<endl;
    cout<<"6 - Derecha"<<endl;
}

int instruccion_de_operacion(){
    cout<<"Suma               -> +"<<endl;
    cout<<"Resta              -> -"<<endl;
    cout<<"Multiplicacion     -> *"<<endl;
    cout<<"Division(Cociente) -> /"<<endl;
    cout<<"Division(Resto)    -> %"<<endl;
}

string traducir_movimiento(char movimiento){
    switch(movimiento){
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


int validar_posiciones(int coordenadaF, int coordenadaC, int desplazamiento, int pilas,char matrix[6][6], int points){
    string value;
    int newF=0,newC=0,acum=0,acum_aux=0;
    bool good_move = true;
    value = matrix[coordenadaF][coordenadaC];

    switch (desplazamiento){
        case 8:
            //first move [x-1][y]
            newF=coordenadaF - 1;
            value = matrix[newF][coordenadaC];

            if(newF == '\0' || value == "X"){
                good_move = false;
            }

            if(good_move){
                //Second move [x-2][y]
                newF=newF-1;
                value = matrix[newF][coordenadaC];
                if( newF == '\0' || value == "X"){
                    good_move = false;
                }
            }

            if(!good_move){
                pilas--;
            }
            return pilas;
            break;

        case 2:
            //first move [x+1][y]
            newF = coordenadaF + 1;
            value = matrix[newF][coordenadaC];

            if( newF == '\0' || value == "X"){
                good_move = false;
            }

            if(good_move == true){
                //Second move [x+2][y]
                newF = newF + 1;
                value = matrix[newF][coordenadaC];
                if( newF == '\0' || value == "X"){
                    good_move = false;
                }
            }

            if(!good_move){
                pilas--;
            }

            return pilas;
            break;

        case 4:
            //First move [x][y-1]
            newC = coordenadaC - 1;
            value = matrix[coordenadaF][newC];

            if( newC == '\0' || value == "X"){
                good_move = false;
            }

            if(good_move == true){
                //Second move [x][y-2]
                newC = newC - 1;
                value = matrix[coordenadaF][newC];
                if( newC == '\0' || value == "X"){
                    good_move = false;
                }
            }

            if(!good_move){
                pilas--;
            }

            return pilas;
            break;

        case 6:
            //First move [x][y+1]
            newC=coordenadaC + 1;
            value = matrix[coordenadaF][newC];

            if( newC == '\0' || value == "X"){
                good_move = false;
            }

            if(good_move == true){
                //Second move [x][y-2]
                newC = newC + 1;
                value = matrix[coordenadaF][newC];
                if( newC == '\0' || value == "X"){
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
    case '/':
        res = division(num1, num2);
    case '%':
        res = resto(num1, num2);
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

            if (result == res){
                matrix[coordenadaF][coordenadaC] = 'X';
                matrix[newCoor][coordenadaC] = 'X';
                matrix[newCoorRes][coordenadaC] = 'X';
                points = acum + num1 + num2 + result;
                cout << "El resultado es correcto. Sumaste " << points << " puntos!" << endl;
            } else {
                cout << "Resultado incorrecto. Perdieste una pila" << endl;
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

            if (result == res){
                matrix[coordenadaF][coordenadaC] = 'X';
                matrix[newCoor][coordenadaC] = 'X';
                matrix[newCoorRes][coordenadaC] = 'X';
                points = acum + num1 + num2 + result;
            } else {
                cout << "Resultado incorrecto. Perdiste una pila" << endl;
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

            if (result == res){
                matrix[coordenadaF][coordenadaC] = 'X';
                matrix[coordenadaF][newCoor] = 'X';
                matrix[coordenadaF][newCoorRes] = 'X';
                points = acum + num1 + num2 + result;
            } else {
                cout << "Resultado incorrecto. Perdiste una pila" << endl;
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

            if(result == res){
                matrix[coordenadaF][coordenadaC] = 'X';
                matrix[coordenadaF][newCoor] = 'X';
                matrix[coordenadaF][newCoorRes] = 'X';
                points = acum + num1 + num2 + result;
            } else {
                cout << "Resultado incorrecto. Perdiste una pila" << endl;
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
        cout<<"Ingrese una direccion de desplazamiento valida: ";
        cin>>desplazamiento;
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
        bool exists = std::find(std::begin(operaciones), std::end(operaciones), operacion) != std::end(operaciones);
    }
    return operacion;
}
