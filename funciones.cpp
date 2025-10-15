#include<iostream>
#include <algorithm>
#include "funciones.h"
#include "rlutil.h"
#include "MICROS.h"
#include "CHOFERES.h"
#include "USUARIOS.h"
#include "ARCHIVO_USUARIOS.h"
#include "DESTINOS.h"
#include "FECHAS.h"
#include "ARCHIVO_HISTORIAL_INGRESOS.h"


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

//Genero interpretar(string g){
//    transform(g.begin(), g.end(), g.begin(), ::tolower);
//
//    if(g=="masculino" or g=="hombre" or g=="m"){
//        return MASCULINO;
//    }else if(g=="famenino" or g=="mujer" or g=="f"){
//        return FEMENINO;
//    }else if(g=="otro" or g=="no binario" or g=="x"){
//        return OTROS;
//    }else return DESCONOCIDO;
//}
//string cargoGenero(string g){
//    switch(g){
//        case MASCULINO: return "Masculino";
//        case FEMENINO:  return "Femenino";
//        case OTROS:     return "Otro";
//        default:        return "Desconocido";
//    }
//}

void ingresar_usuario(){
    Usuarios usuarios;
    Archivo_usuarios archivo;
    int minimo=10000;
    int maximo=99999;
    bool idunico=false;
    int idu;
    int contreg=archivo.contarRegistros();
    if(contreg<0){
        cls();
        idu=minimo+rand()%(maximo-minimo+1);
    }else{
        while(!idunico){
            idu=minimo+rand()%(maximo-minimo+1);
            idunico=true;
            for(int i=0; i<contreg; i++){
                usuarios=archivo.leerRegistros(i);
                if(idu==usuarios.getidUsuario()){
                    idunico=false;
                    break;
                }
            }
        }
    }
    usuarios.cargar(idu);
    archivo.grabarRegistro(usuarios);
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

void SUBMENU_1(){

}

void SUBMENU_2(){

}

void SUBMENU_3(){

}

void SUBMENU_4(){

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

void MENU(){

    int seleccion=0;
    int opcion;
    const int opciones_menu=6;
    string menu[opciones_menu]={
        " INCIAR VIAJE",
        " MICROS",
        " CHOFERES",
        " DESTINOS",
        " USUARIOS",
        " SALIR"
    };
    bool salir=false;

    while(!salir){
        cls();
        setColor(WHITE);
        for(int i=0; i<7; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<7; i++){locate(73,11+i); cout << "|";}
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
        locate(44,18);
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
    while(true){
        bool bandera=false;
        int id;
        char contasena[30];
        cout<<"ingrese ID de usuario: "; cin>>id;
        cout<<"ingrese contraseña: "; cin>>contasena;
        Fechas fecha;
        cout<<"Fecha de ingreso: "<<endl;
        fecha.cargar();
        int contreg=archivos.contarRegistros();
        for(int i=0; i<contreg; i++){
            usuarios=archivos.leerRegistros(i);
            if(usuarios.getidUsuario()==id and strcmp(usuarios.getcontrasena(),contasena)==0 and usuarios.getestado()){
                historial.setidusuario(id);
                historial.setnombre_usuario(usuarios.getnombre());
                historial.setingreso_sesion(fecha);
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
