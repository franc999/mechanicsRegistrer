#include "ESTRUCTURASLOGICAS.h"

///******************** NODOS DOBLE ENLACE ********************///

nodoRepuesto *crearNodo2 (int dato){

    nodo2 *nuevo = (nodo2*) malloc(sizeof(nodo2));
    nuevo->sig = NULL;
    nuevo->ante = NULL;
    nuevo->dato = dato;

    return nuevo;
}

nodo2 *inicLista (nodo2 *lista){

    return NULL;
}

nodo2 *buscarUltimo (nodo2 *lista){

    nodo2 *seg = lista;
    if (lista){

        while (seg->sig){

            seg = seg->sig;
        }
    }
    return seg;
}

nodo2 *agregarPpio (nodo2 *lista, nodo2 *nuevo){

    nuevo->sig = lista;
    if (lista){

        lista->ante = nuevo;
    }
    return nuevo;
}

nodo2 *agregarFinal (nodo2 *lista, nodo2 *nuevo){

    if (lista){

        nodo2 *ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
        nuevo->ante = ultimo;
    }else{

        lista = nuevo;
    }
    return lista;
}

nodo2 *agregarOrdenado (nodo2 *lista, nodo2 *nuevo){

    if (lista){

        if (nuevo->dato < lista->dato){

            lista = agregarPpio(lista, nuevo);
        }else{

            nodo2 *seg = lista->sig;
            nodo2 *ante = lista;

            while (seg && seg->dato < nuevo->dato){

                ante = seg;
                seg = seg->sig;
            }
            ante->sig = nuevo;
            nuevo->sig = seg;
            nuevo->ante = ante;

            if (seg){

                seg->ante = nuevo;
            }
        }
    }else{

        lista = nuevo;
    }
    return lista;
}


///******************** ARBOLES BINARIOS DE BUSQUEDA ********************///

arbolCliente *inicArbol (){

    return NULL;
}

arbolCliente *crearArbol (cliente p){

    arbolCliente *aux = (arbolCliente*) malloc(sizeof (arbolCliente));
    aux->der = NULL;
    aux->izq = NULL;

    aux->usuario.celular = p.celular;
    aux->usuario.telefonoFijo = p.telefonoFijo;
    aux->usuario.realizados = p.realizados;
    aux->usuario.vehiculo = p.vehiculo;
    strcpy (aux->usuario.nombreYapellido, p.nombreYapellido);

    return aux;
}

arbolCliente *insertar ( arbolCliente *arbol , cliente p){

    if (arbol){

        if ( strcmpi ( p.nombreYapellido, arbol->usuario.nombreYapellido) > 0 ){

            arbol->der = insertar(arbol->der, p);
        }else{

            arbol->izq = insertar(arbol->izq, p);
        }
    }else{

        arbol = crearArbol(p);
    }
    return arbol;
}

arbolCliente *cargarArbolCliente (arbolCliente *arbol){

    char control = 's';
    cliente user;

    while (control == 's'){

        printf("Ingrese el nombre y apellido o un apodo\n\n"); fflush(stdin); gets(user.nombreYapellido);
        /// VERIFICACION DE NOMBREYAPELLIDO ///
        /// USUARIO ENCONTRADO, MUESTRA, DESEA REEMPLAZAR DATOS? N / S , LLAMA A MODIFICAR USUARIO ///

        /// ********************************** ///

        int opcion;
        printf("1. Ingrese un telefono fijo\n");
        printf("2. Ingrese un celular\n\n");
        printf("3. Ingrese ambos\n");
        switch (opcion){

        case 1:
            printf("\n\n*** TELEFONO FIJO ***\n\n");
            fflush(stdin); scanf("%i", &user.telefonoFijo);
        case 2:
            printf("\n\n*** CELULAR ***\n\n");
            fflush(stdin); scanf("%i", &user.celular);
        case 3:
            printf("\n\n*** TELEFONO FIJO ***\n\n");
            fflush(stdin); scanf("%i", &user.telefonoFijo);
            printf("\n\n*** CELULAR ***\n\n");
            fflush(stdin); scanf("%i", &user.celular);
        }


        arbol = insertar(arbol, per);

        printf("Desea cargar mas datos s/n\n"); fflush(stdin); scanf("%c", &control);
        system("cls");
    }
    return arbol;
}

