#include<iostream>
#include "PERSONA.h"
#include "funciones.h"
#include<cstring>
#include "rlutil.h"
using namespace rlutil;
using namespace std;

void Persona::setnombre(const char *n){strcpy(nombre, n); }
void Persona::setapellido(const char *a){strcpy(apellido, a); }
void Persona::setdni(long long d){dni=d; }
void Persona::settelefono(long long t){telefono=t; }
void Persona::setemail(const char *e){strcpy(email,e);}
void Persona::setgenero(int g){genero=g;}
void Persona::setnacionalidad(const char *nac){strcpy(nacionalidad, nac); }
void Persona::setfecha_Nacimiento(Fecha f){fecha_Nacimiento = f;}
void Persona::setdomicilio(Domicilio d){domicilio=d;}


const char *Persona::getnombre(){return nombre; }
const char *Persona::getapellido(){return apellido; }
long long Persona::getdni(){return dni; }
long long Persona::gettelefono(){return telefono; }
const char *Persona::getemail(){return email;}
int Persona::getgenero(){return genero;}
const char *Persona::getnacionalidad(){return nacionalidad; }
Fecha Persona::getfecha_Nacimiento(){return fecha_Nacimiento;}
Domicilio Persona::getdomicilio(){return domicilio;}

const char* Persona::getgenerotexto()const{
    switch(genero){
    case 1: return "Masculino";
        break;
    case 2: return "Femenino";
        break;
    case 3: return "No binario";
        break;
    default: return "Desconocido";
        break;
    }
}

void Persona::cargar() {

    setColor(GREEN);
    locate(40,7); cout << "-------------- DATOS PERSONALES --------------";
    setColor(WHITE);

    while(true){
        setColor(CYAN);
        locate(40,9); cout << "Ingrese nombre: ";
        setColor(WHITE);
        locate(40,10); cargarCadena(nombre,39);

        if(validarPalabra(nombre)){
            LimpiarLineas(9,14,40);
            break;
        }
        setColor(RED);
        locate(40,12); cout << "Nombre inválido. Intente nuevamente.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(9,14,40);
    }

    while(true){
        setColor(CYAN);
        locate(40,9); cout << "Ingrese apellido: ";
        setColor(WHITE);
        locate(40,10); cargarCadena(apellido,39);

        if(validarPalabra(apellido)){
            LimpiarLineas(9,14,40);
            break;
        }
        setColor(RED);
        locate(40,12); cout << "Apellido inválido. Intente nuevamente.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(9,14,40);
    }

    while(true){
        setColor(CYAN);
        locate(40,9); cout << "Ingrese DNI (7-11 dígitos): ";
        setColor(WHITE);
        locate(40,10); cin >> dni;

        int longitud = to_string(dni).length();
        if(validar_numero() && longitud>=7 && longitud<=11){
            LimpiarLineas(9,14,40);
            break;
        }
        setColor(RED);
        locate(40,12); cout << "DNI inválido. Intente nuevamente.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(9,14,40);
    }

    while(true){
        setColor(CYAN);
        locate(40,9); cout << "Ingrese Teléfono (10 dígitos): ";
        setColor(WHITE);
        locate(40,10); cin >> telefono;

        int longitud = to_string(telefono).length();
        if(validar_numero() && longitud==10){
            LimpiarLineas(9,14,40);
            break;
        }
        setColor(RED);
        locate(40,12); cout << "Número inválido. Intente nuevamente.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(9,14,40);
    }

    setColor(CYAN);
    locate(40,9); cout << "Ingrese email: ";
    setColor(WHITE);
    locate(40,10); cargarCadena(email,99);
    LimpiarLineas(9,14,40);

    while(true){
        setColor(CYAN);
        locate(40,9); cout << "Género (1=MASC,2=FEM,3=NB): ";
        setColor(WHITE);
        locate(40,10); cin >> genero;

        if(validar_numero() && (genero>=1 && genero<=3)){
            LimpiarLineas(9,14,40);
            break;
        }
        setColor(RED);
        locate(40,12); cout << "Opción inválida.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(9,14,40);
    }

    while(true){
        setColor(CYAN);
        locate(40,9); cout << "Ingrese nacionalidad: ";
        setColor(WHITE);
        locate(40,10); cargarCadena(nacionalidad,39);

        if(validarPalabra(nacionalidad)){
            LimpiarLineas(9,14,40);
            break;
        }
        setColor(RED);
        locate(40,12); cout << "Nacionalidad inválida.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(9,14,40);
    }

    setColor(CYAN);
    locate(40,9); cout << "Fecha de nacimiento: ";
    setColor(WHITE);
    locate(40,10); fecha_Nacimiento.cargar();
    LimpiarLineas(9,14,40);

    setColor(CYAN);
    locate(40,9); cout << "Ingrese domicilio: ";
    setColor(WHITE);
    locate(40,10); domicilio.Cargar();
    LimpiarLineas(9,20,40);
}

