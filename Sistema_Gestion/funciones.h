#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///PROTOROPOS

///FUNCIONES PROFESORES
void listarProfesorNombre();
void listarProfesoresAlfabeticamente();
void altaProfesor();
bool bajaProfesor();
bool modificarProfesor();
int buscarProfesorNombre(const char *nombre, const char *apellido);
int buscarProfesorID(int id);
int estadoProfesor(int id);
void ordenarAlfabeticamenteProfesores(Profesor *p, int registros);
void copiarArchivoEnVector(Profesor *p, int registros);
void mostrarVectorProfesores(Profesor *p, int registros);

///FUNCIONES ALUMNOS
void listarAlumnoNombre();
void listarAlumnosAlfabeticamente();
void altaAlumno();
bool bajaAlumno();
bool modificarAlumno();
int buscarAlumnoNombre(const char *nombre, const char *apellido);
int buscarAlumnoID(int id);
int estadoAlumno(int id);
void ordenarAlfabeticamenteAlumnos(Alumno *p, int registros);
void copiarArchivoEnVectorAlumnos(Alumno *p, int registros);
void mostrarVectorAlumnos(Alumno *p, int registros);

///FUNCIONES CLASES
void presentes();
void listarPresenteAlumno();
void listarAlumnosFecha();
void listarPresenteProfesor();
void listarProfesorFecha();

///FUNCIONES ARTICULOS
void listarArticuloDescripcion();
void listarArticulosPrecio();
void venta();
void listarVentaArticulo();
void listarVentaFecha();
void agregarArticulo();
bool eliminarArticulo();
bool modificarArticulo();
int buscarArticuloDescripcion(const char *descripcion);
int buscarArticuloID(int id);
int estadoArticulo(int id);
void ordenarPrecioArticulos(Articulo *p, int registros);
void copiarArchivoEnVectorArticulos(Articulo *p, int registros);
void mostrarVectorArticulos(Articulo *p, int registros);

///FUNCIONES REPORTES
void ClasesMesProfesores();
void DineroMesProfesores();
void ClasesMesAlumnos();
void AbonoMesAlumnos();
void VentasMesArticulos();
void DineroMesArticulos();

///DESARROLLO

///DESARROLLO FUNCIONES PROFESORES
void altaProfesor(){
    Profesor obj;
    if (obj.Cargar()==false){
        cout<<"NO SE PUDO DAR DE ALTA AL PROFESOR"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    else{
        if (obj.grabarProfesor()==true){
            cout<<endl;
            cout<<"PROFESOR AGREGADO"<<endl;
        }
        else cout<<"NO SE PUDO DAR DE ALTA AL PROFESOR"<<endl;
    }
    system("pause>nul");
    system("cls");
}

bool bajaProfesor(){
    Profesor obj;
    int id;
    int pos, aux;
    bool elimino;
    cout<<"INGRESE ID DEL PROFESOR QUE DESEA DAR DE BAJA: ";
    cin>>id;
    pos=buscarProfesorID(id);
    if(pos==-1){
        cout<<endl;
        cout<<"NO EXISTE ESE PROFESOR"<<endl;
        system("pause>nul");
        system("cls");
        return false;
    }
    aux=estadoProfesor(id);
    if(aux==1){
        cout<<endl;
        cout<<"ESE PROFESOR YA HA SIDO DADO DE BAJA"<<endl;
        system("pause>nul");
        system("cls");
        return false;
    }
    obj.leerDeDisco(pos);
    cout<<endl;
    cout<<"PROFESOR A ELIMINAR:"<<endl<<endl;
    obj.Mostrar();
    cout<<endl;
    obj.setEstadoP(false);
    elimino=obj.modificarEnDisco(pos);
    if(elimino==true){
        cout<<"PROFESOR ELIMINADO CORRECTAMENTE"<<endl;
        system("pause>nul");
        system("cls");
    }
    return elimino;
}

void listarProfesorNombre(){
    Profesor obj;
    int n, m;
    int pos=0;
    char apellido[30];
    char nombre[30];
    cout<<"INGRESE APELLIDO DEL PROFESOR QUE DESEA LISTAR: ";
    cargarCadena(apellido,29);
    cout<<"INGRESE NOMBRE DEL PROFESOR QUE DESEA LISTAR: ";
    cargarCadena(nombre,29);
    cout<<endl;
    n=buscarProfesorNombre(nombre, apellido);
    if(n==-1) cout<<"NO EXISTE ESE PROFESOR"<<endl<<endl;
    while(obj.leerDeDisco(pos++)){
        if(obj.getIDprofesor()==n){
                m=estadoProfesor(obj.getIDprofesor());
                if(m==1) cout<<"ESE PROFESOR HA SIDO DADO DE BAJA"<<endl<<endl;
                else  obj.Mostrar();
        }
    }
    system("pause>nul");
    system("cls");
}

int buscarProfesorNombre(const char *nombre, const char *apellido){
    Profesor obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)==true){
        if(strcmp(nombre, obj.getNombre())==0)
            if (strcmp(apellido, obj.getApellido())==0)
                return pos;
    }
    return -1;
}

