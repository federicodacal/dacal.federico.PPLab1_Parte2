#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

/** \brief Carga la descripcion (string de char) de un elemento seleccionado
 *
 * \param id int id del elemento seleccionado que sera comparado
 * \param clientes[] Cliente
 * \param len int Length clientes
 * \param descrip[] char string char en el que sera copiado la descripcion coincidente
 * \return int 0 (Error) 1 (Exito)
 *
 */
int cargarNombreCliente(int id, Cliente clientes[], int len, char descrip[])
{
    int response=0;

    if(id>=8000 && id<=9000 && clientes!=NULL && len>0 && descrip!=NULL){
        for (int i=0;i<len;i++){
            if(clientes[i].id == id){
                strcpy(descrip,clientes[i].nombre);
                response=1;
                break;
            }
        }
    }
    return response;
}

/** \brief Recorre el array clientes y muestra la lista de clientes
 *
 * \param clientes[] Cliente array
 * \param len int Length array
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int mostrarClientes(Cliente clientes[], int len)
{
    int response=-1;
    if(clientes!=NULL && len>0){
        printf("    *****LISTA DE CLIENTES*****\n");
        printf("        ID  Descripcion\n");
        for(int i=0;i<len;i++){
            mostrarCliente(clientes[i]);
        }
        printf("\n");
        response=0;
    }
    return response;
}

/** \brief Muestra un elemento de clientes
 *
 * \param unCliente Cliente
 * \return void
 *
 */
void mostrarCliente(Cliente unCliente)
{
    printf("        %d  %10s\n", unCliente.id, unCliente.nombre);
}

