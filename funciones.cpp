#include<iostream>
#include<iomanip>
#include<cstring>
#include "funciones.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

bool existePatente(const char *patente, int idMicroAExcluir) {
    Archivo_micro archivo;
    Micro micro;
    int cantidadRegistros = archivo.contarRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        micro = archivo.leerRegistros(i);
        if (strcmp(micro.getPatente(), patente) == 0 && micro.getIdMicro() != idMicroAExcluir) {
            return true;
        }
    }
    return false;
}

void LimpiarLineas(int desdeLinea,int hastaLinea, int columna){
    for(int y=desdeLinea; y<=hastaLinea; y++){
    locate(columna,y); cout << "                                                                                            ";
    }
}

float plusxbutaca(Viaje viaje){
    Archivo_micro archivoMicro;
    Archivo_Precio precios;
    Micro micro;
    Precio valorbutaca;

    valorbutaca=precios.leerRegistros();
    int N = archivoMicro.contarRegistros();

    for (int i = 0; i < N; i++) {
        micro = archivoMicro.leerRegistros(i);

        if (viaje.getIdMicro() == micro.getIdMicro()) {
            const char *tipo = micro.getTipoButaca();

            if (strcmp(tipo, "cama") == 0) return valorbutaca.getPreciobutaca_cama();
            if (strcmp(tipo, "semi-cama") == 0) return valorbutaca.getPreciobutaca_semicama();
            if (strcmp(tipo, "comun") == 0) return valorbutaca.getPreciobutaca_comun();
        }
    }

    return 0.0f;
}

bool esNumero(const string& variable) {
    for(char comparador : variable)
        if(!isdigit(comparador))return false;
    return !variable.empty();
}

