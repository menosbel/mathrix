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
    cout<<" MATHRIX"              <<endl;
    cout<<" --------------------" << endl;
    cout<<" 1 - JUGAR"            << endl;
    cout<<" 2 - ESTADISTICAS"     << endl;
    cout<<" 3 - CREDITOS"         << endl;
    cout<<" --------------------" << endl;
    cout<<" 0 - SALIR"            << endl;
    cout << " "                   << endl;
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
    cout<< " Vidas: "  << pilas << endl;
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


int ingresar_coordenadax(int coordenadax){
    cout<< "Ingrese coordenada Inicial X [1 al 6]"<< endl;
    cin>> coordenadax;
    coordenadax = validar_movimientox(coordenadax);
    return coordenadax;
}


int ingresar_coordenaday(int coordenaday){
    cout<< "Ingrese coordenada Inicial Y [1 al 6]"<< endl;
    cin>> coordenaday;
    coordenaday = validar_movimientoy(coordenaday);
    return coordenaday;
}


int validar_movimientox(int coordenadax){
    while(coordenadax<1 || coordenadax>6){
      cout<< "Coordenada "<< coordenadax << " fuera de rango" << endl;
      cout<< "Ingrese nuevamente coordenada X"<< endl;
      cin>> coordenadax;
    }
    return coordenadax;
}


