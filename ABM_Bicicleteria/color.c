#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "color.h"

/** \brief Carga la descripcion (string de char) de un elemento seleccionado
 *
 * \param id int id del elemento seleccionado que sera comparado
 * \param colores[] Color
 * \param len int Length colores
 * \param descrip[] char string char en el que sera copiado la descripcion coincidente
 * \return int 0 (Error) 1 (Exito)
 *
 */
int cargarDescripcionColor(int id, Color colores[], int len, char descrip[])
{
    int response=0;

    if(id>=5000 && id<=5004 && colores!=NULL && len>0 && descrip!=NULL){
        for (int i=0;i<len;i++){
            if(colores[i].id == id){
                strcpy(descrip,colores[i].nombreColor);
                response=1;
                break;
            }
        }
    }
    return response;
}

/** \brief Recorre el array colores y muestra la lista de colores
 *
 * \param colores[] Color array
 * \param len int Length array
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int mostrarColores(Color colores[], int len)
{
    int response=-1;
    if(colores!=NULL && len>0){
        printf("    *****LISTA DE COLORES*****\n");
        printf("        ID  Descripcion\n");
        for(int i=0;i<len;i++){
            mostrarColor(colores[i]);
        }
        printf("\n");
        response=0;
    }
    return response;
}

/** \brief Muestra un elemento de colores
 *
 * \param unColor Color
 * \return void
 *
 */
void mostrarColor(Color unColor)
{
    printf("        %d  %10s\n", unColor.id, unColor.nombreColor);
}
