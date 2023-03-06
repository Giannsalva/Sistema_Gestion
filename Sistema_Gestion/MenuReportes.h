#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

void menuReportes(){
    int opc;

    setBackgroundColor(YELLOW);
    setlocale(LC_ALL , "Spanish");
    system("cls");

    while(true){
    setColor(GREEN);
    cout<<"----------------------------"<<endl;
    cout<<"       MENU REPORTES        "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<endl;

    setColor(BLUE);
    cout<<"1) Cantidad de clases dadas por profesor por mes"<<endl;
    cout<<"2) Cantidad de dinero acumulado por profesor por mes"<<endl;
    cout<<"3) Cantidad de clases tomadas por alumno por mes"<<endl;
    cout<<"4) Cantidad de dinero abonado por alumno por mes"<<endl;
    cout<<"5) Cantidad de artículos vendidos por mes"<<endl;
    cout<<"6) Cantidad de dinero acumulado por articulo por mes"<<endl;
    cout<<endl;
    cout<<"0) Volver al menu principal"<<endl;
    cout<<endl;

    setColor(GREEN);
    cout<<"----------------------------"<<endl;
    cout<<"INGRESE UNA OPCION: ";
    cin>>opc;
    system("cls");
    setColor(BLUE);

    switch(opc){

        case 1:ClasesMesProfesores();
            break;

        case 2:DineroMesProfesores();
            break;

        case 3:ClasesMesAlumnos();
            break;

        case 4:AbonoMesAlumnos();
            break;

        case 5:VentasMesArticulos();
            break;

        case 6:DineroMesArticulos();
            break;

        case 0:return;

        default:cout<<"ERROR. POR FAVOR, INGRESE UNA OPCION VALIDA"<<endl;
            system("pause>nul");
            system("cls");
            break;

    }
  }
}

#endif // MENUREPORTES_H_INCLUDED
