#include "menuPRINCIPAL.h"

void borra(){
        printf("\n\n");
        system("pause");
        system("cls");
}

void salir(){
        printf("\nSaliendo del sistema . . .\n\n");
        system("pause");
}

void vuelve(){
        printf("\n\n");
        system("pause");
}

void imprimirCabecera ( char cabecera [] ){

    int i;
    printf("%c", 201);

    for(i=0;i<50;i++){
        printf("%c", 205);
    }
    printf("%c\n", 187);
    printf("%c%32s%19c\n", 186,cabecera,186);
    printf("%c", 200);

    for( i=0; i<50 ; i++ ){
        printf("%c", 205);
    }
    printf("%c", 188);
}

void imprimirOpcionesMenu1(){

    printf("1. TURNOS\n\n");
    printf("2. PACIENTE\n\n");
    printf("3. MEDICO\n\n");
    printf("4. SALA DE HABITACIONES\n");
    printf("\n0. SALIR\n\n\n");
}

void case2Paciente(){

    system("cls");
    imprimirCabecera("*** PACIENTE ***");
    printf("\n\n");
    printf("1. CONSULTAR\n\n");
    printf("2. DAR DE ALTA\n\n");
    printf("3. DAR DE BAJA\n\n");
    printf("4. MODIFICACIONES\n\n");
    printf("5. LISTADOS\n\n");
    printf("\n0. SALIR\n");
}

int case2PacienteDNI(){

    int dni;
    printf("\n\n");
    printf("Por favor ingrese su DNI\n");
    printf("\nIngrese ' 0 ' para salir\n\n");
    fflush(stdin);
    scanf("%i",&dni);
    return dni;
}


int case2PacienteModificar (){
    int opcion;
    printf("\n1. MODIFICAR UN CAMPO\n\n");
    printf("2. MODIFICAR AL PACIENTE COMPLETO\n\n");
    printf("0. SALIR\n\n");
    fflush(stdin);
    scanf("%i",&opcion);
    return opcion;

}

int case5Listados (){

    int num ;
    printf("\n1. TODOS\n\n");
    printf("\n\n2. ORDENADOS POR NOMBRE\n\n");
    printf("3. ORDENADOS POR LA CANTIDAD DE VECES QUE FUE ATENDIDO\n\n");
    printf("4. ORDENADOS POR LA CANTIDAD DE VECES QUE FUE INTERNADO\n\n");
    printf("0. SALIR\n");
    fflush(stdin);
    scanf("%i", &num);
    return num;
}

void case5Elegidos (){

    Pacientes listaDePacientes [200];

    int num = case5Listados();

    if ( num == 1 ){

            readpacs();
    }
    else{

        int validos = DeArchivoToArreglo(listaDePacientes);

        if ( num == 2 ){

            ordenaNombre(listaDePacientes, validos);
            muestraArregloDePacientes(listaDePacientes, validos);
        }
        if ( num == 3 ){

            ordenaCANTatendido(listaDePacientes, validos);
            muestraArregloDePacientes(listaDePacientes, validos);
        }
        if ( num == 4 ){

            ordenaCANTinter(listaDePacientes, validos);
            muestraArregloDePacientes(listaDePacientes, validos);
        }
        if ( num != 2 && num != 3 && num != 4){

            salir();
        }
    }
}

int ingresarOpcion(){

    int opcion;
    printf("\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%i", &opcion);
    return opcion;
}

