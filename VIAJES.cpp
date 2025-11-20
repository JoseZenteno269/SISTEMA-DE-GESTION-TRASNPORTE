#include<iostream>
#include "funciones.h"
#include "VIAJES.h"
#include<cstring>
#include "ARCHIVO_MICROS.h"
#include "MICROS.h"
#include "ARCHIVO_CHOFERES.h"
#include "CHOFERES.h"
#include "ARCHIVO_DESTINOS.h"
#include "DESTINOS.h"
#include "TIEMPO_ACTUAL.h"
#include "funciones.h"
#include "ARCHIVO_VIAJES.h"
#include "rlutil.h"

using namespace rlutil;
using namespace std;

void Viaje::setidViaje(int idv){idViaje=idv; }
void Viaje::setidMicro(int idm){idMicro=idm; }
void Viaje::setidChofer(int idc){idChofer=idc; }
void Viaje::setidDestino(int idd){idDestino=idd; }
void Viaje::setfecha_Inicio_Viaje(Fecha fiv){fecha_Inicio_Viaje=fiv; }
void Viaje::setfecha_Fin_Viaje(Fecha ffv){fecha_Fin_Viaje=ffv; }
void Viaje::sethora_Inicio_Viaje(Hora hiv){hora_Inicio_Viaje=hiv; }
void Viaje::sethora_Fin_Viaje(Hora hfv){hora_Fin_Viaje=hfv; }
void Viaje::setrealizado(bool r){realizado=r; }

int Viaje::getidViaje(){return idViaje; }
int Viaje::getidMicro(){return idMicro; }
int Viaje::getidChofer(){return idChofer; }
int Viaje::getidDestino(){return idDestino; }
Fecha Viaje::getfecha_Inicio_Viaje(){return fecha_Inicio_Viaje; }
Fecha Viaje::getfecha_Fin_Viaje(){return fecha_Fin_Viaje; }
Hora Viaje::gethora_Inicio_Viaje(){return hora_Inicio_Viaje; }
Hora Viaje::gethora_Fin_Viaje(){return hora_Fin_Viaje; }
bool Viaje::getrealizado(){return realizado; }

void Viaje::cargar(int idv){
    Archivo_micro archivomicro;
    Archivo_chofer archivochofer;
    Archivo_destino archivodestino;
    Archivo_viaje archivoviaje;
    Tiempo_Actual actual;
    Fecha presente(actual.getDia(), actual.getMes(), actual.getAnio());

    cls();
    setColor(GREEN);
    locate(40,3); cout<<"----------------------------------------------";
    locate(40,4); cout<<"              CARGA DE NUEVO VIAJE           ";
    locate(40,5); cout<<"----------------------------------------------";
    setColor(WHITE);
    locate(40,6); cout<<"ID de viaje asignado: "<<(idViaje = idv);

    Micro micro;
    while(true){
        LimpiarLineas(8,16,40);
        setColor(CYAN);
        locate(40,8); cout << "Ingrese ID de micro (0 para salir): ";
        setColor(WHITE);
        locate(40,9); cin >> idMicro;

        if(!validar_numero()) continue;
        if(idMicro == 0){ setColor(RED); LimpiarLineas(8,16,40); locate(40,8); cout << "Operación cancelada"; setColor(WHITE); anykey(); return; }

        int pos = archivomicro.buscarRegsitro(idMicro);
        if(pos<0){
            setColor(RED);
            LimpiarLineas(8,16,40);
            locate(40,8);
            cout << "ERROR, micro no registrado";
            setColor(WHITE);
            anykey();
            continue;
        }

        micro = archivomicro.leerRegistros(pos);
        break;

    }

    Destino destino;
    while(true){
        LimpiarLineas(8,16,40);
        setColor(CYAN);
        locate(40,8); cout << "Ingrese ID de destino (0 para salir): ";
        setColor(WHITE);
        locate(40,9); cin >> idDestino;

        if(!validar_numero()) continue;
        if(idDestino == 0){ setColor(RED); locate(40,8); cout << "Operación cancelada"; setColor(WHITE); anykey(); return; }

        int pos=archivodestino.buscarRegistros(idDestino);
        if(pos<0){
            setColor(RED);
            LimpiarLineas(8,16,40);
            locate(40,8);
            cout << "ERROR, destino no registrado";
            setColor(WHITE);
            anykey();
            continue;
        }

        destino = archivodestino.leerRegistros(pos);
        break;

    }

    Chofer chofer;
    while(true){
        LimpiarLineas(8,16,40);
        setColor(CYAN);
        locate(40,8); cout << "Ingrese ID de chofer (0 para salir): ";
        setColor(WHITE);
        locate(40,9); cin >> idChofer;
        if(!validar_numero()) continue;
        if(idChofer == 0){ setColor(RED); LimpiarLineas(8,16,40); locate(40,8); cout << "Operación cancelada"; setColor(WHITE); anykey(); return; }

        int pos = archivochofer.buscarRegistro(idChofer);
        if(pos < 0){
            setColor(RED);
            LimpiarLineas(8,16,40);
            locate(40,8);
            cout << "ERROR, chofer no registrado";
            setColor(WHITE);
            anykey();
            continue;
        }

        chofer = archivochofer.leerRegistros(pos);
        break;
    }

    while(true){
        LimpiarLineas(8,16,40);
        setColor(CYAN);
        locate(40,8); cout << "Ingrese fecha de inicio (dd/mm/yyyy): ";
        setColor(WHITE);
        locate(40,9); fecha_Inicio_Viaje.cargar();

        if(esFechaPosterior(fecha_Inicio_Viaje, presente)) break;
        setColor(RED); LimpiarLineas(8,16,40); locate(40,8); cout << "ERROR: no puede ser anterior a la fecha actual"; setColor(WHITE); anykey();

    }

    LimpiarLineas(8,15,40);
    setColor(CYAN);
    locate(40,8); cout << "Ingrese hora de inicio (hh:mm): ";
    setColor(WHITE);
    locate(40,9); hora_Inicio_Viaje.cargar();

    fecha_y_hora_fin(destino, archivodestino, fecha_Fin_Viaje, hora_Fin_Viaje, fecha_Inicio_Viaje, hora_Inicio_Viaje,idDestino);

    realizado = true;
    LimpiarLineas(8,18,40);
    setColor(GREEN);
    locate(40,8); cout << "Viaje cargado correctamente";
    setColor(WHITE);
    anykey();
    cls();

}

