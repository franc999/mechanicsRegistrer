#ifndef CLIENTEAUTOS_H_INCLUDED
#define CLIENTEAUTOS_H_INCLUDED

#include "MENU.h"
#include "TRABAJO.h"

/// ESTRUCTURAS ///

typedef struct{

    char marca [30];
    char modelo [30];
    char patente [15];
}automovil;

typedef struct{

    char nombreYapellido[50];
    int telefonoFijo;
    int celular;
    automovil vehiculo;
    celdaTrabajo realizados;

}cliente;

/// CABECERA FUNCIONES ///

#endif // CLIENTEAUTOS_H_INCLUDED
