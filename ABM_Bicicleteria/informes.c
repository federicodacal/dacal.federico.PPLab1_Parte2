#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "bicicleta.h"
#include "utn_validaciones.h"
#include "color.h"
#include "servicio.h"
#include "fecha.h"
#include "cliente.h"

/** \brief Lista las bicicletas por color elegido por el usuario
 *
 * \param list[] Bicicleta
 * \param len int
 * \param colores[] Color
 * \param lenC int
 * \param tipos[] Tipo
 * \param lenT int
 * \param clientes[] Cliente
 * \param lenCli int
 * \return int -1 Error 0 Exito
 *
 */
int listarBicicletasPorColor(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Cliente clientes[], int lenCli)
{
    int response=-1;
    int idColor;
    int index;
    int flag=0;

    if(list!=NULL && len>0 && colores!=NULL && lenC>0 && tipos!=NULL && lenT>0 && clientes!=NULL && lenCli>0){
        mostrarColores(colores, lenC);
        if(!utn_getNumero(&idColor,"\nIngrese ID de Color: \n","Dato no valido",5000,5004,5)){
            index=buscarColor(idColor, colores, lenC);
            printf("\n**** Bicicletas por Color %s*****\n", colores[index].nombreColor);
            for(int i=0;i<len;i++){
                if(list[i].isEmpty==0 && list[i].idColor==idColor){
                    printBicicleta(list[i],tipos,lenT,colores,lenC,clientes,lenCli);
                    flag=1;
                }
            }
            if(!flag){
                printf("No hay bicicletas de color %s\n", colores[index].nombreColor);
            }
        }
        printf("\n");
        response=0;
    }

    return response;
}

int buscarColor(int id, Color colores[], int len)
{
    int index=-1;

    if(colores!=NULL && len>0){
        for(int i=0;i<len;i++){
            index=i;
            break;
        }
    }
    return index;
}

/** \brief Lista bicicletas por tipo elegido por el usuario
 *
 * \param list[] Bicicleta
 * \param len int
 * \param colores[] Color
 * \param lenC int
 * \param tipos[] Tipo
 * \param lenT int
 * \param clientes[] Cliente
 * \param lenCli int
 * \return int -1 Error 0 Exito
 *
 */
int listarBicicletasPorTipo(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Cliente clientes[], int lenCli)
{
    int response=-1;
    int idTipo;
    int index;
    int flag=0;

    if(list!=NULL && len>0 && colores!=NULL && lenC>0 && tipos!=NULL && lenT>0 && clientes!=NULL && lenCli>0){
        mostrarTipos(tipos, lenT);
        if(!utn_getNumero(&idTipo,"\nIngrese ID de Tipo: \n","Dato no valido",1000,1003,5)){
            index=buscarTipo(idTipo, tipos, lenT);
            printf("\n**** Bicicletas por Tipo %s*****\n", tipos[index].descripcion);
            for(int i=0;i<len;i++){
                if(list[i].isEmpty==0 && list[i].idTipo==idTipo){
                    printBicicleta(list[i],tipos,lenT,colores,lenC,clientes,lenCli);
                    flag=1;
                }
            }
            if(!flag){
                printf("No hay bicicletas de tipo %s\n", tipos[index].descripcion);
            }
        }
        printf("\n");
        response=0;
    }
    return response;
}

int buscarTipo(int id, Tipo tipos[], int len)
{
    int index=-1;

    if(tipos!=NULL && len>0){
        for(int i=0;i<len;i++){
            index=i;
            break;
        }
    }
    return index;
}

/** \brief Lista las bicicletas de menor rodado
 *
 * \param list[] Bicicleta
 * \param len int
 * \param colores[] Color
 * \param lenC int
 * \param tipos[] Tipo
 * \param lenT int
 * \param clientes[] Cliente
 * \param lenCli int
 * \return int -1 Error 0 Exito
 *
 */
