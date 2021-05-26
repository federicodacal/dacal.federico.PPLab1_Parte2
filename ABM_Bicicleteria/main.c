#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "fecha.h"
#include "servicio.h"
#include "trabajo.h"
#include "interfaz.h"
#include "informes.h"
#include "utn_validaciones.h"
#include "datawarehouse.h"
#include "cliente.h"

#define BICICLETA_LEN 5000
#define TIPOS_LEN 4
#define COLORES_LEN 5
#define SERVICIOS_LEN 4
#define TRABAJOS_LEN 1000
#define CLIENTE_LEN 10

int main()
{
    int nextBicicleta=2000;
    int nextIdTrabajo=30000;

    char exit='n';
    int option;
    int optInformes;
    int flag=0;

    Tipo tipos[TIPOS_LEN]={
    {1000, "Rutera"},
    {1001, "Carrera"},
    {1002, "Mountain"},
    {1003, "BMX"},
    };

    Color colores[COLORES_LEN]={
    {5000, "Gris"},
    {5001, "Negro"},
    {5002, "Blanco"},
    {5003, "Azul"},
    {5004, "Rojo"}
    };

    Servicio servicios[SERVICIOS_LEN]={
    {20000, "Limpieza",250},
    {20001, "Parche",300},
    {20002, "Centrado",400},
    {20003, "Cadena",350}
    };

    Cliente clientes[20]={
    {8000,"Donato","masculino",0},
    {8001,"Carmen","femenino",0},
    {8002,"Chepi","femenino",0},
    {8003,"Alex","masculino",0},
    {8004,"German","masculino",0},
    {8005,"Maria","femenino",0},
    {8006,"Damian","masculino",0},
    {8007,"Daniel","masculino",0},
    {8008,"Andrea","femenino",0},
    {8009,"Candela","femenino",0}
    };

    Bicicleta list[BICICLETA_LEN];

    initBicicletas(list, BICICLETA_LEN);

    hcodeBicicletas(list, BICICLETA_LEN, 20, &nextBicicleta);

    Trabajo trabajos[TRABAJOS_LEN];

    initTrabajos(trabajos, TRABAJOS_LEN);

    hcodeTrabajos(trabajos, TRABAJOS_LEN, 20, &nextIdTrabajo);


    do{
        option=menu();
        if(option!=-1){
            switch(option){
                case 1:
                    system("cls");
                    printf("\n*****GESTIONAR ALTA*****\n");
                    printf("-------------------------------------\n");
                    if(!addBicicleta(list, BICICLETA_LEN, &nextBicicleta, tipos, TIPOS_LEN, colores, COLORES_LEN, clientes, CLIENTE_LEN)){
                        printf("ALTA EXITOSA\n\n");
                        flag=1;
                    }
                    else{
                        printf("\nNo se realizo la alta\n\n");
                    }
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    printf("\n*****GESTIONAR MODIFICACION*****\n");
                    printf("-------------------------------------\n");
                    if(flag){
                        if(!updateBicicleta(list, BICICLETA_LEN, tipos, TIPOS_LEN, colores, COLORES_LEN, clientes, CLIENTE_LEN)){
                            printf("Modificacion exitosa\n\n");
                        }
                        else{
                            printf("\nOcurrio un problema\n\n");
                        }
                    }
                    else{
                        printf("\nPrimero se debe realizar al menos un ALTA\n\n");
                    }
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    printf("\n\t\t*****GESTIONAR BAJA*****\n");
                    printf("\t------------------------------------------------------------\n");
                    if(flag){
                        if(!removeBicicleta(list, BICICLETA_LEN, tipos, TIPOS_LEN, colores, COLORES_LEN, clientes, CLIENTE_LEN)){
                            printf("BAJA EXITOSA\n\n");
                        }
                        else{
                            printf("\nNo se realizo baja\n\n");
                        }
                    }
                    else{
                        printf("\nPrimero se debe realizar al menos un ALTA\n\n");
                    }
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    if(flag){
                        if(!sortByciclesByType(list, BICICLETA_LEN)){
                            printBicicletas(list,BICICLETA_LEN, tipos, TIPOS_LEN, colores, COLORES_LEN, clientes, CLIENTE_LEN);
                        }
                    }
                    else{
                        printf("\nPrimero se debe realizar al menos un ALTA\n\n");
                    }
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    if(flag){
                        mostrarTipos(tipos,TIPOS_LEN);
                    }
                    else{
                        printf("\nPrimero se debe realizar al menos un ALTA\n\n");
                    }
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    if(flag){
                        mostrarColores(colores,COLORES_LEN);
                    }
                    else{
                        printf("\nPrimero se debe realizar al menos un ALTA\n\n");
                    }
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    if(flag){
                        mostrarServicios(servicios, SERVICIOS_LEN);
                    }
                    else{
                        printf("\nPrimero se debe realizar al menos un ALTA\n\n");
                    }
                    system("pause");
                    break;
                case 8:
                    system("cls");
                    printf("\n\t\t*****GESTIONAR ALTA DE TRABAJO*****\n");
                    printf("\t------------------------------------------------------------\n");
                    if(flag){
                        if(!addTrabajo(trabajos, TRABAJOS_LEN, &nextIdTrabajo, tipos, TIPOS_LEN, servicios, SERVICIOS_LEN, list, BICICLETA_LEN, colores, COLORES_LEN, clientes, CLIENTE_LEN)){
                            printf("ALTA EXITOSA\n\n");
                        }
                        else{
                            printf("Ocurrio un problema\n\n");
                        }
                    }
                    else{
                        printf("\nPrimero se debe realizar al menos un ALTA\n\n");
                    }
                    system("pause");
                    break;
                case 9:
                    system("cls");
                    if(flag){
                        printTrabajos(trabajos, TRABAJOS_LEN, servicios, SERVICIOS_LEN);
                    }
                    else{
                        printf("\nPrimero se debe realizar al menos un ALTA\n\n");
                    }
                    system("pause");
                    break;
                case 10:
                    system("cls");
                    printf("\t****** INFORMES ******\n");
                    if(flag){
                        optInformes=submenuInformes();
                        if(optInformes!=-1){
                            switch(optInformes){
                                case 1:
                                    listarBicicletasPorColor(list, BICICLETA_LEN, colores, COLORES_LEN, tipos, TIPOS_LEN, clientes, CLIENTE_LEN);
                                    break;
                                case 2:
                                    listarBicicletasPorTipo(list, BICICLETA_LEN, colores, COLORES_LEN, tipos, TIPOS_LEN, clientes, CLIENTE_LEN);
                                    break;
                                case 3:
                                    listarBicicletasMenorRodado(list, BICICLETA_LEN, colores, COLORES_LEN, tipos, TIPOS_LEN, clientes, CLIENTE_LEN);
                                    break;
                                case 4:
                                    listarBicicletasPorCadaTipo(list, BICICLETA_LEN, colores, COLORES_LEN, tipos, TIPOS_LEN, clientes, CLIENTE_LEN);
                                    break;
                                case 5:
                                    contarBicicletasPorColoryTipo(list, BICICLETA_LEN, colores, COLORES_LEN, tipos, TIPOS_LEN);
                                    break;
                                case 6:
                                    mostrarColoresMasElegidos(list, BICICLETA_LEN, colores, COLORES_LEN, tipos, TIPOS_LEN);
                                    break;
                                case 7:
                                    mostrarTrabajosBicicleta(list, BICICLETA_LEN, colores, COLORES_LEN, tipos, TIPOS_LEN, trabajos, TRABAJOS_LEN, servicios, SERVICIOS_LEN, clientes, CLIENTE_LEN);
                                    break;
                                case 8:
                                    calcularImportePorBicicleta(list, BICICLETA_LEN, colores, COLORES_LEN, tipos, TIPOS_LEN, trabajos, TRABAJOS_LEN, servicios, SERVICIOS_LEN, clientes, CLIENTE_LEN);
                                    break;
                                case 9:
                                    mostrarBicicletasPorServicio(list, BICICLETA_LEN, colores, COLORES_LEN, tipos, TIPOS_LEN, trabajos, TRABAJOS_LEN, servicios, SERVICIOS_LEN, clientes, CLIENTE_LEN);
                                    break;
                                case 10:
                                    mostrarServiciosPorFecha(list, BICICLETA_LEN, colores, COLORES_LEN, tipos, TIPOS_LEN, trabajos, TRABAJOS_LEN, servicios, SERVICIOS_LEN);
                                    break;
                                }
                        }
                    }
                    else{
                        printf("\nPrimero se debe realizar al menos un ALTA\n\n");
                    }
                    system("pause");
                    break;
                case 11:
                    printf("Confirmar salida: s/n ");
                    fflush(stdin);
                    exit=getchar();
                    break;
                }
        }
    }while(exit!='s');

    return 0;
}