void mostrarPosOrden (arbolCliente *arbol){

    if (arbol){

        mostrarPreOrden(arbol->izq);
        mostrarPreOrden(arbol->der);
        printf("Nombre y apellido : %s\n\n", arbol->per.nombreApellido);
        printf("Edad : %i\n\n", arbol->per.edad);
    }
}

void mostrarPreOrden (arbolCliente *arbol){

    if (arbol){

        printf("Nombre y apellido : %s\n\n", arbol->per.nombreApellido);
        printf("Edad : %i\n\n", arbol->per.edad);
        mostrarPreOrden(arbol->izq);
        mostrarPreOrden(arbol->der);
    }
}

void mostrarEnOrden (arbolCliente *arbol){

    if (arbol){

        mostrarEnOrden(arbol->izq);
        printf("Nombre y apellido : %s\n\n", arbol->per.nombreApellido);
        printf("Edad : %i\n\n", arbol->per.edad);
        mostrarEnOrden(arbol->der);
    }
}

int sumaDatosArbol (arbolCliente *arbol){

    int rta = 0;
    if (arbol){

        rta = arbol->per.edad + sumaDatosArbol(arbol->der) + sumaDatosArbol(arbol->izq);
    }
    return rta;
}

nodo *pasarDeArbolToListaVinculada (nodo *lista, arbolCliente *arbol){

    if (arbol){

        lista = agregarAlFinal(lista, crearNodoVinculado(arbol->per));
        lista = pasarDeArbolToListaVinculada(lista, arbol->izq);
        lista = pasarDeArbolToListaVinculada(lista, arbol->der);
    }

    return lista;
}

arbolCliente *buscarPorEdad (arbolCliente *arbol, int edad){

    arbolCliente *rta = NULL;
    if (arbol){

        if (arbol->per.edad == edad){

            rta = arbol;

        }else{

            if (arbol->per.edad < edad){

                rta = buscarPorEdad(arbol->der, edad);
            }else{

                rta = buscarPorEdad(arbol->izq, edad);
            }
        }
    }
    return rta;
}

persona menorDeLosMayores (arbolCliente *arbol){   /// EL MAS IZQUIERDO DE LOS SUBDERECHOS ///

    persona menor;

    if (arbol){

        if (arbol->der){

            menor = menorDeLosMayores(arbol->izq);
        }else
            menor = arbol->per;
    }
    return menor;
}

persona mayorDeLosMenores (arbolCliente *arbol){

    persona mayor;

    if (arbol){

        if (arbol->izq){

            mayor = mayorDeLosMenores(arbol->der);

        }else
        mayor = arbol->per;
    }
    return mayor;
}

arbolCliente *borrarNodo (arbolCliente *arbol, persona dato){

    if (arbol){

        if (arbol->per.edad == dato.edad){

            if (!arbol->der && !arbol->izq){

                free(arbol);
                arbol = NULL;
            }else{

                if (arbol->der){

                    arbol->per = menorDeLosMayores(arbol->der);
                    //aEliminar->per.edad = dato;
                    arbol->der = borrarNodo(arbol->der, arbol->per);
                    free(arbol->der);
                    arbol->der = NULL;
                }
                if (arbol->izq){

                    arbol->per = mayorDeLosMenores(arbol->izq);
                    //aEliminar->per.edad = dato;
                    arbol->izq = borrarNodo(arbol->izq, arbol->per);
                    free(arbol->izq);
                    arbol->izq = NULL;
                }
            }
        }else{

            if (dato.edad > arbol->per.edad)
                arbol->der = borrarNodo(arbol->der, dato);
            else
                arbol->izq = borrarNodo(arbol->izq, dato);
        }
    }
    return arbol;
}
