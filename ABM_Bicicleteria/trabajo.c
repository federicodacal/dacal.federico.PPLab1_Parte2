#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "utn_validaciones.h"
#include "cliente.h"

/** \brief Inicializa el array (el campo isEmpty=1 indica que la posicion esta disponible)
 *
 * \param trabajos[] Trabajo array que sera inicializado
 * \param len int Length del array
 * \return int response=-1 (Error) response=0 (La inicializacion fue exitosa)
 *
 */
int initTrabajos(Trabajo trabajos[], int len)
{
    int response=1;
    if(trabajos!=NULL && len>0){
        for(int i=0;i<len;i++){
            trabajos[i].isEmpty=1;
        }
        response=0;
    }
    return response;
}

/** \brief Da de alta un Trabajo en una posicion disponible del array
 *
 * \param trabajos[] Trabajo array
 * \param len int Length array
 * \param pCodigo int* Puntero del codigo predeterminado que sera asignado (id de Trabajo)
 * \param tipos[] Tipo array tipos
 * \param lenT int Length array tipos
 * \param servicios[] Servicio array servicios
 * \param lenS int Length array servicios
 * \param list[] Bicicleta array list
 * \param lenB int Length array list (bicicletas)
 * \param colores[] Color array colores
 * \param lenC int Length array colores
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int addTrabajo(Trabajo trabajos[], int len, int* pCodigo, Tipo tipos[], int lenT, Servicio servicios[], int lenS, Bicicleta list[], int lenB, Color colores[], int lenC, Cliente clientes[], int lenCli)
{
    int response=-1;
    int index;
    int indexBicicleta;
    int codigo;
    int auxDia;
    int auxMes;
    int auxAnio;

    Trabajo newTrabajo;

    if(trabajos!=NULL && len>0 && pCodigo!=NULL && tipos!=NULL && lenT>0 && servicios!=NULL && lenS!=0 && list!=NULL && lenB>0 && colores!=NULL && lenC>0 && clientes!=NULL && lenCli>0){
        index=findEmptyIndexTrabajo(trabajos,len);
        if(index==-1){
            printf("No hay lugar disponible en el sistema\n");
            response=1;
        }
        else{
            printBicicletas(list,len,tipos,lenT,colores,lenC,clientes,lenCli);
            printf("\nCODIGO TRABAJO: %d\n", *pCodigo);
            if(!utn_getNumero(&codigo,"\nIngrese ID de Bicicleta: \n","Dato no valido",2000,5000,5)){
                indexBicicleta=findBicicletaById(list,len,codigo);
                if(indexBicicleta==-1){
                    printf("No hay bicicleta registrada con el ID %d\n",codigo);
                }
                else{
                    printf("\n\t **** BICICLETA *****\n");
                    printBicicleta(list[indexBicicleta], tipos, lenT,  colores, lenC, clientes, lenCli);
                    printf("\n");
                    mostrarServicios(servicios, lenS);
                    if(!utn_getNumero(&newTrabajo.idServicio, "\nIngrese ID de Servicio: ","Error dato no valido\n", 20000,20003,5) &&
                       !utn_getNumero(&auxDia, "\nIngrese dia: ","Error dato no valido\n", 1,31,5) &&
                       !utn_getNumero(&auxMes, "\nIngrese mes: ","Error dato no valido\n", 1,12,5) &&
                       !utn_getNumero(&auxAnio, "\nIngrese anio: ","Error dato no valido\n", 2021,2030,5) &&
                       !validarFecha(auxDia,auxMes)){
                            newTrabajo.id=*pCodigo;
                            (*pCodigo)++;
                            newTrabajo.isEmpty=0;
                            trabajos[index]=newTrabajo;
                            trabajos[index].idBicicleta=list[indexBicicleta].id;
                            trabajos[index].fechaTrabajo.dia=auxDia;
                            trabajos[index].fechaTrabajo.mes=auxMes;
                            trabajos[index].fechaTrabajo.anio=auxAnio;
                            response=0;
                    }
                }
            }
        }
    }
    return response;
}

/** \brief Busca la primera posicion libre dentro del array
 *
 * \param trabajos[] Trabajo array
 * \param len int Length del array
 * \return int index=-1 (Error) o index=i (Posicion encontrada si pudo hallar una posicion disponible)
 *
 */
int findEmptyIndexTrabajo(Trabajo trabajos[], int len)
{
    int index=-1;

    if(trabajos!=NULL && len>0){
        for(int i=0;i<len;i++){
            if(trabajos[i].isEmpty){
                index=i;
                break;
            }
        }
    }
    return index;
}

/** \brief Imprime en pantalla un Trabajo
 *
 * \param unTrabajo Trabajo elemento del array ha ser mostrado
 * \param servicios[] Servicio array
 * \param lenS int length array servicios
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int printTrabajo(Trabajo unTrabajo, Servicio servicios[], int lenS)
{
    int response=-1;
    char servicioDescrip[20];

    if(servicios!=NULL && lenS>0){
        if(cargarDescripcionServicio(unTrabajo.idServicio, servicios, lenS, servicioDescrip)){
            printf("%d \t\t%d \t\t%-10s \t%02d/%02d/%02d\n",
                       unTrabajo.id,
                       unTrabajo.idBicicleta,
                       servicioDescrip,
                       unTrabajo.fechaTrabajo.dia,
                       unTrabajo.fechaTrabajo.mes,
                       unTrabajo.fechaTrabajo.anio
                    );
                    response=0;
        }
    }
    return response;
}

/** \brief Imprime en pantalla los elementos del array
 *
 * \param trabajos[] Trabajo
 * \param len int
 * \param servicios[] Servicio
 * \param lenS int
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int printTrabajos(Trabajo trabajos[], int len, Servicio servicios[], int lenS)
{
    int response=-1;
    int flag=1;
    if(trabajos!=NULL && len>0 && servicios!=NULL && lenS>0){
        printf("\n\t\t*****LISTADO DE TRABAJOS******\n");
        printf("-------------------------------------------------------------------------\n");
        printf("ID Trabajo\tID Bicicleta \tServicio \tFecha \n");
        for(int i=0;i<len;i++){
            if(!trabajos[i].isEmpty){
                printTrabajo(trabajos[i], servicios, lenS);
                flag=0;
            }
        }
        if(flag){
            printf("\n\tNo hay trabajos que mostrar\n");
        }
    response=0;
    printf("\n\n");
    }
    return response;
}

