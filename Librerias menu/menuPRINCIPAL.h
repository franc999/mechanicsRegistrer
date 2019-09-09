#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include <strings.h>
#include "Paciente.h"
#include "Medicos.h"
#include "Turnos.h"
#include "Habitaciones.h"

/// ******* PRINCIPALES ******* ///

void iniciarMenu();
int ingresarOpcion();
void imprimirCabecera(char cabecera[]);
int switchMenu();

/// PRIMERAS OPCIONES A LA VISTA DEL MENU.
void imprimirOpcionesMenu1();

/// EXPLICITAS.
void borra();
void salir();
void vuelve();


/// ******* SUBMENUS ******* ///

void switchSubMenuPAC();        /// PACIENTES
void switchSubMenuMED();        /// MEDICOS
void switchSubMenuTURNOS();     /// TURNOS
void switchSubMenuINTER();      /// INTERNACION



/// ******* PACIENTES ******* ///

/// MENU PRINCIPAL DE PACIENTES.
void case2Paciente();

/// PIDE Y RETORNA UN DNI.
int case2PacienteDNI();

/// MENU DE OPCIONES DE MODIFICACION PARA CASE : 4 DE PACIENTES, RETORNA LA OPCION ELEGIDA.
int case2PacienteModificar ();

/// MENU DE LISTADOS PARA CASE : 5 DE PACIENTES, RETORNA OPCION ELEGIDA.
int case5Listados ();

/// INCLUYE A LA FUNCION ANTERIOR, Y LAS FUNCIONES DE MOSTRAR ORDENADAS DENTRO DE ELLA.
void case5Elegidos ();



/// ******* MEDICOS ******* ///

/// MENU PRINCIPAL DE MEDICOS.
void case3MEDswitch ();

/// MENU DE OPCIONES DE MODIFICACION PARA CASE : 3 DE MEDICOS, RETORNA OPCION ELEGIDA.
int case3MED();

/// PIDE MATRICULA DE MEDICO, Y RETORNA LA MATRICULA INGRESADA.
int baja();

/// MENU DE CONSULTA DE MEDICOS, RETORNA LA OPCION ELEGIDA.
int consultasMED();

/// MENU DE LISTADOS DE MEDICO, POR ORDENAMIENTOS,  CASE : 4, RETORNA OPCION ELEGIDA.
int case4MED();

/// MENU QUE INCLUYE FUNCION ANTERIOR, Y LAS FUNCIONES DE ORDENAMIENTO PARA LUEGO MOSTRAR.
void case4MED2(int num);



/// ******* TURNOS ******* ///

/// MENU PRINCIPAL DE TURNOS.
void case1Turnos();

/// PIDE DNI DE PACIENTE Y RETORNA.
int case1solicitarTurno();

/// PIDE MATRICULA DE MEDICO Y RETORNA.
int cargaMatricula();

/// LISTADO DE TURNOS , INCLUYE SUS FUNCIONES.
void listadoDeTurnos(Turnos a[]);

Habitacion ma[5][10];

#endif // MENUPRINCIPAL_H_INCLUDED
