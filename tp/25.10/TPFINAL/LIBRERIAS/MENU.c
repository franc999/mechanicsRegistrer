#include "MENU.h"

int IngresaOpcion()
{
    int opcion;
    printf("Ingrese una opcion:\n");
    scanf("%i",&opcion);

    return opcion;
}
void imprimirOpcionesMenu1(){
    printf("1. CARGAR TRABAJO\n");
    printf("2. CLIENTE\n");
    printf("3. LISTADOS\n");
    printf("4. CALCULOS\n");
    printf("0. Salir\n\n");
}

void iniciarMenu()
{
    int salida;
    do
    {
        system("cls");
        ImpCabecera("MENU PRINCIPAL");
        printf("\n\n");
        imprimirOpcionesMenu1();
        salida=SwitchMenu();
    }while(salida!=0);
}

void ImpCabecera(char cabecera[])
{
    int i;
    printf("%c", 201);
    for(i=0;i<50;i++){
        printf("%c",205);
    }
    printf("%c\n", 187);
    printf("%c%32s%19c\n", 186,cabecera,186);
    printf("%c", 200);
    for(i=0;i<50;i++){
        printf("%c",205);
    }
    printf("%c", 188);
}

int DNICliente()
{
    float dni;
    printf("Ingrese el dni del cliente:");
    scanf("%f",dni);

    return dni;
}


void switchSubMenuTrabajo()
{
    int op;
    do
    {
        op=IngresaOpcion();
        switch(op)
        {

        case 0:

            //salir();
            system("cls");
            ImpCabecera("MENU PRINCIPAL");
            printf("\n\n");
            imprimirOpcionesMenu1();
            break;
        case 1:
            system("cls");
            ImpCabecera("**TRABAJO**");
            ///INGRESAR NOMBRE CLIENTE
            ///
        //    vuelve();
            break;
        case 2:
            system("cls");
            ImpCabecera("CLIENTE");
            printf("\n\n");
            // caseCliente();
            //SwitchSubMenuCliente();
            break;
        case 3:
            system("cls");
            ImpCabecera("LISTADOS");
            printf("\n\n");
            //caseListados();
            //SwitchSubMenuListados();
            break;
        case 4:
            system("cls");
            ImpCabecera("CALCULOS");
            printf("\n\n");
            //caseCalculos();
            //SwitchSubMenuCalc();
            break;
        default:
            printf("OPCION INCORRECTA, VUELVA A INTENTARLO.\n\n");
            //vuelve();

        }
    }
    while(op>0 || op<5);
    return op;
}

int SwitchMenu()
{
    int op;
    do
    {
        op=IngresaOpcion();
        switch(op)
        {

        case 0:
            printf("hola");
            //salir();
            break;
        case 1:
            system("cls");
            ImpCabecera("TRABAJO");
            printf("\n\n");
            //caseTrabajo();
            //SwitchSubMenuTrabajo();
            break;
        case 2:
            system("cls");
            ImpCabecera("CLIENTE");
            printf("\n\n");
            // caseCliente();
            //SwitchSubMenuCliente();
            break;
        case 3:
            system("cls");
            ImpCabecera("LISTADOS");
            printf("\n\n");
            //caseListados();
            //SwitchSubMenuListados();
            break;
        case 4:
            system("cls");
            ImpCabecera("CALCULOS");
            printf("\n\n");
            //caseCalculos();
            //SwitchSubMenuCalc();
            break;
        default:
            printf("OPCION INCORRECTA, VUELVA A INTENTARLO.\n\n");
            //vuelve();

        }
    }
    while(op>0 || op<5);
    return op;


}