int listarBicicletasMenorRodado(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Cliente clientes[], int lenCli)
{
    int response=-1;
    float menorRodado;
    int flag=0;

    if(list!=NULL && len>0 && colores!=NULL && lenC>0 && tipos!=NULL && lenT>0 && clientes!=NULL && lenCli>0){

        for(int i=0;i<len;i++){
            if(i==0 || (list[i].isEmpty==0 && list[i].rodado<menorRodado)){
                menorRodado=list[i].rodado;
            }
        }

        printf("\n**** Bicicletas de Menor Rodado %.2f*****\n", menorRodado);
        for(int i=0;i<len;i++){
            if(list[i].isEmpty==0 && list[i].rodado==menorRodado){
                printBicicleta(list[i],tipos,lenT,colores,lenC,clientes,lenCli);
                flag=1;
            }
        }
        if(!flag){
            printf("No hay bicicletas que mostrar\n");
            }
        printf("\n");
        response=0;
    }
    return response;
}

/** \brief Lista las bicicletas por los diferentes tipos
 *
 * \param list[] Bicicleta
 * \param len int
 * \param colores[] Color
 * \param lenC int
 * \param tipos[] Tipo
 * \param lenT int
 * \param clientes[] Cliente
 * \param lenCli int
 * \return int -1 Error 0 Exito
 *
 */
int listarBicicletasPorCadaTipo(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Cliente clientes[], int lenCli)
{
    int response=-1;
    int flag;

    if(list!=NULL && len>0 && colores!=NULL && lenC>0 && tipos!=NULL && lenT>0 && clientes!=NULL && lenCli>0){
        printf("    *****LISTADO DE BICICLETAS POR TIPO*****\n\n");
        for(int i=0;i<lenT;i++){
            printf("\nTipo: %s\n", tipos[i].descripcion);
            flag=1;
            for(int j=0;j<len;j++){
                if(list[j].isEmpty==0 && list[j].idTipo==tipos[i].id){
                    printBicicleta(list[j],tipos,lenT,colores,lenC,clientes,lenCli);
                    flag=0;
                }
            }
            if(flag==1){
                printf("No hay bicicletas \n");
            }
        }
        printf("\n");
        response=0;
    }
    return response;
}

/** \brief Cuente las bicicletas por color y tipo elegido
 *
 * \param list[] Bicicleta
 * \param len int
 * \param colores[] Color
 * \param lenC int
 * \param tipos[] Tipo
 * \param lenT int
 * \return int -1 Error 0 Exito
 *
 */
int contarBicicletasPorColoryTipo(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT)
{
    int response=-1;
    int idColor;
    int idTipo;
    int contador=0;
    int indexC;
    int indexT;
    int flag=0;

    if(list!=NULL && len>0 && colores!=NULL && lenC>0 && tipos!=NULL && lenT>0){
        mostrarColores(colores, lenC);
        mostrarTipos(tipos, lenT);
        if(!utn_getNumero(&idColor,"\nIngrese ID de Color: \n","Dato no valido",5000,5004,5) &&
           !utn_getNumero(&idTipo,"\nIngrese ID de Tipo: \n","Dato no valido",1000,1003,5)){
            indexC=buscarColor(idColor, colores, lenC);
            indexT=buscarTipo(idTipo, tipos, lenT);
            printf("\n**** Bicicletas por Color %s y Tipo %s*****\n", colores[indexC].nombreColor, tipos[indexT].descripcion);
            for(int i=0;i<len;i++){
                if(list[i].isEmpty==0 && list[i].idColor==idColor && list[i].idTipo==idTipo){
                    contador++;
                    flag=1;
                }
            }
            if(!flag){
                printf("No hay bicicletas de Color %s y de Tipo %s\n", colores[indexC].nombreColor, tipos[indexT].descripcion);
            }
            else{
                printf("Se encontraron %d Bicicletas de Color %s y de Tipo %s\n", contador, colores[indexC].nombreColor, tipos[indexT].descripcion);
            }
        }
        printf("\n");
        response=0;
    }
    return response;
}

/** \brief Muestra el color o colores con mas bicicletas
 *
 * \param list[] Bicicleta
 * \param len int
 * \param colores[] Color
 * \param lenC int
 * \param tipos[] Tipo
 * \param lenT int
 * \return int -1 Error 0 Exito
 *
 */
