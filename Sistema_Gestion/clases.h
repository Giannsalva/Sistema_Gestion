#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

class Fecha{
private:
    int dia, mes, anio;
public:
    ///gets
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    ///constructor
    Fecha(int d=0, int m=0, int a=0){
        if((d+m+a)==0){
            time_t tiempo;
            struct tm *tmPtr;
            tiempo = time(NULL);
            tmPtr = localtime(&tiempo);
            dia=tmPtr->tm_mday;
            mes=tmPtr->tm_mon+1;
            anio=1900+tmPtr->tm_year;
        }
        else{
            dia=d;
            mes=m;
            anio=a;
        }
    }
    ///sets
    bool setDia(int d){
        if(d>0 && d<=31){
            dia=d;
            return true;
        }
        return false;
    }
    bool setMes(int d){
        if(d>0 && d<=12){
            mes=d;
            return true;
        }
        return false;
    }
    bool setAnio(int d){
        if(d>1900 && d<=2021){
          anio=d;
          return true;
        }
        return false;
    }
    ///funciones
    bool validarFecha(int dia, int mes, int anio){
        int diasPorMes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(dia>diasPorMes[mes-1]) {
            cout << "FECHA INVALIDA" << endl;
            system("pause>nul");
            return false;
        }
        return true;
    }
    bool Cargar(){
        int d,m,a;
        cout<<"DIA: ";
        cin>>d;
        if(!setDia(d)){
                cout<<"DIA INVALIDO"<<endl;
                system("pause>nul");
                return false;
        }
        cout<<"MES: ";
        cin>>m;
        if(setMes(m)==false){
                cout<<"MES INVALIDO"<<endl;
                system("pause>nul");
                return false;
        }
        cout<<"AÑO: ";
        cin>>a;
        if(!setAnio(a)){
                cout<<"AÑO INVALIDO"<<endl;
                system("pause>nul");
                return false;
        }
        Fecha aux(0,0,0);
        if(compararFecha(aux)==1){
            cout << "FECHA INVALIDA" << endl;
            system("pause>nul");
            return false;
        }
        return validarFecha(d,m,a);
    }
    void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }
    void MostrarConLetras(){
        char meses[12][11]={"ENERO", "FEBRERO","MARZO","ABRIL","MAYO", "JUNIO","JULIO", "AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};
        cout<<dia<<" de "<<meses[mes-1]<<" de "<<anio<<endl;
    }
    int compararFecha(Fecha aux){
        /// 0 si son iguales
        ///1 si la fecha del objeto que llama es mayor
        ///-1si la fecha del objeto que llama es menor
        if(anio>aux.anio) return 1;
        if(anio<aux.anio) return -1;
        ///las siguientes líneas se ejecutan si los anios son iguales
        if(mes>aux.mes)return 1;
        if(mes<aux.mes)return -1;
        ///las siguientes líneas se ejecutan si los meses son iguales (y los años también)
        if(dia>aux.dia) return 1;
        if(dia<aux.dia) return -1;
        return 0;
    }
};

class Persona{
protected:
    char apellido[30];
    char nombre[30];
    int DNI;
    char residencia [30];
    int telefono;
    Fecha fechaNac;
public:
    ///sets()
    void setApellido(const char *a){strcpy(apellido,a);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setDNI(int d){DNI=d;}
    void setResidencia(const char *r){strcpy(residencia,r);}
    void setTelefono(int tel){telefono=tel;}
    void setFechaNac(Fecha fn){fechaNac=fn;}
    ///gets()
    const char *getApellido(){return apellido;}
    const char *getNombre(){return nombre;}
    int getDNI(){return DNI;}
    const char *getResidencia(){return residencia;}
    int getTelefono(){return telefono;}
    Fecha getFechaNac(){return fechaNac;}
    ///funciones()
    bool Cargar();
    void Mostrar();
};

bool Persona::Cargar(){
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 29);
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 29);
    cout<<"DNI: ";
    cin>>DNI;
    cout<<"RESIDENCIA: ";
    cargarCadena(residencia, 29);
    cout<<"NUMERO DE TELEFONO: ";
    cin>>telefono;
    cout<<"FECHA DE NACIMIENTO: "<<endl;
    if (fechaNac.Cargar()==false) return false;
    return true;
}

void Persona::Mostrar(){
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"DNI: ";
    cout<<DNI<<endl;
    cout<<"RESIDENCIA: ";
    cout<<residencia<<endl;
    cout<<"NUMERO DE TELEFONO: ";
    cout<<telefono<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNac.Mostrar();
}

