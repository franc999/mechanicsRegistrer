#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "MENU.h"

/// ESTRUCTURAS ///

typedef struct{

    char nombre[30];
    char distribuidor[30];
    float precio;

}repuesto;

typedef struct{

    char fecha [100];
    char diagnostico [100];       ///   lo que tiene el auto
    char trabajoArealizar [100]; ///    cuando no se realiza todo lo que se indico en el diagnostico
    char observaciones [100];   ///     detalle de garantias, del trabajo, o proxima fecha de cambios.
    float precioManoDeObra;
    struct nodoRepuesto *lista; ///     lista aparte dentro de arreglo de trabajo guarda repuesto de cada trabajo.
}celdaTrabajo;

/// CABECERA FUNCIONES ///



#endif // TRABAJO_H_INCLUDED