bool validar_numero(){
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

     if(cin.peek()!='\n' and cin.peek()!=EOF){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

void fecha_y_hora_fin(Destino destino, Archivo_destino archivodestino, Fecha &fecha_Fin_Viaje, Hora &hora_Fin_Viaje, Fecha fecha_Inicio_Viaje, Hora hora_Inicio_Viaje, int idDestino){
    int pos=archivodestino.buscarRegistros(idDestino);
    destino=archivodestino.leerRegistros(pos);

    int dias=destino.getDuracion().getHora()/24;
    int horas=destino.getDuracion().getHora()%24;

    int nuevahora=hora_Inicio_Viaje.getHora()+horas;
    int nuevominuto=hora_Inicio_Viaje.getMinuto()+destino.getDuracion().getMinuto();

    if(nuevominuto>=60){
        nuevominuto-=60;
        nuevahora++;
    }

    if(nuevahora>=24){
        nuevahora-=24;
        dias++;
    }
    hora_Fin_Viaje.setHora(nuevahora);
    hora_Fin_Viaje.setMinuto(nuevominuto);

    int dias_mes=diasEnMes(fecha_Inicio_Viaje.getMes(), fecha_Inicio_Viaje.getAnio());

    if((fecha_Inicio_Viaje.getDia()+dias)>dias_mes){
        fecha_Fin_Viaje.setDia((fecha_Inicio_Viaje.getDia()+dias)-dias_mes);
        if((fecha_Inicio_Viaje.getMes()+1)==13){
            fecha_Fin_Viaje.setMes(1);
            fecha_Fin_Viaje.setAnio(fecha_Inicio_Viaje.getAnio()+1);
        }else{
            fecha_Fin_Viaje.setMes(fecha_Inicio_Viaje.getMes()+1);
            fecha_Fin_Viaje.setAnio(fecha_Inicio_Viaje.getAnio());
        }
    }else{
        fecha_Fin_Viaje.setDia(fecha_Inicio_Viaje.getDia()+dias);
        fecha_Fin_Viaje.setMes(fecha_Inicio_Viaje.getMes());
        fecha_Fin_Viaje.setAnio(fecha_Inicio_Viaje.getAnio());
    }
}

bool chequearSalidaESC(string mensaje){
    system("cls");

    setColor(RED);
    locate(44, 8);  cout << "--------------------------------------------";
    setColor(YELLOW);
    locate(44, 9);  cout << "               CONFIRMACION             ";
    setColor(RED);
    locate(44, 10); cout << "--------------------------------------------";
    setColor(RED);

    for(int i = 0; i < 9; i++){
        locate(43, 8 + i); cout << "|";
        locate(88, 8 + i); cout << "|";
    }

    setColor(WHITE);
    locate(44, 12);
    cout << mensaje;

    setColor(RED);
    locate(44, 14);
    cout << "Presione ESC para volver al menu";

    locate(44, 15);
    cout << "Presione cualquier otra tecla para continuar";
    locate(44, 16); cout << "--------------------------------------------";


    setColor(WHITE);

    int tecla = getkey();
    system("cls");

    if(tecla == KEY_ESCAPE) return true;

    return false;
}

//bool chequearSalidaESCsinRlutil(string mensaje){
//    cls();
//    cout<<mensaje<<endl<<endl;
//    cout<<"Presione ESC para cancelar y volver al menu"<<endl;
//    cout<<"Presione cualquier otra tecla para continuar..."<<endl;
//
//    int tecla=getkey();
//    cls();
//    if(tecla==KEY_ESCAPE)return true;
//
//    return false;
//}

bool esFechaPosterior(Fecha inicio ,Fecha presente){
    if(inicio.getAnio()>presente.getAnio())return true;
    if(inicio.getAnio()<presente.getAnio())return false;

    if(inicio.getMes()>presente.getMes())return true;
    if(inicio.getMes()<presente.getMes())return false;

    if(inicio.getDia()>=presente.getDia())return true;

    return false;
}

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

const char *funcion_provincias(int pos){
    const char *provincias[]={"buenos aires", "catamarca", "chaco", "chubut", "cordoba", "corrientes", "entre rios", "formosa", "jujuy",
    "la pampa", "la rioja", "mendoza", "misiones", "neuquen", "rio negro", "salta", "san juan", "san luis", "santa cruz", "santa fe",
    "santiago del estero", "tierra del fuego", "tucuman"};

    return provincias[pos];
}

const char* funcion_provincias(int pos, int formato) {

    const char *provincias_minus[] = {
        "buenos aires", "catamarca", "chaco", "chubut", "cordoba",
        "corrientes", "entre rios", "formosa", "jujuy", "la pampa",
        "la rioja", "mendoza", "misiones", "neuquen", "rio negro",
        "salta", "san juan", "san luis", "santa cruz", "santa fe",
        "santiago del estero", "tierra del fuego", "tucuman"
    };

    const char *provincias_mayus[] = {
        "BUENOS AIRES", "CATAMARCA", "CHACO", "CHUBUT", "CORDOBA",
        "CORRIENTES", "ENTRE RIOS", "FORMOSA", "JUJUY", "LA PAMPA",
        "LA RIOJA", "MENDOZA", "MISIONES", "NEUQUEN", "RIO NEGRO",
        "SALTA", "SAN JUAN", "SAN LUIS", "SANTA CRUZ", "SANTA FE",
        "SANTIAGO DEL ESTERO", "TIERRA DEL FUEGO", "TUCUMAN"
    };

    const char *provincias_titulo[] = {
        "Buenos Aires", "Catamarca", "Chaco", "Chubut", "Cordoba",
        "Corrientes", "Entre Rios", "Formosa", "Jujuy", "La Pampa",
        "La Rioja", "Mendoza", "Misiones", "Neuquen", "Rio Negro",
        "Salta", "San Juan", "San Luis", "Santa Cruz", "Santa Fe",
        "Santiago del Estero", "Tierra del Fuego", "Tucuman"
    };

    if (pos < 1 || pos > 23) return "";

    switch (formato) {
        case 1: return provincias_minus[pos - 1];
        case 2: return provincias_mayus[pos - 1];
        case 3: return provincias_titulo[pos - 1];
    }
    return "";
}

bool validarPatente(const char *patente){
    if(strlen(patente)!=7)return false;

    for(int i=0; i<2; i++) if(patente[i]<'A' or patente[i]>'Z') return false;

    for(int i=2; i<5; i++) if(patente[i]<'0' or patente[i]>'9') return false;

    for(int i=5; i<7; i++) if(patente[i]<'A' or patente[i]>'Z') return false;

    return true;
}

bool validarPalabra(const char *palabra){
    int longitud=strlen(palabra);
    if(longitud==0)return false;

    for(int i=0; i<longitud; i++){
        if(!((palabra[i]>='A' and palabra[i]<='Z') or (palabra[i]>='a' and palabra[i]<='z') or palabra[i]==' ')){
            return false;
        }
    }
    return true;
}

bool esBisiesto(int anio){
    return(anio%4==0 and anio%100!=0) or (anio%400==0);
}

int diasEnMes(int mes, int anio){
    int dias[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(mes==2 and esBisiesto(anio)) return 29;
    return dias[mes-1];
}

string nombreMes(int mes){
    string meses[]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    return meses[mes-1];
}

int diaSemanaPrimeroMes(int mes, int anio) {
    int dias=0;
    for(int a=1900; a<anio; a++) dias+=esBisiesto(a) ? 366 : 365;

    for(int m=1; m<mes; m++) dias+=diasEnMes(m, anio);

    return(dias+1)%7;
}

void calendario(int mes, int anio){
    cls();

    setColor(YELLOW);
    locate(40, 2); cout << "==================== CALENDARIO ====================";
    setColor(WHITE);

    locate(40, 4); cout << "Presione < o > para moverse en el calendario";
    locate(40, 5); cout << "ENTER para seleccionar el mes";
    locate(40, 6); cout << "Presione ESC para salir";

    locate(50, 8); cout << nombreMes(mes) << " " << anio;

    locate(40, 10); cout << " Do  Lu  Ma  Mi  Ju  Vi  Sa";

    int primerDia = diaSemanaPrimeroMes(mes, anio);
    int totalDias = diasEnMes(mes, anio);

    int filaInicio = 11;
    int colInicio = 40;

    Archivo_viaje archivo;
    int contreg = archivo.contarRegistros();

    int fila = filaInicio;
    int col = colInicio + primerDia * 4;

    for(int dia = 1; dia <= totalDias; dia++){

        bool tieneViaje = false;
        for(int i = 0; i < contreg; i++){
            Viaje viaje = archivo.leerRegistros(i);
            if(viaje.getFecha_Inicio_Viaje().getDia() == dia and viaje.getFecha_Inicio_Viaje().getMes() == mes and viaje.getFecha_Inicio_Viaje().getAnio() == anio){
                tieneViaje = true;
                break;
            }
        }

        locate(col, fila);

        int diaSemana = (primerDia + dia - 1) % 7;
        if(tieneViaje) setColor(GREEN);
        else setColor(WHITE);

        cout << setw(2) << dia;

        setColor(WHITE);
        cout << " ";

        col += 4;
        if(diaSemana == 6){
            col = colInicio;
            fila++;
        }
    }

    cout << endl << endl;
}

int viajes_disponibles() {
    cls();
    Viaje viaje;
    Archivo_viaje archivo;
    Tiempo_Actual tiempo;

    int mes = tiempo.getMes();
    int anio = tiempo.getAnio();

    while (true) {
        int dia;

        while (true) {
            cls();
            setColor(YELLOW);
            locate(40, 2); cout << "====================== CALENDARIO ======================";
            setColor(WHITE);
            calendario(mes, anio);

            int tecla = getkey();
            if (tecla == KEY_RIGHT) {
                mes++;
                if (mes == 13) { mes = 1; anio++; }
            } else if (tecla == KEY_LEFT) {
                mes--;
                if (mes == 0) { mes = 12; anio--; }
            } else if (tecla == KEY_ENTER) {
                break;
            } else if (tecla == KEY_ESCAPE) {
                return -1;
            }
        }

        setColor(CYAN);
        locate(40, 19); cout << "Ingrese el día para ver los viajes disponibles: ";
        setColor(WHITE);
        bool bandera2=true;
        while(true){
            locate(40, 20); cin >> dia;
            if(validar_numero())break;
            else{bandera2=false; break;}

            LimpiarLineas(20, 23, 40);
        }

        if(!bandera2)continue;

        int contreg = archivo.contarRegistros();
        bool bandera = false;

        cls();
        setColor(YELLOW);
        locate(40, 3); cout << "=============== VIAJES DISPONIBLES ===============";
        setColor(WHITE);

        for (int i = 0; i < contreg; i++) {
            viaje = archivo.leerRegistros(i);

            if (dia == viaje.getFecha_Inicio_Viaje().getDia() &&
                mes == viaje.getFecha_Inicio_Viaje().getMes() &&
                anio == viaje.getFecha_Inicio_Viaje().getAnio()) {
                LimpiarLineas(3,25,40);
                viaje.mostrar();
                anykey();
                bandera = true;
            }
        }
        LimpiarLineas(2,25,40);
        if (!bandera) {
            setColor(RED);
            locate(40, 19); cout << "No hay viajes pendientes para la fecha seleccionada.";
            setColor(WHITE);
            anykey();
            continue;
        }
        int idv;
        bool bandera1=false;
        while(true){

            setColor(CYAN);
            locate(40, 3); cout << "Ingrese el ID del viaje a seleccionar o presione (ESC) para salir: ";
            setColor(WHITE);

            int tecla = getkey();
            if (tecla == KEY_ESCAPE){ bandera1=true; break;}

            locate(40, 4); cin >> idv;
            int pos=archivo.buscarRegistro(idv);
            if(pos<0){locate(40, 6); cout<<"Error, no se encontro el archivo"<<endl;  anykey(); LimpiarLineas(4, 7, 40); continue; }
            viaje=archivo.leerRegistros(pos);

            if(validar_numero() and viaje.getIdViaje()==idv and viaje.getFecha_Inicio_Viaje().getDia()==dia)break;
            else{
                locate(40, 6);
                cout<<"ID de viaje no disponible, Ingrese la ID que disponga un viaje"<<endl;
            }

            anykey();
            LimpiarLineas(4, 7, 40);
        }
        if(!bandera1) return idv;
        else continue;
    }
    return -1;
}

int selecion_de_butacas(int cant, Micro micro, int idViaje){
    int columnas=4;
    int posSeleccionada=1;

    Archivo_pasaje archivo;
    Pasaje Pasaje;
    int cont=archivo.contarRegistros();
    int* ocupadas=new int[cont];
    int numOcupadas=0;
    for(int i=0; i<cont; i++){
        Pasaje=archivo.leerRegistros(i);
        if(Pasaje.getIdviaje()==idViaje){
            ocupadas[numOcupadas++]=Pasaje.getButaca();
        }
    }

    if(strcmp(micro.getTipo(), "simple-piso")==0){
        while(true){
            cls();
            int filas=(cant+columnas-1)/columnas;
            locate(52, 3); cout<<"BUTACAS"<<endl;
            for(int f=0; f<filas; f++){
                int colInicio=(40 + (columnas*4)/2);
                for(int c=0; c<columnas; c++){
                    int i=f*columnas+c;
                    if(i>=cant) break;
                    bool estaOcupada=false;
                    for(int j=0; j<numOcupadas; j++){
                        if(ocupadas[j]==i+1){ estaOcupada=true; break; }
                    }
                    if(estaOcupada)setColor(RED);
                    else if((i+1)==posSeleccionada)setColor(GREEN);
                    else setColor(WHITE);
                    locate(colInicio+c*4, 10+f);
                    cout<<"["<<((i+1<10) ? "0" : "")<<i+1<< "]";
                }
            }

            int tecla=getkey();
            if(tecla==KEY_UP){ posSeleccionada-=columnas; if(posSeleccionada<=0)posSeleccionada+=cant; }
            else if(tecla==KEY_DOWN){ posSeleccionada+=columnas; if(posSeleccionada>cant)posSeleccionada-=cant; }
            else if(tecla==KEY_LEFT){ posSeleccionada--; if(posSeleccionada<1)posSeleccionada=cant; }
            else if(tecla==KEY_RIGHT){ posSeleccionada++; if(posSeleccionada>cant)posSeleccionada=1; }
            else if(tecla==KEY_ENTER){
                bool ocupada=false;
                for(int j=0; j<numOcupadas; j++){ if(ocupadas[j]==posSeleccionada){ ocupada=true; break; } }
                if(!ocupada){ delete[] ocupadas; return posSeleccionada; }
                setColor(WHITE);
            }else if(tecla==KEY_ESCAPE){ delete[] ocupadas; break; }
        }
    }else if(strcmp(micro.getTipo(), "doble-piso")==0){
        int cantPorPiso=cant/2;
        int filas=(cantPorPiso + columnas - 1) / columnas;
        locate(52, 3); cout<<"BUTACAS"<<endl;
        while(true){
            cls();
            locate(40, 2); cout<<"Piso Inferior\t\tPiso Superior\n\n";
            for(int fila=0; fila<filas; fila++){
                int colInicio=40;
                for(int col=0; col<columnas; col++){
                    int num=fila*columnas+col+1;


                    if(num>cantPorPiso){
                        cout<<"    ";
                        if(col<columnas-1)cout<<" ";
                        continue;
                    }

                    bool estaOcupada=false;
                    for(int j=0; j<numOcupadas; j++){ if(ocupadas[j]==num){ estaOcupada=true; break; } }
                    if(estaOcupada)setColor(RED);
                    else if(num==posSeleccionada)setColor(GREEN);
                    else setColor(WHITE);
                    locate(colInicio+col*4, 4+fila);
                    cout<<"["<<((num<10) ? "0" : "")<<num<<"]";
                }

                for(int col=0; col<columnas; col++){
                    int num=cantPorPiso+fila*columnas+col+1;

                    if(num>cant) {
                        cout<<"    ";
                        if(col<columnas-1)cout<<" ";
                        continue;
                    }

                    bool estaOcupada=false;
                    for(int j=0; j<numOcupadas; j++){ if(ocupadas[j]==num){ estaOcupada=true; break; } }
                    if(estaOcupada)setColor(RED);
                    else if(num==posSeleccionada)setColor(GREEN);
                    else setColor(WHITE);
                    locate(colInicio+columnas*6+col*4, 4+fila);
                    cout<<"["<<((num<10) ? "0" : "")<<num<<"]";
                }
            }

            int tecla=getkey();
            if(tecla==KEY_UP){ posSeleccionada-=columnas; if(posSeleccionada<=0)posSeleccionada+=cant; }
            else if(tecla==KEY_DOWN){ posSeleccionada+=columnas; if(posSeleccionada>cant)posSeleccionada-=cant; }
            else if(tecla==KEY_LEFT){ posSeleccionada--; if(posSeleccionada<1)posSeleccionada=cant; }
            else if(tecla==KEY_RIGHT){ posSeleccionada++; if(posSeleccionada>cant)posSeleccionada=1; }
            else if(tecla==KEY_ENTER){
                bool ocupada=false;
                for(int j=0; j<numOcupadas; j++){ if(ocupadas[j]==posSeleccionada){ ocupada=true; break; } }
                if(!ocupada){ delete[] ocupadas; return posSeleccionada; }
            }else if(tecla==KEY_ESCAPE){ delete[] ocupadas; break; }
        }
    }
    delete[] ocupadas;
    return -1;
}


///Funciones Viajes-pasajes
void venta_de_pasaje() {
    cls();
    Pasajero pasajero;
    Archivo_pasajero archivoPasajeros;

    Viaje viaje;
    Archivo_viaje archivoViajes;

    Destino destino;
    Archivo_destino archivoDestinos;

    Pasaje Pasaje;
    Archivo_pasaje archivoPasaje;

    Micro micro;
    Archivo_micro archivoMicros;

    Precio precio;
    Archivo_Precio archivoPrecio;

    int contregPasajeros = archivoPasajeros.contarRegistros();
    if (contregPasajeros < 0) {
        setColor(RED);
        locate(40, 10); cout << "ERROR AL LEER EL ARCHIVO DE PASAJEROS";
        setColor(WHITE);
        anykey();
        return;
    }

    int idViaje = viajes_disponibles();

    if (idViaje < 0) {
        setColor(RED);
        cls();
        locate(40, 12); cout << "ERROR AL VER LOS ARCHIVOS";
        setColor(WHITE);
        anykey();
        return;
    }

    setColor(CYAN);
    locate(40, 5); cout << "Ingrese cantidad de personas: ";
    setColor(WHITE);
    int cantPasajes;
    locate(40, 6); cin >> cantPasajes;

    for (int i = 0; i < cantPasajes; i++) {
        setColor(YELLOW);
        locate(40,5); cout << "=== Pasajero " << i + 1 << " ===";
        setColor(WHITE);

        int numeroPasaje = contregPasajeros + 1 + i;
        Pasaje.setPasaje(numeroPasaje);

        int posviaje = archivoViajes.buscarRegistro(idViaje);
        viaje = archivoViajes.leerRegistros(posviaje);
        if (viaje.getIdViaje() == idViaje) {
            Pasaje.setIdviaje(viaje.getIdViaje());
        }

        int posmicro = archivoMicros.buscarRegsitro(viaje.getIdMicro());
        micro = archivoMicros.leerRegistros(posmicro);
        if (viaje.getIdMicro() == micro.getIdMicro()) {
            int butaca = selecion_de_butacas(micro.getCapacidad(), micro, idViaje);
            LimpiarLineas(1,40,40);
            Pasaje.setButaca(butaca);
            Pasaje.setTipo_butaca(micro.getTipoButaca());
        }

        int posdestino = archivoDestinos.buscarRegistros(viaje.getIdDestino());
        destino = archivoDestinos.leerRegistros(posdestino);
        if (viaje.getIdDestino() == destino.getIdDestino()) {
            precio = archivoPrecio.leerRegistros();
            float butaca=plusxbutaca(viaje);
            Pasaje.setPrecio(destino.getDistanciaKm()*precio.getPrecio()+butaca);
        }

        pasajero.cargar(Pasaje.getPasaje());

        if (archivoPasaje.grabarRegistro(Pasaje) and archivoPasajeros.grabarRegistro(pasajero)) {
            setColor(GREEN);
            locate(40, 18); cout << "Pasaje " << numeroPasaje << " registrado correctamente.";
            setColor(WHITE);
            anykey();
        } else {
            setColor(RED);
            locate(40, 18); cout << "Error al registrar el pasaje.";
            setColor(WHITE);
            anykey();
        }
        LimpiarLineas(16, 20, 40);
    }

    system("pause");
    system("cls");
}
void mostrar_pasajes_vendidos(){
    cls();
    Archivo_pasaje archivopasaje;
    archivopasaje.listar();
    anykey();
    system("cls");
}
void cargar_viaje(){
    cls();
    if(chequearSalidaESC("Usted esta por ingresar un nuevo Viaje."))return;

    Viaje viaje;
    Archivo_viaje archivo;
    int idv;

    int contreg=archivo.contarRegistros();

    if(contreg<0){
        cout<<"ERROR AL LEER EL ARCHIVO"<<endl;
        return;
    }

    if(contreg==0){
        idv=1000;
    }else{
        int idmax=999;
        viaje=archivo.leerRegistros(contreg-1);
        if(viaje.getIdViaje()>idmax) idmax=viaje.getIdViaje();
        idv=idmax+1;
    }
    viaje.cargar(idv);

    if(viaje.getIdMicro()==0 or viaje.getIdDestino()==0 or viaje.getIdChofer()==0)return;

    if(archivo.grabarRegistro(viaje))cout<<endl<<"VIAJE REGISTRADO SATISFACTORIAMENTE. ID: "<<idv<<endl;
    else cout<<"ERROR AL GUARDAR EL REGISTRO."<<endl;

    system("pause");
    system("cls");
}
void mostrar_viajes(){
    cls();
    Archivo_viaje archivo;
    archivo.listartabla();
    system("cls");
    locate(40, 5);  cout << "----------------------------------------------";
    locate(40, 6);  cout << "                 FIN DE REGISTRO              ";
    locate(40, 7);  cout << "----------------------------------------------";
    anykey();
    system("cls");
}

///FUNCIONES PRECIOS
void modificar_precios(){
    cls();
    Precio precio;
    Archivo_Precio archivo;

    precio=archivo.leerRegistros();
    cout<<"PRECIO ACTUAL POR KILOMETRO: "<<precio.getPrecio()<<"\n";

    while(true){
        cout<<"\nDESEA CAMBIAR EL PRECIO POR KILOMETRO?? \n(ENTER)para cambiar precio o (ESC)para salir"<<endl;
        int tecla=getkey();
        if(tecla==KEY_ENTER){
            int precio_nuevo;
            cout<<"\nINGRESE EL VALOR DEL KILOMETRO RECORRIDO PARA TODOS LOS VIAJES: "; cin>>precio_nuevo;
            if(precio_nuevo<=0)cout<<"EL VALOR DEL PRECIO POR KILOMETRO NO PUEDE SER CERO O NEGRATIVO"<<endl;
            else{
                cout<<"SE CAMBIO CORRECTAMENTE"<<endl;
                precio.setPrecio(precio_nuevo);
                archivo.grabarRegistro(precio);
                break;
            }

        }else if(tecla==KEY_ESCAPE){
            break;
        }
    }

    cout<<"PRECIO ACTUAL POR KILOMETRO: "<<precio.getPreciobutaca_cama()<<"\n";
    while(true){
        cout<<"\nDESEA CAMBIAR EL PRECIO DE LA BUTACA?? \n(ENTER)para cambiar precio o (ESC)para salir"<<endl;
        int tecla=getkey();
        if(tecla==KEY_ENTER){
            int precio_nuevo;
            cout<<"\nINGRESE EL VALOR DEL PRECIO: "; cin>>precio_nuevo;
            if(precio_nuevo<=0)cout<<"EL VALOR DEL PRECIO POR KILOMETRO NO PUEDE SER CERO O NEGRATIVO"<<endl;
            else{
                cout<<"SE CAMBIO CORRECTAMENTE"<<endl;
                precio.setPreciobutaca_cama(precio_nuevo);
                archivo.grabarRegistro(precio);
                break;
            }

        }else if(tecla==KEY_ESCAPE){
            break;
        }
    }

    cout<<"PRECIO ACTUAL DE BUTACA COMUN: "<<precio.getPreciobutaca_comun()<<"\n";
    while(true){
        cout<<"\nDESEA CAMBIAR EL PRECIO DE LA BUTACA?? \n(ENTER)para cambiar precio o (ESC)para salir"<<endl;
        int tecla=getkey();
        if(tecla==KEY_ENTER){
            int precio_nuevo;
            cout<<"\nINGRESE EL VALOR DEL PRECIO: "; cin>>precio_nuevo;
            if(precio_nuevo<=0)cout<<"EL VALOR DEL PRECIO POR KILOMETRO NO PUEDE SER CERO O NEGRATIVO"<<endl;
            else{
                cout<<"SE CAMBIO CORRECTAMENTE"<<endl;
                precio.setPreciobutaca_comun(precio_nuevo);
                archivo.grabarRegistro(precio);
                break;
            }

        }else if(tecla==KEY_ESCAPE){
            break;
        }
    }

    cout<<"PRECIO ACTUAL DE BUTATCA SEMI-CAMA: "<<precio.getPreciobutaca_semicama()<<"\n";
    while(true){
        cout<<"\nDESEA CAMBIAR EL PRECIO DE LA BUTACA?? \n(ENTER)para cambiar precio o (ESC)para salir"<<endl;
        int tecla=getkey();
        if(tecla==KEY_ENTER){
            int precio_nuevo;
            cout<<"\nINGRESE EL VALOR DEL PRECIO: "; cin>>precio_nuevo;
            if(precio_nuevo<=0)cout<<"EL VALOR DEL PRECIO POR KILOMETRO NO PUEDE SER CERO O NEGRATIVO"<<endl;
            else{
                cout<<"SE CAMBIO CORRECTAMENTE"<<endl;
                precio.setPreciobutaca_semicama(precio_nuevo);
                archivo.grabarRegistro(precio);
                break;
            }

        }else if(tecla==KEY_ESCAPE){
            break;
        }
    }

    system("pause");
    system("cls");
}
void cargar_precios(){
    cls();

    setColor(YELLOW);
    locate(40,3); cout << "----------------------------------------------";
    locate(40,4); cout << "                CARGA DE PRECIOS              ";
    locate(40,5); cout << "----------------------------------------------";
    setColor(WHITE);

    Precio precios;
    Archivo_Precio archivo;

    precios.cargar();
    archivo.grabarRegistro(precios);

    setColor(GREEN);
    locate(40,12); cout << "VALORES GUARDADOS CORRECTAMENTE";
    setColor(WHITE);

    anykey();
    cls();
}
void mostrar_precios(){
    Archivo_Precio archivo;
    Precio precio=archivo.leerRegistros();
    precio.mostrar();
}

///Funciones usuarios
void ingresar_usuario() {
    system("cls");

    if (chequearSalidaESC("Usted está por ingresar un nuevo Usuario.")) return;

    Usuario usuario;
    Archivo_usuario archivo;

    int contreg = archivo.contarRegistros();
    int idu;

    if (contreg < 0) {
        setColor(RED);
        locate(40, 8);  cout << "ERROR: No se puede acceder al archivo.";
        setColor(WHITE);
        locate(40, 10); anykey();
        system("cls");
        return;
    }

    if (contreg == 0) {
        idu = 10000;
    }
    else {
        usuario = archivo.leerRegistros(contreg - 1);
        int idmax = usuario.getIdUsuario();
        if (idmax < 9999) idmax = 9999;
        idu = idmax + 1;
    }

    setColor(WHITE);
    usuario.cargar(idu);

    system("cls");

    if (archivo.grabarRegistro(usuario)) {
        setColor(GREEN);
        locate(40, 5);  cout << "----------------------------------------------";
        locate(40, 6);  cout << "       USUARIO REGISTRADO CORRECTAMENTE       ";
        locate(40, 7);  cout << "----------------------------------------------";

        setColor(CYAN);
        locate(40, 9);  cout << "ID asignado: " << idu;
    }
    else {
        setColor(RED);
        locate(40, 5);  cout << "----------------------------------------------";
        locate(40, 6);  cout << "           USUARIO NO REGISTRADO              ";
        locate(40, 7);  cout << "----------------------------------------------";
    }

    setColor(WHITE);
    locate(40, 12);
    cout << "Presione una tecla para continuar...";
    locate(40, 13);
    anykey();

    setColor(WHITE);
    system("cls");
}
void mostrar_usuarios(){
    cls();
    Archivo_usuario archivo;
    archivo.listar();
    system("cls");
    locate(40, 5);  cout << "----------------------------------------------";
    locate(40, 6);  cout << "                 FIN DE REGISTRO              ";
    locate(40, 7);  cout << "----------------------------------------------";
    anykey();
    system("cls");
}
void eliminar_usuario(){
    cls();

    if(chequearSalidaESC("Usted esta por eliminar un Usuario.")) return;

    Archivo_usuario archivo;
    int idu;

    setColor(YELLOW);
    locate(40, 3);  cout << "----------------------------------------------";
    locate(40, 4);  cout << "              BAJA DE USUARIO                 ";
    locate(40, 5);  cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40, 7);  cout << "ID de usuario a dar de baja: ";
    while(true){
        locate(40, 8);
        setColor(WHITE);
        cin>>idu;

        if(validar_numero())break;

        LimpiarLineas(8, 10, 40);
    }

    int pos = archivo.buscarRegistro(idu);

    if(pos < 0){
        setColor(RED);
        locate(40, 10); cout << "NO EXISTE UN USUARIO CON ESE ID EN EL ARCHIVO";
        anykey();
        cls();
        return;
    }

    Usuario usuario = archivo.leerRegistros(pos);

    if(usuario.getEstado() == false){
        setColor(YELLOW);
        locate(40, 12); cout << "EL USUARIO YA FUE DADO DE BAJA";
        anykey();
        cls();
        return;
    }

    usuario.setEstado(false);
    archivo.modificarRegistro(usuario, pos);

    setColor(GREEN);
    locate(40, 12); cout << "SE DIO DE BAJA AL USUARIO CORRECTAMENTE";

    anykey();
    cls();
}
void dar_alta_usuario(){
    cls();

    if(chequearSalidaESC("Usted esta por dar de alta un Usuario.")) return;

    Archivo_usuario archivo;
    int idu;

    setColor(YELLOW);
    locate(40, 3);  cout << "----------------------------------------------";
    locate(40, 4);  cout << "              ALTA DE USUARIO                 ";
    locate(40, 5);  cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40, 7);  cout << "ID de usuario a dar de alta: ";
    while(true){
        locate(40, 8);
        setColor(WHITE);
        cin>>idu;

        if(validar_numero())break;

        LimpiarLineas(8, 10, 40);
    }

    int pos = archivo.buscarRegistro(idu);

    if(pos < 0){
        setColor(RED);
        locate(40, 10); cout << "NO EXISTE UN USUARIO CON ESE ID EN EL ARCHIVO";
        anykey();
        cls();
        return;
    }

    Usuario usuario = archivo.leerRegistros(pos);

    if(usuario.getEstado() == true){
        setColor(YELLOW);
        locate(40, 12); cout << "EL USUARIO YA FUE DADO DE ALTA";
        anykey();
        cls();
        return;
    }

    usuario.setEstado(true);
    archivo.modificarRegistro(usuario, pos);

    setColor(GREEN);
    locate(40, 12); cout << "SE DIO DE ALTA AL USUARIO CORRECTAMENTE";

    anykey();
    cls();
}
void cambiar_contrasena(){
    cls();
    Archivo_usuario archivo;
    int idu;

    setColor(YELLOW);
    locate(40, 3);  cout << "----------------------------------------------";
    locate(40, 4);  cout << "            CAMBIO DE CONTRASENA              ";
    locate(40, 5);  cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40, 7);  cout << "ID de usuario: ";
    while(true){
        locate(40, 8);
        setColor(WHITE);
        cin>>idu;

        if(validar_numero())break;

        LimpiarLineas(8, 10, 40);
    }

    int pos = archivo.buscarRegistro(idu);

    if(pos < 0){
        setColor(RED);
        locate(40, 10); cout << "NO EXISTE UN USUARIO CON ESE ID EN EL ARCHIVO";
        anykey();
        cls();
        return;
    }

    Usuario usuario = archivo.leerRegistros(pos);

    char nueva_contrasena[30];

    if(usuario.getEstado()){
        setColor(WHITE);
        locate(40, 12); cout << "Nueva contrasena: ";
        locate(60, 12); cin >> nueva_contrasena;

        usuario.setContrasena(nueva_contrasena);
        archivo.modificarRegistro(usuario, pos);

        setColor(GREEN);
        locate(40, 14); cout << "SE CAMBIO LA CONTRASENA CORRECTAMENTE";
    }
    else{
        setColor(RED);
        locate(40, 12); cout << "USUARIO INEXISTENTE";
    }

    anykey();
    cls();
}
void cambiar_datos_usuario(){
    if(chequearSalidaESC("Usted esta por cambiar los datos de un usuario."))return;
    Archivo_usuario archivo;
    Usuario usuario;
    int idu;
    while(true){
        locate(40, 15);
        setColor(GREEN);
        cout<<"INGRESE EL ID DEL USUARIO: ";
        locate(40, 16);
        setColor(WHITE);
        cin>>idu;
        if(validar_numero())break;

        LimpiarLineas(16, 18, 40);
    }
    int pos=archivo.buscarRegistro(idu);

    if(pos<0){
        locate(40, 17);
        cout<<"NO EXISTE UN USUARIO CON ESE ID EN EL ARCHIVO"<<endl;
        anykey();
        cls();
        return;
    }
    usuario=archivo.leerRegistros(pos);
    if(usuario.getEstado()){
        usuario.modificar();
        archivo.modificarRegistro(usuario, pos);
        locate(40, 17);
        cout<<"SE CAMBIARON LOS DATOS CORRECTAMENTE"<<endl;
    }else {
        locate(40, 18);
        cout<<"USUARIO INEXISTENTE"<<endl;
    }

    anykey();
    system("cls");

}
void listar_ingresos(){
    cls();
    Archivo_historial_usuario historia;
    historia.listar();
    system("cls");
    locate(40, 5);  cout << "----------------------------------------------";
    locate(40, 6);  cout << "                 FIN DE REGISTRO              ";
    locate(40, 7);  cout << "----------------------------------------------";
    anykey();
    system("cls");
}

