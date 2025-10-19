#include "TIEMPO_ACTUAL.h"
#include <ctime>

Tiempo_Actual::Tiempo_Actual() {
    time_t t=time(nullptr);
    tm* ahora=localtime(&t);

    dia=ahora->tm_mday;
    mes=ahora->tm_mon+1;
    anio=ahora->tm_year+1900;
}

int Tiempo_Actual::getDia() {
    return dia; }

int Tiempo_Actual::getMes() {
    return mes; }

int Tiempo_Actual::getAnio() {
    return anio; }
