#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"


/*
@brief : otroga un numero usado para id secuencial creciente
@return : numero id
*/
static int getNextId()
{
    static int newId = 0;
    return newId++;

}

/*
* \brief inicializa el elemento isEmpty del array
* \param array a se inicializado
* \param extension del array
* \return -1 si hay error , 0 si se pudo ejecutar correctamente
*/

int initEmployees(Employee* list, int len)
{
    int retorno =-1;
    int i;
    if (len >=0 && list != NULL)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty = 1;
            list[i].salary=0;
        }
        retorno = 0;
    }
    return retorno;
}

/*
* \brief da de alta un empleado con datos ya validados
* \param array empleados
* \param extension del array
* \param id del empleado
* \param nombre del empleado
* \param salario del empleado
* \param sector del empleado
* \return -1 si hay error , 0 si se pudo ejecutar correctamente
*/


int addEmployee(Employee* list,int len, int id, char name[],char lastName[], float salary, int sector)
{
  int retorno =-1;
  int indice=findEmployeeIsEmpty(list,len);

    if( list != NULL && len > 0 && indice >=0)
    {
        list[indice].id=id;
        list[indice].isEmpty=0;
        strncpy(list[indice].lastName,lastName,51);
        strncpy(list[indice].name,name,51);
        list[indice].salary=salary;
        list[indice].sector=sector;
        retorno=0;
    }

  return retorno;
}
/*
* \brief toma datos por consola y da de alta un empleado
* \param array empleados
* \param extension del array
* \param nombre del empleado
* \param apellido del empleado
* \param salario del empleado
* \param sector del empleado
* \return -1 si hay error , 0 si se pudo ejecutar correctamente
*/

int addConsoleEmployee(Employee* list,int len)
{
    int retorno=-1;
    int auxId;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    int auxIndex;

  if (utn_getString(auxName,51,"Ingrese nombre del empleado : ","Error al ingresar nombre empleado")==0 &&
      utn_getString(auxLastName,51,"Ingrese apellido del empleado : ","Error al ingresar apellido empleado")==0 &&
      utn_getFloat(&auxSalary,10,"Ingrese sueldo del empleado : ","Error sueldo empleado")==0 &&
      utn_getInt(&auxSector,10,"Ingrese sector del empleado :", "Error sector empleado")==0)
        {
        auxId=getNextId();
        addEmployee(list,len,auxId,auxName,auxLastName,auxSalary, auxSector);
        auxIndex=findEmployeeById(list, len, auxId);
        printf("\n** Empleado dado de alta id : %d \n",list[auxIndex].id);
        printf(">> %s, %s \n",list[auxIndex].name,list[auxIndex].lastName);
        printf(">> Sueldo : %f , Sector : %d \n",list[auxIndex].salary,list[auxIndex].sector);
        retorno=0;
        }
    return retorno;
}


/*
* \brief busca un empleado por el dato id
* \param array empleados
* \param extension del array
* \return -1 si hay error , o el indice del elemento asociado a ese id
*/

