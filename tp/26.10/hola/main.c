#include <stdio.h>
#include <stdlib.h>

void borra()
{
    printf("\n");
    system("cls");
}

void salir()
{
    system("cls");
}

void vuelve()
{
    printf("\n");

}

int IngresaOpcion()
{
    int opcion;
    printf("Ingrese una opcion:\n");
    scanf("%i",&opcion);

    return opcion;
}
void imprimirOpcionesMenu1()
{
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
        // imprimirOpcionesMenu1();
        salida=SwitchMenu();
    }
    while(salida!=0);
}

void ImpCabecera(char cabecera[])
{
    int i;
    printf("%c", 201);
    for(i=0; i<50; i++)
    {
        printf("%c",205);
    }
    printf("%c\n", 187);
    printf("%c%32s%19c\n", 186,cabecera,186);
    printf("%c", 200);
    for(i=0; i<50; i++)
    {
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
int SwitchMenu()
{
    int op;
    do
    {
        printf("1. CARGAR TRABAJO\n");
        printf("2. CLIENTE\n");
        printf("3. LISTADOS\n");
        printf("4. CALCULOS\n");
        printf("0. Salir\n\n");

        op=IngresaOpcion();
        switch(op)
        {

        case 0:
            salir();
            break;
        case 1:
            system("cls");
            ImpCabecera("**TRABAJO**");     ///FALTA ING DNI
            printf("\n\n");
            system("pause");

            break;
        case 2:
            system("cls");
            ImpCabecera("**CLIENTE**");
            printf("\n\n");
            //caseCliente();
            SwitchSubMenuCliente();
            break;
        case 3:
            system("cls");
            ImpCabecera("**LISTADOS**");
            printf("\n\n");
            //caseListados();
            //SwitchSubMenuListados();
            break;
        case 4:
            system("cls");
            ImpCabecera("**CALCULOS**");
            printf("\n\n");
            //caseCalculos();
            //SwitchSubMenuCalc();
            break;
        default:
            printf("OPCION INCORRECTA, VUELVA A INTENTARLO.\n\n");
            vuelve();

        }
    }
    while(op>0 || op<5);
    return op;


}

void SwitchSubMenuCliente()
{
    int op;
    do
    {
        system("cls");
        ImpCabecera("**CLIENTE**");
        printf("\n\n");
        printf("1. DAR DE ALTA\n");
        printf("2. DAR DE BAJA\n");
        printf("3. MODIFICACIONES\n");
        printf("0. SALIR\n\n");

        op=IngresaOpcion();
        switch(op)
        {

        case 0:

            salir();
            system("cls");
            ImpCabecera("MENU PRINCIPAL");
            printf("\n\n");
            SwitchMenu();
            break;
        case 1:
            system("cls");
            ImpCabecera("**ALTA**");
            ///INGRESAR DNI CLIENTE
            ///
            vuelve();
            break;
        case 2:
            system("cls");
            ImpCabecera("**BAJA**");
            printf("\n\n");

            break;
        case 3:
            system("cls");
            ImpCabecera("**MODIFICAR**");
            printf("\n\n");
            //caseModificar();
            SwitchSubMenuModificar();
            break;
        default:
            printf("OPCION INCORRECTA, VUELVA A INTENTARLO.\n\n");
            vuelve();

        }
    }
    while((op>0 || op<4));
    //return op;
}

void SwitchSubMenuModificar()
{
    int op;
    do
    {
        system("cls");
        ImpCabecera("**MODIFICAR**");
        printf("\n\n");
        printf("1. AUTO \n");
        printf("2. TELEFONO FIJO \n");
        printf("2. CELULAR \n");
        printf("0. SALIR\n\n");
        op=IngresaOpcion();
        switch(op)
        {

        case 0:

            salir();
            system("cls");
            ImpCabecera("MENU PRINCIPAL");
            printf("\n\n");
            SwitchMenu();
            break;
        case 1:
            system("cls");
            ImpCabecera("**MODIFICAR AUTO**");

            caseModificar2();
            break;
        case 2:
            system("cls");
            ImpCabecera("**MODIFICAR TELEFONO**");
            printf("\n\n");

            caseModificar2();
            break;
        case 3:
            system("cls");
            ImpCabecera("**MODIFICAR CELULAR**");
            printf("\n\n");

            caseModificar2();
            break;
        default:
            printf("OPCION INCORRECTA, VUELVA A INTENTARLO.\n\n");
            vuelve();

        }
    }
    while(op>0 || op<4);
    return op;
}




/*void caseCliente()
{

    system("cls");
    ImpCabecera("**CLIENTE**");
    printf("\n\n");
    printf("1. DAR DE ALTA\n");
    printf("2. DAR DE BAJA\n");
    printf("3. MODIFICACIONES\n");
    printf("0. SALIR\n\n");
}
*/
void caseModificar2()
{

    system("cls");
    ImpCabecera("**MODIFICAR**");
    printf("\n\n");
    printf("1. AGREGAR \n");
    printf("2. ELIMIAR \n");
    printf("0. SALIR\n\n");
    system("pause");
}/*

void caseModificar()
{

    system("cls");
    ImpCabecera("**MODIFICAR**");
    printf("\n\n");
    printf("1. AUTO \n");
    printf("2. TELEFONO FIJO \n");
    printf("2. CELULAR \n");
    printf("0. SALIR\n\n");
}*/

int main()
{
    iniciarMenu();
    return 0;
}
