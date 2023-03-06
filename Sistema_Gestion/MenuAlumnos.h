#ifndef MENUALUMNOS_H_INCLUDED
#define MENUALUMNOS_H_INCLUDED

void menuAlumnos(){
    int opc;

    setBackgroundColor(YELLOW);
    setlocale(LC_ALL , "Spanish");
    system("cls");

    while(true){
    setColor(GREEN);
    cout<<"----------------------------"<<endl;
    cout<<"         MENU ALUMNOS       "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<endl;

    setColor(BLUE);
    cout<<"1) Listar alumno por nombre"<<endl;
    cout<<"2) Listar alumnos alfabeticamente"<<endl;
    cout<<"3) Dar de alta alumno"<<endl;
    cout<<"4) Dar de baja alumno"<<endl;
    cout<<"5) Modificar alumno"<<endl;
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

        case 1:listarAlumnoNombre();
            break;

        case 2:listarAlumnosAlfabeticamente();
            break;

        case 3:altaAlumno();
            break;

        case 4:bajaAlumno();
            break;

        case 5:modificarAlumno();
            break;

        case 0:return;

        default:cout<<"ERROR. POR FAVOR, INGRESE UNA OPCION VALIDA"<<endl;
            system("pause>nul");
            system("cls");
            break;

    }
  }
}

#endif // MENUALUMNOS_H_INCLUDED
