#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "MICROS.h"
#include "ARCHIVO_MICROS.h"
#include "CHOFERES.h"
#include "ARCHIVO_CHOFERES.h"
#include "USUARIOS.h"
#include "ARCHIVO_USUARIOS.h"
#include "HISTORIAL_INGRESOS.h"
#include "ARCHIVO_HISTORIAL_INGRESOS.h"
#include "DESTINOS.h"
#include "ARCHIVO_DESTINOS.h"
#include "FECHAS.h"
#include "TIEMPO_ACTUAL.h"
#include "HORA.h"
#include "PROVINCIAS.h"
#include "ARCHIVO_PROVINCIAS.h"
#include "VIAJES.h"
#include "ARCHIVO_VIAJES.h"
#include "PASAJE.h"
#include "ARCHIVO_PASAJE.h"
#include "PASAJEROS.h"
#include "ARCHIVO_PASAJEROS.h"
#include "PRECIO.h"
#include "ARCHIVO_PRECIO.h"

bool existePatente(const char *patente, int idMicroAExcluir);
void LimpiarLineas(int,int,int);
float plusxbutaca(Viajes viaje);
bool esNumero(const std::string&);
bool validar_numero();
void fecha_y_hora_fin(Destinos , Archivo_destinos , Fecha &, Hora &, Fecha , Hora , int);
bool chequearSalidaESC(std::string);
bool esFechaPosterior(Fecha, Fecha);
void cargarCadena(char *, int );
const char *funcion_provincias(int pos);
const char *funcion_provincias(int,int );
bool validarPatente(const char *);
bool validarPalabra(const char *);
bool esBisiesto(int );
int diasEnMes(int , int );
std::string nombreMes(int);
int diaSemanaPrimeroMes(int, int);
void calendario(int, int);
int viajes_disponibles();
int selecion_de_butacas(int , Micros , int );

///Funciones viajes-pasajes
void venta_de_pasaje();
void pasajes_vendidos();
void cargar_viaje();
void mostrar_viajes();

/// funcion precios
void valor_kilometro();
void cargar_precio_butaca();
void mostrar_precio_butacas();

///Funciones usuarios
void ingresar_usuario();
void mostrar_usuarios();
void eliminar_usuario();
void dar_alta_usuario();
void cambiar_contrasena();
void cambiar_datos_usuario();
void listar_ingresos();

///Funciones micros
void ingresar_Micro();
void mostrar_Micro();
void eliminar_Micro();
void dar_alta_Micro();
void cambiar_patente_Micro();
void cambiar_unidad_Micro();

///Funciones destinos-provincias
void ingresar_destino();
void mostrar_destino();
void eliminar_destino();
void dar_alta_destino();
void cargar_prvincias();
void mostar_provincias();

///Funciones choferes
void ingresar_chofer();
void mostrar_choferes();
void eliminar_chofer();
void dar_alta_chofer();
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
void SUBMENU_7();
void MENU_VENTAS();
void MENU();
void inicio_de_sesion();
void mostrarCartelUTN();
#endif // FUNCIONES_H_INCLUDED