///Funciones micros
void ingresar_Micro(){
    cls();

    if(chequearSalidaESC("Usted esta por ingresar un nuevo Micro."))return;

    Micro micros;
    Archivo_micro archivo;
    int idm;

    int contreg=archivo.contarRegistros();

    if(contreg<0){
        setColor(RED);
        locate(44, 13);
        cout << "ERROR AL LEER EL ARCHIVO. NO SE PUEDE REGISTRAR.";
        setColor(WHITE);
        system("pause");
        return;
    }

    if(contreg==0){
        idm=1000;
    }else{
        int idmax=999;
        micros=archivo.leerRegistros(contreg-1);
        if(micros.getIdMicro()>idmax)idmax=micros.getIdMicro();
        idm=idmax+1;
    }

    micros.cargar(idm);

    if(archivo.grabarRegistro(micros)){
        setColor(WHITE);
        locate(44, 11);
        cout << "----------------------------------------";
        setColor(GREEN);
        locate(44, 12);
        cout << "MICRO REGISTRADO SATISFACTORIAMENTE";
        locate(44, 13);
        cout << "ID: " << idm;
        setColor(WHITE);
        locate(44, 14);
        cout << "----------------------------------------"<<endl;

    }
    else {
        setColor(RED);
        locate(44, 13);
        cout << "ERROR AL GUARDAR EL REGISTRO.";
        setColor(WHITE);
    }


    system("pause");
    system("cls");
}
void mostrar_Micro(){
    Archivo_micro archivo;
    archivo.listartabla();
    system("cls");
}
void eliminar_Micro() {
    system("cls");
    if (chequearSalidaESC("Usted está por eliminar un Micro.")) return;

    Archivo_micro archivo;
    int idm;

    setColor(WHITE);

    locate(44, 8);  cout << "--------- ELIMINAR MICRO ---------";
    locate(44, 9);  cout << "----------------------------------";

    locate(44, 11); cout << "Ingrese ID de micro a dar de baja:";
    locate(44, 12); cout << "> ";
    while(true){
        locate(48, 12);
        cin >> idm;
        if(validar_numero())break;

        LimpiarLineas(12, 13, 48);
    }

    int pos = archivo.buscarRegsitro(idm);

    system("cls");

    locate(44, 8);  cout << "--------- ELIMINAR MICRO ---------";
    locate(44, 9);  cout << "----------------------------------";

    if (pos < 0) {
        locate(44, 11); cout << "No existe un micro con ese ID.";
        locate(44, 14); anykey();
        system("cls");
        return;
    }

    Micro micros = archivo.leerRegistros(pos);

    if (!micros.getDisponible()) {
        locate(44, 11); cout << "El micro ya fue dado de baja anteriormente.";
        locate(44, 14); anykey();
        system("cls");
        return;
    }

    micros.setDisponible(false);
    archivo.modificarRegistro(micros, pos);

    locate(44, 11); cout << "Micro dado de baja correctamente.";
    locate(44, 14); anykey();
    system("cls");
}
void dar_alta_Micro(){
    system("cls");
    if (chequearSalidaESC("Usted está por dar de alta un Micro.")) return;

    Archivo_micro archivo;
    int idm;

    setColor(WHITE);

    locate(44, 8);  cout << "--------- DAR ALTA MICRO ---------";
    locate(44, 9);  cout << "----------------------------------";

    locate(44, 11); cout << "Ingrese ID de micro a dar de alta:";
    locate(44, 12); cout << "> ";
    while(true){
        locate(48, 12);
        cin >> idm;
        if(validar_numero())break;

        LimpiarLineas(12, 13, 48);
    }


    int pos = archivo.buscarRegsitro(idm);

    system("cls");

    locate(44, 8);  cout << "--------- DAR ALTA MICRO ---------";
    locate(44, 9);  cout << "----------------------------------";

    if (pos < 0) {
        locate(44, 11); cout << "No existe un micro con ese ID.";
        locate(44, 14); anykey();
        system("cls");
        return;
    }

    Micro micros = archivo.leerRegistros(pos);

    if (micros.getDisponible()) {
        locate(44, 11); cout << "El micro ya esta dado de alta.";
        locate(44, 14); anykey();
        system("cls");
        return;
    }

    micros.setDisponible(true);
    archivo.modificarRegistro(micros, pos);

    locate(44, 11); cout << "Micro dado de alta correctamente.";
    locate(44, 14); anykey();
    system("cls");
}
void cambiar_patente_Micro() {
    system("cls");
    if (chequearSalidaESC("Usted está por cambiar la patente de un Micro.")) return;

    Archivo_micro archivo;
    Micro micro;
    int idm;

    setColor(WHITE);
    locate(44, 8);  cout << "------- CAMBIAR PATENTE -------";
    locate(44, 9);  cout << "-------------------------------";

    locate(44, 11); cout << "Ingrese el ID del micro:";
    locate(44, 12); cout << "> ";
    while(true){
        locate(48, 12);
        cin >> idm;
        if(validar_numero())break;

        LimpiarLineas(12, 13, 48);
    }

    system("cls");

    int pos = archivo.buscarRegsitro(idm);

    locate(44, 8);  cout << "------- CAMBIAR PATENTE -------";
    locate(44, 9);  cout << "-------------------------------";

    if (pos < 0) {
        locate(44, 11); cout << "No existe micro con ese ID.";
        locate(44, 15); anykey();
        system("cls");
        return;
    }

    micro = archivo.leerRegistros(pos);

    if (!micro.getDisponible()) {
        locate(44, 11); cout << "El micro no está disponible.";
        locate(44, 15); anykey();
        system("cls");
        return;
    }

    char patenteNueva[20];
    bool ok = false;

    while (!ok) {
        locate(44, 11);  cout << "Ingrese nueva patente (AA111AA):     ";
        locate(44, 12);  cout << ">                                   ";
        locate(46, 12);  cargarCadena(patenteNueva, 19);

        for(int i=0; patenteNueva[i]; i++) patenteNueva[i] = toupper(patenteNueva[i]);

        ok = validarPatente(patenteNueva);

        if (ok) {
            if (existePatente(patenteNueva, idm)) {
                locate(44, 14); cout << "ERROR: La patente ya existe. Intente con otra.";
                ok = false;
            }
        }

        if (!ok) {
            locate(44, 14); cout << "Patente inválida. Intente nuevamente.";
            locate(44, 15); anykey();
            locate(44, 14); cout << "                                        ";
            locate(44, 15); cout << "                                        ";
        }
    }

    micro.setPatente(patenteNueva);
    archivo.modificarRegistro(micro, pos);

    locate(44, 14); cout << "Patente cambiada correctamente.";
    locate(44, 16); anykey();
    system("cls");

}
void cambiar_unidad_Micro() {
    system("cls");
    if (chequearSalidaESC("Usted está por cambiar la unidad del Micro.")) return;

    Archivo_micro archivo;
    Micro micro;
    int idm;

    setColor(GREEN);
    locate(40, 3);  cout << "------------------------------------------";
    locate(40, 4);  cout << "          CAMBIAR UNIDAD DE MICRO         ";
    locate(40, 5);  cout << "------------------------------------------";
    setColor(WHITE);

    while(true){
        locate(40, 8); cout << "Ingrese ID del micro:";
        locate(40, 9); cout << "> ";
        cin >> idm;

        if(validar_numero())break;
        LimpiarLineas(9, 12, 40);
    }


    system("cls");

    int pos = archivo.buscarRegsitro(idm);

    if (pos < 0) {
        locate(40, 8); cout << "No existe un micro con ese ID.";
        locate(40, 11); anykey();
        system("cls");
        return;
    }

    micro = archivo.leerRegistros(pos);

    if (!micro.getDisponible()) {
        locate(40, 8); cout << "El micro no está disponible.";
        locate(40, 11); anykey();
        system("cls");
        return;
    }

    micro.cargar(idm);
    archivo.modificarRegistro(micro, pos);

    locate(40, 8); cout << "Unidad modificada correctamente.";
    locate(40, 11); anykey();
    system("cls");
}

