///PERSONA.H
int calcularEdad();

///PERSOANA.CPP
int Persona::calcularEdad(){
    Tiempo_Actual hoy;
    int edad = hoy.getAnio() - fecha_Nacimiento.getAnio();
    if(hoy.getMes() < fecha_Nacimiento.getMes() ||
       (hoy.getMes() == fecha_Nacimiento.getMes() && hoy.getDia() < fecha_Nacimiento.getDia())){
        edad--;
    }
    return edad;
}

///FUNCIONES.H
///LISTADOS
//CHOFERES
void Choferes_ordenados_apellido();
void Choferes_ordenados_edad();

//CLIENTES
void Pasajeros_ordenados_apellido();
void Pasajeros_ordenados_edad();

//UNIDADES
void Micros_ordenados_Fabricante();
void Micros_ordenados_Carroceria();
void Micros_ordenados_Asientos();

//VENTAS
void Ventas_ordenados_Precio();
void Ventas_ordenados_destinos();

//DESTINOS
void Destinos_ordenados_Provincia();
void Destinos_ordenados_Kilometros();

///FUNCIONES.CPP
///LISTADOS
//CHOFERES
void Choferes_ordenados_apellido(){
    cls();
    Archivo_chofer arch;
    int n = arch.contarRegistros();
    if(n <= 0){ anykey(); return; }

    Chofer *v = new Chofer[n];
    for(int i=0;i<n;i++) v[i]=arch.leerRegistros(i);

   for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(strcasecmp(v[j].getApellido(), v[j+1].getApellido()) > 0){
                swap(v[j], v[j+1]);
            }
        }
    }
    setColor(GREEN); locate(40,1); cout<<"-------------------------------\n";
    setColor(WHITE); locate(40,2); cout<<"CHOFERES ORDENADOS POR APELLIDO\n";
    setColor(GREEN); locate(40,3); cout<<"-------------------------------\n";

    for(int i=0;i<n;i++){
        setColor(WHITE); locate(40,5+i); cout<<"Apellido: ";
        setColor(CYAN); cout<<v[i].getApellido();
        setColor(WHITE); cout<<"  Nombre: ";
        setColor(CYAN); cout<<v[i].getNombre();
    }

    delete[] v;
    setColor(WHITE);
    anykey();
}
void Choferes_ordenados_edad(){
    cls();
    Archivo_chofer arch;
    int n = arch.contarRegistros();
    if(n <= 0){ anykey(); return; }

    Chofer *v = new Chofer[n];
    for(int i=0;i<n;i++) v[i] = arch.leerRegistros(i);

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(v[j].calcularEdad() > v[j+1].calcularEdad()){
                Chofer temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }

    setColor(GREEN); locate(40,1); cout<<"---------------------------\n";
    setColor(WHITE); locate(40,2); cout<<"CHOFERES ORDENADOS POR EDAD\n";
    setColor(GREEN); locate(40,3); cout<<"---------------------------\n";

    for(int i=0;i<n;i++){
        setColor(WHITE); locate(40,5+i); cout<<"Edad: ";
        setColor(CYAN); cout<<v[i].calcularEdad();
        setColor(WHITE); cout<<"  Nombre: ";
        setColor(CYAN); cout<<v[i].getApellido()<<", "<<v[i].getNombre();
    }

    delete[] v;
    setColor(WHITE);
    anykey();
}