class Profesor: public Persona{
private:
    int IDprofesor;
    char tipoProfesor[20];
    Fecha fechaIng;
    bool estadoP;
public:
    ///sets
    void setIDprofesor(int IDP){IDprofesor=IDP;}
    void setTipoProfesor(const char *TP){strcpy(tipoProfesor,TP);}
    void setFechaIng(Fecha FI){fechaIng=FI;}
    void setEstadoP(bool EP){estadoP=EP;}
    ///gets
    int getIDprofesor(){return IDprofesor;}
    const char *getTipoProfesor(){return tipoProfesor;}
    Fecha getFechaIng(){return fechaIng;}
    bool getEstadoP(){return estadoP;}
    ///funciones
    bool Cargar();
    void Mostrar();
    bool grabarProfesor();
    bool leerDeDisco(int pos);
    bool modificarEnDisco(int pos);
};

int contarRegistrosP(){
    FILE *p;
    p=fopen("profesores.dat", "rb");
    if(p==NULL) return -1;
    fseek(p,0,2);
    int cantBytes=ftell(p)/sizeof (Profesor);
    fclose(p);
    return cantBytes+1;
}

bool Profesor::Cargar(){
    if(contarRegistrosP()==-1){
        IDprofesor=1;
        cout<<"ID DEL PROFESOR: "<<IDprofesor<<endl;
    }
    else{
        IDprofesor=contarRegistrosP();
        cout<<"ID DEL PROFESOR: "<<IDprofesor<<endl;
    }
    if(Persona::Cargar()==false) return false;
    cout<<"TIPO DE PROFESOR: ";
    cin>>tipoProfesor;
    cout<<"FECHA DE INGRESO: "<<endl;
    if(fechaIng.Cargar()==false) return false;
    estadoP=true;
    return true;
}

void Profesor::Mostrar(){
    if(estadoP==true){
        cout<<"ID DEL PROFESOR: ";
        cout<<IDprofesor<<endl;
        Persona::Mostrar();
        cout<<"TIPO DE PROFESOR: ";
        cout<<tipoProfesor<<endl;
        cout<<"FECHA DE INGRESO: ";
        fechaIng.Mostrar();
    }
}

bool Profesor::grabarProfesor(){
            FILE *p;
            bool grabo;
            p=fopen("profesores.dat", "ab");
            if(p==NULL){
                cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
                return false;
            }
            grabo=fwrite(this,sizeof *this,1,p);
            fclose(p);
            return grabo;
}

bool Profesor::leerDeDisco(int pos){
            FILE *p;
            bool leyo;
            p=fopen("profesores.dat", "rb");
            if(p==NULL){
                cout<<endl;
                cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
                return false;
            }
            fseek(p, sizeof(Profesor)*pos, 0);
            leyo=fread(this,sizeof(Profesor),1,p);
            fclose(p);
            return leyo;
}

