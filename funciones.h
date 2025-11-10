#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargarCadena(char *palabra, int tam);

const char *funcion_provincias(int pos);

void calendario(int, int);
int viajes_disponibles();

bool validarPatente(const char *patente);
bool validarPalabra(const char *palabra);
bool esBisiesto(int anio);
//int selecion_de_butacas(int cant, Micros micro);

///Funciones viajes-pasajes
void venta_de_pasaje();
void pasajes_vendidos();
void cargar_viaje();
void mostrar_viajes();

///Funciones usuarios
void ingresar_usuario();
void mostrar_usuarios();
void eliminar_usuario();
void cambiar_contrasena();

///Funciones micros
void ingresar_Micro();
void mostrar_Micro();
void eliminar_Micro();
void cambiar_patente_Micro();
void cambiar_unidad_Micro();

///Funciones destinos-provincias
void ingresar_destino();
void mostrar_destino();
void eliminar_destino();
void cargar_prvincias();
void mostar_provincias();

///Funciones choferes
void ingresar_chofer();
void mostrar_choferes();
void eliminar_chofer();
void cambiar_mail_chofer();
void cambiar_telefeno_chofer();

///Funciones reportes
void por_anio();
void por_micro();
void por_destino();
void cantPasajes_destino_mes();
void kilometros_micro();
void por_genero_anio();
void viajes_chofer_mes();

///MENUS Y SUBMENUS
void SUBMENU_1();
void SUBMENU_2();
void SUBMENU_3();
void SUBMENU_4();
void SUBMENU_5();
void SUBMENU_6();
void MENU();
void inicio_de_sesion();
void MENU_ADMIN();
void MENU_VENTAS();

#endif // FUNCIONES_H_INCLUDED