void Viaje::mostrar(){

    setColor(YELLOW);
    locate(40, 3);  cout << "----------------------------------------------";
    locate(40, 4);  cout << "             INFORMACION DEL VIAJE            ";
    locate(40, 5);  cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40, 7);  cout << "==============================================";
    locate(40, 8);  cout << "ID de Viaje:               " << idViaje;


    Micro micro;
    Archivo_micro archivomicro;
    int pos1 = archivomicro.buscarRegsitro(idMicro);
    if(pos1 >= 0){
        micro = archivomicro.leerRegistros(pos1);

        locate(40, 9);  cout << "ID de Micro:               " << idMicro;
        locate(40, 10); cout << "Marca/Modelo:              " << micro.getmarca();
        locate(40, 11); cout << "Patente:                   " << micro.getpatente();
    }
    else {
        locate(40, 9); cout << "Error al cargar datos del micro";
    }


    locate(40, 13); cout << "ID de chofer:              " << idChofer;


    Destino destino;
    Archivo_destino archivodestino;
    int pos2 = archivodestino.buscarRegistros(idDestino);

    if(pos2 >= 0){
        destino = archivodestino.leerRegistros(pos2);

        locate(40, 15); cout << "Destino:                   " << destino.getnombre_destino();
        locate(40, 16); cout << "Provincia:                 " << destino.getnombre_provincia();
    }
    else {
        locate(40, 15); cout << "Destino no encontrado";
    }


    locate(40, 18); cout << "Fecha de inicio:           ";
    fecha_Inicio_Viaje.mostrarEn(18, 70);

    locate(40, 19); cout << "Fecha de fin:              ";
    fecha_Fin_Viaje.mostrarEn(19, 70);

    locate(40, 20); cout << "Hora de inicio:            ";
    hora_Inicio_Viaje.mostrarEn(20, 70);

    locate(40, 21); cout << "Hora de fin:               ";
    hora_Fin_Viaje.mostrarEn(21, 70);

    locate(40, 23); cout << "==============================================";
}

void Viaje::listartabla() {
    cls();
    Archivo_viaje Arch_Via;
    Archivo_micro Arch_Mic;
    Archivo_destino Arch_Dest;
    Archivo_Precio Arch_Precio;

    int contViajes = Arch_Via.contarRegistros();
    if (contViajes <= 0) {
        setColor(RED);
        locate(40, 10); cout << "NO HAY VIAJES REGISTRADOS";
        setColor(WHITE);
        anykey();
        cls();
        return;
    }

    Precio precioBase = Arch_Precio.leerRegistros();

    setColor(YELLOW);
    locate(5, 3);  cout << "----------------------------------------------------------------------------------------------------------";
    locate(5, 4);  cout << "                                             LISTADO DE VIAJES                                            ";
    locate(5, 5);  cout << "----------------------------------------------------------------------------------------------------------";
    setColor(WHITE);

    locate(5, 7);
    cout << "ID VIAJE";
    locate(15, 7); cout << "ID MICRO";
    locate(25, 7); cout << "PROVINCIA";
    locate(40, 7); cout << "DESTINO";
    locate(55, 7); cout << "DURACION";
    locate(65, 7); cout << "DISTANCIA";
    locate(77, 7); cout << "PRECIO";
    locate(90, 7); cout << "FECHA";
    locate(100, 7); cout << "HORA INICIO";

    locate(5, 8); cout << "----------------------------------------------------------------------------------------------------------";

    int fila = 9;
    Viaje viaje;

    for (int i = 0; i < contViajes; i++) {
        viaje = Arch_Via.leerRegistros(i);

        int idMicro = viaje.getidMicro();
        string provincia = "-";
        string nombreDestino = "-";
        float distancia = 0;
        Hora duracion;

        int posDest = Arch_Dest.buscarRegistros(viaje.getidDestino());
        if (posDest >= 0) {
            Destino destino = Arch_Dest.leerRegistros(posDest);
            nombreDestino = destino.getnombre_destino();
            provincia = destino.getnombre_provincia();
            distancia = destino.getdistanciaKm();
            duracion = destino.getduracion();
        }

        float butaca=plusxbutaca(viaje);
        float precioTotal=distancia*precioBase.getPrecio()+butaca;

        locate(5, fila); cout << viaje.getidViaje();
        locate(15, fila); cout << idMicro;
        locate(25, fila); cout << provincia;
        locate(40, fila); cout << nombreDestino;
        locate(55, fila); duracion.mostrarEn(fila, 55);
        locate(65, fila); cout << distancia;
        locate(75, fila); cout << precioTotal;
        locate(85, fila); viaje.getfecha_Inicio_Viaje().mostrarEn(90, fila);
        locate(100, fila); viaje.gethora_Inicio_Viaje().mostrarEn(105, fila);

        fila++;
    }

    setColor(YELLOW);
    locate(5, fila); cout << "--------------------------------------------------------------------------------------------------------";
    setColor(WHITE);

    anykey();
    cls();
}
