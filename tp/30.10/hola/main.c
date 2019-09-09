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

int IngresaOpcion()
{
    int opcion;
    printf("Ingrese una opcion:\n");
    scanf("%i",&opcion);

    return opcion;
}

void iniciarMenu()
{
    int salida;
    do
    {
        system("cls");
        ImpCabecera("MENU PRINCIPAL");
        printf("\n\n");
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
    int dni;
    printf("Ingrese el dni del cliente:");
    scanf("%i",dni);

    return dni;
}
int SwitchMenu()
{
    int flag=1;
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
            flag=0;
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
            SwitchSubMenuCliente();
            break;
        case 3:
            system("cls");
            ImpCabecera("**LISTADOS**");
            printf("\n\n");
            SwitchSubMenuListados();
            break;
        case 4:
            system("cls");
            ImpCabecera("**CALCULOS**");
            printf("\n\n");
            system("pause");
            //caseCalculos();
            //SwitchSubMenuCalc();
            break;
        default:
            printf("OPCION INCORRECTA, VUELVA A INTENTARLO.\n\n");
        }
    }
    while((op>0 && op<5)&&flag==1);

    return op;

}

void SwitchSubMenuCliente()
{
    int flag=1;
    int op;
    do
    {
        printf("1. DAR DE ALTA\n");
        printf("2. DAR DE BAJA\n");
        printf("3. MODIFICACIONES\n");
        printf("0. Salir\n\n");

        op=IngresaOpcion();
        switch(op)
        {

        case 0:
            salir();
            ImpCabecera("MENU PRINCIPAL");
            printf("\n\n");
            flag=0;
            //  SwitchMenu();
            break;
        case 1:
            system("cls");
            ImpCabecera("**ALTA**");
            ///INGRESAR DNI CLIENTE
            ///
            //vuelve();
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
            SwitchSubMenuModificar();
            break;
        default:
            printf("OPCION INCORRECTA, VUELVA A INTENTARLO.\n\n");
        }
    }
    while((op>0 && op<4)||flag==1);
}

void SwitchSubMenuModificar()
{
    int flag=1;
    int op;
    do
    {
        printf("1. AUTO \n");
        printf("2. TELEFONO FIJO \n");
        printf("3. CELULAR \n");
        printf("0. Salir\n\n");
        op=IngresaOpcion();
        switch(op)
        {

        case 0:

            salir();
            flag=0;
            ImpCabecera("MENU PRINCIPAL");
            printf("\n\n");
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
        }
    }
    while((op>0 && op<4)||flag==1);

}

void SwitchSubMenuListados()
{
    int flag=1;
    int op;
    do
    {
        printf("1. POR NOMBRE\n");
        printf("2. FRECUENCIA DEL CLIENTE\n");
        printf("3. POR PATENTE\n");
        printf("0. Salir\n\n");

        op=IngresaOpcion();
        switch(op)
        {

        case 0:
            salir();
            ImpCabecera("MENU PRINCIPAL");
            printf("\n\n");
            flag=0;
            break;
        case 1:
            system("cls");
            ImpCabecera("**MOSTRAR NOMBRES**");
            printf("\n\n");
            caseMostrar();
            break;
        case 2:
            system("cls");
            ImpCabecera("**MEJORES CLIENTES**");
            printf("\n\n");
            caseMostrar();

            break;
        case 3:
            system("cls");
            ImpCabecera("**MOSTRAR PATENTES**");
            printf("\n\n");
            caseMostrar();
            break;
        default:
            printf("OPCION INCORRECTA, VUELVA A INTENTARLO.\n\n");
        }
    }
    while((op>0 && op<4)&&flag==1);
}

void SwitchSubMenuNombre()
{
    int flag=1;
    int op;
    do
    {
        system("cls");
        printf("1. POR NOMBRE\n");
        printf("2. FRECUENCIA DEL CLIENTE\n");
        printf("3. POR PATENTE\n");
        printf("0. Salir\n\n");

        op=IngresaOpcion();
        switch(op)
        {

        case 0:
            salir();
            ImpCabecera("MENU PRINCIPAL");
            printf("\n\n");
            flag=0;
            //  SwitchMenu();
            break;
        case 1:
            system("cls");
            ImpCabecera("**MOSTRAR NOMBRES**");
            printf("\n\n");
            caseMostrar();
            break;
        case 2:
            system("cls");
            ImpCabecera("**MEJORES CLIENTES**");
            printf("\n\n");
            caseMostrar();

            break;
        case 3:
            system("cls");
            ImpCabecera("**MOSTRAR PATENTES**");
            printf("\n\n");
            caseMostrar();
            SwitchSubMenuModificar();
            break;
        default:
            printf("OPCION INCORRECTA, VUELVA A INTENTARLO.\n\n");
        }
    }
    while((op>0 && op<4)||flag==1);
}

void caseModificar2()
{
    printf("1. AGREGAR \n");
    printf("2. ELIMINAR \n");
    printf("0. SALIR\n\n");
    system("pause");
}
void caseMostrar()
{
    printf("1. PREORDER\n");
    printf("2. INORDER\n");
    printf("3. POSTORDER\n");
    printf("0. Salir\n\n");
    system("pause");
    system("cls");
}



int main()
{
    iniciarMenu();
    return 0;
}