int findEmployeeById(Employee* list, int len, int id)
{
    int retorno=-1;
    int i;
    for (i=0;i<len;i++)
    {
        if (list[i].id == id )
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

/*
* \brief busca un lugar vacio en la lista
* \param array empleados
* \param extension del array
* \return -1 si hay error , o el primer indice vacio si se pudo ejecutar correctamente
*/

int findEmployeeIsEmpty(Employee* list, int len)
{
    int retorno=-1;
    int i;
    for (i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            retorno= i;
            break;
        }
    }

    return retorno;
}

/*
* \brief busca un empleado por id y realiza una baja logica
* \param array empleados
* \param extension del array
* \param id del elemento a dar de baja
* \return -1 si hay error , o el primer indice vacio si se pudo ejecutar correctamente
*/

int removeEmployee(Employee* list, int len, int id)
{
    int retorno=-1;
    int indice = findEmployeeById(list,len, id);

    if(indice !=-1)
    {
        list[indice].isEmpty=1;
        retorno=0;
    }
    else
    {
        printf("Id Inexistente - BAJA");
    }
    return retorno;
}


/*
@brief : lista empleados por orden del apellido y sector
@param : array de la estructura
@param : limite de la estructura
@param : 0 orden ascendente 1 orden descendente
@value : 0 is successful
*/

int sortEmployee(Employee* list, int len,int order)
{
int  j;
int flag=1;
int retorno=-1;

if (list != NULL && order>-1 && order<2)
{
    retorno=0;
}
while (flag==1 && retorno==0)
{
    flag=0;
    for (j = 1; j < len; j++)
    {
        if (strcmp(list[j-1].lastName,list[j].lastName)>0 && order ==0 )
        {
            swapEmployee(list,j);
            flag=1;
        }
        else if(strcmp(list[j-1].lastName,list[j].lastName)==0 && list[j-1].sector > list[j].sector && order ==0)
        {
            swapEmployee(list,j);
            flag=1;
        }
        if (strcmp(list[j-1].lastName,list[j].lastName)<0 && order ==1 )
        {
            swapEmployee(list,j);
            flag=1;
        }
        else if(strcmp(list[j-1].lastName,list[j].lastName)==0 && list[j-1].sector < list[j].sector && order ==1)
        {
            swapEmployee(list,j);
            flag=1;
        }


    }
}
return retorno;
}

/*
@brief : intercambia datos de dos elementos consecutivos de la lista/auxiliar de para ordenar
@param : indice del elemento que se intercambiara con el anterior
@return : 0 is successful , -1 error
*/

int swapEmployee(Employee* list, int index)
{
    int retorno=-1;
    Employee aux;
    if (list != NULL && index >-1)
    {

        strncpy(aux.name,list[index].name,50);
        strncpy(aux.lastName,list[index].lastName,50);
        aux.salary=list[index].salary;
        aux.id=list[index].id;
        aux.isEmpty=list[index].isEmpty;
        aux.sector=list[index].sector;

        strncpy(list[index].name,list[index-1].name,50);
        strncpy(list[index].lastName,list[index-1].lastName,50);
        list[index].salary=list[index-1].salary;
        list[index].id=list[index-1].id;
        list[index].isEmpty=list[index-1].isEmpty;
        list[index].sector=list[index-1].sector;

        strncpy(list[index-1].name,aux.name,50);
        strncpy(list[index-1].lastName,aux.lastName,50);
        list[index-1].salary=aux.salary;
        list[index-1].id=aux.id;
        list[index-1].isEmpty=aux.isEmpty;
        list[index-1].sector=aux.sector;
        retorno=0;

    }

    return retorno;
}

/*
@brief : imprime lista de empleados
@param : array de la estructura
@param : limite de la estructura
@value : 0 is successful -1 error
*/

int printEmployee(Employee* list, int length)
{
    int retorno=-1;
    int i;
    float totalSalario=0;
    int cantSalarios=0;
    int cantSalariosMayor=0;
    float promedio;

    if (list != NULL && length>=0)
    {
        for (i=0;i<length;i++)
        {
            if(list[i].isEmpty==0)
            {
                printf("Id : %d \n",list[i].id);
                printf("Nombre : %s \n",list[i].name);
                printf("Apellido : %s \n",list[i].lastName);
                printf("Salario : %f \n", list[i].salary);
                printf("Sector : %d \n",list[i].sector);
                printf("-------------------------\n");
                totalSalario=totalSalario+list[i].salary;
                cantSalarios++;
            }
        }
    promedio=totalSalario/cantSalarios;
    printf("SALARIO PROMEDIO --> %f \n",promedio);

    for (i=0;i<length;i++)
    {
        if(list[i].salary>promedio)
        {
            cantSalariosMayor++;
        }
    }
    printf("\nEMPLEADOS QUE SUPERAR SUELDO PROMEDIO--> %d\n",cantSalariosMayor);
    retorno=0;
    }

    return retorno;
}


/*
* \brief modifica datos por consola
* \param array empleados
* \param extension del array
* \param nombre del empleado
* \param apellido del empleado
* \param salario del empleado
* \param sector del empleado
* \return -1 si hay error , 0 si se pudo ejecutar correctamente
*/

int editEmployee(Employee* list,int len)
{
    int retorno=-1;
    char opcion[5];
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    int id;
    utn_getInt(&id,5,"Ingrese el id del empleaod a modificar :","Error id");
    int index=findEmployeeById(list,len,id);

    if (index >=0)
    {
        utn_getString(opcion,5,"Desea modificar el nombre? <S-N> : " , "Error nombre" );
        if ((strcmp(opcion,"S\0")==0 || (strcmp(opcion,"s\0")==0)))
        {
            utn_getString(auxName,52,"Ingrese nombre del empleado : ","Error al ingresar nombre empleado");
            strncpy(list[index].name,auxName,51);
        }

        utn_getString(opcion,3,"Desea modificar el Apellido? <S/N> : ","Error apellido");
        if ((strcmp(opcion,"S\0")==0 || (strcmp(opcion,"s\0")==0)) && utn_getString(auxLastName,51,"Ingrese apellido del empleado : ","Error apellido empleado")==0)
        {
            strncpy(list[index].lastName,auxLastName,51);
        }

        utn_getString(opcion,3,"Desea modificar el sueldo? <S/N> : ","Error sueldo");
        if ((strcmp(opcion,"S\0")==0 || (strcmp(opcion,"s\0")==0)) && utn_getFloat(&auxSalary,51,"Ingrese sueldo del empleado : ","Error al ingresar sueldo empleado")==0)
        {
            list[index].salary=auxSalary;
        }

        utn_getString(opcion,3,"Desea modificar el sector? <S/N> : ","Error sector");
        if ((strcmp(opcion,"S\0")==0 || (strcmp(opcion,"s\0")==0)) && utn_getInt(&auxSector,51,"Ingrese sueldo del empleado : ","Error al ingresar sueldo empleado")==0)
        {
            list[index].sector=auxSector;
        }

        retorno=0;
    }

    return retorno;
}

/*
* \brief valida si la lista esta vacia
* \param array empleados

* \return 0 si no esta vacia , -1 si esta vacia
*/
int emptyList(Employee* list, int length)
{
    int retorno=-1;
    int i;

    if (list != NULL && length>=0)
    {
        for (i=0;i<length;i++)
        {
            if(list[i].isEmpty==0)
            {
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}
