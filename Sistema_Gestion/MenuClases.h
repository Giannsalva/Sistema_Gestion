#ifndef MENUCLASES_H_INCLUDED
#define MENUCLASES_H_INCLUDED

void menuClases(){
    int opc;

    setBackgroundColor(YELLOW);
    setlocale(LC_ALL , "Spanish");
    system("cls");

    while(true){
    setColor(GREEN);
    cout<<"----------------------------"<<endl;
    cout<<"         MENU CLASES        "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<endl;

    setColor(BLUE);
    cout<<"1) Registrar presente en clase"<<endl;
    cout<<"2) Listar clases de alumno"<<endl;
    cout<<"3) Listar clases de alumno por fecha"<<endl;
    cout<<"4) Listar clases de profesor"<<endl;
    cout<<"5) Listar clases de profesor por fecha"<<endl;
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

        case 1:presentes();
            break;

        case 2:listarPresenteAlumno();
            break;

        case 3:listarAlumnosFecha();
            break;

        case 4:listarPresenteProfesor();
            break;

        case 5:listarProfesorFecha();
            break;

        case 0:return;

        default:cout<<"ERROR. POR FAVOR, INGRESE UNA OPCION VALIDA"<<endl;
            system("pause>nul");
            system("cls");
            break;

    }
  }
}

#endif // MENUCLASES_H_INCLUDED