bool Profesor::modificarEnDisco(int pos){
        FILE *p;
        p=fopen("profesores.dat","rb+");
        if(p==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
        fseek(p,sizeof(Profesor)*pos,0);
        bool leyo=fwrite(this, sizeof(Profesor), 1, p);
        fclose(p);
        return leyo;
}

class Alumno: public Persona{
private:
    int IDalumno;
    char tipoAlumno[20];
    char nivel [20];
    Fecha fechaIng;
    bool estadoA;

public:
    ///sets
    void setIDalumno(int IDA){IDalumno=IDA;}
    void setTipoAlumno(const char *TA){strcpy(tipoAlumno,TA);}
    void setNivel(const char *N){strcpy(nivel,N);}
    void setFechaIng(Fecha FI){fechaIng=FI;}
    void setEstadoA(bool EA){estadoA=EA;}
    ///gets
    int getIDalumno(){return IDalumno;}
    const char *getTipoAlumno(){return tipoAlumno;}
    const char *getNivel(){return nivel;}
    Fecha getFechaIng(){return fechaIng;}
    bool getEstadoA(){return estadoA;}
    ///funciones
    bool Cargar();
    void Mostrar();
    bool grabarAlumno();
    bool leerDeDisco(int pos);
    bool modificarEnDisco(int pos);
};

int contarRegistrosA(){
    FILE *p;
    p=fopen("alumnos.dat", "rb");
    if(p==NULL) return -1;
    fseek(p,0,2);
    int cantBytes=ftell(p)/sizeof (Alumno);
    fclose(p);
    return cantBytes+1;
}

bool Alumno::Cargar(){
    if(contarRegistrosA()==-1){
        IDalumno=1;
        cout<<"ID DEL ALUMNO: "<<IDalumno<<endl;
    }
    else{
        IDalumno=contarRegistrosA();
        cout<<"ID DEL ALUMNO: "<<IDalumno<<endl;
    }
    if(Persona::Cargar()==false) return false;
    cout<<"TIPO DE ALUMNO: ";
    cin>>tipoAlumno;
    cout<<"NIVEL DEL ALUMNO: ";
    cin>>nivel;
    cout<<"FECHA DE INGRESO: "<<endl;
    if(fechaIng.Cargar()==false) return false;
    estadoA=true;
    return true;
}

void Alumno::Mostrar(){
    if (estadoA==true){
        cout<<"ID DEL ALUMNO: ";
        cout<<IDalumno<<endl;
        Persona::Mostrar();
        cout<<"TIPO DE ALUMNO: ";
        cout<<tipoAlumno<<endl;
        cout<<"NIVEL DEL ALUMNO: ";
        cout<<nivel<<endl;
        cout<<"FECHA DE INGRESO: ";
        fechaIng.Mostrar();
    }
}

bool Alumno::grabarAlumno(){
            FILE *p;
            bool grabo;
            p=fopen("alumnos.dat", "ab");
            if(p==NULL){
                cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
                return false;
            }
            grabo=fwrite(this,sizeof *this,1,p);
            fclose(p);
            return grabo;
}

bool Alumno::leerDeDisco(int pos){
            FILE *p;
            bool leyo;
            p=fopen("alumnos.dat", "rb");
            if(p==NULL){
                cout<<endl;
                cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
                return false;
            }
            fseek(p, sizeof(Alumno)*pos, 0);
            leyo=fread(this,sizeof(Alumno),1,p);
            fclose(p);
            return leyo;
}

bool Alumno::modificarEnDisco(int pos){
        FILE *p;
        p=fopen("alumnos.dat","rb+");
        if(p==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
        fseek(p,sizeof(Alumno)*pos,0);
        bool leyo=fwrite(this, sizeof(Alumno), 1, p);
        fclose(p);
        return leyo;
}

class Articulo{
private:
    int IDarticulo;
    char descripcion [40];
    float precio;
    int stock;
    bool estadoA;
public:
    ///sets
    void setIDarticulo(int IDA){IDarticulo=IDA;}
    void setDescripcion(const char *D){strcpy(descripcion,D);}
    void setPrecio(float P){precio=P;}
    void setStock(int S){stock=S;}
    void setEstadoA(bool EA){estadoA=EA;}
    ///gets
    int getIDarticulo(){return IDarticulo;}
    const char *getDescripcion(){return descripcion;}
    float getPrecio(){return precio;}
    int getStock(){return stock;}
    bool getEstadoA(){return estadoA;}
    ///funciones
    bool Cargar();
    void Mostrar();
    bool grabarArticulo();
    bool leerDeDisco(int pos);
    bool modificarEnDisco(int pos);
};

int contarRegistrosAR(){
    FILE *p;
    p=fopen("articulos.dat", "rb");
    if(p==NULL) return -1;
    fseek(p,0,2);
    int cantBytes=ftell(p)/sizeof (Articulo);
    fclose(p);
    return cantBytes+1;
}

bool Articulo::Cargar(){
    if(contarRegistrosAR()==-1){
        IDarticulo=1;
        cout<<"ID DEL ARTICULO: "<<IDarticulo<<endl;
    }
    else{
        IDarticulo=contarRegistrosAR();
        cout<<"ID DEL ARTICULO: "<<IDarticulo<<endl;
    }
    cout<<"DESCRIPCION: ";
    cargarCadena(descripcion, 39);
    cout<<"PRECIO: ";
    cin>>precio;
    if(precio<=0){
            cout<<"PRECIO INVALIDO"<<endl;
            return false;
    }
    cout<<"STOCK: ";
    cin>>stock;
    if(stock<=0){
            cout<<"STOCK INVALIDO"<<endl;
            return false;
    }
    estadoA=true;
    return true;
}

void Articulo::Mostrar(){
    if(estadoA==true){
            cout<<"ID DEL ARTICULO: ";
            cout<<IDarticulo<<endl;
            cout<<"DESCRIPCION: ";
            cout<<descripcion<<endl;
            cout<<"PRECIO: ";
            cout<<precio<<endl;
            cout<<"STOCK: ";
            cout<<stock<<endl;
    }
}

bool Articulo::grabarArticulo(){
            FILE *p;
            bool grabo;
            p=fopen("articulos.dat", "ab");
            if(p==NULL){
                cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
                return false;
            }
            grabo=fwrite(this,sizeof *this,1,p);
            fclose(p);
            return grabo;
}

bool Articulo::leerDeDisco(int pos){
            FILE *p;
            bool leyo;
            p=fopen("articulos.dat", "rb");
            if(p==NULL){
                cout<<endl;
                cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
                return false;
            }
            fseek(p, sizeof(Articulo)*pos, 0);
            leyo=fread(this,sizeof(Articulo),1,p);
            fclose(p);
            return leyo;
}

bool Articulo::modificarEnDisco(int pos){
        FILE *p;
        p=fopen("articulos.dat","rb+");
        if(p==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
        fseek(p,sizeof(Articulo)*pos,0);
        bool leyo=fwrite(this, sizeof(Articulo), 1, p);
        fclose(p);
        return leyo;
}

class Presente{
private:
    int IDP;
    int IDA;
    int abono;
    Fecha fechaClase;
public:
    ///sets
    void setIDP(int IDpro){IDP=IDpro;}
    void setIDA(int IDalu){IDA=IDalu;}
    void setAbono(int a){abono=a;}
    void setFechaClase(Fecha FE){fechaClase=FE;}
    ///gets
    int getIDP(){return IDP;}
    int getIDA(){return IDA;}
    int getAbono(){return abono;}
    Fecha getFechaClase(){return fechaClase;}
    ///funciones
    bool Cargar();
    void Mostrar();
    bool grabarPresente();
    bool leerDeDisco(int pos);
};

int buscarProfesorID(int id){
    Profesor obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==true){
        if(obj.getIDprofesor()==id)
            return pos;
        pos++;
    }
    return -1;
}

int estadoProfesor(int id){
    Profesor obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==true){
        if(obj.getIDprofesor()==id){
           if(obj.getEstadoP()==false){
            return 1;
           }
        }
        pos++;
    }
    return -1;
}

int buscarAlumnoID(int id){
    Alumno obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==true){
        if(obj.getIDalumno()==id)
            return pos;
        pos++;
    }
    return -1;
}

