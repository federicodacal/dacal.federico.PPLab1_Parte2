#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"

/** \brief Carga la descripcion (string de char) de un elemento seleccionado
 *
 * \param id int id del elemento seleccionado que sera comparado
 * \param tipos[] Tipo
 * \param len int Length tipos
 * \param descrip[] char string char en el que sera copiado la descripcion coincidente
 * \return int 0 (Error) 1 (Exito)
 *
 */
int cargarDescripcionTipo(int id, Tipo tipos[], int len, char descrip[])
{
    int response=0;

    if(id>=1000 && id<=1003 && tipos!=NULL && len>0 && descrip!=NULL){
        for (int i=0;i<len;i++){
            if(tipos[i].id==id){
                strcpy(descrip,tipos[i].descripcion);
                response=1;
                break;
            }
        }
    }
    return response;
}

/** \brief Recorre el array tipos y muestra la lista de tipos
 *
 * \param tipos[] Tipo
 * \param len int Length tipos
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int mostrarTipos(Tipo tipos[], int len)
{
    int response=-1;
    if(tipos!=NULL && len>0){
        printf("    *****LISTA DE TIPOS*****\n");
        printf("        ID  Descripcion\n");
        for(int i=0;i<len;i++){
            mostrarTipo(tipos[i]);
        }
        printf("\n");
        response=0;
    }
    return response;
}

/** \brief Muestra un elemento de tipos
 *
 * \param unTipo Tipo
 * \return void
 *
 */
void mostrarTipo(Tipo unTipo)
{
    printf("        %d  %10s\n", unTipo.id, unTipo.descripcion);
}
