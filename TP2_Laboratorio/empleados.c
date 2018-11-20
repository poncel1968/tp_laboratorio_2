
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"



static int getNextId();

/*
@brief : otroga un numero usado para id secuencial creciente
@value : numero id
*/
static int getNextId()
{
    static int newId = 0;
    return newId++;

}

/*
@brief : alta de cliente
@param : array con estructura de clientes
@param : tamaño array anterior:
@value : id is successful ;-1 error
*/
int empleado_alta(cliente* nuevoCliente,int limitearray)
{
    char nombre[50];
    char apellido[50];
    char cuit[13];
    int i;
    int flag=0;
    int retorno=-1;

    for(i=0;i<limitearray;i++)
    {
        if(nuevoCliente[i].isEmpty==1)
        {
            flag=1;
            break;
         }
    }
    if (i==(limitearray-1))
    {
        printf("No hay lugar para nuevos clientes \n");
    }

    if (flag==1 && utn_getNombre(nombre,50,"Ingrese nombre cliente : ")== 0 &&
    utn_getNombre(apellido,50,"Ingrese Apellido cliente : ")== 0 &&
    utn_getString(cuit,13,"Ingrese CUIT Cliente : ","Error CUIT")==0)
    {

        strncpy(nuevoCliente[i].nombre,strupr(nombre),(strlen(nombre)));
        strncpy(nuevoCliente[i].apellido,strupr(apellido),(strlen(apellido)));
        strncpy(nuevoCliente[i].cuit,cuit,(strlen(cuit)));
        nuevoCliente[i].isEmpty=0;
        nuevoCliente[i].id=getNextId();
        retorno=nuevoCliente[i].id;
    }
    else
    {
        printf("Error Alta Cliente");
    }
return retorno;
}
/*
@brief : inicializa valores isEmpty del array
@param : array de la estructura
@param : limite de la estructura
@value : 0 is successful
*/
int clientes_init(cliente* cliente,int limitearray)
{
    int i;
    for(i=0;i<limitearray;i++)
    {
    cliente[i].isEmpty = 1;
    }
return 0;

}
/*
@brief : modificacion elemento del array
@param : array de la estructura
@param : limite de la estructura
@value : 0 is successful
*/
int clientes_modificar(cliente* array,int limite)
{
    char nombre[50];
    char apellido[50];
    char cuit[13];
    int i;
    int flag=0;
    int retorno=-1;
    int idBuscado;

    printf("\nIngrese Id a Modificar :");
    utn_getInt(&idBuscado,5,"\nIngrese Id a Modificar\n","\nError Id ingresado \n");
    printf("\nEligio id %d \n",idBuscado);

    for (i=0;i<limite;i++)
    {
        if (array[i].id==idBuscado && array[i].isEmpty==0)
        {
            flag=1;
            printf("Id encontrado\n");
            break;
        }
    }
    if (flag==1 && utn_getNombre(nombre,50,"Ingrese nombre cliente : ")== 0 &&
    utn_getNombre(apellido,50,"Ingrese Apellido cliente : ")== 0 &&
    utn_getString(cuit,13,"Ingrese CUIT Cliente : ","Error CUIT")==0)
    {

        strncpy(array[i].nombre,nombre,(strlen(nombre)));
        strncpy(array[i].apellido,apellido,(strlen(apellido)));
        strncpy(array[i].cuit,cuit,(strlen(cuit)));
        retorno=0;

    }
    else
    {
        printf("\nError Modificacion Cliente\n");
    }

return retorno;

 }
/*
@brief : Baja de cliente ((vuelve isEmpty a 1)
@param : array de la estructura
@param : limite de la estructura
@param : id cliente a dar de baja
@value : 0 is successful
*/
int clientes_baja(cliente* array,int limite, int idClienteBuscado)
{
    int i;
    int flag=0;
    int retorno=-1;
    int confirmacionBaja;
    for (i=0;i<limite;i++)
    {
        if (array[i].id==idClienteBuscado && array[i].isEmpty==0)
        {
            flag=1;
            utn_getInt(&confirmacionBaja,5,"\nPara confirmar la baja pulse 9 :","Error opcion");
            break;
        }
    }
    if (flag==1 && confirmacionBaja==9)
    {
        array[idClienteBuscado].isEmpty=1;
        printf("Baja procesada del Id %d",idClienteBuscado);
        retorno=0;
    }
    else
    {
        printf("\nLa Baja de Cliente no se proceso\n");
    }
return retorno;

 }
 /*
@brief : retorna 0 si halla el id buscado
@param : array de la estructura
@param : limite de la estructura
@param : id cliente a buscar
@value : 0 is successful
*/
 int clientes_existeId(cliente* array, int limite, int idBuscar)
{
    int retorno =-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if (array[i].id == idBuscar)
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
 /*
@brief : alta forzada de clientes para pruebas
@param : array de la estructura
@param : limite de la estructura
@param : nombre a ingresar en el alta, dato de la estructura
@param : aprellido a ingresar en el alta, dato de la estructura
@param : cuit a ingresar en el alta, dato de la estructura
@value : 0 is successful
*/
 int clientes_filler(cliente* array, int limite, char* nombre, char* apellido, char* cuit )
{