///Funciones destinos-pasajes
void ingresar_destino(){
    cls();
    if(chequearSalidaESC("Usted esta por ingresar un nuevo Destino.")) return;

    Destino destinos;
    Archivo_destino archivo;
    int idd;

    setColor(YELLOW);
    locate(40,3);  cout << "----------------------------------------------";
    locate(40,4);  cout << "            INGRESAR NUEVO DESTINO            ";
    locate(40,5);  cout << "----------------------------------------------";
    setColor(WHITE);

    int contreg = archivo.contarRegistros();

    if(contreg < 0){
        setColor(RED);
        locate(40,8); cout << "ERROR AL LEER EL ARCHIVO. NO SE PUEDE REGISTRAR.";
        setColor(WHITE);
        anykey();
        cls();
        return;
    }

    if(contreg == 0){
        idd = 100000;
    } else {
        int idmax = 99999;
        destinos = archivo.leerRegistros(contreg - 1);
        if(destinos.getIdDestino() > idmax) idmax = destinos.getIdDestino();
        idd = idmax + 1;
    }

    locate(40,8); cout << "ID generado: " << idd;
    locate(40,10);

    destinos.cargar(idd);

    cls();
    setColor(YELLOW);
    locate(40,3);  cout << "----------------------------------------------";
    locate(40,4);  cout << "                REGISTRO DESTINO              ";
    locate(40,5);  cout << "----------------------------------------------";
    setColor(WHITE);

    if(archivo.grabarRegistro(destinos)){
        setColor(GREEN);
        locate(40,8); cout << "DESTINO REGISTRADO CORRECTAMENTE.";
        locate(40,10); cout << "ID asignado: " << idd;
    }
    else{
        setColor(RED);
        locate(40,8); cout << "ERROR AL GUARDAR EL REGISTRO.";
    }

    setColor(WHITE);
    locate(40,12);
    anykey();
    cls();
}
void mostrar_destino(){
    cls();
    Archivo_destino archivo;
    archivo.listar();
    system("cls");
    locate(40, 5);  cout << "----------------------------------------------";
    locate(40, 6);  cout << "                 FIN DE REGISTRO              ";
    locate(40, 7);  cout << "----------------------------------------------";
    anykey();
    system("cls");
}
void eliminar_destino(){
    cls();

    if(chequearSalidaESC("Usted esta por eliminar un Destino.")) return;

    Archivo_destino archivo;
    int idd;

    setColor(YELLOW);
    locate(40,3); cout << "----------------------------------------------";
    locate(40,4); cout << "               BAJA DE DESTINO               ";
    locate(40,5); cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40,8); cout << "ID del destino a dar de baja: ";

    while(true){
        locate(40, 9);
        cin >> idd;
        if(validar_numero())break;

        LimpiarLineas(9, 11, 40);
    }

    int pos = archivo.buscarRegistros(idd);

    if(pos < 0){
        setColor(RED);
        locate(40,10); cout << "NO EXISTE UN DESTINO CON ESE ID EN EL ARCHIVO";
        anykey();
        cls();
        return;
    }

    Destino destinos = archivo.leerRegistros(pos);

    if(destinos.getHabilitado() == false){
        setColor(YELLOW);
        locate(40,12); cout << "EL DESTINO YA FUE DADO DE BAJA";
        setColor(WHITE);
        anykey();
        cls();
        return;
    }

    destinos.setHabilitado(false);
    archivo.modificarRegistro(destinos, pos);

    setColor(GREEN);
    locate(40,12); cout << "SE DIO DE BAJA EL DESTINO CORRECTAMENTE";

    anykey();
    cls();
}
void dar_alta_destino(){
cls();

    if(chequearSalidaESC("Usted esta por dar de alta un Destino.")) return;

    Archivo_destino archivo;
    int idd;

    setColor(YELLOW);
    locate(40,3); cout << "----------------------------------------------";
    locate(40,4); cout << "               ALTA DE DESTINO               ";
    locate(40,5); cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40,8); cout << "ID del destino a dar de alta: ";
    while(true){
        locate(40, 9);
        cin >> idd;
        if(validar_numero())break;

        LimpiarLineas(9, 11, 40);
    }

    int pos = archivo.buscarRegistros(idd);

    if(pos < 0){
        setColor(RED);
        locate(40,10); cout << "NO EXISTE UN DESTINO CON ESE ID EN EL ARCHIVO";
        anykey();
        cls();
        return;
    }

    Destino destinos = archivo.leerRegistros(pos);

    if(destinos.getHabilitado() == true){
        setColor(YELLOW);
        locate(40,12); cout << "EL DESTINO YA FUE DADO DE ALTA";
        setColor(WHITE);
        anykey();
        cls();
        return;
    }

    destinos.setHabilitado(true);
    archivo.modificarRegistro(destinos, pos);

    setColor(GREEN);
    locate(40,12); cout << "SE DIO DE ALTA EL DESTINO CORRECTAMENTE";

    anykey();
    cls();
}
void mostrar_provincias(){
    cls();

    setColor(YELLOW);
    locate(40,3);  cout << "----------------------------------------------";
    locate(40,4);  cout << "            LISTADO DE PROVINCIAS             ";
    locate(40,5);  cout << "----------------------------------------------";
    setColor(WHITE);

    int fila = 7;

    for(int i = 1; i <= 9; i++){
        locate(40, fila);
        cout << i << " - " << funcion_provincias(i,3);
        fila++;
    }
    for(int i = 10; i <= 23; i++){
        locate(39, fila);
        cout << i << " - " << funcion_provincias(i,3);
        fila++;
    }

    anykey();
    cls();
}