void listarProfesoresAlfabeticamente(){
    Profesor *p;
    int cantReg;
    cantReg=contarRegistrosP();
    if(cantReg==0){
        cout<<"NO HAY PROFESORES AGREGADOS"<<endl;
        return;
    }
    p=new Profesor[cantReg];
    if(p==NULL)return;
    copiarArchivoEnVector(p,cantReg);
    ordenarAlfabeticamenteProfesores(p,cantReg);
    mostrarVectorProfesores(p,cantReg);
    delete p;
}

void copiarArchivoEnVector(Profesor *p,int registros){
    int i;
    for(i=0;i<registros;i++)
        p[i].leerDeDisco(i);
}

void ordenarAlfabeticamenteProfesores(Profesor *p,int registros){
    Profesor aux;
    int i, j, posMin;
    for(i=0;i<registros-1;i++){
        posMin=i;
        for(j=i+1;j<registros;j++){
            if(strcmp(p[j].getApellido(),p[posMin].getApellido())<0){
                posMin=j;
            }
        }
        aux=p[i];
        p[i]=p[posMin];
        p[posMin]=aux;
    }
}

void mostrarVectorProfesores(Profesor *p,int registros){
    int i;
    for(i=0;i<registros;i++){
        p[i].Mostrar();
        cout<<endl;
    }
    system("pause>nul");
    system("cls");
}

bool modificarProfesor(){
    Profesor obj;
    char residencia[30], tipoProfesor[20];
    int telefono;
    int pos, aux, id;
    bool modifico;
    cout<<"INGRESE ID DEL PROFESOR QUE DESEA MODIFICAR: ";
    cin>>id;
    pos=buscarProfesorID(id);
    if(pos==-1){
        cout<<endl;
        cout<<"NO EXISTE ESE PROFESOR"<<endl;
        system("pause>nul");
        system("cls");
        return false;
    }
    aux=estadoProfesor(id);
    if(aux==1){
        cout<<endl;
        cout<<"ESE PROFESOR HA SIDO DADO DE BAJA"<<endl;
        system("pause>nul");
        system("cls");
        return false;
    }
    obj.leerDeDisco(pos);
    cout<<endl;
    cout<<"PROFESOR A MODIFICAR:"<<endl<<endl;
    obj.Mostrar();
    cout<<endl;
    cout<<"RESIDENCIA: ";
    cargarCadena(residencia, 29);
    obj.setResidencia(residencia);
    cout<<"NUMERO DE TELEFONO: ";
    cin>>telefono;
    obj.setTelefono(telefono);
    cout<<"TIPO DE PROFESOR: ";
    cin>>tipoProfesor;
    obj.setTipoProfesor(tipoProfesor);
    modifico=obj.modificarEnDisco(pos);
    if(modifico==true){
        cout<<endl;
        cout<<"DATOS MODIFICADOS CORRECTAMENTE"<<endl;
        system("pause>nul");
        system("cls");
    }
    return modifico;
}