//CLIENTES
void Pasajeros_ordenados_apellido(){
    cls();
    Archivo_pasajero arch;
    int n = arch.contarRegistros();
    if(n<=0){ anykey(); return; }

    Pasajero *v = new Pasajero[n];
    for(int i=0;i<n;i++) v[i]=arch.leerRegistros(i);

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(strcasecmp(v[j].getApellido(), v[j+1].getApellido())>0)
                swap(v[j], v[j+1]);

    setColor(GREEN); locate(40,1); cout<<"---------------------------------\n";
    setColor(WHITE); locate(40,2); cout<<"PASAJEROS ORDENADOS POR APELLIDO\n";
    setColor(GREEN); locate(40,3); cout<<"---------------------------------\n";

    for(int i=0;i<n;i++){
        setColor(WHITE); locate(40,5+i); cout<<"Apellido: ";
        setColor(CYAN); cout<<v[i].getApellido();
        setColor(WHITE); cout<<"  Nombre: ";
        setColor(CYAN); cout<<v[i].getNombre();
    }

    delete[] v;
    setColor(WHITE);
    anykey();
}
void Pasajeros_ordenados_edad(){
    cls();
    Archivo_pasajero arch;
    int n = arch.contarRegistros();
    if(n<=0){ anykey(); return; }

    Pasajero *v = new Pasajero[n];
    for(int i=0;i<n;i++) v[i] = arch.leerRegistros(i);

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(v[j].calcularEdad() > v[j+1].calcularEdad()){
                Pasajero temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }

    setColor(GREEN); locate(40,1); cout<<"------------------------------\n";
    setColor(WHITE); locate(40,2); cout<<"PASAJEROS ORDENADOS POR EDAD\n";
    setColor(GREEN); locate(40,3); cout<<"------------------------------\n";

    for(int i=0;i<n;i++){
        setColor(WHITE); locate(40,5+i); cout<<"Edad: ";
        setColor(CYAN); cout<<v[i].calcularEdad();
        setColor(WHITE); cout<<"  Nombre: ";
        setColor(CYAN); cout<<v[i].getApellido()<<", "<<v[i].getNombre();
    }

    delete[] v;
    setColor(WHITE);
    anykey();
}

//UNIDADES
void Micros_ordenados_Fabricante(){
    cls();
    Archivo_micro arch;
    int n = arch.contarRegistros();
    if(n<=0){ anykey(); return; }

    Micro *v = new Micro[n];
    for(int i=0;i<n;i++) v[i]=arch.leerRegistros(i);

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(strcasecmp(v[j].getMarca(), v[j+1].getMarca())>0)
                swap(v[j], v[j+1]);

    setColor(GREEN); locate(40,1); cout<<"----------------------------------\n";
    setColor(WHITE); locate(40,2); cout<<"MICROS ORDENADOS POR FABRICANTE\n";
    setColor(GREEN); locate(40,3); cout<<"----------------------------------\n";

    for(int i=0;i<n;i++){
        setColor(WHITE); locate(40,5+i); cout<<"Fabricante: ";
        setColor(CYAN); cout<<v[i].getMarca();
    }

    delete[] v;
    setColor(WHITE);
    anykey();
}
void Micros_ordenados_Carroceria(){
    cls();
    Archivo_micro arch;
    int n = arch.contarRegistros();
    if(n<=0){ anykey(); return; }

    Micro *v = new Micro[n];
    for(int i=0;i<n;i++) v[i]=arch.leerRegistros(i);

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(strcasecmp(v[j].getTipo(), v[j+1].getTipo())>0)
                swap(v[j], v[j+1]);

    setColor(GREEN); locate(40,1); cout<<"----------------------------------\n";
    setColor(WHITE); locate(40,2); cout<<"MICROS ORDENADOS POR CARROCERIA\n";
    setColor(GREEN); locate(40,3); cout<<"----------------------------------\n";

    for(int i=0;i<n;i++){
        setColor(WHITE); locate(40,5+i); cout<<"Carroceria: ";
        setColor(CYAN); cout<<v[i].getTipo();
    }

    delete[] v;
    setColor(WHITE);
    anykey();
}
void Micros_ordenados_Asientos(){
    cls();
    Archivo_micro arch;
    int n = arch.contarRegistros();
    if(n <= 0){ anykey(); return; }

    Micro *v = new Micro[n];
    for(int i=0; i<n; i++) v[i] = arch.leerRegistros(i);

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(v[j].getCapacidad() > v[j+1].getCapacidad()){
                Micro temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }

    setColor(GREEN); locate(40,1); cout<<"--------------------------------\n";
    setColor(WHITE); locate(40,2); cout<<"MICROS ORDENADOS POR ASIENTOS\n";
    setColor(GREEN); locate(40,3); cout<<"--------------------------------\n";

    for(int i=0; i<n; i++){
        setColor(WHITE); locate(40,5+i); cout<<"Asientos: ";
        setColor(CYAN); cout<<v[i].getCapacidad();
    }

    delete[] v;
    setColor(WHITE);
    anykey();
}