///Funciones choferes
void ingresar_chofer(){
    cls();

    if(chequearSalidaESC("Usted esta por ingresar un nuevo Chofer.")) return;

    setColor(YELLOW);
    locate(40,3); cout << "----------------------------------------------";
    locate(40,4); cout << "              INGRESO DE CHOFER              ";
    locate(40,5); cout << "----------------------------------------------";
    setColor(WHITE);

    Chofer chofer;
    Archivo_chofer archivo;
    int leg;

    int contreg = archivo.contarRegistros();

    if(contreg < 0){
        setColor(RED);
        locate(40,7); cout << "ERROR AL LEER EL ARCHIVO. NO SE PUEDE REGISTRAR.";
        setColor(WHITE);
        anykey();
        cls();
        return;
    }

    if(contreg == 0){
        leg = 100;
    } else {
        int idmax = 99;
        chofer = archivo.leerRegistros(contreg-1);
        if(chofer.getLegajo() > idmax) idmax = chofer.getLegajo();
        leg = idmax + 1;
    }

    chofer.cargar(leg);

    if(archivo.grabarRegistro(chofer)){
        setColor(GREEN);
        locate(40,12); cout << "CHOFER REGISTRADO SATISFACTORIAMENTE. ID: " << leg;
        setColor(WHITE);
    } else {
        setColor(RED);
        locate(40,12); cout << "ERROR AL GUARDAR EL REGISTRO.";
        setColor(WHITE);
    }

    anykey();
    cls();
}
void mostrar_choferes(){
    cls();
    Archivo_chofer archivo;
    archivo.listar();
    locate(40, 5);  cout << "----------------------------------------------";
    locate(40, 6);  cout << "                 FIN DE REGISTRO              ";
    locate(40, 7);  cout << "----------------------------------------------";
    anykey();
    system("cls");
}
void eliminar_chofer(){
    cls();

    if(chequearSalidaESC("Usted esta por eliminar un Chofer.")) return;

    Archivo_chofer archivo;
    Chofer chofer;
    int leg;

    setColor(YELLOW);
    locate(40, 3);  cout << "----------------------------------------------";
    locate(40, 4);  cout << "              BAJA DE CHOFER                 ";
    locate(40, 5);  cout << "----------------------------------------------";
    setColor(WHITE);

    setColor(GREEN);
    locate(40, 7); cout << "INGRESE LEGAJO DEL CHOFER A DAR DE BAJA: ";
    while(true){
        locate(40, 8);
        setColor(WHITE);
        cin>>leg;

        if(validar_numero())break;

        LimpiarLineas(8, 10, 40);
    }

    int pos = archivo.buscarRegistro(leg);

    if(pos < 0){
        setColor(RED);
        locate(40, 9); cout << "NO EXISTE UN CHOFER CON ESE LEGAJO EN EL ARCHIVO";
        setColor(WHITE);
        anykey();
        LimpiarLineas(7, 9, 40);
        return;
    }

    chofer = archivo.leerRegistros(pos);

    if(chofer.getEstado() == false){
        setColor(YELLOW);
        locate(40, 9); cout << "EL CHOFER YA FUE DADO DE BAJA";
        setColor(WHITE);
        anykey();
        LimpiarLineas(7, 9, 40);
        return;
    }

    chofer.setEstado(false);
    archivo.modificarRegistro(chofer, pos);

    setColor(GREEN);
    locate(40, 9); cout << "SE DIO DE BAJA AL CHOFER CORRECTAMENTE";
    setColor(WHITE);
    anykey();
    LimpiarLineas(7, 9, 40);
}
void dar_alta_chofer(){
    cls();

    if(chequearSalidaESC("Usted esta por dar de alta un Chofer.")) return;

    Archivo_chofer archivo;
    Chofer chofer;
    int leg;

    setColor(YELLOW);
    locate(40, 3);  cout << "----------------------------------------------";
    locate(40, 4);  cout << "              ALTA DE CHOFER                 ";
    locate(40, 5);  cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40, 7); cout << "INGRESE LEGAJO DEL CHOFER A DAR DE ALTA: ";
    while(true){
        locate(40, 8);
        setColor(WHITE);
        cin>>leg;

        if(validar_numero())break;

        LimpiarLineas(8, 10, 40);
    }

    int pos = archivo.buscarRegistro(leg);

    if(pos < 0){
        setColor(RED);
        locate(40, 9); cout << "NO EXISTE UN CHOFER CON ESE LEGAJO EN EL ARCHIVO";
        setColor(WHITE);
        anykey();
        LimpiarLineas(7, 9, 40);
        return;
    }

    chofer = archivo.leerRegistros(pos);

    if(chofer.getEstado() == true){
        setColor(YELLOW);
        locate(40, 9); cout << "EL CHOFER YA FUE DADO DE ALTA";
        setColor(WHITE);
        anykey();
        LimpiarLineas(7, 9, 40);
        return;
    }

    chofer.setEstado(true);
    archivo.modificarRegistro(chofer, pos);

    setColor(GREEN);
    locate(40, 9); cout << "SE DIO DE ALTA AL CHOFER CORRECTAMENTE";
    setColor(WHITE);
    anykey();
    LimpiarLineas(7, 9, 40);
}
void cambiar_mail_chofer(){
    cls();

    Archivo_chofer archivo;
    Chofer chofer;
    int leg;

    setColor(YELLOW);
    locate(40, 3);  cout << "----------------------------------------------";
    locate(40, 4);  cout << "             CAMBIO DE EMAIL CHOFER           ";
    locate(40, 5);  cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40, 7); cout << "INGRESE EL LEGAJO DEL CHOFER: ";
    while(true){
        locate(40, 8);
        setColor(WHITE);
        cin>>leg;

        if(validar_numero())break;

        LimpiarLineas(8, 10, 40);
    }

    int pos = archivo.buscarRegistro(leg);

    if(pos < 0){
        setColor(RED);
        locate(40, 9); cout << "NO EXISTE EL CHOFER CON ESE LEGAJO EN EL ARCHIVO";
        setColor(WHITE);
        anykey();
        LimpiarLineas(7, 9, 40);
        return;
    }

    chofer = archivo.leerRegistros(pos);
    char Mail_Nuevo[40];

    if(chofer.getEstado()){
        locate(40, 9); cout << "INGRESE NUEVO MAIL: ";
        locate(60, 9); cin >> Mail_Nuevo;
        chofer.setEmail(Mail_Nuevo);
        archivo.modificarRegistro(chofer, pos);

        setColor(GREEN);
        locate(40, 11); cout << "SE CAMBIO EL MAIL CORRECTAMENTE";
        setColor(WHITE);
        anykey();
        LimpiarLineas(3, 11, 40);
    }else{
        setColor(RED);
        locate(40, 9); cout << "CHOFER INEXISTENTE";
        setColor(WHITE);
        anykey();
        LimpiarLineas(3, 9, 40);
    }
}
void cambiar_telefono_chofer(){
    cls();

    Archivo_chofer archivo;
    Chofer chofer;
    int leg;

    setColor(YELLOW);
    locate(40, 3);  cout << "----------------------------------------------";
    locate(40, 4);  cout << "            CAMBIO DE TELEFONO CHOFER         ";
    locate(40, 5);  cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40, 7); cout << "INGRESE EL LEGAJO DEL CHOFER: ";
    while(true){
        locate(40, 8);
        setColor(WHITE);
        cin>>leg;

        if(validar_numero())break;

        LimpiarLineas(8, 10, 40);
    }

    int pos = archivo.buscarRegistro(leg);

    if(pos < 0){
        setColor(RED);
        locate(40, 9); cout << "NO EXISTE EL CHOFER CON ESE LEGAJO EN EL ARCHIVO";
        setColor(WHITE);
        anykey();
        LimpiarLineas(7, 9, 40);
        return;
    }

    chofer = archivo.leerRegistros(pos);
    int Tel_Nuevo;

    if(chofer.getEstado()){
        locate(40, 9); cout << "INGRESE NUEVO TELEFONO: ";
        locate(66, 9); cin >> Tel_Nuevo;
        chofer.setTelefono(Tel_Nuevo);
        archivo.modificarRegistro(chofer, pos);

        setColor(GREEN);
        locate(40, 11); cout << "SE CAMBIO EL TELEFONO CORRECTAMENTE";
        setColor(WHITE);
        anykey();
        LimpiarLineas(3, 11, 40);
    }else{
        setColor(RED);
        locate(40, 9); cout << "CHOFER INEXISTENTE";
        setColor(WHITE);
        anykey();
        LimpiarLineas(3, 9, 40);
    }
}
void cambiar_datos_chofer(){
    if(chequearSalidaESC("Usted esta por cambiar los datos de un chofer."))return;
    Archivo_chofer archivo;
    Chofer chofer;
    int leg;

    setColor(GREEN);
    locate(40, 7);
    cout<<"INGRESE EL LEGAJO: ";
    while(true){
        locate(40, 8);
        setColor(WHITE);
        cin>>leg;

        if(validar_numero())break;

        LimpiarLineas(8, 10, 40);
    }
    int pos=archivo.buscarRegistro(leg);

    if(pos<0){
        locate(40, 9);
        cout<<"NO EXISTE UN CHOFER CON ESE LEGAJO EN EL ARCHIVO"<<endl;
        anykey();
        cls();
        return;
    }
    chofer=archivo.leerRegistros(pos);
    if(chofer.getEstado()){
        chofer.modificar();
        archivo.modificarRegistro(chofer, pos);
        locate(40, 10);
        cout<<"SE CAMBIARON LOS DATOS CORRECTAMENTE"<<endl;
    }else {
        locate(40, 10);
        cout<<"CHOFER INEXISTENTE"<<endl;
    }

    anykey();
    system("cls");
}