///DESARROLLO FUNCIONES ALUMNOS
void altaAlumno(){
    Alumno obj;
    if (obj.Cargar()==false){
        cout<<"NO SE PUDO DAR DE ALTA AL ALUMNO"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    else{
        if (obj.grabarAlumno()==true){
            cout<<endl;
            cout<<"ALUMNO AGREGADO"<<endl;
        }
        else cout<<"NO SE PUDO DAR DE ALTA AL ALUMNO"<<endl;
    }
    system("pause>nul");
    system("cls");
}

bool bajaAlumno(){
    Alumno obj;
    int id;
    int pos, aux;
    bool elimino;
    cout<<"INGRESE ID DEL ALUMNO QUE DESEA DAR DE BAJA: ";
    cin>>id;
    pos=buscarAlumnoID(id);
    if(pos==-1){
        cout<<endl;
        cout<<"NO EXISTE ESE ALUMNO"<<endl;
        system("pause>nul");
        system("cls");
        return false;
    }
    aux=estadoAlumno(id);
    if(aux==1){
        cout<<endl;
        cout<<"ESE ALUMNO YA HA SIDO DADO DE BAJA"<<endl;
        system("pause>nul");
        system("cls");
        return false;
    }
    obj.leerDeDisco(pos);
    cout<<endl;
    cout<<"ALUMNO A ELIMINAR:"<<endl<<endl;
    obj.Mostrar();
    cout<<endl;
    obj.setEstadoA(false);
    elimino=obj.modificarEnDisco(pos);
    if(elimino==true){
        cout<<"ALUMNO ELIMINADO CORRECTAMENTE"<<endl;
        system("pause>nul");
        system("cls");
    }
    return elimino;
}

void listarAlumnoNombre(){
    Alumno obj;
    int n, m;
    int pos=0;
    char apellido[30];
    char nombre[30];
    cout<<"INGRESE APELLIDO DEL ALUMNO QUE DESEA LISTAR: ";
    cargarCadena(apellido,29);
    cout<<"INGRESE NOMBRE DEL ALUMNO QUE DESEA LISTAR: ";
    cargarCadena(nombre,29);
    cout<<endl;
    n=buscarAlumnoNombre(nombre, apellido);
    if(n==-1) cout<<"NO EXISTE ESE ALUMNO"<<endl<<endl;
    while(obj.leerDeDisco(pos++)){
        if(obj.getIDalumno()==n){
                m=estadoAlumno(obj.getIDalumno());
                if(m==1) cout<<"ESE ALUMNO HA SIDO DADO DE BAJA"<<endl<<endl;
                else  obj.Mostrar();
        }
    }
    system("pause>nul");
    system("cls");
}

int buscarAlumnoNombre(const char *nombre, const char *apellido){
    Alumno obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)==true){
        if(strcmp(nombre, obj.getNombre())==0)
            if (strcmp(apellido, obj.getApellido())==0)
                return pos;
    }
    return -1;
}

void listarAlumnosAlfabeticamente(){
    Alumno *p;
    int cantReg;
    cantReg=contarRegistrosA();
    if(cantReg==0){
        cout<<"NO HAY ALUMNOS AGREGADOS"<<endl;
        return;
    }
    p=new Alumno[cantReg];
    if(p==NULL)return;
    copiarArchivoEnVectorAlumnos(p,cantReg);
    ordenarAlfabeticamenteAlumnos(p,cantReg);
    mostrarVectorAlumnos(p,cantReg);
    delete p;
}

void copiarArchivoEnVectorAlumnos(Alumno *p,int registros){
    int i;
    for(i=0;i<registros;i++)
        p[i].leerDeDisco(i);
}

void ordenarAlfabeticamenteAlumnos(Alumno *p,int registros){
    Alumno aux;
    int i, j, posMin;
    for(i=0;i<registros-1;i++){
        posMin=i;
        for(j=i+1;j<registros;j++){
            if(strcmp(p[j].getApellido(),p[posMin].getApellido())<0){
                posMin=j;
            }
        }
        aux=p[i];
        p[i]=p[posMin];
        p[posMin]=aux;
    }
}

void mostrarVectorAlumnos(Alumno *p,int registros){
    int i;
    for(i=0;i<registros;i++){
        p[i].Mostrar();
        cout<<endl;
    }
    system("pause>nul");
    system("cls");
}

