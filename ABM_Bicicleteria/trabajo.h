#include "servicio.h"
#include "fecha.h"
#include "tipo.h"
#include "bicicleta.h"


#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idBicicleta;
    int idServicio;
    Fecha fechaTrabajo;
    int isEmpty;
}Trabajo;


int initTrabajos(Trabajo trabajos[], int len);
int findEmptyIndexTrabajo(Trabajo trabajos[], int len);
int printTrabajo(Trabajo unTrabajo, Servicio servicios[], int lenS);
int printTrabajos(Trabajo trabajos[], int len, Servicio servicios[], int lenS);
int addTrabajo(Trabajo trabajos[], int len, int* pCodigo, Tipo tipos[], int lenT, Servicio servicios[], int lenS, Bicicleta list[], int lenB, Color colores[], int lenC, Cliente clientes[], int lenCli);


#endif // TRABAJO_H_INCLUDED