int mostrarColoresMasElegidos(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT)
{
    int response=-1;
    int contadores[lenC];
    int mayorColor;

    if(list!=NULL && len>0 && colores!=NULL && lenC>0 && tipos!=NULL && lenT>0){
        for(int i=0;i<lenC;i++){
            contadores[i]=0;
            for(int j=0; j<len;j++){
                if(list[j].isEmpty==0 && list[j].idColor==colores[i].id){
                    contadores[i]++;
                }
            }
        }
        for(int i=0;i<lenC;i++){
            if(i==0 || mayorColor<contadores[i]){
                mayorColor=contadores[i];
            }
        }
        printf("\nColor/es mas elegidos: \n");
        for(int i=0;i<lenC;i++){
            if(contadores[i]==mayorColor){
                printf("%s\n", colores[i].nombreColor);
            }
        }

        printf("Cantidad: %d bicicletas\n", mayorColor);
        response=0;
    }
    return response;
}

/** \brief Lista los trabajos realizados a una bicicleta
 *
 * \param list[] Bicicleta
 * \param len int
 * \param colores[] Color
 * \param lenC int
 * \param tipos[] Tipo
 * \param lenT int
 * \param trabajos[] Trabajo
 * \param lenTr int
 * \param servicios[] Servicio
 * \param lenS int
 * \param clientes[] Cliente
 * \param lenCli int
 * \return int -1 Error 0 Exito
 *
 */
int mostrarTrabajosBicicleta(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Trabajo trabajos[], int lenTr, Servicio servicios[], int lenS, Cliente clientes[], int lenCli)
{
    int response=-1;
    int idBicicleta;
    int index;
    int flag=0;

    if(list!=NULL && len>0 && tipos!=NULL && lenT>0 && colores!=NULL && lenC>0 && trabajos!=NULL && lenTr>0 && servicios!=NULL && lenS>0&& clientes!=NULL && lenCli>0){
        printBicicletas(list,len,tipos,lenT,colores,lenC,clientes,lenCli);
        if(!utn_getNumero(&idBicicleta,"\nIngrese ID de Bicicleta: \n","Dato no valido",2000,5000,5)){
            index=findBicicletaById(list,len,idBicicleta);

            if(index==-1){
                printf("No hay bicicleta registrada con el ID %d\n",idBicicleta);
            }
            else{
                printf("\n");
                printBicicleta(list[index], tipos, lenT,  colores, lenC, clientes, lenCli);
                printf("\n Trabajo realizado: \n");
                for(int i=0;i<lenTr;i++){
                    if(trabajos[i].isEmpty==0 && trabajos[i].idBicicleta==idBicicleta){
                        printTrabajo(trabajos[i], servicios, lenS);
                        flag=1;
                    }
                }
            }
            if(flag==0){
                printf("No se le realizaron trabajos a la bicicleta seleccionada\n\n");
            }
        }
        response=0;
    }
    return response;
}

/** \brief Calcula el importe total de una bicicleta
 *
 * \param list[] Bicicleta
 * \param len int
 * \param colores[] Color
 * \param lenC int
 * \param tipos[] Tipo
 * \param lenT int
 * \param trabajos[] Trabajo
 * \param lenTr int
 * \param servicios[] Servicio
 * \param lenS int
 * \param clientes[] Cliente
 * \param lenCli int
 * \return int -1 Error 0 Exito
 *
 */
int calcularImportePorBicicleta(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Trabajo trabajos[], int lenTr, Servicio servicios[], int lenS, Cliente clientes[], int lenCli)
{
    int response=-1;
    int idBicicleta;
    int index;
    int flag=1;
    float importeTotal=0;

        if(list!=NULL && len>0 && tipos!=NULL && lenT>0 && colores!=NULL && lenC>0 && trabajos!=NULL && lenTr>0 && servicios!=NULL && lenS>0 && clientes!=NULL && lenCli>0){
        printBicicletas(list,len,tipos,lenT,colores,lenC,clientes,lenCli);
        if(!utn_getNumero(&idBicicleta,"\nIngrese ID de Bicicleta: \n","Dato no valido",2000,5000,5)){
            index=findBicicletaById(list,len,idBicicleta);

            if(index==-1){
                printf("No hay bicicleta registrada con el ID %d\n",idBicicleta);
            }
            else{
                for(int i=0;i<lenTr;i++){
                    if(trabajos[i].isEmpty==0 && trabajos[i].idBicicleta==idBicicleta){
                        for(int j=0;j<lenS;j++){
                            if(servicios[j].id==trabajos[i].idServicio){
                                importeTotal+=servicios[j].precio;
                            }
                        }
                    flag=0;
                    }
                }
            }
            if(flag){
                printf("La bicicleta no registra trabajos realizados\n");
            }
            else{
                printf("Total Importe: $ %.2f\n",importeTotal);
            }
        }
        response=0;
    }
    return response;
}