//VENTAS
void Ventas_ordenados_Precio(){
    cls();
    Archivo_pasaje arch;
    int n = arch.contarRegistros();
    if(n <= 0){ anykey(); return; }

    Pasaje *v = new Pasaje[n];
    for(int i=0; i<n; i++) v[i] = arch.leerRegistros(i);

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(v[j].getPrecio() > v[j+1].getPrecio()){
                Pasaje temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }

    setColor(GREEN); locate(40,1); cout<<"----------------------------\n";
    setColor(WHITE); locate(40,2); cout<<"VENTAS ORDENADAS POR PRECIO\n";
    setColor(GREEN); locate(40,3); cout<<"----------------------------\n";

    for(int i=0; i<n; i++){
        setColor(WHITE); locate(40,5+i); cout<<"Precio: ";
        setColor(CYAN); cout<<v[i].getPrecio() << endl;
    }

    delete[] v;
    setColor(WHITE);
    anykey();
}
void Ventas_ordenados_destinos(){
    cls();
    Archivo_pasaje archPasaje;
    Archivo_viaje archViaje;
    Archivo_destino archDestino;

    int n = archPasaje.contarRegistros();
    if(n <= 0){ anykey(); return; }

    Pasaje *v = new Pasaje[n];
    for(int i=0; i<n; i++) v[i] = archPasaje.leerRegistros(i);

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            int idDest_j = archViaje.leerRegistros(v[j].getIdviaje()).getIdDestino();
            int idDest_j1 = archViaje.leerRegistros(v[j+1].getIdviaje()).getIdDestino();

            char nombre_j[40], nombre_j1[40];
            strcpy(nombre_j, archDestino.leerRegistros(idDest_j).getNombre_destino());
            strcpy(nombre_j1, archDestino.leerRegistros(idDest_j1).getNombre_destino());

            if(strcasecmp(nombre_j, nombre_j1) > 0){
                swap(v[j], v[j+1]);
            }
        }
    }

    setColor(GREEN); locate(40,1); cout<<"-------------------------------\n";
    setColor(WHITE); locate(40,2); cout<<"VENTAS ORDENADAS POR DESTINO\n";
    setColor(GREEN); locate(40,3); cout<<"-------------------------------\n";

    for(int i=0; i<n; i++){
        int idDest = archViaje.leerRegistros(v[i].getIdviaje()).getIdDestino();
        Destino dest = archDestino.leerRegistros(idDest);
        setColor(WHITE); locate(40,5+i); cout<<"Destino: ";
        setColor(CYAN); cout<<dest.getNombre_destino();
    }

    delete[] v;
    setColor(WHITE);
    anykey();
}

//DESTINOS
void Destinos_ordenados_Provincia(){
    cls();
    Archivo_destino arch;
    int n = arch.contarRegistros();
    if(n<=0){ anykey(); return; }

    Destino *v = new Destino[n];
    for(int i=0;i<n;i++) v[i]=arch.leerRegistros(i);

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(strcasecmp(v[j].getNombre_provincia(), v[j+1].getNombre_provincia())>0)
                swap(v[j], v[j+1]);

    setColor(GREEN); locate(40,1); cout<<"----------------------------------\n";
    setColor(WHITE); locate(40,2); cout<<"DESTINOS ORDENADOS POR PROVINCIA\n";
    setColor(GREEN); locate(40,3); cout<<"----------------------------------\n";

    for(int i=0;i<n;i++){
        setColor(WHITE); locate(40,5+i); cout<<"Provincia: ";
        setColor(CYAN); cout<<v[i].getNombre_provincia();
    }

    delete[] v;
    setColor(WHITE);
    anykey();
}
void Destinos_ordenados_Kilometros(){
    cls();
    Archivo_destino arch;
    int n = arch.contarRegistros();
    if(n <= 0){ anykey(); return; }

    Destino *v = new Destino[n];
    for(int i=0; i<n; i++) v[i] = arch.leerRegistros(i);

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(v[j].getDistanciaKm() > v[j+1].getDistanciaKm()){
                Destino temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }

    setColor(GREEN); locate(40,1); cout<<"----------------------------------\n";
    setColor(WHITE); locate(40,2); cout<<"DESTINOS ORDENADOS POR KILOMETROS\n";
    setColor(GREEN); locate(40,3); cout<<"----------------------------------\n";

    for(int i=0; i<n; i++){
        setColor(WHITE); locate(40,5+i); cout<<"Km: ";
        setColor(CYAN); cout<<v[i].getDistanciaKm();
    }

    delete[] v;
    setColor(WHITE);
    anykey();
}
