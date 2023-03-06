#ifndef MENUARTICULOS_H_INCLUDED
#define MENUARTICULOS_H_INCLUDED

void menuArticulos(){
    int opc;

    setBackgroundColor(YELLOW);
    setlocale(LC_ALL , "Spanish");
    system("cls");

    while(true){
    setColor(GREEN);
    cout<<"----------------------------"<<endl;
    cout<<"       MENU ARTICULOS       "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<endl;

    setColor(BLUE);
    cout<<"1) Listar articulo por descripcion"<<endl;
    cout<<"2) Listar articulos por precio"<<endl;
    cout<<"3) Registrar venta"<<endl;
    cout<<"4) Listar ventas de articulo"<<endl;
    cout<<"5) Listar ventas por fecha"<<endl;
    cout<<"6) Agregar articulo"<<endl;
    cout<<"7) Eliminar articulo"<<endl;
    cout<<"8) Modificar articulo"<<endl;
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

        case 1:listarArticuloDescripcion();
            break;

        case 2:listarArticulosPrecio();
            break;

        case 3:venta();
            break;

        case 4:listarVentaArticulo();
            break;

        case 5:listarVentaFecha();
            break;

        case 6:agregarArticulo();
            break;

        case 7:eliminarArticulo();
            break;

        case 8:modificarArticulo();
            break;

        case 0:return;

        default:cout<<"ERROR. POR FAVOR, INGRESE UNA OPCION VALIDA"<<endl;
            system("pause>nul");
            system("cls");
            break;

    }
  }
}

#endif // MENUARTICULOS_H_INCLUDED