int validar_movimientoy(int coordenaday){
    while(coordenaday<1 || coordenaday>6){
      cout<< "Coordenada "<< coordenaday << " fuera de rango" << endl;
      cout<< "Ingrese nuevamente coordenada Y"<< endl;
      cin>> coordenaday;
    }
    return coordenaday;
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

int validar_posiciones(int coordenadax, int coordenaday, int desplazamiento, int pilas,char matrix[6][6], int points){
    string value;
    int newx=0,newy=0,acum=0,acum_aux=0;
    bool good_move = true;
    value = matrix[coordenadax][coordenaday];
/*
    if(value == "X"){

            cout<< "La posicion seleccionada esta inhabilitada, pierdes una vida" << endl;
            good_move = false;
                    }
*/
    switch (desplazamiento){
    //_______________________________________________________________________________________________
                case 8:
                    //first move [x-1][y]
                    newx=coordenadax-1;
                    value = matrix[newx][coordenaday];

                    if(newx == '\0' || value == "X"){
                        cout << "Posicion de dezplasamiento primaria invalida"<<endl;
                        cout << "Pierdes una vida"<<endl;
                        good_move = false;
                    }

                    if(good_move){
                        //Second move [x-2][y]
                        newx=newx-1;
                        value = matrix[newx][coordenaday];
                        if( newx == '\0' || value == "X"){
                                cout << "Posicion de dezplasamiento secundaria invalida"<<endl;
                                cout << "Pierdes una vida"<<endl;
                                good_move = false;
                        }
                    }

                    if(!good_move){
                        pilas--;
                    }
                    return pilas;
                    break;

    //_______________________________________________________________________________________________
                case 2:
                    //first move [x-1][y]
                    newx = coordenadax+1;
                    value = matrix[newx][coordenaday];

                    if( newx == '\0' || value == "X"){
                        cout << "Posicion de dezplasamiento primaria invalida"<<endl;
                        cout << "Pierdes una vida"<<endl;

                        good_move = false;
                    }

                    if(good_move == true){
                        //Second move [x-2][y]
                        newx = newx+1;
                        value = matrix[newx][coordenaday];
                        if( newx == '\0' || value == "X"){
                            cout << "Posicion de dezplasamiento secundaria invalida"<<endl;
                            cout << "Pierdes una vida"<<endl;
                            good_move = false;
                        }
                    }

                    if(!good_move){
                        pilas--;
                    }

                    return pilas;
                    break;

    //_______________________________________________________________________________________________
                case 4:
                    //First move [x][y-1]
                    newy = coordenaday-1;
                    value = matrix[coordenadax][newy];

                    if( newx == '\0' || value == "X"){
                        cout << "Posicion de dezplasamiento primaria invalida"<<endl;
                        cout << "Pierdes una vida"<<endl;
                        good_move = false;
                    }

                    if(good_move == true){
                        //Second move [x][y-2]
                        newx = newx-1;
                        value = matrix[coordenadax][newy];
                        if( newx == '\0' || value == "X"){
                            cout << "Posicion de dezplasamiento secundaria invalida"<<endl;
                            cout << "Pierdes una vida"<<endl;
                            good_move = false;
                        }
                    }

                    if(!good_move){
                        pilas--;
                    }

                    return pilas;
                    break;

    //_______________________________________________________________________________________________
                case 6:
                    //First move [x][y+1]
                    newy=coordenaday+1;
                    value = matrix[coordenadax][newy];

                    if( newx == '\0' || value == "X"){
                        cout << "Posicion de dezplasamiento primaria invalida"<<endl;
                        cout << "Pierdes una vida"<<endl;

                        good_move = false;
                    }

                    if(good_move == true){
                        //Second move [x][y-2]
                        newx = newx+1;
                        value = matrix[coordenadax][newy];
                        if( newx == '\0' || value == "X"){
                            cout << "Posicion de dezplasamiento secundaria invalida"<<endl;
                            cout << "Pierdes una vida"<<endl;
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


int get_points(int points, char matrix[6][6], int coordenadax, int coordenaday, int desplazamiento){
    int newx=0, newy=0, acum = 0 , acum_aux=0;
    string value;
    switch (desplazamiento){
        case 8:
            acum = points;
            cout << "Acum: " << acum << endl;
            acum_aux = matrix[coordenadax][coordenaday] - '0';
            acum += acum_aux;
            matrix[coordenadax][coordenaday] = 'X';
            cout << "Num: " << acum_aux << endl;
            cout << "Acum: " << acum << endl;

            //First move [x-1][y]
            newx=coordenadax - 1;
            acum_aux = matrix[newx][coordenaday] - '0';
            acum += acum_aux;
            matrix[newx][coordenaday] = 'X';
            cout << "Num: " << acum_aux <<endl;
            cout << "Acum: " << acum << endl;

            //Second move [x-2][y]
            newx=coordenadax - 2;
            acum_aux = matrix[newx][coordenaday] - '0';
            matrix[newx][coordenaday] = 'X';
            acum += acum_aux;
            cout << "Num: " << acum_aux << endl;
            cout << "Acum: " << acum << endl;

            points = acum;
            cout << "Points: " << points << endl;
            return points;
            break;

        case 4:
            acum = points;
            acum_aux = matrix[coordenadax][coordenaday] - '0';
            acum = acum + acum_aux;
            matrix[coordenadax][coordenaday] = 'X';
            //Firs25-t move [x][y-1]
            newy=coordenaday-1;
            acum_aux = matrix[coordenadax][newy] - '0';
            acum = acum + acum_aux;
            matrix[coordenadax][newy] = 'X';
            //Second move [x][y-2]
            newx--;
            acum_aux = matrix[coordenadax][newy] - '0';
            acum = acum + acum_aux;
            matrix[coordenadax][newy] = 'X';
            points = acum;
            return points;
            break;
        case 6:
            acum = points;
            acum_aux = matrix[coordenadax][coordenaday] - '0';
            acum = acum + acum_aux;
            matrix[coordenadax][coordenaday] = 'X';
            //First move [x][y-1]
            newy=coordenaday+1;
            acum_aux = matrix[coordenadax][newy] - '0';
            acum = acum + acum_aux;
            matrix[coordenadax][newy] = 'X';
            //Second move [x][y-2]
            newx++;
            acum_aux = matrix[coordenadax][newy] - '0';
            acum = acum + acum_aux;
            matrix[coordenadax][newy] = 'X';
            points = acum;
            return points;
            break;
    }
}


int validar_movimiento(int desplazamiento){
    int desplazamientos[4] = {8,4,2,6};
    bool exists = std::find(std::begin(desplazamientos), std::end(desplazamientos), desplazamiento) != std::end(desplazamientos);

    while(!exists){
        cout<<"Ingrese nuevamente direccion de desplazamiento" << endl;
        cin>>desplazamiento;
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
