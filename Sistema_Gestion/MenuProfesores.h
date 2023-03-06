#ifndef MENUPROFESORES_H_INCLUDED
#define MENUPROFESORES_H_INCLUDED

void menuProfesores(){
    int opc;

    setBackgroundColor(YELLOW);
    setlocale(LC_ALL , "Spanish");
    system("cls");

    while(true){
    setColor(GREEN);
    cout<<"----------------------------"<<endl;
    cout<<"       MENU PROFESORES      "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<endl;

    setColor(BLUE);
    cout<<"1) Listar profesor por nombre"<<endl;
    cout<<"2) Listar profesores alfabeticamente"<<endl;
    cout<<"3) Dar de alta profesor"<<endl;
    cout<<"4) Dar de baja profesor"<<endl;
    cout<<"5) Modificar profesor"<<endl;
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

        case 1:listarProfesorNombre();
            break;

        case 2:listarProfesoresAlfabeticamente();
            break;

        case 3:altaProfesor();
            break;

        case 4:bajaProfesor();
            break;

        case 5:modificarProfesor();
            break;

        case 0:return;

        default:cout<<"ERROR. POR FAVOR, INGRESE UNA OPCION VALIDA"<<endl;
            system("pause>nul");
            system("cls");
            break;

    }
  }
}

#endif // MENUPROFESORES_H_INCLUDED