///REPORTES
void por_anio(){
    cls();
    Pasaje Pasaje;
    Archivo_pasaje archivopasaje;

    Viaje viaje;
    Archivo_viaje archivoviaje;

    int anio;
    while(true){
        setColor(YELLOW);
        locate(40, 15); cout<<"Ingrese el año: ";
        setColor(WHITE);
        cin>>anio;
        int longitud=to_string(anio).length();
        if(validar_numero() and (longitud>=4 and longitud<=4)) break;
        else{
            setColor(RED);
            locate(40, 17);
            cout << "Entrada invalida. Debe ingresar un anio de 4 cifras.";
            anykey();
            LimpiarLineas(15, 20, 40);
            setColor(WHITE);
            continue;
        }
    }


    float acumulador=0;

    int tam=archivopasaje.contarRegistros();
    int cant=archivoviaje.contarRegistros();

    for(int i=0; i<tam; i++){
        Pasaje=archivopasaje.leerRegistros(i);
        for(int x=0; x<cant; x++){
            viaje=archivoviaje.leerRegistros(x);
            if(viaje.getIdViaje()==Pasaje.getIdviaje()){
                if(viaje.getFecha_Inicio_Viaje().getAnio()==anio){
                    acumulador+=Pasaje.getPrecio();
                }
            }
        }
    }
    setColor(GREEN);
    locate(40, 15);
    cout<<"RECAUDACION TOTAL EN EL AÑO "<<anio<<" $:"<<acumulador<<endl;
    setColor(WHITE);
    anykey();
    cls();
}
void por_micro(){
    cls();
    Micro micros;
    Archivo_micro archivomicro;

    Pasaje Pasaje;
    Archivo_pasaje archivopasaje;

    Viaje viaje;
    Archivo_viaje archivoviaje;

  int id;
    while(true){
        setColor(YELLOW);
        locate(40, 15); cout<<"Ingrese el id del micro: ";
        setColor(WHITE);
        cin>>id;
        if(validar_numero() and (id>=1000 and id<=2000)) break;
        else {
            setColor(RED);
            locate(40, 17);
            cout << "ID de micro invalido, intente nuevamente: ";
            anykey();
            LimpiarLineas(15, 20, 40);
            setColor(WHITE);
            continue;
        }
    }

    float acumulador=0;
    int cantregmicro=archivomicro.contarRegistros();
    int cantregviaje=archivoviaje.contarRegistros();
    int cantregpasaje=archivopasaje.contarRegistros();

    int posmicro=archivomicro.buscarRegsitro(id);
    if(posmicro<0)return;
    micros=archivomicro.leerRegistros(posmicro);

    for(int i=0; i<cantregviaje; i++){
        viaje=archivoviaje.leerRegistros(i);
        if(viaje.getIdMicro()==micros.getIdMicro()){
            for(int z=0; z<cantregpasaje; z++){
                Pasaje=archivopasaje.leerRegistros(z);
                if(Pasaje.getIdviaje()==viaje.getIdViaje()){
                    acumulador+=Pasaje.getPrecio();
                }
            }
        }
    }
    setColor(GREEN);
    locate(40, 15);
    cout << "RECAUDACION TOTAL DEL MICRO "<<micros.getIdMicro()<<" ES DE $"<<acumulador<<endl;
    setColor(WHITE);
    anykey();
    cls();
}
void por_provincia(){
    cls();
    Pasaje Pasaje;
    Archivo_pasaje archivopasaje;

    Viaje viaje;
    Archivo_viaje archivoviaje;

    Destino destino;
    Archivo_destino archivodestino;

    int contregpasaje=archivopasaje.contarRegistros();
    int contregviaje=archivoviaje.contarRegistros();
    int contregdestino=archivodestino.contarRegistros();

    float recaudacio_provincia[23]={0};

    for(int i=0; i<contregpasaje; i++){
        Pasaje=archivopasaje.leerRegistros(i);
        int posviaje=archivoviaje.buscarRegistro(Pasaje.getIdviaje());
        if(posviaje<0)continue;
        viaje=archivoviaje.leerRegistros(posviaje);

        for(int z=0; z<contregdestino; z++){
            destino=archivodestino.leerRegistros(z);
            if(viaje.getIdDestino()==destino.getIdDestino()){
                for(int x=0; x<24; x++){
                    const char *provincia=funcion_provincias(x, 1);
                    if(strcmp(provincia, destino.getNombre_provincia())==0){
                        recaudacio_provincia[x]+=Pasaje.getPrecio();
                    }
                    provincia=funcion_provincias(x, 2);
                    if(strcmp(provincia, destino.getNombre_provincia())==0){
                        recaudacio_provincia[x]+=Pasaje.getPrecio();
                    }
                    provincia=funcion_provincias(x, 3);
                    if(strcmp(provincia, destino.getNombre_provincia())==0){
                        recaudacio_provincia[x]+=Pasaje.getPrecio();
                    }
                }
            }
        }
    }
    cout<<"=============================================="<<endl;
    cout<<"        RECAUDACION TOTAL POR DESTINO         "<<endl;
    cout<<"=============================================="<<endl;
    cout<<endl;
    cout<<"PROVINCIA"<<setw(20)<<" "<<"RECAUDACION"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(int i=0; i<23; i++){
        locate(0, i+8);
        cout<<funcion_provincias(i);
        locate(33, i+7);
        cout<<recaudacio_provincia[i+1]<<endl;
    }
    anykey();
    cls();
}
void cantPasajes_destino_mes(){
    cls();
    Archivo_destino archivodestino;
    Archivo_pasaje archivopasajes;
    Archivo_viaje archivoviaje;

    int cant_pasajes=archivopasajes.contarRegistros();
    int cant_destinos=archivodestino.contarRegistros();
    int cant_viajes=archivoviaje.contarRegistros();

    int *por_destino=new int[cant_destinos];
    for (int i=0;i<cant_destinos;i++){
        por_destino[i]=0;
    }
Fecha fecha_desde;
    setColor(YELLOW);
    locate(40, 8); cout << "Ingrese FECHA DESDE:";
    setColor(WHITE);
    fecha_desde.cargar();

    anykey();
    cls();

    Fecha fecha_hasta;
    setColor(YELLOW);
    locate(40, 8); cout << "Ingrese FECHA HASTA:";
    setColor(WHITE);
    fecha_hasta.cargar();

    int fecha_desde_num =
        fecha_desde.getAnio() * 10000 +
        fecha_desde.getMes() * 100 +
        fecha_desde.getDia();

    int fecha_hasta_num =
        fecha_hasta.getAnio() * 10000 +
        fecha_hasta.getMes() * 100 +
        fecha_hasta.getDia();

    for(int i=0;i<cant_pasajes;i++){
        Pasaje p= archivopasajes.leerRegistros(i);
        Fecha f;
        int a=f.getAnio();
        int m=f.getMes();
        int d=f.getDia();

        int fecha_pasaje_num=a*10000+m*100+d;
        if(fecha_pasaje_num>=fecha_desde_num&&fecha_pasaje_num<=fecha_hasta_num){

            Destino destino;
            Viaje viaje;
            Pasaje Pasaje;
            for(int i=0; i<cant_viajes; i++){
                viaje=archivoviaje.leerRegistros(i);
                int posdestino=archivodestino.buscarRegistros(viaje.getIdDestino());
                destino=archivodestino.leerRegistros(posdestino);

                for(int x=0; x<cant_pasajes; x++){
                    Pasaje=archivopasajes.leerRegistros(x);
                    if(Pasaje.getIdviaje()==viaje.getIdViaje()){
                        por_destino[destino.getIdDestino()-1]++;
                    }
                }

            }

//            int idDestino=p.getidDestino();
//
//        int posDestino=-1;
//
//        for(int j=0;j<cant_destinos;j++){
//            Destinos dest=archivodestino.leerRegistros(j);
//            if(dest.getidDestino()==idDestino){
//                posDestino=j;
//                break;
//            }
//        }posDestino
//          if(!=-1){
//            por_destino[posDestino]++;
//        }
    }
}
    rlutil::cls();
    cout << "CANTIDAD DE PASAJES VENDIDOS\n\n";
    cout << "Periodo: " << fecha_desde.getDia() << "/" << fecha_desde.getMes() << "/" << fecha_desde.getAnio()<< "  al  "
    << fecha_hasta.getDia() << "/" << fecha_hasta.getMes() << "/" << fecha_hasta.getAnio()<< endl << endl;
    cout << left << setw(20) <<  "Destino"<< right << setw(10) << "Pasajes" << endl;
    cout << "----------------------------------------------\n";
    for (int j = 0; j < cant_destinos; j++) {
        Destino dest = archivodestino.leerRegistros(j);
        cout << left << setw(20) << dest.getNombre_destino()<< right << setw(10) << por_destino[j] << endl;
    }

    cout << endl;
    anykey();
    cls();
    delete[] por_destino;
}
void kilometros_micro(){
    cls();
    Micro micro;
    Viaje viaje;
    Destino destino;

    Archivo_micro archivomicro;
    Archivo_viaje archivoviaje;
    Archivo_destino archivodestino;

    int cantviajes=archivoviaje.contarRegistros();
    int cantmicros=archivomicro.contarRegistros();

    float* micros=new float[cantmicros];
    if(micros==nullptr){
        cout<<"ERROR AL ASIGNAR MEMORIA"<<endl;
        return;
    }

    for(int i=0; i<cantmicros; i++)micros[i]=0;
 int anio;
    while(true){
            setColor(GREEN);
            locate(40, 15); cout<<"Ingrese el anio: ";
            setColor(WHITE);
            cin>>anio;
            int longitud=to_string(anio).length();
            if(validar_numero() and (longitud>=4 and longitud<=4)) break;
            else {
                setColor(RED);
                locate(40, 17);
                 cout << "Entrada invalida. Debe ingresar un anio de 4 cifras.";
                 anykey();
                 LimpiarLineas(15, 20, 40);
                 setColor(WHITE);
                 continue;
             }
        }

    int contador=0;
    for(int i=0; i<cantviajes; i++){
        viaje=archivoviaje.leerRegistros(i);
        int pos=archivodestino.buscarRegistros(viaje.getIdDestino());
        destino=archivodestino.leerRegistros(pos);
        for(int x=0; x<cantmicros; x++){
            micro=archivomicro.leerRegistros(x);
            if(viaje.getIdMicro()==micro.getIdMicro() and viaje.getFecha_Inicio_Viaje().getAnio()==anio){
                micros[viaje.getIdMicro()-1000]+=destino.getDistanciaKm();
            }
        }
    }


    cls();
    setColor(YELLOW);
    int fila=0, columna=40;
    locate(40, 10); cout<<"=================================================="<<endl;
    locate(40, 11); cout<<"KILOMETROS RECORRIDOS POR MICRO EN EL ANIO "<<anio<<endl;
    locate(40, 13); cout<<"Micros"<<setw(20)<<" "<<"kilometros recorridos"<<endl;
    locate(40, 14); cout<<"--------------------------------------------------"<<endl;
    for(int i=0; i<cantmicros; i++){
        micro=archivomicro.leerRegistros(i);
        if(micro.getDisponible()){
            locate(columna, i+14); cout<<micro.getIdMicro()<<setw(30)<<" "<<micros[i]<<endl;
            fila=i+15;
        }
    }
    locate(40, fila+1); cout<<"================================================"<<endl;


    delete[] micros;
    anykey();
    cls();
}
void recaudacion_por_genero_anio(){


    cls();
    Pasaje Pasaje;
    Archivo_pasaje archivopasajes;

    Viaje viaje;
    Archivo_viaje archivoviajes;

    Pasajero pasajero;
    Archivo_pasajero archivopasajero;

    float recaudacion_generos[3]={0};

 int anio;
    while(true){
            setColor(GREEN);
            locate(40, 15); cout<<"Ingrese el anio: ";
            setColor(WHITE);
            cin>>anio;
            int longitud=to_string(anio).length();
            if(validar_numero() and (longitud>=4 and longitud<=4)) break;
            else {
                setColor(RED);
                locate(40, 17);
                 cout << "Entrada invalida. Debe ingresar un anio de 4 cifras.";
                 anykey();
                 LimpiarLineas(15, 20, 40);
                 setColor(WHITE);
                 continue;
             }
        }
        cls();

    int cant_pasajes=archivopasajes.contarRegistros();
    int cant_viajes=archivoviajes.contarRegistros();
    int cant_pasajeros=archivopasajero.contarRegistros();

    for(int i=0; i<cant_pasajes; i++){
        Pasaje=archivopasajes.leerRegistros(i);
        int pospasaje=archivopasajero.buscarRegistro(Pasaje.getPasaje());
        pasajero=archivopasajero.leerRegistros(pospasaje);

        int posviaje=archivoviajes.buscarRegistro(Pasaje.getIdviaje());
        viaje=archivoviajes.leerRegistros(posviaje);

        if(pasajero.getHabilitado() and viaje.getFecha_Inicio_Viaje().getAnio()==anio){
            recaudacion_generos[pasajero.getGenero()-1]+=Pasaje.getPrecio();
        }
    }
    setColor(YELLOW);

    locate(40, 10);cout<<"=============================================="<<endl;
    locate(40, 11);cout<<"   RECAUDACION POR GENERO - AÑO "<<anio<<endl;
    locate(40, 12);cout<<"==============================================" << endl;
    locate(40, 13);cout<<endl;
    locate(40, 14);cout<<"Masculino:         $ "<<recaudacion_generos[0]<<endl;
    locate(40, 15);cout<<"Femenino:          $ "<<recaudacion_generos[1]<<endl;
    locate(40, 16);cout<<"No binario:        $ "<<recaudacion_generos[2]<<endl;
    anykey();
    cls();

}
void viajes_chofer_mes(){
    cls();
Archivo_viaje archivoviaje;
    Archivo_chofer archivochoferes;

    int cant_choferes = archivochoferes.contarRegistros();
    int cant_viajes   = archivoviaje.contarRegistros();


    int anio;
    while(true){
            setColor(GREEN);
            locate(40, 15); cout<<"Ingrese el anio: ";
            setColor(WHITE);
            cin>>anio;
            int longitud=to_string(anio).length();
            if(validar_numero() and (longitud>=4 and longitud<=4)) break;
            else {
                setColor(RED);
                locate(40, 17);
                 cout << "Entrada invalida. Debe ingresar un anio de 4 cifras.";
                 anykey();
                 LimpiarLineas(15, 20, 40);
                 setColor(WHITE);
                 continue;
             }
        }
    rlutil::cls();
    setColor(YELLOW);

    for (int c = 0; c < cant_choferes; c++) {

        Chofer chofer = archivochoferes.leerRegistros(c);
        int vmes[12] = {0};
        int legajoActual = chofer.getLegajo();

        for (int i = 0; i < cant_viajes; i++) {
            Viaje viaje = archivoviaje.leerRegistros(i);

            if (viaje.getIdChofer() == legajoActual) {
                Fecha f = viaje.getFecha_Inicio_Viaje();
                if (f.getAnio() == anio) {
                    int mes = f.getMes();
                    if (mes >= 1 && mes <= 12) {
                        vmes[mes - 1]++;
                    }
                }
            }
        }
        cout << "chofer legajo: " << chofer.getLegajo();
        cout << " - " << chofer.getApellido() << ", " << chofer.getNombre() << endl;
        cout << "Mes:   ";
        for (int m = 1; m <= 12; m++) {
            cout << setw(4) << m;
        }
        cout << endl;
        cout << "Viajes:";
        for (int m = 0; m < 12; m++) {
            cout << setw(4) << vmes[m];
        }
        cout << endl << "----------------------------------------" << endl;
    }
    anykey();
    cls();
}