void switchSubMenuPAC(){
    int op;
    do{
        op = ingresarOpcion();
        switch(op){
            case 0:
                salir();
                system("cls");
                imprimirCabecera("***PACIENTE***");
                printf("\n\n");
                imprimirOpcionesMenu1();
                break;
            case 1:
                {
                system("cls");
                imprimirCabecera("***BUSCAR PACIENTE***");
                int dnibusc;
                dnibusc = case2PacienteDNI();
                if ( dnibusc > 0 ){
                    dnibusc = buscaPACxDNI(dnibusc);
                    system("pause");
                }
                else{
                    salir();
                }
                }
                break;
            case 2:
                system("cls");
                imprimirCabecera("***ALTA DE PACIENTE***");
                altaPaciente();
                vuelve();
                break;
            case 3:
                {
                system("cls");
                imprimirCabecera("***BAJA DE PACIENTE***");
                int dni;
                dni = case2PacienteDNI();

                if ( dni > 0 ){

                    bajaPAC(dni);
                }
                else{
                    salir();
                }
                }
                break;
            case 4:
                {
                system("cls");
                imprimirCabecera("***MODIFICACIONES***");
                int opcion = case2PacienteModificar();
                if ( opcion == 0 ){

                    salir();
                }
                else{

                    int dni = case2PacienteDNI();
                    modificacionesPAC(opcion, dni);
                }
                }
                break;
            case 5:
                system("cls");
                imprimirCabecera("***LISTADO DE PACIENTES***");
                case5Elegidos();
                vuelve();
                break;
            default:
                printf("Opcion incorrecta\n");
                vuelve();
        }
    }while(op>5 || op<0);
}

        /// ******** MEDICOS ******** ///

void case3MEDswitch (){

    printf("\n1. DAR DE ALTA\n\n");
    printf("2. DAR DE BAJA\n\n");
    printf("3. MODIFICACIONES\n\n");
    printf("4. LISTADOS\n\n");
    printf("\n0. SALIR\n\n");
}

int case3MED (){

    int num;
    printf("\n1. MODIFICAR UN CAMPO\n\n");
    printf("2. MODIFICAR AL MEDICO COMPLETO\n\n");
    printf("0. SALIR\n\n");
    fflush(stdin);
    scanf("%i",&num);
    return num;
}

int baja (){

    int mat;
    printf("\nPOR FAVOR INGRESE LA MATRICULA DEL MEDICO\n");
    printf("\n0. SALIR\n\n");
    fflush(stdin);
    scanf("%i", &mat);

    return mat;
}

int case4MED (){

    int num;
    printf("\n\n");
    printf("\n1. VER TODOS\n");
    printf("\n2. ORDENADOS POR MATRICULA\n\n");
    printf("3. ORDENADOS POR ESPECIALIDAD\n\n");
    printf("4. CONSULTAS\n\n\n");
    printf("0. SALIR\n");
    fflush(stdin);
    scanf("%i",&num);

    return num;
}


void case4MED2 ( int num ){

    Medico lista [100];

    if ( num == 1){

        readMED();
    }
    else{

        int validos = medArchToArray(lista);
        char especialidad [30];

        if ( num == 2){

            ordenarPorMatricula(lista, validos);
            muestraArregloDeMedicos(lista,validos);
        }
        if ( num == 3){

            ordenaEspecialidadMED(lista, validos);
            muestraArregloDeMedicos(lista,validos);
        }
        if ( num == 4 ){

            int op;
            printf("\n1. CONSULTA POR ESPECIALIDAD\n\n");
            printf("2. CONSULTA POR MATRICULA\n");
            fflush(stdin);
            scanf("%i", &op);

            if ( op == 1){

                printf("INGRESE LA ESPECIALIDAD QUE DESEA CONSULTAR\n");
                fflush(stdin);
                gets(especialidad);

                printf("\nESPECIALIDAD ELEGIDA : %s", especialidad);
                borra();
                buscaESP(lista, validos, especialidad);
            }
            if ( op == 2){

                int mat;

                printf("INGRESE LA MATRICULA DEL MEDICO QUE DESEA CONSULTAR\n");
                fflush(stdin);
                scanf("%i", &mat);

                mat = buscaMED(mat);
            }
        }

        if ( num != 2 && num != 3 && num != 4){

            salir();
        }
    }
}

