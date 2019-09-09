#ifndef ESTRUCTURASLOGICAS_H_INCLUDED
#define ESTRUCTURASLOGICAS_H_INCLUDED

#include "MENU.h"
#include "CLIENTEAUTOS.h"
#include "TRABAJO.h"

///******************** NODOS       DOBLE     ENLACE ********************///

typedef struct{

    repuesto r;
    struct nodo2 *ante;
    struct nodo2 *sig;
}nodoRepuesto;

///******************** ARREGLO       DE      LISTAS *********************///



///******************** ARBOLES BINARIOS DE BUSQUEDA ********************///


/// ESTRUCTURAS ///

typedef struct{

    cliente usuario;
    struct arbolCliente *izq;
    struct arbolCliente *der;
}arbolCliente;

/// CABECERA FUNCIONES ///

arbolCliente *inicArbol ();
arbolCliente *crearArbol (cliente c);
arbolCliente *insertar ( arbolCliente *arbol , cliente c);
arbolCliente *cargarArbolBusqueda (arbolCliente *arbol);

void mostrarEnOrden (arbolCliente *arbol);
void mostrarPreOrden (arbolCliente *arbol);
void mostrarPosOrden (arbolCliente *arbol);

int sumaDatosArbol (arbolCliente *arbol);

#endif // ESTRUCTURASLOGICAS_H_INCLUDED
