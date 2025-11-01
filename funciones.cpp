#include<iostream>
#include <iomanip>
#include<cstring>
#include "funciones.h"
#include "rlutil.h"
#include "MICROS.h"
#include "ARCHIVO_MICROS.h"
#include "CHOFERES.h"
#include "ARCHIVO_CHOFERES.h"
#include "USUARIOS.h"
#include "ARCHIVO_USUARIOS.h"
#include "ARCHIVO_HISTORIAL_INGRESOS.h"
#include "DESTINOS.h"
#include "ARCHIVO_DESTINOS.h"
#include "FECHAS.h"
#include "TIEMPO_ACTUAL.h"
#include "HORA.h"
#include "PROVINCIAS.h"
#include "ARCHIVO_PROVINCIAS.h"
#include "VIAJES.h"
#include "ARCHIVO_VIAJES.h"
#include "PASAJE.h"
#include "ARCHIVO_PASAJE.h"
#include "PASAJEROS.h"
#include "ARCHIVO_PASAJEROS.h"


using namespace std;
using namespace rlutil;

void cargarCadena(char *palabra, int tam){
    int i=0;
    fflush(stdin);
    for (i=0; i<tam; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}

const char *funcion_provincias(int pos){
    const char *provincias[]={"buenos aires", "catamarca", "chaco", "chubut", "cordoba", "corrientes", "entre rios", "formosa", "jujuy",
    "la pampa", "la rioja", "mendoza", "misiones", "neuquen", "rio negro", "salta", "san juan", "san luis", "santa cruz", "santa fe",
    "santiago del estero", "tierra del fuego", "tucuman"};

    return provincias[pos-1];
}

bool validarPatente(const char *patente){
    if(strlen(patente)!=7)return false;

    for(int i=0; i<2; i++) if(patente[i]<'A' or patente[i]>'Z') return false;

    for(int i=2; i<5; i++) if(patente[i]<'0' or patente[i]>'9') return false;

    for(int i=5; i<7; i++) if(patente[i]<'A' or patente[i]>'Z') return false;

    return true;
}

bool validarPalabra(const char *palabra){
    int longitud=strlen(palabra);
    if(longitud==0)return false;

    for(int i=0; i<longitud; i++){
        if(!((palabra[i]>='A' and palabra[i]<='Z') or (palabra[i]>='a' and palabra[i]<='z') or palabra[i]==' ')){
            return false;
        }
    }
    return true;
}

bool esBisiesto(int anio){
    return(anio%4==0 and anio%100!=0) or (anio%400==0);
}

int diasEnMes(int mes, int anio){
    int dias[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(mes==2 and esBisiesto(anio)) return 29;
    return dias[mes-1];
}

string nombreMes(int mes){
    string meses[]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    return meses[mes-1];
}

int diaSemanaPrimeroMes(int mes, int anio) {
    int dias=0;
    for(int a=1900; a<anio; a++) dias+=esBisiesto(a) ? 366 : 365;

    for(int m=1; m<mes; m++) dias+=diasEnMes(m, anio);

    return(dias+1)%7;
}

void calendario(int mes, int anio){
    cls();
    cout<<"Preciones < o > para meverse en el calentario o (ENTER) para seleccionar el mes"<<endl;
    cout<<"\t"<<nombreMes(mes)<<" "<<anio<<endl;
    cout<<" Do  Lu  Ma  Mi  Ju  Vi  Sa"<<endl;

    int primerdia=diaSemanaPrimeroMes(mes, anio);
    int totaldias=diasEnMes(mes, anio);

    for(int i=0; i<primerdia; i++)cout<<"    ";

    for(int dia=1; dia<=totaldias; dia++){
        cout<<setw(3)<<dia<< " ";
        if((dia+primerdia)%7==0)cout<<endl;
    }
    cout<<endl<<endl;
}

int viajes_disponibles(){
    Viajes viaje;
    Archivo_viajes archivo;

    Tiempo_Actual tiempo;

    while(true){
        int mes, anio;
        mes=tiempo.getMes();
        anio=tiempo.getAnio();
        while(true){
            int dia;
            calendario(mes, anio);
            while(true){
                int tecla=getkey();
                if(tecla==KEY_RIGHT){
                    mes++;
                    if(mes==13){mes=1; anio++; }
                } else if(tecla==KEY_LEFT){
                    mes--;
                    if(mes==0){mes=12; anio--; }
                } else if(tecla==KEY_ENTER)break;
                calendario(mes, anio);
            }
            cout<<"ingrese el dia para ver los viajes disponibles"<<endl;
            cin>>dia;

            int contreg=archivo.contarRegistros();

            for(int i=0; i<contreg; i++){
                viaje=archivo.leerRegistros(i);
                if(dia==viaje.getfecha_Inicio_Viaje().getdia() and mes==viaje.getfecha_Inicio_Viaje().getmes() and anio==viaje.getfecha_Inicio_Viaje().getanio()){
                    viaje.mostrar();
                    cout<<"ingrese el ID de viaje a selecionar o preciones (ESC) para salir: ";
                    int idv;
                    int tecla=getkey();
                    if(tecla==KEY_ESCAPE)break;
                    cin>>idv;
                    return idv;
                }else {cout<<"Sin viajes disponibles (preciones una tecla)"<<endl; anykey();}
            }
        }
        cout<<"(ESC) para salir o precione una tecla para continuar"<<endl;
        int tecla=_getch();
        cls();
        if(tecla==27)break;
    }
    return -1;
}

int selecion_de_butacas(int cant, Micros micro){
    int butacas;
    int columnas=4;
    int posSeleccionada=1;

    if(strcmp(micro.gettipo(), "simple-piso")==0){
        while(true){
            cls();
            for(int i=0; i<cant; i++){
                if((i+1)==posSeleccionada)setColor(GREEN);
                else setColor(WHITE);
                cout<<"["<<((i+1<10) ? "0" : "")<<i+1<< "]";
                if((i+1)%columnas==0)cout<<"\n";
                else cout<<" ";
            }

            int tecla=getkey();

            if(tecla==KEY_UP){
                posSeleccionada-=columnas;
                if(posSeleccionada<=0)posSeleccionada+=cant;
            }else if(tecla==KEY_DOWN){
                posSeleccionada+=columnas;
                if(posSeleccionada>cant)posSeleccionada-=cant;
            }else if(tecla==KEY_LEFT){
                posSeleccionada--;
                if(posSeleccionada<1)posSeleccionada=cant;
            }else if(tecla==KEY_RIGHT){
                posSeleccionada++;
                if(posSeleccionada>cant)posSeleccionada=1;
            }else if(tecla==KEY_ENTER){
                return posSeleccionada;
            }else if(tecla==KEY_ESCAPE){
                break;
            }
        }
    }else if(strcmp(micro.gettipo(), "doble-piso")==0){
        int cantPorPiso=cant/2;
        int filas=cantPorPiso/columnas;

        while(true){
            cls();
            cout<<"Piso Inferior\t\t\t\tPiso Superior\n\n";
            for(int fila=0; fila<filas; fila++) {

                for(int col=0; col<columnas; col++) {
                    int num=fila*columnas+col+1;
                    if(num==posSeleccionada)setColor(GREEN);
                    else setColor(WHITE);
                    cout<<"["<<((num<10) ? "0" : "") <<num<<"]";
                    if(col<columnas-1)cout<<" ";
                }
                cout<<"\t\t";
                for(int col=0; col<columnas; col++) {
                    int num=cantPorPiso+fila*columnas+col+1;
                    if(num==posSeleccionada)setColor(GREEN);
                    else setColor(WHITE);
                    cout<<"["<<num<<"]";
                    if(col<columnas-1)cout<<" ";
                }
                cout<<"\n";
            }

            int tecla=getkey();
            if(tecla==KEY_UP) {
                posSeleccionada-=columnas;
                if(posSeleccionada<=0)posSeleccionada+=cant;
            }else if(tecla==KEY_DOWN){
                posSeleccionada+=columnas;
                if(posSeleccionada>cant)posSeleccionada-=cant;
            }else if(tecla==KEY_LEFT){
                posSeleccionada--;
                if(posSeleccionada<1)posSeleccionada=cant;
            }else if(tecla==KEY_RIGHT){
                posSeleccionada++;
                if(posSeleccionada>cant)posSeleccionada=1;
            }else if(tecla==KEY_ENTER){
                return posSeleccionada;
            }else if(tecla==KEY_ESCAPE){
                break;
            }
        }
    }
}

///Funciones Viajes-pasajes
void venta_de_pasaje(){

    Pasajeros pasajero;
    Archivo_pasajeros archivoPasajeros;

    Viajes viaje;
    Archivo_viajes archivoViajes;

    Pasajes pasaje;
    Archivo_pasajes archivoPasaje;

    Destinos destino;
    Archivo_destinos archivoDestinos;

    Provincia provincia;
    Archivo_provincias archivoProvincias;

    Micros micro;
    Archivo_micros archivoMicros;

    int contregViajes=archivoViajes.contarRegistros();
    int contregDestinos=archivoDestinos.contarRegistros();
    int contregProvincias=archivoProvincias.contarRegistros();
    int contregMicros=archivoMicros.contarRegistros();
    int contregPasajeros=archivoPasajeros.contarRegistros();

    if(contregViajes<0){cout<<"ERROR AL LEER EL ARCHIVO DE VIAJES"<<endl; return; }
    if(contregDestinos<0){cout<<"ERROR AL LEER EL ARCHIVO DE DESTINOS"<<endl; return; }
    if(contregProvincias<0){cout<<"ERROR AL LEER EL ARCHIVO DE PROVINCIAS"<<endl; return; }
    if(contregMicros<0){cout<<"ERROR AL LEER EL ARCHIVO DE MICROS"<<endl; return; }
    if(contregPasajeros<0){cout<<"ERROR AL LEER EL ARCHIVO DE PASAJEROS"<<endl; return; }

    int idViaje;
    idViaje=viajes_disponibles();
    if(idViaje<0)cout<<"ERROR AL VER LOS ARCHIVOS"<<endl;
    cout<<"Ingrese cantidad de personas: ";
    int cantPasajes;
    cin>>cantPasajes;

    for(int i=0; i<cantPasajes; i++){
        cout<<"\n=== Pasajero "<<i+1<<" ==="<<endl;

        int numeroPasaje=contregPasajeros+1;
        pasaje.setpasaje(numeroPasaje);

        bool viajeValido=false;
        while(!viajeValido){

            for(int i=0; i<contregViajes; i++){
                viaje=archivoViajes.leerRegistros(i);
                if(viaje.getidViaje()==idViaje){
                    pasaje.setidviaje(viaje.getidViaje());
                    for(int x=0; x<contregMicros; x++){
                        micro=archivoMicros.leerRegistros(i);
                        if(viaje.getidMicro()==micro.getidMicro()){
                            int butaca=selecion_de_butacas(micro.getcapacidad(), micro);
                            pasaje.setbutaca(butaca);
                            pasaje.settipo_butaca(micro.gettipo());
                            for(int z=0; z<contregDestinos; z++){
                                destino=archivoDestinos.leerRegistros(i);
                                if(viaje.getidDestino()==destino.getidDestino()){
                                    pasaje.setnombre_destino(destino.getnombre_destino());
                                    pasaje.setprovincia_destino(destino.getnombre_provincia());
                                }
                            }
                        }
                    }
                }
            }
            pasajero.cargar(pasaje.getpasaje());
            archivoPasajeros.grabarRegistro(pasajero);

            archivoPasaje.grabarRegistro(pasaje);

            cout<<"Pasaje "<<numeroPasaje<<" registrado correctamente.\n";
            viajeValido=true;
            break;

        }
    }
}

void mostrar_pasajes_vendidos(){
    Archivo_pasajes archivo;
    archivo.listar();

}
void cargar_viaje(){
    Viajes viaje;
    Archivo_viajes archivo;
    int idv;

    int contreg=archivo.contarRegistros();

    if(contreg<0){
        cout<<"ERROR AL LEER EL ARCHIVO"<<endl;
        return;
    }

    if(contreg==0){
        idv=1000;
    }else{
        int idmax=999;
        viaje=archivo.leerRegistros(contreg-1);
        if(viaje.getidViaje()>idmax) idmax=viaje.getidViaje();
        idv=idmax+1;
    }
    viaje.cargar(idv);
    if(archivo.grabarRegistro(viaje))cout<<endl<<"VIAJE REGISTRADO SATISFACTORIAMENTE. ID: "<<idv<<endl;
    else cout<<"ERROR AL GUARDAR EL REGISTRO."<<endl;
}
void mostrar_viajes(){
    Archivo_viajes archivo;
    archivo.listar();
}


///Funciones usuarios
void ingresar_usuario(){
    Usuarios usuario;
    Archivo_usuarios archivo;
    int idu;

    int contreg=archivo.contarRegistros();

    if(contreg<0){
        cout<<"ERROR AL LEER EL ARCHIVO. NO SE PUEDE REGISTRAR."<<endl;
        return;
    }

    if(contreg==0){
        idu=10000;
    }else{
        int idmax=9999;
        usuario=archivo.leerRegistros(contreg-1);
        if(usuario.getidUsuario()>idmax)idmax=usuario.getidUsuario();
        idu=idmax+1;
    }
    usuario.cargar(idu);

    if (archivo.grabarRegistro(usuario))cout<<endl<<"USUARIO REGISTRADO SATISFACTORIAMENTE. ID: "<<idu<<endl;
    else cout<<"ERROR AL GUARDAR EL REGISTRO."<<endl;
}
void mostrar_usuarios(){
    Archivo_usuarios archivo;
    archivo.listar();
}
void eliminar_usuario(){
    Archivo_usuarios archivo;
    int idu;
    cout<<"INGRESE ID DE USUARIO A DAR DE BAJA: "; cin>>idu;
    int pos=archivo.buscarRegistro(idu);
    if(pos<0){
        cout<<"NO EXISTE UN USUARIO CON ESE ID EN EL ARCHIVO"<<endl;
        return;
    }
    Usuarios usuario=archivo.leerRegistros(pos);
    if(usuario.getestado()==true){
        cout<<"EL USUARIO YA FUE DADO DE BAJA"<<endl;
        return;
    }else{
        usuario.setestado(true);
        archivo.modificarRegistro(usuario, pos);
        cout<<"SE DIO DE BAJA AL USUARIO CORRECTAMENTE"<<endl;
    }
}
void cambiar_contrasena(){
    Archivo_usuarios archivo;
    int idu;
    cout<<"INGRESE LA ID A CAMBIAR LA CONTRASEÑA"<<endl;
    cin>>idu;
    int pos=archivo.buscarRegistro(idu);

    if(pos<0){
        cout<<"NO EXISTE EL USUARIO CON ESE ID EN EL ARCHIVO"<<endl;
        return;
    }
    Usuarios ususario=archivo.leerRegistros(pos);
    char nueva_contrasena[30];
    if(ususario.getestado()){
        cout<<"INGRESE NUEVA CONTRASEÑA"<<endl;
        cin>>nueva_contrasena;
        ususario.setcontrasena(nueva_contrasena);
        archivo.modificarRegistro(ususario, pos);
        cout<<"SE CAMBIO LA CONTRASEÑA CORRECTAMENTE"<<endl;
    }else cout<<"USUARIO INEXISTENTE"<<endl;
}

///Funciones micros
void ingresar_Micro(){
    Micros micros;
    Archivo_micros archivo;
    int idm;

    int contreg=archivo.contarRegistros();

    if(contreg<0){
        cout<<"ERROR AL LEER EL ARCHIVO. NO SE PUEDE REGISTRAR."<<endl;
        return;
    }

    if(contreg==0){
        idm=1000;
    }else{
        int idmax=999;
        micros=archivo.leerRegistros(contreg-1);
        if(micros.getidMicro()>idmax)idmax=micros.getidMicro();
        idm=idmax+1;
    }

    micros.cargar(idm);

    if (archivo.grabarRegistro(micros))cout<<endl<<"USUARIO REGISTRADO SATISFACTORIAMENTE. ID: "<<idm<<endl;
    else cout<<"ERROR AL GUARDAR EL REGISTRO."<<endl;
}
void mostrar_Micro(){
    Archivo_micros archivo;
    archivo.listar();
}
void eliminar_Micro(){
    Archivo_micros archivo;
    int idm;
    cout<<"INGRESE ID DE MICRO A DAR DE BAJA: "; cin>>idm;
    int pos=archivo.buscarRegsitro(idm);
    if(pos<0){
        cout<<"NO EXISTE UN MICRO CON ESE ID EN EL ARCHIVO"<<endl;
        return;
    }
    Micros micros=archivo.leerRegistros(pos);
    if(micros.getdisponible()==false){
        cout<<"EL MICRO YA FUE DADO DE BAJA"<<endl;
        return;
    }else{
        micros.setdisponible(false);
        archivo.modificarRegistro(micros, pos);
        cout<<"SE DIO DE BAJA EL MICRO CORRECTAMENTE"<<endl;
    }
}
void cambiar_patente_Micro(){
    Archivo_micros archivo;
    Micros micro;
    int id;
    cout << "ingrese el ID del micro: " << endl;
    cin >> id;
    int pos=archivo.buscarRegsitro(id);
    if(pos<0){
        cout<<"NO EXISTE MICRO CON ESE ID EN EL ARCHIVO"<<endl;
        return;
    }
    micro=archivo.leerRegistros(pos);
    char patente_Nuevo[20];
    bool patenteOK=false;
    if(micro.getdisponible()){
        while(!patenteOK){
            cout<<"INGRESE LA NUEVA PATENTE (formato AA111AA): ";
            cargarCadena(patente_Nuevo, 19);
            for(int i=0; patente_Nuevo[i]; i++)patente_Nuevo[i]=toupper(patente_Nuevo[i]);

            patenteOK=validarPatente(patente_Nuevo);
        }
        micro.setpatente(patente_Nuevo);
        archivo.modificarRegistro(micro, pos);
        cout<<"SE CAMBIO LA PATENTE CORRECTAMENTE"<<endl;
    }else cout<<"MICRO INEXISTENTE"<<endl;
}
void cambiar_unidad_Micro(){
    Archivo_micros archivo;
    Micros micro;
    int idm;
    cout<<"ingrese el ID del micro: "; cin>>idm;
    int pos=archivo.buscarRegsitro(idm);
    if(pos<0){
        cout<<"NO EXISTE MICRO CON ESE ID EN EL ARCHIVO"<<endl;
        return;
    }
    micro=archivo.leerRegistros(pos);
    if (micro.getdisponible()){
        micro.cargar(idm);
        archivo.modificarRegistro(micro, pos);
    }else cout<<"MICRO INEXISTENTE"<<endl;
}

///Funciones destinos-pasajes
void ingresar_destino(){
    Destinos destinos;
    Archivo_destinos archivo;
    int idd;

    int contreg=archivo.contarRegistros();

    if(contreg<0){
        cout<<"ERROR AL LEER EL ARCHIVO. NO SE PUEDE REGISTRAR."<<endl;
        return;
    }

    if(contreg==0){
        idd=100000;
    }else{
        int idmax=99999;
        destinos=archivo.leerRegistros(contreg-1);
        if(destinos.getidDestino()>idmax)idmax=destinos.getidDestino();
        idd=idmax+1;
    }
    destinos.cargar(idd);

    if(archivo.grabarRegistro(destinos))cout<<endl<<"USUARIO REGISTRADO SATISFACTORIAMENTE. ID: "<<idd<<endl;
    else cout<<"ERROR AL GUARDAR EL REGISTRO."<<endl;
}
void mostrar_destino(){
    Archivo_destinos archivo;
    archivo.listar();
}
void eliminar_destino(){
    Archivo_destinos archivo;
    Destinos destinos;
    int idd;
    cout<<"INGRESE ID DEL DESTINO A DAR DE BAJA: ";
    cin>>idd;

    int pos=archivo.buscarRegistros(idd);
    if (pos<0) {
        cout<<"NO EXISTE UN DESTINO CON ESE ID EN EL ARCHIVO"<<endl;
        return;
    }

    destinos=archivo.leerRegistros(pos);
    if (destinos.gethabilitado()==false) {
        cout<<"EL DESTINO YA FUE DADO DE BAJA"<<endl;
        return;
    }else{
        destinos.sethabilitado(false);
        archivo.modificarRegistro(destinos, pos);
        cout << "SE DIO DE BAJA EL DESTINO CORRECTAMENTE" << endl;
    }
}
void cargar_prvincias(){
    Provincia provincia;
    Archivo_provincias archivo;

    int contreg=archivo.contarRegistros();

    if(contreg<0){
        cout<<"ERROR AL LEER EL ARCHIVO"<<endl;
        return;
    }

    provincia.cargar();
    archivo.grabarRegistro(provincia);
}
void mostar_provincias(){
    Archivo_provincias archivo;
    archivo.listar();
}

///Funciones choferes
void ingresar_chofer(){
    Choferes chofer;
    Archivo_choferes archivo;
    int leg;

    int contreg=archivo.contarRegistros();

    if(contreg<0){
        cout<<"ERROR AL LEER EL ARCHIVO. NO SE PUEDE REGISTRAR."<<endl;
        return;
    }

    if(contreg==0){
        leg=100;
    }else{
        int idmax=99;
        chofer=archivo.leerRegistros(contreg-1);
        if(chofer.getlegajo()>idmax)idmax=chofer.getlegajo();
        leg=idmax+1;
    }
    chofer.cargar(leg);

    if (archivo.grabarRegistro(chofer))cout<<endl<<"CHOFER REGISTRADO SATISFACTORIAMENTE. ID: "<<leg<<endl;
    else cout<<"ERROR AL GUARDAR EL REGISTRO."<<endl;
}
void mostrar_choferes(){
    Archivo_choferes archivo;
    archivo.listar();
}
void eliminar_chofer(){
    Archivo_choferes archivo;
    Choferes chofer;
    int leg;
    cout<<"INGRESE LEGAJO DEL CHOFER A DAR DE BAJA: "; cin>>leg;
    int pos=archivo.buscarRegistro(leg);
    if(pos<0){
        cout<<"NO EXISTE UN CHOFER CON ESE LEGAJO EN EL ARCHIVO"<<endl;
        return;
    }
    chofer=archivo.leerRegistros(pos);
    if(chofer.getestado()==false){
        cout<<"EL CHOFER YA FUE DADO DE BAJA"<<endl;
        return;
    }else{
        chofer.setestado(false);
        archivo.modificarRegistro(chofer, pos);
        cout<<"SE DIO DE BAJA AL CHOFER CORRECTAMENTE"<<endl;
    }
}
void cambiar_mail_chofer(){
    Archivo_choferes archivo;
    Choferes chofer;
    int leg;
    cout<<"INGRESE EL LEGAJO DEL CHOFER: ";
    cin>>leg;
    int pos=archivo.buscarRegistro(leg);

    if(pos<0){
        cout<<"NO EXISTE EL CHOFER CON ESE LEGAJO EN EL ARCHIVO"<<endl;
        return;
    }
    chofer=archivo.leerRegistros(pos);
    char Mail_Nuevo[40];
    if(chofer.getestado()){
        cout<<"INGRESE NUEVO MAIL"<<endl;
        cin>>Mail_Nuevo;
        chofer.setemail(Mail_Nuevo);
        archivo.modificarRegistro(chofer, pos);
        cout<<"SE CAMBIO EL MAIL CORRECTAMENTE"<<endl;
    }else cout<<"CHOFER INEXISTENTE"<<endl;
}
void cambiar_telefono_chofer(){
    Archivo_choferes archivo;
    Choferes chofer;
    int leg;
    cout<<"INGRESE EL LEGAJO DEL CHOFER: ";
    cin>>leg;
    int pos=archivo.buscarRegistro(leg);

    if(pos<0){
        cout<<"NO EXISTE EL CHOFER CON ESE LEGAJO EN EL ARCHIVO"<<endl;
        return;
    }
    chofer=archivo.leerRegistros(pos);
    int Tel_Nuevo;
    if(chofer.getestado()){
        cout<<"INGRESE NUEVO TELEFONO"<<endl;
        cin>>Tel_Nuevo;
        chofer.settelefono(Tel_Nuevo);
        archivo.modificarRegistro(chofer, pos);
        cout<<"SE CAMBIO EL TELEFONO CORRECTAMENTE"<<endl;
    }else cout<<"CHOFER INEXISTENTE"<<endl;
}

//void por_anio(){
//    Pasajes pasaje;
//    cout<<"ingrese un año: "<<endl;
//    int anio;
//    cin>>anio;
//    float acumulador=0;
//    int tam=pasaje.contarRegistros();
//    for(int i=0; i<tam; i++){
//        pasaje=pasaje.leerRegistros(i);
//        if(pasaje.getfecha_Inicio().getanio()==anio){
//            acumulador += pasaje.getprecioxkm();
//        }
//    }
//    cout<<"RECAUDACION TOTAL EN EL AÑO "<<anio<<": "<<acumulador<<endl;
//}
//void por_micro(){
//    Archivo_micros archivo;
//    Micros micros;
//    Pasajes pasaje;
//    cout<<"ingrese el ID del micro: "<<endl;
//    int id;
//    cin>>id;
//    float acumulador;
//    int cantreg1=archivo.contarRegistros();
//    int cantreg2=pasaje.contarRegistros();
//
//    for (int i=0; i<cantreg1; i++){
//        micros=archivo.leerRegistros(i);
//        if (micros.getidMicro()==id){
//            for(int z=0; z<cantreg2; z++){
//                pasaje=pasaje.leerRegistros(i);
//                if(pasaje.getidmicro()==micros.getidMicro()) acumulador += pasaje.getprecioxkm();
//            }
//        }
//    }
//    cout << "RECAUDACION TOTAL DEL MICRO ES DE :" << acumulador << endl;
//}
void por_destino(){
    /**
    Archivo_destinos archivo;
    Destinos destino;
    pasajes pasaje;
    float acumulador[23];
    int tam = archivo.contarRegistros;
    for (int i = 0; i < tam; i++){
        destino = archivo.leerRegistro(i);
        acumulador[destino.getnumero_destino()-1] += precio

    }
    cout << "RECAUDACION TOTAL DEL MICRO ES DE :" << acumulador << endl;
    */
}
void cantPasajes_destino_mes(){}
void kilometros_micro(){}
void por_genero_anio(){}
void viajes_chofer_mes(){}

///MENUS Y SUBMENUS
void SUBMENU_1(){
    int seleccion=0;
    const int opciones_submenu=5;
    string submenu[opciones_submenu]={
        " COMPRA DE PASAJE",
        " PASAJES VENDIDOS",
        " CARGAR VIAJES",
        " MOSTRAR VIAJES DISPONIBLES",
        " MENU PRINCIPAL"
    };
    bool salir=false;

    while(!salir){
        cls();
        setColor(WHITE);
        for(int i=0; i<6; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<6; i++){locate(75,11+i); cout << "|";}
        locate(44,10);
        cout<<"-----------USUARIOS------------"<<endl;
        locate(44,11);
        cout<<"-------------------------------"<<endl;
        for(int i=0; i<opciones_submenu; i++){
            setColor(WHITE);
            locate(45,12+i);
            if(i==seleccion){
                setColor(GREEN);
                cout<<"> "<<submenu[i]<<endl;
                setColor(WHITE);
            }else cout<<"  "<<submenu[i]<<endl;
        }
        setColor(WHITE);
        locate(44,17);
        cout<<"-------------------------------"<<endl;
        setColor(WHITE);
        int tecla=getkey();
        if(tecla==KEY_UP){
            seleccion--;
            if(seleccion<0)seleccion=opciones_submenu-1;
        }else if(tecla==KEY_DOWN){
            seleccion++;
            if(seleccion>=opciones_submenu)seleccion=0;
        }else if(tecla==KEY_ENTER){
            cls();
            switch(seleccion){
            case 0:
                cls();
                venta_de_pasaje();
                anykey();
                cls();
                break;
            case 1:
                cls();
                mostrar_pasajes_vendidos();
                anykey();
                cls();
                break;
            case 2:
                cls();
                cargar_viaje();
                anykey();
                cls();
                break;
            case 3:
                cls();
                mostrar_viajes();
                anykey();
                cls();
                break;
            case 4:
                salir=true;
                break;
            }
        }
    }
}

void SUBMENU_2(){
    int seleccion=0;
    const int opciones_submenu=6;
    string submenu[opciones_submenu]={
        " INGRESA MICRO",
        " MOSTRAR MICROS",
        " DAR DE BAJA MICRO",
        " CAMBIAR PATENTE",
        " CAMBIAR LA UNIDAD",
        " MENU PRINCIPAL"
    };
    bool salir=false;

    while(!salir){
        cls();
        setColor(WHITE);
        for(int i=0; i<7; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<7; i++){locate(73,11+i); cout << "|";}
        locate(44,10);
        cout<<"----------USUARIOS-----------"<<endl;
        locate(44,11);
        cout<<"-----------------------------"<<endl;
        for(int i=0; i<opciones_submenu; i++){
            setColor(WHITE);
            locate(45,12+i);
            if(i==seleccion){
                setColor(GREEN);
                cout<<"> "<<submenu[i]<<endl;
                setColor(WHITE);
            }else cout<<"  "<<submenu[i]<<endl;
        }
        setColor(WHITE);
        locate(44,18);
        cout<<"-----------------------------"<<endl;
        setColor(WHITE);
        int tecla=getkey();
        if(tecla==KEY_UP){
            seleccion--;
            if(seleccion<0)seleccion=opciones_submenu-1;
        }else if(tecla==KEY_DOWN){
            seleccion++;
            if(seleccion>=opciones_submenu)seleccion=0;
        }else if(tecla==KEY_ENTER){
            cls();
            switch(seleccion){
            case 0:
                cls();
                ingresar_Micro();
                anykey();
                cls();
                break;
            case 1:
                cls();
                mostrar_Micro();
                anykey();
                cls();
                break;
            case 2:
                cls();
                eliminar_Micro();
                anykey();
                cls();
                break;
            case 3:
                cls();
                cambiar_patente_Micro();
                anykey();
                cls();
                break;
            case 4:
                cls();
                cambiar_unidad_Micro();
                anykey();
                cls();
                break;
            case 5:
                salir=true;
                break;
            }

        }
    }
}

void SUBMENU_3(){
    int seleccion=0;
    const int opciones_submenu=6;
    string submenu[opciones_submenu]={
        " ALTA DE NUEVO CONDUCTOR",
        " LISTA DE CONDUCTORES",
        " DAR DE BAJA",
        " CAMBIAR MAIL ",
        " CAMBIAR TELEFONO",
        " MENU PRINCIPAL"
    };
    bool salir=false;

    while(!salir){
        cls();
        setColor(WHITE);
        for(int i=0; i<7; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<7; i++){locate(73,11+i); cout << "|";}
        locate(44,10);
        cout<<"----------CHOFERES-----------"<<endl;
        locate(44,11);
        cout<<"-----------------------------"<<endl;
        for(int i=0; i<opciones_submenu; i++){
            setColor(WHITE);
            locate(45,12+i);
            if(i==seleccion){
                setColor(GREEN);
                cout<<"> "<<submenu[i]<<endl;
                setColor(WHITE);
            }else cout<<"  "<<submenu[i]<<endl;
        }
        setColor(WHITE);
        locate(44,18);
        cout<<"-----------------------------"<<endl;
        setColor(WHITE);
        int tecla=getkey();
        if(tecla==KEY_UP){
            seleccion--;
            if(seleccion<0)seleccion=opciones_submenu-1;
        }else if(tecla==KEY_DOWN){
            seleccion++;
            if(seleccion>=opciones_submenu)seleccion=0;
        }else if(tecla==KEY_ENTER){
            cls();
            switch(seleccion){
            case 0:
                cls();
                ingresar_chofer();
                anykey();
                cls();
                break;
            case 1:
                cls();
                mostrar_choferes();
                anykey();
                cls();
                break;
            case 2:
                cls();
                eliminar_chofer();
                anykey();
                cls();
                break;
            case 3:
                cls();
                cambiar_mail_chofer();
                anykey();
                cls();
                break;
            case 4:
                cls();
                cambiar_telefono_chofer();
                anykey();
                cls();
                break;
            case 5:
                salir=true;
                break;
            }

        }
    }
}

void SUBMENU_4(){
    int seleccion=0;
    const int opciones_submenu=5;
    string submenu[opciones_submenu]={
        " INGRESAR DESTINO",
        " MOSTRAR DESTINO",
        " DAR DE BAJA UN DESTINO",
        " PROVINCIAS",
        " SALIR AL MENU"
    };
    bool salir=false;

    while(!salir){
        cls();
        setColor(WHITE);
        for(int i=0; i<6; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<6; i++){locate(73,11+i); cout << "|";}
        locate(44,10);
        cout<<"----------USUARIOS-----------"<<endl;
        locate(44,11);
        cout<<"-----------------------------"<<endl;
        for(int i=0; i<opciones_submenu; i++){
            setColor(WHITE);
            locate(45,12+i);
            if(i==seleccion){
                setColor(GREEN);
                cout<<"> "<<submenu[i]<<endl;
                setColor(WHITE);
            }else cout<<"  "<<submenu[i]<<endl;
        }
        setColor(WHITE);
        locate(44,17);
        cout<<"-----------------------------"<<endl;
        setColor(WHITE);
        int tecla=getkey();
        if(tecla==KEY_UP){
            seleccion--;
            if(seleccion<0)seleccion=opciones_submenu-1;
        }else if(tecla==KEY_DOWN){
            seleccion++;
            if(seleccion>=opciones_submenu)seleccion=0;
        }else if(tecla==KEY_ENTER){
            cls();
            switch(seleccion){
            case 0:
                cls();
                ingresar_destino();
                anykey();
                cls();
                break;
            case 1:
                cls();
                mostrar_destino();
                anykey();
                cls();
                break;
            case 2:
                cls();
                eliminar_destino();
                anykey();
                cls();
                break;
            case 3:
                cls();
                mostar_provincias();
                anykey();
                cls();
                break;
            case 4:
                salir=true;
                break;
            }
        }
    }
}

void SUBMENU_5(){
    Archivo_historial_usuarios historial;
    int seleccion=0;
    const int opciones_submenu=6;
    string submenu[opciones_submenu]={
        " INGRESAR NUEVO USUARIO",
        " MOSTRAR USUARIOS",
        " MOSTRAR SESIONES",
        " DAR DE BAJA USUARIO",
        " CAMBIAR CONTRASEÑA",
        " MENU PRINCIPAL"
    };
    bool salir=false;

    while(!salir){
        cls();
        setColor(WHITE);
        for(int i=0; i<7; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<7; i++){locate(73,11+i); cout << "|";}
        locate(44,10);
        cout<<"----------USUARIOS-----------"<<endl;
        locate(44,11);
        cout<<"-----------------------------"<<endl;
        for(int i=0; i<opciones_submenu; i++){
            setColor(WHITE);
            locate(45,12+i);
            if(i==seleccion){
                setColor(GREEN);
                cout<<"> "<<submenu[i]<<endl;
                setColor(WHITE);
            }else cout<<"  "<<submenu[i]<<endl;
        }
        setColor(WHITE);
        locate(44,18);
        cout<<"-----------------------------"<<endl;
        setColor(WHITE);
        int tecla=getkey();
        if(tecla==KEY_UP){
            seleccion--;
            if(seleccion<0)seleccion=opciones_submenu-1;
        }else if(tecla==KEY_DOWN){
            seleccion++;
            if(seleccion>=opciones_submenu)seleccion=0;
        }else if(tecla==KEY_ENTER){
            cls();
            switch(seleccion){
            case 0:
                cls();
                ingresar_usuario();
                anykey();
                cls();
                break;
            case 1:
                cls();
                mostrar_usuarios();
                anykey();
                cls();
                break;
            case 2:
                cls();
                historial.listar();
                anykey();
                cls();
                break;
            case 3:
                cls();
                eliminar_usuario();
                anykey();
                cls();
                break;
            case 4:
                cls();
                cambiar_contrasena();
                anykey();
                cls();
                break;
            case 5:
                salir=true;
                break;
            }

        }
    }
}

void SUBMENU_6(){
    int seleccion=0;
    const int opciones_submenu=8;
    string submenu[opciones_submenu]={
        " RECAUDACION POR AÑO",
        " RECAUDACION POR MICRO",
        " RECAUDACION POR DESTINO",
        " PASAJES VENDIDOS POR DESTINO EN UN MES",
        " KILOMETROS RECORRIDOS POR MICRO",
        " RECAUDACION POR GENERO EN UN AÑO",
        " VIAJES POR CHOFER EN UN MES",
        " MENU PRINCIPAL"
    };
    bool salir=false;

    while(!salir){
        cls();
        setColor(WHITE);
        for(int i=0; i<9; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<9; i++){locate(86,11+i); cout << "|";}
        locate(44,10);
        cout<<"-----------------REPORTES-----------------"<<endl;
        locate(44,11);
        cout<<"------------------------------------------"<<endl;
        for(int i=0; i<opciones_submenu; i++){
            setColor(WHITE);
            locate(45,12+i);
            if(i==seleccion){
                setColor(GREEN);
                cout<<"> "<<submenu[i]<<endl;
                setColor(WHITE);
            }else cout<<"  "<<submenu[i]<<endl;
        }
        setColor(WHITE);
        locate(44,20);
        cout<<"------------------------------------------"<<endl;
        setColor(WHITE);
        int tecla=getkey();
        if(tecla==KEY_UP){
            seleccion--;
            if(seleccion<0)seleccion=opciones_submenu-1;
        }else if(tecla==KEY_DOWN){
            seleccion++;
            if(seleccion>=opciones_submenu)seleccion=0;
        }else if(tecla==KEY_ENTER){
            cls();
            switch(seleccion){
            case 0:
                cls();
                //por_anio();
                anykey();
                cls();
                break;
            case 1:
                cls();
                //por_micro();
                anykey();
                cls();
                break;
            case 2:
                cls();

                anykey();
                cls();
                break;
            case 3:
                cls();

                anykey();
                cls();
                break;
            case 4:
                cls();

                anykey();
                cls();
                break;
            case 5:
                cls();

                anykey();
                cls();
                break;
            case 6:
                cls();

                anykey();
                cls();
                break;
            case 7:
                salir=true;
                break;
            }

        }
    }
}

void MENU(){

    int seleccion=0;
    int opcion;
    const int opciones_menu=7;
    string menu[opciones_menu]={
        " INCIAR VIAJE",
        " MICROS",
        " CHOFERES",
        " DESTINOS",
        " USUARIOS",
        " REPORTES",
        " SALIR"
    };
    bool salir=false;

    while(!salir){
        cls();
        setColor(WHITE);
        for(int i=0; i<8; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<8; i++){locate(73,11+i); cout << "|";}
        locate(44,10);
        cout<<"------------MENU-------------"<<endl;
        locate(44,11);
        cout<<"-----------------------------"<<endl;
        for(int i=0; i<opciones_menu; i++){
            setColor(WHITE);
            locate(45,12+i);
            if(i==seleccion){
                setColor(GREEN);
                cout<<"> "<<menu[i]<<endl;
                setColor(WHITE);
            } else {cout<<"  "<<menu[i]<<endl;}
        }
        setColor(WHITE);
        locate(44,19);
        cout<<"-----------------------------"<<endl;

        setColor(WHITE);
        int tecla=getkey();

        if(tecla==KEY_UP){
            seleccion--;
            if(seleccion<0) seleccion=opciones_menu-1;
        } else if(tecla==KEY_DOWN){
            seleccion++;
            if(seleccion>=opciones_menu) seleccion=0;
        } else if(tecla==KEY_ENTER){
            cls();
            switch(seleccion){
            case 0:
                cls();
                SUBMENU_1();
                break;
            case 1:
                cls();
                SUBMENU_2();
                break;
            case 2:
                cls();
                SUBMENU_3();
                break;
            case 3:
                cls();
                SUBMENU_4();
                break;
            case 4:
                cls();
                SUBMENU_5();
                break;
            case 5:
                cls();
                SUBMENU_6();
                break;
            case 6:
                salir=true;
                break;
            }
        }
    }

}

void inicio_de_sesion(){
    Usuarios usuarios;
    Archivo_usuarios archivos;
    Archivo_historial_usuarios historial;
    Tiempo_Actual tiempo;
    while(true){
        bool bandera=false;
        int id;
        char contasena[30];
        cout<<"ingrese ID de usuario: "; cin>>id;
        cout<<"ingrese contraseña: "; cin>>contasena;
        Fechas fecha(tiempo.getDia(), tiempo.getMes(), tiempo.getAnio());
        Hora actual;

        int contreg=archivos.contarRegistros();
        for(int i=0; i<contreg; i++){
            usuarios=archivos.leerRegistros(i);
            if(usuarios.getidUsuario()==id and strcmp(usuarios.getcontrasena(),contasena)==0 and usuarios.getestado()){
                historial.setidusuario(id);
                historial.setnombre_usuario(usuarios.getnombre());
                historial.setingreso_sesion(fecha);
                historial.setinicio(actual);
                historial.grabarRegistro();
                bandera=true;
                break;
            }
        }
        if(bandera==false){
            cls();
            cout<<"Usuario y/o Contraseña incorrectos"<<endl;
            anykey();
            cls();
        }
        if(bandera){MENU(); break;}
    }
}