void switchSubMenuMED(){
    int op;
    do{
        op = ingresarOpcion();
        switch(op){
            case 0:
                salir();
                system("cls");
                imprimirCabecera("MENU PRINCIPAL");
                printf("\n\n");
                imprimirOpcionesMenu1();
                break;
            case 1:
                {
                system("cls");
                imprimirCabecera("***ALTA MEDICO***");
                altaMED();
                vuelve();
                }
                break;
            case 2:
                system("cls");
                imprimirCabecera("***BAJA MEDICO***");
                int mat = baja();
                if ( mat == 0){
                        salir();
                }
                else{
                    bajaMED(mat);
                }
                break;
            case 3:
                {
                system("cls");
                imprimirCabecera("***MODIFICACION***");
                modificarMED();
                }
                break;
            case 4:
                {
                system("cls");
                imprimirCabecera("***LISTADOS***");
                int num = case4MED();
                case4MED2(num);
                vuelve();
                }
                break;
            default:
                printf("Opcion incorrecta\n");
                vuelve();
        }
    }while(op>4 || op<0);
}




        ///     **** TURNOS ****    ///

void case1Turnos(){

    system("cls");
    imprimirCabecera("*** TURNOS ***");
    printf("\n\n");
    printf("1. DAR TURNO\n\n");
    printf("2. ATENDER PACIENTE\n\n");
    printf("3. LISTADO DE TURNOS\n\n");
    printf("\n0. SALIR\n");
}

int case1solicitarTurno(){

    int dni=0;
    system("cls");
    imprimirCabecera("*** TURNOS ***");
    printf("\n\n");
    printf("Solicitamos su DNI para verificar si esta registrado en nuestra lista de pacientes\n\n");
    printf("Por favor ingrese su DNI\n\n");
    printf("Ingrese ' 0 ' para salir\n\n");
    fflush(stdin);
    scanf("%i",&dni);

    return dni;
}

int cargaMatricula (){

    int mat;
    system("cls");
    imprimirCabecera("*** TURNOS ***");
    printf("\n\n");
    printf("POR FAVOR INGRESE LA MATRICULA DEL MEDICO\n");
    fflush(stdin);
    scanf("%i",&mat);
    return mat;
}

void listadoDeTurnos ( Turnos a [] ){
    int num;
    printf("\n1. TURNOS DE DETERMINADO DIA\n\n");
    printf("2. TURNOS POR SEMANA\n\n");
    printf("0. Salir\n");
    fflush(stdin);
    scanf("%i",&num);

    if ( num == 1 ){

        int num1;
        system("cls");
        imprimirCabecera("***TURNOS POR DIA***");
        printf("\n\n");
        printf("\nQUE LISTAS DESEA VER :\n");
        printf("\n1. DIAS LIBRES\n\n");
        printf("2. DIAS OCUPADOS\n\n");
        printf("0. SALIR\n");
        fflush(stdin);
        scanf("%i", &num1);

        if ( num1 == 1 ){

            mostrarTurnosXdia(a,0);
        }

        if ( num1 == 2 ){

            mostrarTurnosXdia(a,1);
        }
    }

    if ( num == 2 ){

        system("cls");
        int num2;
        imprimirCabecera("***TURNOS POR SEMANA***");
        printf("\n\n");
        printf("\nQUE LISTAS DESEA VER :\n\n");
        printf("\n1. DIAS LIBRES\n\n");
        printf("2. DIAS OCUPADOSn\n");
        printf("0. SALIR\n");
        fflush(stdin);
        scanf("%i", &num2);

        if ( num2 == 1 ){

            mostrarTurnosXmedico(a,0);
        }

        if ( num2 == 2 ){

            mostrarTurnosXmedico(a,1);
        }
    }
}