///MENUS Y SUBMENUS
void SUBMENU_1(){
    int seleccion=0;
    const int opciones_submenu=5;
    string submenu[opciones_submenu]={
        " COMPRA DE PASAJE",
        " PASAJES VENDIDOS",
        " CARGAR VIAJES",
        " MOSTRAR VIAJES DISPONIBLES",
        " MENU PRINCIPAL"
    };
    bool salir=false;

    while(!salir){
        setColor(WHITE);
        for(int i=0; i<6; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<6; i++){locate(75,11+i); cout << "|";}
        locate(44,10);
        cout<<"-------------VENTA-------------"<<endl;
        locate(44,11);
        cout<<"-------------------------------"<<endl;
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
        cout<<"-------------------------------"<<endl;
        setColor(WHITE);
        int tecla=getkey();
        if(tecla==KEY_UP){
            seleccion--;
            if(seleccion<0)seleccion=opciones_submenu-1;
        }else if(tecla==KEY_DOWN){
            seleccion++;
            if(seleccion>=opciones_submenu)seleccion=0;
        }else if(tecla==KEY_ENTER){
            switch(seleccion){
            case 0:
                venta_de_pasaje();
                cls();
                break;
            case 1:
                mostrar_pasajes_vendidos();
                cls();
                break;
            case 2:
                cargar_viaje();
                cls();
                break;
            case 3:
                mostrar_viajes();
                cls();
                break;
            case 4:
                salir=true;
                break;
            }
        }
    }
}

void SUBMENU_2(){
    int seleccion=0;
    const int opciones_submenu=7;
    string submenu[opciones_submenu]={
        " INGRESA MICRO",
        " MOSTRAR MICROS",
        " DAR DE BAJA MICRO",
        " DAR DE ALTA MICRO",
        " CAMBIAR PATENTE",
        " CAMBIAR LA UNIDAD",
        " MENU PRINCIPAL"
    };
    bool salir=false;

    while(!salir){
        setColor(WHITE);
        for(int i=0; i<10; i++){locate(43,10+i); cout << "|";}
        for(int i=0; i<10; i++){locate(72,10+i); cout << "|";}
        locate(44,10);
        cout << "---------- MICROS ----------"<<endl;
        locate(44,11);
        cout<<"----------------------------"<<endl;
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
        locate(44,19);
        cout<<"----------------------------"<<endl;
        setColor(WHITE);

        int tecla=getkey();
        if(tecla==KEY_UP){
            seleccion--;
            if(seleccion<0)seleccion=opciones_submenu-1;
        }else if(tecla==KEY_DOWN){
            seleccion++;
            if(seleccion>=opciones_submenu)seleccion=0;
        }else if(tecla==KEY_ENTER){

            switch(seleccion){
            case 0:
                ingresar_Micro();
                cls();
                break;
            case 1:
                cls();
                mostrar_Micro();
                break;
            case 2:
                eliminar_Micro();
                break;
            case 3:
                dar_alta_Micro();
                break;
            case 4:
                cambiar_patente_Micro();
                break;
            case 5:
                cambiar_unidad_Micro();
                break;
            case 6:
                salir=true;
                break;
            }

        }
    }
}

