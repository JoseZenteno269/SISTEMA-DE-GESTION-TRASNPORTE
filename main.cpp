#include <iostream>
#include "rlutil.h"
#include <windows.h>
#include "funciones.h"
#include <ctime>
#include "PERSONA.h"
#include "PASAJEROS.h"
#include "ARCHIVO_PASAJEROS.h"

using namespace std;
using namespace rlutil;

int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    //HWND console = GetConsoleWindow();
    //ShowWindow(console, SW_MAXIMIZE);
    //setBackgroundColor(BLUE);

    MENU();
    //inicio_de_sesion();

    cout<<endl<<endl;

    system("pause");

    return 0;
}

