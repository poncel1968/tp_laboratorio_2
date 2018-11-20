#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define CANTIDAD 1000


int main()
{
    int opcion;
    int validacion;
    int auxId;
    int salir=0;
    Employee listaEmpleados[CANTIDAD];
    initEmployees(listaEmpleados, CANTIDAD);

///menu


    while(salir==0)
    {
        printf("\nMENU EMPLEADOS \n1. ALTA EMPLEADOS \n2. MODIFICACION EMPLEADOS \n3. BAJA EMPLEADOS  \n4. LISTADOS\n9. SALIR\n");
        do
        {
            validacion=utn_getInt(&opcion,2,"Ingrese una opcion del Menu : ", "Valor del menu ingresado Erroneo");
        }
        while (validacion==-1);

        switch(opcion)
        {
            case 1:
                addConsoleEmployee(listaEmpleados,CANTIDAD);
                break;
            case 2:
                if (emptyList(listaEmpleados, CANTIDAD)==0)
                {
                    editEmployee(listaEmpleados,CANTIDAD);
                }
                else
                {
                    printf("\nNo hay empleados para modificar");
                }
                break;
            case 3:
                if (emptyList(listaEmpleados, CANTIDAD)==0)
                {
                    utn_getInt(&auxId,5,"Ingrese Id de empleado a dar de Baja :","error Id");
                    removeEmployee(listaEmpleados, CANTIDAD, auxId);
                }
                else
                {
                    printf("\nNo hay empleados para dar de baja");
                }
                break;

            case 4:
                if (emptyList(listaEmpleados, CANTIDAD)==0)
                {
                    printEmployee(listaEmpleados, CANTIDAD);
                }
                else
                {
                    printf("\nNo hay empleados para listar");
                }
                break;

            case 9:
                salir=1;
                break;

            default :
                printf("Ingrese opcion correcta - 9 para Salir \n");
        }
    }
    return 0;
}
