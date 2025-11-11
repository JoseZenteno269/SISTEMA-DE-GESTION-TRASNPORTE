#include<iostream>
#include<conio.h>
#include"rlutil.h"
#include<windows.h>
#include"funciones.h"
#include<ctime>
#include<iomanip>
#include "TIEMPO_ACTUAL.h"
#include "FECHAS.h"

using namespace std;
using namespace rlutil;

int main(){
    cout<<fixed<<setprecision(2);
    srand(time(NULL));
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    //HWND console = GetConsoleWindow();
    //ShowWindow(console, SW_MAXIMIZE);
    //setBackgroundColor(BLUE);

<<<<<<< HEAD
    //MENU();
    inicio_de_sesion();
=======
    ocultarCursor();

    MENU();
    //inicio_de_sesion();
>>>>>>> a802f24 (AL DIA(creo))

    cout<<endl<<endl;

    system("pause");

    return 0;
}