void switchSubMenuTURNOS(){
    int op;
    do{
        op = ingresarOpcion();
        switch(op){
            case 0:
                salir();
                system("cls");
                imprimirCabecera("***MENU PRINCIPAL***");
                printf("\n\n");
                imprimirOpcionesMenu1();

                break;
            case 1:
                system("cls");
                imprimirCabecera("***DAR TURNO***");
                char control = 's';
                int dni = case1solicitarTurno();
                int comprueba = buscaPACxDNI(dni);
                    if( comprueba == -1 ){

                        printf("\n\nPaciente inexistente, Desea registrarlo s/n :\n");
                        fflush(stdin);
                        scanf("%c",&control);
                        if ( control == 's'){

                            altaPaciente();
                            printf("\n\nEl paciente fue registrado satisfactoriamente.");
                        }
                    }
                    else{
                        system("pause");
                    }
                if ( comprueba > 0 ){
                        int matri = cargaMatricula();
                        Medico med;
                        muestraArregloDeTurnos(med.listaTurnos, matri, comprueba);
                }
                vuelve();
                break;
            case 2:
                system("cls");
                imprimirCabecera("***ATENDER PACIENTE***");
                AtenderTurno(comprueba);
                vuelve();
                break;
            case 3:
                {
                system("cls");
                imprimirCabecera("***LISTADO DE TURNOS***");
                Medico med;
                listadoDeTurnos(med.listaTurnos);
                vuelve();
                }
                break;
            default:
                printf("Opcion incorrecta\n");
                vuelve();
        }
    }while(op>3 || op<0) ;
}




        /// ******** HABITACIONES ******** ///

void caseHabitaciones (){

    printf("\n1. VER TODAS LAS HABITACIONES\n");
    printf("2. VER HABITACIONES OCUPADAS POR PISO\n");
    printf("3. VER HABITACIONES LIBRES POR PISO\n");
    printf("4. DAR DE ALTA UN PACIENTE INTERNADO\n");
    printf("0. SALIR\n");
}

void switchSubMenuINTER(){
    int op;
    do{
        op = ingresarOpcion();
        switch(op){
            case 0:
                salir();
                system("cls");
                imprimirCabecera("***MENU PRINCIPAL***");
                printf("\n\n");
                imprimirOpcionesMenu1();
                break;
            case 1:
                system("cls");
                imprimirCabecera("*** TODAS LAS HABITACIONES ***");
                readMAT();
                vuelve();
                break;
            case 2:
                system("cls");
                imprimirCabecera("*** HABITACIONES OCUPADAS ***");
                printf("\n\n");
                verHabitacionesOcupadas();
                vuelve();
                break;
            case 3:
                {
                system("cls");
                imprimirCabecera("*** HABITACIONES LIBRES ***");
                verHabitacionesDisponibles();
                vuelve();
                }
                break;
            case 4:
                system("cls");
                imprimirCabecera("*** DAR DE ALTA AL PACIENTE ***");
                darAltaPorHAB();
                vuelve();
                break;
            default:
                printf("Opcion incorrecta\n");
                vuelve();
        }
    }while(op>5 || op<0);
}

int switchMenu(){
    int op;
    do{
        op = ingresarOpcion();
        switch(op){
            case 0:
                salir();
                break;
            case 1:
                system("cls");
                imprimirCabecera("MENU PRINCIPAL");
                printf("\n\n");
                case1Turnos();
                switchSubMenuTURNOS();

                break;
            case 2:
                system("cls");
                imprimirCabecera("MENU PRINCIPAL");
                printf("\n\n");
                case2Paciente();
                switchSubMenuPAC();

                break;
            case 3:
                system("cls");
                imprimirCabecera("MENU PRINCIPAL");
                printf("\n\n");
                case3MEDswitch();
                switchSubMenuMED();
                break;
            case 4:
                system("cls");
                imprimirCabecera("MENU PRINCIPAL");
                printf("\n\n");
                caseHabitaciones();
                switchSubMenuINTER();
                break;
            default:
                printf("OPCION INCORRECTA, INGRESE NUEVAMENTE\n\n");
                vuelve();
        }
    }while(op >4 || op <0);
    return op;
}

void iniciarMenu(){
    int salida;
    do{
        system("cls");
        imprimirCabecera("MI MENU PRINCIPAL");
        printf("\n\n");
        imprimirOpcionesMenu1();
        salida = switchMenu();
    }while(salida != 0);
}