int estadoAlumno(int id){
    Alumno obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==true){
        if(obj.getIDalumno()==id){
           if(obj.getEstadoA()==false){
            return 1;
           }
        }
        pos++;
    }
    return -1;
}

bool Presente::Cargar(){
    Profesor obj;
    Alumno reg;
    int pos, aux;
    int est, est2;
    cout<<"ID DEL PROFESOR: ";
    cin>>IDP;
    cout<<endl;
    pos=buscarProfesorID(IDP);
    est=estadoProfesor(IDP);
    if(pos==-1){
        cout<<endl;
        cout<<"NO EXISTE ESE PROFESOR"<<endl;
        system("pause>nul");
        return false;
    }
    if(est==1){
        cout<<endl;
        cout<<"ESE PROFESOR HA SIDO DADO DE BAJA"<<endl;
        system("pause>nul");
        return false;
    }
    obj.leerDeDisco(pos);
    cout<<"PROFESOR: "<<endl<<endl;
    obj.Mostrar();
    cout<<endl;
    cout<<"ID DEL ALUMNO: ";
    cin>>IDA;
    cout<<endl;
    aux=buscarAlumnoID(IDA);
    est2=estadoAlumno(IDA);
    if(aux==-1){
        cout<<endl;
        cout<<"NO EXISTE ESE ALUMNO"<<endl;
        system("pause>nul");
        return false;
    }
    if(est2==1){
        cout<<endl;
        cout<<"ESE ALUMNO HA SIDO DADO DE BAJA"<<endl;
        system("pause>nul");
        return false;
    }
    reg.leerDeDisco(aux);
    cout<<"ALUMNO: "<<endl<<endl;
    reg.Mostrar();
    cout<<endl;
    cout<<"ABONO DE LA CLASE: ";
    cin>>abono;
    cout<<endl;
    if(abono<=0){
            cout<<"ABONO INVALIDO"<<endl;
            return false;
    }
    cout<<"FECHA DE LA CLASE: "<<endl;
    if(fechaClase.Cargar()==false) return false;
    return true;
}

