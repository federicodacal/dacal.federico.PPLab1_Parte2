#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "servicio.h"

/** \brief Carga la descripcion (string de char) de un elemento seleccionado
 *
 * \param id int id del elemento seleccionado que sera comparado
 * \param servicios[] Servicios
 * \param len int Length servicios
 * \param descrip[] char string char en el que sera copiado la descripcion coincidente
 * \return int 0 (Error) 1 (Exito)
 *
 */
int cargarDescripcionServicio(int id, Servicio servicios[], int len, char descrip[])
{
    int response=0;

    if(id>=20000 && id<=20003 && servicios!=NULL && len>0 && descrip!=NULL){
        for (int i=0;i<len;i++){
            if(servicios[i].id==id){
                strcpy(descrip,servicios[i].descripcion);
                response=1;
                break;
            }
        }
    }
    return response;
}

/** \brief Recorre el array servicios y muestra la lista de servicios
 *
 * \param servicios[] Servicio array
 * \param len int Length array
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int mostrarServicios(Servicio servicios[], int len)
{
    int response=-1;
    if(servicios!=NULL && len>0){
        printf("    *****LISTA DE SERVICIOS*****\n");
        printf("        ID  Descripcion Costo\n");
        for(int i=0;i<len;i++){
            mostrarServicio(servicios[i]);
        }
        printf("\n");
        response=0;
    }
    return response;
}

/** \brief Muestra un elemento de servicios
 *
 * \param unServicio Servicio
 * \return void
 *
 */
void mostrarServicio(Servicio unServicio)
{
    printf("        %d  %10s $%.2f\n", unServicio.id, unServicio.descripcion, unServicio.precio);
}

int findServicioById(Servicio servicios[], int len, int id)
{
    int index=-1;

    if(servicios!=NULL && len>0){
        for(int i=0;i<len;i++){
            if(servicios[i].id==id){
                index=i;
            }
        }
    }
    return index;
}