bool modificarAlumno(){
    Alumno obj;
    char residencia[30], tipoAlumno[20], nivel[20];;
    int telefono;
    int pos, aux, id;
    bool modifico;
    cout<<"INGRESE ID DEL ALUMNO QUE DESEA MODIFICAR: ";
    cin>>id;
    pos=buscarAlumnoID(id);
    if(pos==-1){
        cout<<endl;
        cout<<"NO EXISTE ESE ALUMNO"<<endl;
        system("pause>nul");
        system("cls");
        return false;
    }
    aux=estadoAlumno(id);
    if(aux==1){
        cout<<endl;
        cout<<"ESE ALUMNO HA SIDO DADO DE BAJA"<<endl;
        system("pause>nul");
        system("cls");
        return false;
    }
    obj.leerDeDisco(pos);
    cout<<endl;
    cout<<"ALUMNO A MODIFICAR:"<<endl<<endl;
    obj.Mostrar();
    cout<<endl;
    cout<<"RESIDENCIA: ";
    cargarCadena(residencia, 29);
    obj.setResidencia(residencia);
    cout<<"NUMERO DE TELEFONO: ";
    cin>>telefono;
    obj.setTelefono(telefono);
    cout<<"TIPO DE ALUMNO: ";
    cin>>tipoAlumno;
    obj.setTipoAlumno(tipoAlumno);
    cout<<"NIVEL DEL ALUMNO: ";
    cin>>nivel;
    obj.setNivel(nivel);
    modifico=obj.modificarEnDisco(pos);
    if(modifico==true){
        cout<<endl;
        cout<<"DATOS MODIFICADOS CORRECTAMENTE"<<endl;
        system("pause>nul");
        system("cls");
    }
    return modifico;
}


