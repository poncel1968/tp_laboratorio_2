#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/*
@brief : obtiene un string
@param : puntero a string
@param : limite string
@param : mensaje al usuario para que ingrese string
@param : mensaje de error
@value : 0 = successful
*/
int utn_getString(char* arrayString, int limite,char* msg,char* msgError)
{
    int retorno=-1;
    printf(msg);
    char auxString[limite];
    fgets(auxString,limite,stdin);
    fflush(stdin);

    if (auxString!= NULL)
    {
        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        strncpy(arrayString,auxString,limite);
        retorno=0;
    }
    else
    {
        printf(msgError);
    }
    return retorno;

}
/*
@brief : valida si hay un numero en un string
@param : string donde esta el numero a validar
@param : limite string
@value : 1 = succefull
*/
int validarIntInStr(char* stringInt, int limitedigit )
{
    int retorno=0;
    int i;
       for (i=0;i<strlen(stringInt);i++)
        {
        if (!((stringInt[i]>='0' && stringInt[i]<='9')|| stringInt[i]=='\n' || stringInt[i]=='\0'))
        {
            retorno=0;
            break;
        }
        }
       if (i==strlen(stringInt))
        {
        retorno=1;
        }

    return retorno;
}
/*
@brief : obtiene un entero a partir de un string
@param : puntero a entero
@param : limite de dígitos
@value : 0 = successful
*/
int utn_getInt(int* valor,int limitedigit, char* msg, char* msgError)
{
    int retorno;
    char auxString[limitedigit];
    int auxInt;
    int valorGetString;
    valorGetString=utn_getString(auxString,limitedigit,msg,msgError);

    if (validarIntInStr(auxString,limitedigit)&& !valorGetString)
    {
        auxInt=atoi(auxString);
        *valor=auxInt;
        retorno=0;
    }
    else
    {

        retorno=-1;
    }
    return retorno;
}



int validarStrTelefono(char* string, int limite)
{
    int retorno=0;
    int i;
    for (i=0;i<strlen(string);i++)
    {
        if (!((string[i]>='0' && string[i]<='9')|| string[i]=='\n' || string[i]=='\0' || string[i]==' ' || string[i]=='-'))
        {
            retorno=0;
            break;
        }
    }
    if (i==(strlen(string)))
    {
        retorno=1;
    }
    return retorno;
}

/*
@brief : valida si hay un nombre del tipo nombre (valida solo caracteres alfanumericos)
@param : string donde esta el numero a validar
@param : limite string

*/
int validarNombreInStr(char* string)
{
    int retorno=0;
    int i=-1;
    int tamanio=strlen(string);

    for (i=0;i<tamanio;i++)
    {
        if (!((string[i]>='a' && string[i]<='z')|| (string[i]>='A' && string[i]<='Z') || string[i]=='\n' || string[i]=='\0') && tamanio>0)
        {
            retorno=0;
            break;
        }
    }
    if (i==tamanio)
    {
        retorno=1;
    }
    return retorno;
}



int utn_getNombre(char* nombre,int limite,char* msg)
{
    char auxString[4096];
    int retorno =-1;

    if (nombre != NULL && limite >0)
    {
        ///__fpurge(stdin);
        fflush(stdin);
        printf(msg);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limite && validarNombreInStr(auxString))
        {
            strncpy(nombre,auxString,limite);
            retorno=0;
        }
    }
    return retorno;
}

/*
@brief : valida si hay un numero flotante en un string
@param : string donde esta el numero a validar
@param : limite string
@value : 1 = succefull
*/
int validarFloatInStr(char* stringFloat, int limitedigit )
{
    int retorno=0;
    int i;
    int cantCeros=0;
       for (i=0;i<strlen(stringFloat);i++)
        {
        if (!((stringFloat[i]>='0' && stringFloat[i]<='9')|| stringFloat[i]=='\n' || stringFloat[i]=='\0' ||
              stringFloat[0]=='-' || cantCeros<2))
        {
            retorno=0;
            break;
        }
        if (stringFloat[i]=='.')
        {
            cantCeros++;
        }
        }
        if (i==strlen(stringFloat))
        {
            retorno=1;
        }
    return retorno;
}
/*
@brief : obtiene un numero flotatan a partir de un string
@param : puntero a flotante
@param : limite de dígitos
@value : 0 = successful
*/
int utn_getFloat(float* valor,int limitedigit, char * msg, char * msgError)
{
    int retorno;
    char auxString[limitedigit];
    float aux;
    int valorGetString;
    valorGetString=utn_getString(auxString,limitedigit,msg,msgError);

    if (validarFloatInStr(auxString,limitedigit)&& !valorGetString)
    {
        aux=atof(auxString);
        *valor=aux;
        retorno=0;
    }
    else
    {

        retorno=-1;
    }
    return retorno;

}



