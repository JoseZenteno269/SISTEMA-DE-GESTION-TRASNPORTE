#include<iostream>
#include "USUARIOS.h"
#include<cstring>
#include "funciones.h"
#include "TIEMPO_ACTUAL.h"
#include "rlutil.h"

using namespace rlutil;
using namespace std;

void Usuarios::setidUsuario(int idu){idUsuario=idu; }
void Usuarios::setcontrasena(const char *c){strcpy(contrasena, c); }
void Usuarios::setingreso(Fechas i){ingreso=i; }
void Usuarios::setnivel(int n){nivel=n; }
void Usuarios::setestado(bool e){estado=e; }

int Usuarios::getidUsuario(){return idUsuario; }
const char *Usuarios::getcontrasena(){return contrasena; }
Fechas Usuarios::getingreso(){return ingreso; }
int Usuarios::getnivel(){return nivel; }
bool Usuarios::getestado(){return estado; }

void Usuarios::cargar(int idu){
    system("cls");

    setColor(GREEN);
    locate(40,3); cout << "----------------------------------------------";
    locate(40,4); cout << "            CARGA DE NUEVO USUARIO            ";
    locate(40,5); cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40,6);
    cout << "ID de usuario asignado: " << (idUsuario = idu);

    Personas::cargar();

    Tiempo_Actual tiempo;
    Fechas fecha(tiempo.getDia(), tiempo.getMes(), tiempo.getAnio());
    setingreso(fecha);

    setColor(CYAN);
    locate(40,9); cout << "Fecha de ingreso: ";
    setColor(WHITE);

    fecha.mostrarEn(40,10);

    while(true){
        setColor(CYAN);
        locate(40,12); cout << "Nivel de usuario (1=Admin,2=Vendedor): ";
        setColor(WHITE);
        locate(40,13); cin >> nivel;

        if(validar_numero() && (nivel==1 || nivel==2)){
            LimpiarLineas(12,16,40);
            break;
        }
        setColor(RED);
        locate(40,15); cout << "Valor inválido.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(12,16,40);
    }

    setColor(CYAN);
    locate(40,12); cout << "Crear contraseña: ";
    setColor(WHITE);
    locate(40,13); cargarCadena(contrasena,29);

    estado = true;
    system("cls");
}

void Usuarios::mostrar() {

    setColor(YELLOW);
    locate(40, 3);  cout << "----------------------------------------------";
    locate(40, 4);  cout << "            INFORMACION DEL USUARIO           ";
    locate(40, 5);  cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40, 7);  cout << "ID de usuario:         " << idUsuario;
    locate(40, 8);  cout << "Nombre:                " << nombre;
    locate(40, 9);  cout << "Apellido:              " << apellido;
    locate(40, 10); cout << "DNI:                   " << dni;
    locate(40, 11); cout << "Telefono:              " << telefono;
    locate(40, 12); cout << "Email:                 " << email;
    locate(40, 13); cout << "Genero:                " << genero;
    locate(40, 14); cout << "Nacionalidad:          " << nacionalidad;

    setColor(YELLOW);
    locate(40, 16); cout << "------------ FECHA DE NACIMIENTO ------------";
    setColor(WHITE);
    locate(40, 17); fecha_Nacimiento.mostrar();

    setColor(YELLOW);
    locate(40, 19); cout << "------------------ DOMICILIO -----------------";
    setColor(WHITE);
    domicilio.Mostrar();

    setColor(YELLOW);
    locate(40, 27); cout << "----------------------------------------------";
    setColor(WHITE);
    anykey();
    LimpiarLineas(7,14,63);
    LimpiarLineas(17,18,40);
    LimpiarLineas(20,26,53);
}