///DESARROLLO FUNCIONES CLASES
void presentes(){
    Presente obj;
    if (obj.Cargar()==false){
        cout<<"NO SE PUDO PASAR EL PRESENTE"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    else{
        if (obj.grabarPresente()==true){
            cout<<endl;
            cout<<"PRESENTE PASADO CORRECTAMENTE"<<endl;
        }
        else cout<<"NO SE PUDO PASAR EL PRESENTE"<<endl;
    }
    system("pause>nul");
    system("cls");
}

void listarPresenteAlumno(){
    Presente reg;
    int pos=0;
    int id, n;
    cout<<"INGRESE ID DEL ALUMNO: ";
    cin>>id;
    cout<<endl;
    n=buscarAlumnoID(id);
    if(n==-1){
        cout<<"NO EXISTE ESE ALUMNO"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    while(reg.leerDeDisco(pos++)){
    if(id==reg.getIDA()){
            reg.Mostrar();
            cout<<endl;
        }
    }
    system("pause>nul");
    system("cls");
}

void listarAlumnosFecha(){
    Fecha aux;
    Presente reg;
    int pos=0;
    int cont=0;
    int id;
    int n;
    cout<<"INGRESE ID DEL ALUMNO: ";
    cin>>id;
    n=buscarAlumnoID(id);
    if(n==-1){
        cout<<"NO EXISTE ESE ALUMNO"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    cout<<"INGRESE UNA FECHA: "<<endl;
    if(aux.Cargar()==false){
            system("pause>nul");
    }
    cout<<endl;
    while(reg.leerDeDisco(pos++)){
    if(id==reg.getIDA()){
        if(aux.getAnio()==reg.getFechaClase().getAnio()){
            if(aux.getMes()==reg.getFechaClase().getMes()){
                if(aux.getDia()==reg.getFechaClase().getDia()){
                        reg.Mostrar();
                        cout<<endl;
                        cont++;
            }
        }
    }
 }
}
if(cont==0) cout<<"NO HAY CLASES EN ESA FECHA"<<endl;
system("pause>nul");
system("cls");
}

void listarPresenteProfesor(){
    Presente reg;
    int pos=0;
    int id, n;
    cout<<"INGRESE ID DEL PROFESOR: ";
    cin>>id;
    cout<<endl;
    n=buscarProfesorID(id);
    if(n==-1){
        cout<<"NO EXISTE ESE PROFESOR"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    while(reg.leerDeDisco(pos++)){
    if(id==reg.getIDP()){
            reg.Mostrar();
            cout<<endl;
        }
    }
    system("pause>nul");
    system("cls");
}

void listarProfesorFecha(){
    Fecha aux;
    Presente reg;
    int pos=0;
    int cont=0;
    int id, n;
    cout<<"INGRESE ID DEL PROFESOR: ";
    cin>>id;
    n=buscarProfesorID(id);
    if(n==-1){
        cout<<"NO EXISTE ESE PROFESOR"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    cout<<"INGRESE UNA FECHA: "<<endl;
    if(aux.Cargar()==false){
            system("pause>nul");
    }
    cout<<endl;
    while(reg.leerDeDisco(pos++)){
    if(id==reg.getIDP()){
        if(aux.getAnio()==reg.getFechaClase().getAnio()){
            if(aux.getMes()==reg.getFechaClase().getMes()){
                if(aux.getDia()==reg.getFechaClase().getDia()){
                        reg.Mostrar();
                        cout<<endl;
                        cont++;
            }
        }
    }
 }
}
if(cont==0) cout<<"NO HAY CLASES EN ESA FECHA"<<endl;
system("pause>nul");
system("cls");
}

///DESARROLLO FUNCIONES ARTICULOS
void agregarArticulo(){
    Articulo obj;
    obj.Cargar();
    if (obj.grabarArticulo()==true){
        cout<<endl;
        cout<<"ARTICULO AGREGADO"<<endl;
    }
    else cout<<"NO SE PUDO AGREGAR EL ARTICULO"<<endl;
    system("pause>nul");
    system("cls");
}

bool eliminarArticulo(){
    Articulo obj;
    int id;
    int pos, aux;
    bool elimino;
    cout<<"INGRESE ID DEL ARTICULO QUE DESEA ELIMINAR: ";
    cin>>id;
    pos=buscarArticuloID(id);
    if(pos==-1){
        cout<<endl;
        cout<<"NO EXISTE ESE ARTICULO"<<endl;
        system("pause>nul");
        system("cls");
        return false;
    }
    aux=estadoArticulo(id);
    if(aux==1){
        cout<<endl;
        cout<<"ESE ARTICULO YA HA SIDO ELIMINADO"<<endl;
        system("pause>nul");
        system("cls");
        return false;
    }
    obj.leerDeDisco(pos);
    cout<<endl;
    cout<<"ARTICULO A ELIMINAR:"<<endl<<endl;
    obj.Mostrar();
    cout<<endl;
    obj.setEstadoA(false);
    elimino=obj.modificarEnDisco(pos);
    if(elimino==true){
        cout<<"ARTICULO ELIMINADO CORRECTAMENTE"<<endl;
        system("pause>nul");
        system("cls");
    }
    return elimino;
}

void listarArticuloDescripcion(){
    Articulo obj;
    int n, m;
    int pos=0;
    char descripcion[30];
    cout<<"INGRESE LA DESCRIPCION DEL ARTICULO QUE DESEA LISTAR: ";
    cargarCadena(descripcion,29);
    cout<<endl;
    n=buscarArticuloDescripcion(descripcion);
    if(n==-1) cout<<"NO EXISTE ESE ARTICULO"<<endl<<endl;
    while(obj.leerDeDisco(pos++)){
        if(obj.getIDarticulo()==n){
                m=estadoArticulo(obj.getIDarticulo());
                if(m==1) cout<<"ESE ARTICULO HA SIDO ELIMINADO"<<endl<<endl;
                else  obj.Mostrar();
        }
    }
    system("pause>nul");
    system("cls");
}

int buscarArticuloDescripcion(const char *descripcion){
    Articulo obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)==true){
        if(strcmp(descripcion, obj.getDescripcion())==0)
            return pos;
    }
    return -1;
}

void listarArticulosPrecio(){
    Articulo *p;
    int cantReg;
    cantReg=contarRegistrosAR();
    if(cantReg==0){
        cout<<"NO HAY ARTICULOS AGREGADOS"<<endl;
        return;
    }
    p=new Articulo[cantReg];
    if(p==NULL)return;
    copiarArchivoEnVectorArticulos(p,cantReg);
    ordenarPrecioArticulos(p,cantReg);
    mostrarVectorArticulos(p,cantReg);
    delete p;
}

void copiarArchivoEnVectorArticulos(Articulo *p,int registros){
    int i;
    for(i=0;i<registros;i++)
        p[i].leerDeDisco(i);
}

void ordenarPrecioArticulos(Articulo *p,int registros){
    Articulo aux;
    int i, j, posMin;
    for(i=0;i<registros-1;i++){
        posMin=i;
        for(j=i+1;j<registros;j++){
            if(p[j].getPrecio()<p[posMin].getPrecio()){
                posMin=j;
            }
        }
        aux=p[i];
        p[i]=p[posMin];
        p[posMin]=aux;
    }
}

void mostrarVectorArticulos(Articulo *p,int registros){
    int i;
    for(i=0;i<registros;i++){
        p[i].Mostrar();
        cout<<endl;
    }
    system("pause>nul");
    system("cls");
}

bool modificarArticulo(){
    Articulo obj;
    float precio;
    int pos, aux, id, stock;
    bool modifico;
    cout<<"INGRESE ID DEL ARTICULO QUE DESEA MODIFICAR: ";
    cin>>id;
    pos=buscarArticuloID(id);
    if(pos==-1){
        cout<<endl;
        cout<<"NO EXISTE ESE ARTICULO"<<endl;
        system("pause>nul");
        system("cls");
        return false;
    }
    aux=estadoArticulo(id);
    if(aux==1){
        cout<<endl;
        cout<<"ESE ARTICULO HA SIDO ELIMINADO"<<endl;
        system("pause>nul");
        system("cls");
        return false;
    }
    cout<<endl;
    obj.leerDeDisco(pos);
    cout<<"ARTICULO A MODIFICAR"<<endl<<endl;
    obj.Mostrar();
    cout<<endl;
    cout<<"PRECIO: ";
    cin>>precio;
    obj.setPrecio(precio);
    cout<<"STOCK: ";
    cin>>stock;
    obj.setStock(stock);
    modifico=obj.modificarEnDisco(pos);
    if(modifico==true){
        cout<<endl;
        cout<<"ARTICULO MODIFICADO CORRECTAMENTE"<<endl;
        system("pause>nul");
        system("cls");
    }
    return modifico;
}

void venta(){
    Venta obj;
    if (obj.Cargar()==false){
        cout<<"NO SE PUDO REGISTRAR LA VENTA"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    else{
        if (obj.grabarVenta()==true){
            cout<<endl;
            cout<<"VENTA REGISTRADA CORRECTAMENTE"<<endl;
        }
        else cout<<"NO SE PUDO REGISTRAR LA VENTA"<<endl;
    }
    system("pause>nul");
    system("cls");
}

void listarVentaFecha(){
    Fecha aux;
    Venta reg;
    int pos=0;
    int cont=0;
    cout<<"INGRESE UNA FECHA: "<<endl;
    if(aux.Cargar()==false){
    system("cls");
    return;
    }
    cout<<endl;
    while(reg.leerDeDisco(pos++)){
        if(aux.getAnio()==reg.getFechaVenta().getAnio()){
            if(aux.getMes()==reg.getFechaVenta().getMes()){
                if(aux.getDia()==reg.getFechaVenta().getDia()){
                        reg.Mostrar();
                        cout<<endl;
                        cont++;
            }
        }
    }
 }
if(cont==0) cout<<"NO HAY VENTAS EN ESA FECHA"<<endl;
system("pause>nul");
system("cls");
}

void listarVentaArticulo(){
    Venta reg;
    int pos=0;
    int id, n;
    cout<<"INGRESE ID DEL ARTICULO: ";
    cin>>id;
    cout<<endl;
    n=buscarArticuloID(id);
    if(n==-1){
        cout<<"NO EXISTE ESE ARTICULO"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    while(reg.leerDeDisco(pos++)){
    if(id==reg.getIDART()){
            reg.Mostrar();
            cout<<endl;
        }
    }
    system("pause>nul");
    system("cls");
}

///FUNCIONES REPORTES
void ClasesMesProfesores(){
    Presente obj;
    int id, aux, est;
    int i, pos=0, mes[12]={0};
    cout<<"INGRESE ID DEL PROFESOR: ";
    cin>>id;
    cout<<endl;
    aux=buscarProfesorID(id);
    est=estadoProfesor(id);
    if(aux==-1){
        cout<<"NO EXISTE ESE PROFESOR"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    if(est==1){
        cout<<"ESE PROFESOR HA SIDO DADO DE BAJA"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    while(obj.leerDeDisco(pos++)==true){
            if(obj.getIDP()==id) mes[obj.getFechaClase().getMes()-1]++;
    }
    for(i=0;i<12;i++){
            cout<<"Profesor:"<<id<<"  Mes:"<<i+1<<"  Cantidad de clases:"<<mes[i]<<endl<<endl;
    }
    system("pause>nul");
    system("cls");
}

void DineroMesProfesores(){
    Presente obj;
    int id, aux, est;
    int i, pos=0, dinero=600, mes[12]={0};
    cout<<"INGRESE ID DEL PROFESOR: ";
    cin>>id;
    cout<<endl;
    aux=buscarProfesorID(id);
    est=estadoProfesor(id);
    if(aux==-1){
        cout<<"NO EXISTE ESE PROFESOR"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    if(est==1){
        cout<<"ESE PROFESOR HA SIDO DADO DE BAJA"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    while(obj.leerDeDisco(pos++)==true){
            if(obj.getIDP()==id) mes[obj.getFechaClase().getMes()-1]+=dinero;
    }
    for(i=0;i<12;i++){
            cout<<"Profesor:"<<id<<"  Mes:"<<i+1<<"  Cantidad de dinero acumulado:"<<mes[i]<<endl<<endl;
    }
    system("pause>nul");
    system("cls");
}

void ClasesMesAlumnos(){
    Presente obj;
    int id, aux, est;
    int i, pos=0, mes[12]={0};
    cout<<"INGRESE ID DEL ALUMNO: ";
    cin>>id;
    cout<<endl;
    aux=buscarAlumnoID(id);
    est=estadoProfesor(id);
    if(aux==-1){
        cout<<"NO EXISTE ESE ALUMNO"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    if(est==1){
        cout<<"ESE ALUMNO HA SIDO DADO DE BAJA"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    while(obj.leerDeDisco(pos++)==true){
            if(obj.getIDA()==id) mes[obj.getFechaClase().getMes()-1]++;
    }
    for(i=0;i<12;i++){
            cout<<"Alumno:"<<id<<"  Mes:"<<i+1<<"  Cantidad de clases:"<<mes[i]<<endl<<endl;
    }
    system("pause>nul");
    system("cls");
}

void AbonoMesAlumnos(){
    Presente obj;
    int id, aux, est;
    int i, pos=0, mes[12]={0};
    cout<<"INGRESE ID DEL ALUMNO: ";
    cin>>id;
    cout<<endl;
    aux=buscarAlumnoID(id);
    est=estadoProfesor(id);
    if(aux==-1){
        cout<<"NO EXISTE ESE ALUMNO"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    if(est==1){
        cout<<"ESE ALUMNO HA SIDO DADO DE BAJA"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    while(obj.leerDeDisco(pos++)==true){
            if(obj.getIDA()==id) mes[obj.getFechaClase().getMes()-1]+=obj.getAbono();
    }
    for(i=0;i<12;i++){
            cout<<"Alumno:"<<id<<"  Mes:"<<i+1<<"  Dinero Abonado:"<<mes[i]<<endl<<endl;
    }
    system("pause>nul");
    system("cls");
}

void VentasMesArticulos(){
    Venta obj;
    int id, aux, est;
    int i, pos=0, mes[12]={0};
    cout<<"INGRESE ID DEL ARTICULO: ";
    cin>>id;
    cout<<endl;
    aux=buscarArticuloID(id);
    est=estadoArticulo(id);
    if(aux==-1){
        cout<<"NO EXISTE ESE ARTICULO"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    if(est==1){
        cout<<"ESE ARTICULO HA SIDO ELIMINADO"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    while(obj.leerDeDisco(pos++)==true){
            if(obj.getIDART()==id) mes[obj.getFechaVenta().getMes()-1]++;
    }
    for(i=0;i<12;i++){
            cout<<"Articulo:"<<id<<"  Mes:"<<i+1<<"  Cantidad de ventas:"<<mes[i]<<endl<<endl;
    }
    system("pause>nul");
    system("cls");
}

void DineroMesArticulos(){
    Venta obj;
    int id, aux, est;
    int i, pos=0, mes[12]={0};
    cout<<"INGRESE ID DEL ARTICULO: ";
    cin>>id;
    cout<<endl;
    aux=buscarArticuloID(id);
    est=estadoArticulo(id);
    if(aux==-1){
        cout<<"NO EXISTE ESE ARTICULO"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    if(est==1){
        cout<<"ESE ARTICULO HA SIDO ELIMINADO"<<endl;
        system("pause>nul");
        system("cls");
        return;
    }
    while(obj.leerDeDisco(pos++)==true){
            if(obj.getIDART()==id) mes[obj.getFechaVenta().getMes()-1]+=obj.getDinero();
    }
    for(i=0;i<12;i++){
            cout<<"Articulo:"<<id<<"  Mes:"<<i+1<<"  Cantidad de dinero acumulado:"<<mes[i]<<endl<<endl;
    }
    system("pause>nul");
    system("cls");
}

#endif // FUNCIONES_H_INCLUDED