void Presente::Mostrar(){
            cout<<"ID DEL PROFESOR: ";
            cout<<IDP<<endl;
            cout<<"ID DEL ALUMNO: ";
            cout<<IDA<<endl;
            cout<<"ABONO DE LA CLASE: ";
            cout<<abono<<endl;
            cout<<"FECHA DE LA CLASE: ";
            fechaClase.Mostrar();
}

bool Presente::grabarPresente(){
            FILE *p;
            bool grabo;
            p=fopen("presentes.dat", "ab");
            if(p==NULL){
                cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
                return false;
            }
            grabo=fwrite(this,sizeof *this,1,p);
            fclose(p);
            return grabo;
}

bool Presente::leerDeDisco(int pos){
            FILE *p;
            bool leyo;
            p=fopen("presentes.dat", "rb");
            if(p==NULL){
                cout<<endl;
                cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
                return false;
            }
            fseek(p, sizeof(Presente)*pos, 0);
            leyo=fread(this,sizeof(Presente),1,p);
            fclose(p);
            return leyo;
}

class Venta{
private:
    int IDART;
    int dinero;
    Fecha fechaVenta;
public:
    ///sets
    void setIDART(int IDarticulo){IDART=IDarticulo;}
    void setDinero(int DA){DA=dinero;}
    void setFechaVenta(Fecha FV){fechaVenta=FV;}
    ///gets
    int getIDART(){return IDART;}
    int getDinero(){return dinero;}
    Fecha getFechaVenta(){return fechaVenta;}
    ///funciones
    bool Cargar();
    void Mostrar();
    bool grabarVenta();
    bool leerDeDisco(int pos);
};

int buscarArticuloID(int id){
    Articulo obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==true){
        if(obj.getIDarticulo()==id)
            return pos;
        pos++;
    }
    return -1;
}

int estadoArticulo(int id){
    Articulo obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==true){
        if(obj.getIDarticulo()==id){
           if(obj.getEstadoA()==false){
            return 1;
           }
        }
        pos++;
    }
    return -1;
}

bool Venta::Cargar(){
    Articulo obj;
    int pos, aux;
    cout<<"ID DEL ARTICULO: ";
    cin>>IDART;
    cout<<endl;
    pos=buscarArticuloID(IDART);
    aux=estadoArticulo(IDART);
    if(pos==-1){
        cout<<endl;
        cout<<"NO EXISTE ESE ARTICULO"<<endl;
        system("pause>nul");
        return false;
    }
    if(aux==1){
        cout<<endl;
        cout<<"ESE ARTICULO HA SIDO ELIMINADO"<<endl;
        system("pause>nul");
        return false;
    }
    obj.leerDeDisco(pos);
    cout<<"ARTICULO: "<<endl<<endl;
    obj.Mostrar();
    cout<<endl;
    cout<<"DINERO ABONADO: ";
    cin>>dinero;
    if(dinero<=0){
            cout<<"ABONO INVALIDO"<<endl;
            return false;
    }
    cout<<endl;
    cout<<"FECHA DE LA VENTA: "<<endl;
    if(fechaVenta.Cargar()==false) return false;
    obj.leerDeDisco(pos);
    obj.setStock(obj.getStock()-1);
    obj.modificarEnDisco(pos);
    return true;
}

void Venta::Mostrar(){
            cout<<"ID DEL ARTICULO: ";
            cout<<IDART<<endl;
            cout<<"DINERO ABONADO: ";
            cout<<dinero<<endl;
            cout<<"FECHA DE LA VENTA: ";
            fechaVenta.Mostrar();
}

bool Venta::grabarVenta(){
            FILE *p;
            bool grabo;
            p=fopen("ventas.dat", "ab");
            if(p==NULL){
                cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
                return false;
            }
            grabo=fwrite(this,sizeof *this,1,p);
            fclose(p);
            return grabo;
}

bool Venta::leerDeDisco(int pos){
            FILE *p;
            bool leyo;
            p=fopen("ventas.dat", "rb");
            if(p==NULL){
                cout<<endl;
                cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
                return false;
            }
            fseek(p, sizeof(Venta)*pos, 0);
            leyo=fread(this,sizeof(Venta),1,p);
            fclose(p);
            return leyo;
}

#endif // CLASES_H_INCLUDED
