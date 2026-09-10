#ifndef PASAJEROS_H_INCLUDED
#define PASAJEROS_H_INCLUDED
#include "PERSONA.h"

class Pasajero:public Persona{
private:
    int numero_pasaje;
    bool habilitado;
public:
    void setNumero_pasaje(int);
    void setHabilitado(bool);

    int getNumero_pasaje();
    bool getHabilitado();

    void cargar(int);
    void mostrar();
};



#endif // PASAJEROS_H_INCLUDED