/** \brief Lista las bicicletas segun servicio
 *
 * \param list[] Bicicleta
 * \param len int
 * \param colores[] Color
 * \param lenC int
 * \param tipos[] Tipo
 * \param lenT int
 * \param trabajos[] Trabajo
 * \param lenTr int
 * \param servicios[] Servicio
 * \param lenS int
 * \param clientes[] Cliente
 * \param lenCli int
 * \return int -1 Error 0 Exito
 *
 */
int mostrarBicicletasPorServicio(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Trabajo trabajos[], int lenTr, Servicio servicios[], int lenS, Cliente clientes[], int lenCli)
{
    int response=-1;
    int idServicio;
    int index;
    int flag=1;

    if(list!=NULL && len>0 && tipos!=NULL && lenT>0 && colores!=NULL && lenC>0 && trabajos!=NULL && lenTr>0 && servicios!=NULL && lenS>0 && clientes!=NULL && lenCli>0){
        mostrarServicios(servicios, lenS);
        if(!utn_getNumero(&idServicio, "\nIngrese ID de Servicio: ","Error dato no valido\n", 20000,20003,5)){
            index=findServicioById(servicios, lenS, idServicio);
            if(index==-1){
                printf("No hay servicio registrado con el ID %d\n",idServicio);
            }
            else{
                for(int i=0;i<lenTr;i++){
                    if(trabajos[i].isEmpty==0 && trabajos[i].idServicio==idServicio){
                        for(int j=0;j<lenS;j++){
                            if(servicios[j].id==trabajos[i].idServicio){
                                printf("\nTrabajo: \n");
                                printTrabajo(trabajos[i], servicios, lenS);
                                for(int k=0;k<len;k++){
                                    if(trabajos[i].idBicicleta==list[k].id){
                                        printBicicleta(list[k],tipos,lenT,colores,lenC,clientes,lenCli);
                                    }
                                }
                            }
                        }
                        flag=0;
                    }
                }
            }
            if(flag){
                printf("El servicio elegido no registra bicicletas\n");
            }
        }
        response=0;
    }
    return response;
}


/** \brief Lista los servicios realizados por fecha
 *
 * \param list[] Bicicleta
 * \param len int
 * \param colores[] Color
 * \param lenC int
 * \param tipos[] Tipo
 * \param lenT int
 * \param trabajos[] Trabajo
 * \param lenTr int
 * \param servicios[] Servicio
 * \param lenS int
 * \return int -1 Error 0 Exito
 *
 */
int mostrarServiciosPorFecha(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Trabajo trabajos[], int lenTr, Servicio servicios[], int lenS)
{
    int response=-1;
    int flag=1;
    Fecha auxFecha;

    if(list!=NULL && len>0 && tipos!=NULL && lenT>0 && colores!=NULL && lenC>0 && trabajos!=NULL && lenTr>0 && servicios!=NULL && lenS>0){

        if(!utn_getNumero(&auxFecha.dia, "\nIngrese dia: ","Error dato no valido\n", 1,31,5) &&
           !utn_getNumero(&auxFecha.mes, "\nIngrese mes: ","Error dato no valido\n", 1,12,5) &&
           !utn_getNumero(&auxFecha.anio, "\nIngrese anio: ","Error dato no valido\n", 2021,2030,5) &&
           !validarFecha(auxFecha.dia,auxFecha.mes)){
            for(int i=0;i<lenTr;i++){
                if(trabajos[i].isEmpty==0 && compararFechas(auxFecha,trabajos[i].fechaTrabajo)){
                    printf("\nTrabajo: \n");
                    printTrabajo(trabajos[i], servicios, lenS);
                    flag=0;
                }
            }
        }

        if(flag){
        printf("La fecha elegida no registra servicios\n");
        }

        response=0;
    }
    return response;
}

