#include<iostream>
#include "ARCHIVO_MICROS.h"
#include<cstring>
#include "rlutil.h"
using namespace rlutil;

using namespace std;

Archivo_micros::Archivo_micros(const char *a){
    strcpy(archivo, a);
    FILE *p=fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p==nullptr){               // si no existe, lo creo vacío
        p=fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_micros::contarRegistros(){
    FILE *p=fopen(archivo,"rb");
    if (p==nullptr){
        cout<<"no existe el archivo"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Micros);
}
int Archivo_micros::buscarRegsitro(int idm){
    Micros micro;
    int contreg=contarRegistros();
    for (int i=0;i<contreg;i++){
        micro=leerRegistros(i);
        if(micro.getidMicro()==idm){
            return i;
        }
    }
    return -2;
}

Micros Archivo_micros::leerRegistros(int pos){
    FILE *p=fopen(archivo,"rb");
    Micros micro;
    if(p==nullptr){
        micro.setidMicro(-3);
        return micro;
    }
    fseek(p,pos*sizeof micro,0);
    micro.setidMicro(-4);
    fread(&micro,sizeof micro,1,p);
    fclose(p);
    return micro;

}
bool Archivo_micros::grabarRegistro(Micros micro){
    FILE *p=fopen(archivo,"ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&micro,sizeof micro,1,p);
    fclose(p);
    return escribo;
}
bool Archivo_micros::modificarRegistro(Micros micro, int pos){
    FILE *p=fopen(archivo,"rb+");
    if(p==nullptr){
        return false;
    }
    fseek(p,pos*sizeof micro,0 );
    bool escribo=fwrite(&micro,sizeof micro,1,p);
    fclose (p);
    return escribo;
}

void Archivo_micros::listar(){
    Micros micro;
    int contreg=contarRegistros();
    for(int i=0;i<contreg;i++){
        micro=leerRegistros(i);
        if(micro.getdisponible()){
            micro.mostrar();
            cout<<endl;
        }
    }
}
void Archivo_micros::listartabla(){
    system("cls");

    Micros micro;
    int contreg = contarRegistros();

    if(contreg <= 0){
        setColor(RED);
        locate(40, 10); cout << "NO HAY MICROS REGISTRADOS";
        setColor(WHITE);
        system("pause");
        system("cls");
        return;
    }

    setColor(YELLOW);
    locate(20, 3);  cout << "-------------------------------------------------------------------------------";
    locate(20, 4);  cout << "                             LISTADO DE MICROS                                  ";
    locate(20, 5);  cout << "-------------------------------------------------------------------------------";
    setColor(WHITE);


    locate(20, 7); cout << "ID";
    locate(27, 7); cout << "MARCA";
    locate(43, 7); cout << "TIPO";
    locate(59, 7); cout << "CAP";
    locate(65, 7); cout << "BUTACA";
    locate(78, 7); cout << "PATENTE";

    locate(20, 8);
    cout << "-------------------------------------------------------------------------------";

    int fila = 9;

    for(int i = 0; i < contreg; i++){
        micro = leerRegistros(i);

        if(micro.getdisponible()){

            locate(20, fila);
            cout << micro.getidMicro();

            locate(27, fila);
            cout << micro.getmarca();

            locate(43, fila);
            cout << micro.gettipo();

            locate(59, fila);
            cout << micro.getcapacidad();

            locate(65, fila);
            cout << micro.gettipoButaca();

            locate(78, fila);
            cout << micro.getpatente();

            fila++;
        }
    }

    setColor(YELLOW);
    locate(20, fila + 2);
    cout << "-------------------------------------------------------------------------------";
    setColor(WHITE);

    anykey();
}
