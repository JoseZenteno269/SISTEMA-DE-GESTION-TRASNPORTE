#include<iostream>
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

///Funciones usuarios
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

///Funciones micros
void ingresar_Micro(){
    Micros micros;
    Archivo_micros archivo;
    int minimo=1000;
    int maximo=9999;
    bool idunico=false;
    int idm;
    int contreg=archivo.contarRegistros();
    if(contreg<0){
        cls();
        idm=minimo+rand()%(maximo-minimo+1);
    }else{
        while(!idunico){
            idm=minimo+rand()%(maximo-minimo+1);
            idunico=true;
            for(int i=0; i<contreg; i++){
                micros=archivo.leerRegistros(i);
                if(idm==micros.getidMicro()){
                    idunico=false;
                    break;
                }
            }
        }
    }
    micros.cargar(idm);
    archivo.grabarRegistro(micros);
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

///Funciones destinos
void ingresar_destino(){

}
void mostrar_destino(){

}
void eliminar_destino(){

}

///Funciones choferes
void ingresar_chofer(){
    Choferes chofer;
    Archivo_choferes archivo;
    int minimo = 100;
    int maximo = 999;
    bool idunico = false;
    int leg;
    int contreg = archivo.contarRegistros();
    if(contreg < 0){
        cls();
       leg = minimo+rand()%(maximo-minimo+1);
    }
    else{
        while(!idunico){
            leg=minimo+rand()%(maximo-minimo+1);
            idunico=true;
            for(int i=0; i<contreg; i++){
                chofer=archivo.leerRegistros(i);
                if(leg==chofer.getlegajo()){
                    idunico=false;
                    break;
                }
            }
        }
    }
    chofer.cargar(leg);
    archivo.grabarRegistro(chofer);
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
void cambiar_mail(){
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

///MENUS Y SUBMENUS
/**
    no hay archivos .dat cargados de sus clases que realizaron.
    en el submenu 2 y submenu 4 dejar la parte de cambiar, despues vemos con que lo reemplazamos

    realizen inmgresos al .dat asi ya quedan guardados, no den de baja ninguno,
    y si no se agrega nada a las clases de destino, micros y choferes, realizen las cargas y
    realizen una copia de ese archivo asi no perdemos nada


    GONZALO, seguir con las funciones de destinos. realizar ingresos al archivo de destinos con 25 destinos

    LEO, realizar ingresos al archivo de micros con 20 micros.
    TIPOS DE MICRO:
    "Común"
    "Semi Cama"
    "Cama Ejecutivo"
    "Cama Suite" o "Suite"
    "Doble Piso"
    "Charter"
    "Mini Bus"

    TIPOS DE BUTACA:
    "Estándar"
    "Reclinable"
    "Ergonómica"
    "Cuero"
    "Cuero Premium"
    "Butaca 180°"
    "Tela Acolchada"
    "Con Apoyapiés"

    ANGEL, completar el submenu 3 (deja de poner variables con nombres tontos y/o absurdos). realizar ingresos al archivo de choferes ingresando 20 choferes
*/
void SUBMENU_1(){

}

void SUBMENU_2(){
    int seleccion=0;
    const int opciones_submenu=5;
    string submenu[opciones_submenu]={
        " INGRESA MICRO",
        " MOSTRAR MICROS",
        " DAR DE BAJA MICRO",
        " CAMBIAR ALGO",
        " MENU PRINCIPAL"
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

void SUBMENU_3(){

}

void SUBMENU_4(){
    int seleccion=0;
    const int opciones_submenu=5;
    string submenu[opciones_submenu]={
        " INGRESAR DESTINO",
        " MOSTRAR DESTINO",
        " DAR DE BAJA UN DESTINO",
        " CAMBIAR ALGO",
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