void Persona::modificar(){
    int key;
    cls();
    setColor(GREEN);
    locate(40, 7); cout<<"-----------------------------------------------"<<endl;
    locate(40, 8); cout<<"------------ MODIFICACION DE DATOS ------------"<<endl;
    locate(40, 9); cout<<"-----------------------------------------------"<<endl;
    setColor(WHITE);

    setColor(CYAN);
    locate(40,12); cout<<"Nombre actual: "<<getnombre()<<endl;
    locate(40,13); cout<<"ENTER para modificar o tecla cualquiera para saltar..."<<endl;
    setColor(WHITE);

    key=getkey();
    if(key==KEY_ENTER){
        char temp_nombre[40];
        while(true){
            setColor(YELLOW);
            locate(40, 15); cout<<"Ingrese nuevo nombre: ";
            setColor(WHITE);
            cargarCadena(temp_nombre, 39);
            if(!validarPalabra(temp_nombre)){
                LimpiarLineas(15, 20, 40);
                continue;
            }break;
        }
        setnombre(temp_nombre);
        setColor(GREEN);
        locate(40, 17);
        cout<<">> Nombre actualizado." << endl;
        anykey();
        LimpiarLineas(12, 25, 40);
    }
    LimpiarLineas(12, 25, 40);


    setColor(CYAN);
    locate(40,12); cout<<"Apellido actual: "<<getapellido()<<endl;
    locate(40,13); cout<<"ENTER para modificar o tecla cualquiera para saltar..."<<endl;
    setColor(WHITE);

    key=getkey();
    if (key==KEY_ENTER){
        char temp_apellido[40];
        while(true){
            setColor(YELLOW);
            locate(40, 15); cout<<"Ingrese nuevo apellido: ";
            setColor(WHITE);
            cargarCadena(temp_apellido, 39);
            if(!validarPalabra(temp_apellido)){
                LimpiarLineas(15, 20, 40);
                continue;
            }break;
        }
        setapellido(temp_apellido);
        setColor(GREEN);
        locate(40, 17);
        cout<<">> Apellido actualizado."<<endl;
        anykey();
        LimpiarLineas(12, 25, 40);
    }
    LimpiarLineas(12, 25, 40);

    setColor(CYAN);
    locate(40,12); cout<<"DNI actual: "<<getdni()<<endl;
    locate(40,13); cout<<"ENTER para modificar o tecla cualquiera para saltar..."<<endl;
    setColor(WHITE);

    key=getkey();
    if(key==KEY_ENTER){
        long long temp_dni;
        while(true){
            setColor(YELLOW);
            locate(40, 15); cout<<"Ingrese nuevo DNI (7-11 digitos): ";
            setColor(WHITE);
            cin>>temp_dni;
            int longitud=to_string(temp_dni).length();
            if(validar_numero() and (longitud>=7 and longitud<=11)) break;
            else {LimpiarLineas(15, 20, 40); continue; }
        }
        setdni(temp_dni);
        setColor(GREEN);
        locate(40, 17);
        cout<<">> DNI actualizado."<<endl;
        anykey();
        LimpiarLineas(12, 25, 40);
    }
    LimpiarLineas(12, 25, 40);

    setColor(CYAN);
    locate(40,12); cout<<"Telefono actual: "<<gettelefono()<<endl;
    locate(40,13); cout<<"ENTER para modificar o tecla cualquiera para saltar..."<<endl;
    setColor(WHITE);

    key=getkey();
    if(key==KEY_ENTER){
        long long temp_tel;
        while(true){
            setColor(YELLOW);
            locate(40, 15); cout<<"Ingrese nuevo N° de contacto (10 digitos): ";
            setColor(WHITE);
            cin>>temp_tel;
            int longitud=to_string(temp_tel).length();
            if (validar_numero() and longitud==10) break;
            else {LimpiarLineas(15, 20, 40); continue; }
        }
        settelefono(temp_tel);
        setColor(GREEN);
        locate(40, 17);
        cout<<">> Telefono actualizado."<<endl;
        anykey();
        LimpiarLineas(12, 25, 40);
    }
    LimpiarLineas(12, 25, 40);


    setColor(CYAN);
    locate(40,12); cout<<"Email actual: "<<getemail()<<endl;
    locate(40,13); cout<<"ENTER para modificar o tecla cualquiera para saltar..."<<endl;
    setColor(WHITE);

    key=getkey();
    if(key==KEY_ENTER){
        char temp_email[100];
        setColor(YELLOW);
        locate(40, 15); cout<<"Ingrese su nuevo email: ";
        setColor(WHITE);
        cargarCadena(temp_email, 99);
        setemail(temp_email);
        setColor(GREEN);
        locate(40, 17);
        cout<<">> Email actualizado."<<endl;
        anykey();
        LimpiarLineas(12, 25, 40);
    }
    LimpiarLineas(12, 25, 40);


    setColor(CYAN);
    locate(40,12); cout<<"Genero actual: "<<getgenerotexto()<<endl;
    locate(40,13); cout<<"ENTER para modificar o tecla cualquiera para saltar..."<<endl;
    setColor(WHITE);

    key=getkey();
    if(key==KEY_ENTER) {
        int temp_gen;
        while(true){
            setColor(YELLOW);
            locate(40, 15); cout<<"Ingrese su nuevo genero(1=masc, 2=fem, 3=no binario): ";
            setColor(WHITE);
            cin>>temp_gen;
            if(validar_numero() and (temp_gen==1 or temp_gen==2 or temp_gen==3)) break;
            else {LimpiarLineas(15, 20, 40); continue;}
        }
        setgenero(temp_gen);
        setColor(GREEN);
        locate(40, 17);
        cout<<">> Genero actualizado."<<endl;
        anykey();
        LimpiarLineas(12, 25, 40);
    }
    LimpiarLineas(12, 25, 40);

    setColor(CYAN);
    locate(40,12); cout<<"Nacionalidad actual: "<<getnacionalidad()<<endl;
    locate(40,13); cout<<"ENTER para modificar o tecla cualquiera para saltar..."<<endl;
    setColor(WHITE);

    key=getkey();
    if(key==KEY_ENTER){
        char temp_nac[40];
        while(true){
            setColor(YELLOW);
            locate(40, 15); cout<<"Ingrese su nueva nacionalidad: ";
            setColor(WHITE);
            cargarCadena(temp_nac, 39);
            if(validarPalabra(temp_nac)) break;
            else {LimpiarLineas(15, 20, 40); continue;}
        }
        setnacionalidad(temp_nac);
        setColor(GREEN);
        locate(40, 17);
        cout<<">> Nacionalidad actualizada."<<endl;
        anykey();
        LimpiarLineas(12, 25, 40);
    }
    LimpiarLineas(12, 25, 40);


    setColor(CYAN);
    locate(40,12); cout<<"Fecha de Nacimiento actual: "; getfecha_Nacimiento().mostrarEn(70, 12);
    locate(40,13); cout<<"ENTER para modificar o tecla cualquiera para saltar..."<<endl;
    setColor(WHITE);

    key=getkey();
    if(key==KEY_ENTER){
        Fecha temp_fecha;
        setColor(YELLOW);
        locate(40, 15); cout<<"--- Cargando nueva Fecha de Nacimiento ---"<<endl;
        temp_fecha.cargarEn(42, 17);
        setfecha_Nacimiento(temp_fecha);
        setColor(GREEN);
        locate(40, 22);
        cout<<">> Fecha de Nacimiento actualizada."<<endl;
    }
    anykey();
    LimpiarLineas(11, 25, 40);

    setColor(CYAN);
    locate(40,12); cout<<"Domicilio actual: "<<endl; getdomicilio().Mostrar(40, 15);
    locate(40,13); cout<<"ENTER para modificar o tecla cualquiera para saltar..."<<endl;
    setColor(WHITE);

    key=getkey();
    if(key==KEY_ENTER){
        LimpiarLineas(12, 25, 40);
        Domicilio temp_dom;
        setColor(YELLOW);
        locate(40, 10); cout<<"--- Cargando nuevo Domicilio ---"<<endl;
        temp_dom.CargarEn(40, 12);
        setdomicilio(temp_dom);
        locate(40, 22);
        cout<<">> Domicilio actualizado."<<endl;
    }
    anykey();
    LimpiarLineas(12, 25, 40);

    locate(40, 13);
    setColor(GREEN);
    cout<<"--- FIN DE LA MODIFICACION ---"<<endl;
    locate(40, 14);
    cout<<"Presione cualquier tecla para continuar..."<<endl;
    anykey();
    cls();
}

void Persona::mostrar(int lineaBase){
    setColor(YELLOW);
    locate(40, lineaBase); cout << "Nombre: " << nombre;
    locate(40, lineaBase+1); cout << "Apellido: " << apellido;
    locate(40, lineaBase+2); cout << "N° de DNI: " << dni;
    locate(40, lineaBase+3); cout << "N° de contacto: " << telefono;
    locate(40, lineaBase+4); cout << "Email: " << email;
    locate(40, lineaBase+5); cout << "Genero: " << getgenerotexto();
    locate(40, lineaBase+6); cout << "Nacionalidad: " << nacionalidad;

    setColor(GREEN);
    locate(40, lineaBase+8); cout << "------------ FECHA DE NACIMIENTO -------------";
    setColor(WHITE);
    fecha_Nacimiento.mostrarEn(40, lineaBase+9);

    setColor(GREEN);
    locate(40, lineaBase+10); cout << "------------------ DOMICILIO -----------------";
    setColor(WHITE);
    domicilio.Mostrar(40,lineaBase+11);
}