void SUBMENU_3(){
    int seleccion=0;
    const int opciones_submenu=8;
    string submenu[opciones_submenu]={
        " ALTA DE NUEVO CONDUCTOR",
        " LISTA DE CONDUCTORES",
        " DAR DE BAJA CHOFER",
        " DAR DE ALTA CHOFER",
        " CAMBIAR MAIL ",
        " CAMBIAR TELEFONO",
        " CAMBIAR DATOS DE CHOFER",
        " MENU PRINCIPAL"
    };
    bool salir=false;

    while(!salir){
        setColor(WHITE);
        for(int i=0; i<9; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<9; i++){locate(73,11+i); cout << "|";}
        locate(44,10);
        cout<<"----------CHOFERES-----------"<<endl;
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
        locate(44,20);
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

            switch(seleccion){
            case 0:
                ingresar_chofer();
                break;
            case 1:
                mostrar_choferes();
                break;
            case 2:
                eliminar_chofer();
                break;;
            case 3:
                dar_alta_chofer();
                break;
            case 4:
                cambiar_mail_chofer();
                break;
            case 5:
                cambiar_telefono_chofer();
                break;
            case 6:
                cambiar_datos_chofer();
                break;
            case 7:
                salir=true;
                break;
            }

        }
    }
}

void SUBMENU_4(){
    int seleccion=0;
    const int opciones_submenu=6;
    string submenu[opciones_submenu]={
        " INGRESAR DESTINO",
        " MOSTRAR DESTINO",
        " DAR DE BAJA UN DESTINO",
        " DAR DE ALTA UN DESTINO",
        " PROVINCIAS",
        " SALIR AL MENU"
    };
    bool salir=false;

    while(!salir){
        setColor(WHITE);
        for(int i=0; i<7; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<7; i++){locate(73,11+i); cout << "|";}
        locate(44,10);
        cout<<"----------DESTINOS-----------"<<endl;
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

            switch(seleccion){
            case 0:
                ingresar_destino();
                break;
            case 1:
                mostrar_destino();
                break;
            case 2:
                eliminar_destino();
                break;
            case 3:
                dar_alta_destino();
                break;
            case 4:
                mostrar_provincias();
                break;
            case 5:
                salir=true;
                break;
            }
        }
    }
}

void SUBMENU_5(){
    int seleccion=0;
    const int opciones_submenu=8;
    string submenu[opciones_submenu]={
        " INGRESAR NUEVO USUARIO",
        " MOSTRAR USUARIOS",
        " MOSTRAR SESIONES",
        " DAR DE BAJA USUARIO",
        " DAR DE ALTA USUARIO",
        " CAMBIAR CONTRASEÑA",
        " CAMBIR DATOS PERSONALES",
        " MENU PRINCIPAL"
    };
    bool salir=false;

    while(!salir){
        setColor(WHITE);
        for(int i=0; i<9; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<9; i++){locate(73,11+i); cout << "|";}
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
        locate(44,20);
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

            switch(seleccion){
            case 0:
                ingresar_usuario();
                break;
            case 1:
                mostrar_usuarios();
                break;
            case 2:
                listar_ingresos();
                break;
            case 3:
                eliminar_usuario();
                break;
            case 4:
                dar_alta_usuario();
                break;
            case 5:
                cambiar_contrasena();
                break;
            case 6:
                cambiar_datos_usuario();
                break;
            case 7:
                salir=true;
                break;
            }

        }
    }
}

void SUBMENU_6(){
    int seleccion=0;
    const int opciones_submenu=8;
    string submenu[opciones_submenu]={
        " RECAUDACION POR AÑO",
        " RECAUDACION POR MICRO",
        " RECAUDACION POR DESTINO",
        " PASAJES VENDIDOS POR DESTINO EN UN MES",
        " KILOMETROS RECORRIDOS POR MICRO",
        " RECAUDACION POR GENERO EN UN AÑO",
        " VIAJES POR CHOFER EN UN MES",
        " MENU PRINCIPAL"
    };
    bool salir=false;


    while(!salir){
        setColor(WHITE);
        for(int i=0; i<9; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<9; i++){locate(86,11+i); cout << "|";}
        locate(44,10);
        cout<<"-----------------REPORTES-----------------"<<endl;
        locate(44,11);
        cout<<"------------------------------------------"<<endl;
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
        locate(44,20);
        cout<<"------------------------------------------"<<endl;
        setColor(WHITE);
        int tecla=getkey();
        if(tecla==KEY_UP){
            seleccion--;
            if(seleccion<0)seleccion=opciones_submenu-1;
        }else if(tecla==KEY_DOWN){
            seleccion++;
            if(seleccion>=opciones_submenu)seleccion=0;
        }else if(tecla==KEY_ENTER){

            switch(seleccion){
            case 0:
                por_anio();
                break;
            case 1:
                por_micro();
                break;
            case 2:
                por_provincia();
                break;
            case 3:
                cantPasajes_destino_mes();
                break;
            case 4:
                kilometros_micro();
                break;
            case 5:
                recaudacion_por_genero_anio();
                break;
            case 6:
                viajes_chofer_mes();
                break;
            case 7:
                salir=true;
                break;
            }
        }
    }
}

void SUBMENU_7(){
    int seleccion=0;
    const int opciones_submenu=4;
    string submenu[opciones_submenu]={
        " CARGAR PRECIO X BUTACA",
        " MOSTRAR PRECIO X BUTACA",
        " MODIFICAR PRECIOS",
        " MENU PRINCIPAL"
    };
    bool salir=false;


    while(!salir){
        setColor(WHITE);
        for(int i=0; i<5; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<5; i++){locate(73,11+i); cout << "|";}
        locate(44,10);
        cout<<"-----------PRECIOS-----------"<<endl;
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
        locate(44,16);
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

            switch (seleccion) {
                case 0:
                    cls();
                    cargar_precios();
                    cls();
                    break;
                case 1:
                    mostrar_precios();
                    cls();
                    break;
                case 2:
                    modificar_precios();
                    cls();
                    break;
                case 3:
                    salir = true;
                    break;
            }
        }
    }
}

void MENU(){
    int seleccion=0;
    int opcion;
    const int opciones_menu=8;
    string menu[opciones_menu]={
        " INCIAR VIAJE",
        " MICROS",
        " CHOFERES",
        " DESTINOS",
        " USUARIOS",
        " REPORTES",
        " PRECIO",
        " SALIR"
    };
    bool salir=false;

    while(!salir){
        setColor(WHITE);
        for(int i=0; i<9; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<9; i++){locate(73,11+i); cout << "|";}
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
        locate(44,20);
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
                SUBMENU_1();
                cls();
                break;
            case 1:
                SUBMENU_2();
                cls();
                break;
            case 2:
                SUBMENU_3();
                cls();
                break;
            case 3:
                SUBMENU_4();
                cls();
                break;
            case 4:
                SUBMENU_5();
                cls();
                break;
            case 5:
                SUBMENU_6();
                cls();
                break;
            case 6:
                SUBMENU_7();
                cls();
                break;
            case 7:
                salir=true;
                break;
            }
        }
    }
}

void MENU_VENTAS(){
    int seleccion=0;
    const int opciones_submenu=4;
    string submenu[opciones_submenu]={
        " VENTA DE PASAJE",
        " PASAJES VENDIDOS",
        " MOSTRAR VIAJES DISPONIBLES",
        " CERRAR SESION"
    };
    bool salir=false;

    while(!salir){
        cls();
        setColor(WHITE);
        for(int i=0; i<7; i++){locate(43,11+i); cout << "|";}
        for(int i=0; i<7; i++){locate(75,11+i); cout << "|";}
        locate(44,10);
        cout<<"--------------MENU-------------"<<endl;
        locate(44,11);
        cout<<"-------------------------------"<<endl;
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
        cout<<"-------------------------------"<<endl;
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
                venta_de_pasaje();
                anykey();
                cls();
                break;
            case 1:
                cls();
                mostrar_pasajes_vendidos();
                anykey();
                cls();
                break;
            case 2:
                cls();
                mostrar_viajes();
                anykey();
                cls();
                break;
            case 3:
                salir=true;
                break;

            }
        }
    }
}

void inicio_de_sesion(){
    Usuario usuarios;
    Archivo_usuario archivos;

    Historial_ingreso historial;
    Archivo_historial_usuario historial_usuario;

    Tiempo_Actual tiempo;

    while(true){
        mostrarCartelUTN();
        bool bandera=false;

        string id;
        while(true){
            locate(40, 20); cout<<"Ingrese ID de usuario: ";
            getline(cin, id);
            if(id.empty() or !esNumero(id) or id.length()>=9){
                LimpiarLineas(20,25,40);
                continue;
            }
            break;
        }
        int idu=stoi(id);

        string contrasena;
        while(true){
            locate(40, 23); cout<<"Ingrese contrasena: ";
            getline(cin, contrasena);
            if(contrasena.empty()){
                LimpiarLineas(23,28,40);
                continue;
            }
            break;
        }

        Fecha fecha(tiempo.getDia(), tiempo.getMes(), tiempo.getAnio());
        Hora actual;

        int contreg=archivos.contarRegistros();

        for(int i=0; i<contreg; i++){
            usuarios=archivos.leerRegistros(i);

            if(usuarios.getIdUsuario()==idu and contrasena==usuarios.getContrasena() and usuarios.getEstado()){
                historial.setIdusuario(idu);
                historial.setNombre_usuario(usuarios.getNombre());
                historial.setIngreso_sesion(fecha);
                historial.setInicio(actual);
                historial_usuario.grabarRegistro(historial);
                bandera=true;
                break;
            }
        }

        if(bandera==false){
            cls();
            locate (40, 15); setColor(RED); cout<<"USUARIO Y/O CONTRASEÑA INCORRECTA"<<endl;
            anykey();
            cls();
        }
        if(bandera){
            switch(usuarios.getNivel()){
            case 1:
                cls();
                hidecursor();
                MENU();
                bandera=true;
                break;
            case 2:
                cls();
                MENU_VENTAS();
                break;
            default:
                setColor(RED);
                locate(42, 13);
                cout << "ERROR EN LOS DATOS DEL USUARIO";
                setColor(WHITE);
                anykey();
                break;
            }
        }
    }
}

void mostrarCartelUTN(){
    setColor(GREEN);
    locate(15, 2); cout << "#####################################################################################";
    locate(15, 3); cout << "#                                                                                   #";
    locate(15, 4); cout << "#   ###       ###   ###     ######        ###     ###   ###########   ####     ##   #";
    locate(15, 5); cout << "#   ###       ###   ###    ###  ###       ###     ###   ###########   #####    ##   #";
    locate(15, 6); cout << "#    ###     ###    ###   ###    ###      ###     ###       ###       ## ###   ##   #";
    locate(15, 7); cout << "#     ###   ###     ###   ##########      ###     ###       ###       ##  ###  ##   #";
    locate(15, 8); cout << "#      ### ###      ###   ##########      ###     ###       ###       ##   ### ##   #";
    locate(15, 9); cout << "#       #####       ###   ###    ###      ###########       ###       ##    #####   #";
    locate(15,10); cout << "#        ###        ###   ###    ###      ###########       ###       ##     ####   #";
    locate(15,11); cout << "#                                                                                   #";
    locate(15,12); cout << "#                           # # #  V I A   U T N  # # #                             #";
    locate(15,13); cout << "#                                                                                   #";
    locate(15,14); cout << "#####################################################################################";
    setColor(WHITE);

    setColor(GREEN);
    locate(40, 17); cout << "======= INICIO DE SESION =======";
    setColor(WHITE);
}
