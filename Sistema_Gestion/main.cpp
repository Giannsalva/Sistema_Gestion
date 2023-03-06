#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#include "rlutil.h"

using namespace rlutil;

#include "cargarcadena.h"
#include "clases.h"
#include "funciones.h"
#include "MenuProfesores.h"
#include "MenuAlumnos.h"
#include "MenuClases.h"
#include "MenuArticulos.h"
#include "MenuReportes.h"

int main()
{
    int opc;

    setBackgroundColor(YELLOW);
    setlocale(LC_ALL , "Spanish");
    system("cls");

    while(true){
    setColor(GREEN);
    cout<<"----------------------------"<<endl;
    cout<<"           SGATC            "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<endl;

    setColor(BLUE);
    cout<<"1) Profesores"<<endl;
    cout<<"2) Alumnos"<<endl;
    cout<<"3) Clases"<<endl;
    cout<<"4) Articulos"<<endl;
    cout<<"5) Reportes"<<endl;
    cout<<endl;
    cout<<"0) Fin del programa"<<endl;
    cout<<endl;

    setColor(GREEN);
    cout<<"----------------------------"<<endl;
    cout<<"INGRESE UNA OPCION: ";
    cin>>opc;
    system("cls");
    setColor(BLUE);

    switch(opc){

        case 1:menuProfesores();
            break;

        case 2:menuAlumnos();
            break;

        case 3:menuClases();
            break;

        case 4:menuArticulos();
            break;

        case 5:menuReportes();
            break;

        case 0:cout<<"FIN DEL PROGRAMA."<<endl;
            return 0;
            break;

        default:cout<<"ERROR. POR FAVOR, INGRESE UNA OPCION VALIDA"<<endl;
            system("pause>nul");
            system("cls");
            break;
    }
  }

return 0;
}
