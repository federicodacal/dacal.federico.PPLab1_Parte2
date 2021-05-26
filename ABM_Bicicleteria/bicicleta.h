#include "tipo.h"
#include "color.h"
#include "cliente.h"
#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int idCliente;
    float rodado;
    int isEmpty;
}Bicicleta;

int initBicicletas(Bicicleta list[], int len);
int addBicicleta(Bicicleta list[], int len, int* pCodigo, Tipo tipos[], int lenT, Color colores[], int lenC, Cliente clientes[], int lenCli);
int findEmptyIndex(Bicicleta list[], int len);
int printBicicleta(Bicicleta bici, Tipo tipos[], int lenT, Color colores[], int lenC, Cliente clientes[], int lenCli);
int printBicicletas(Bicicleta list[], int len, Tipo tipos[], int lenT, Color colores[], int lenC, Cliente clientes[], int lenCli);
int removeBicicleta(Bicicleta list[], int len, Tipo tipos[], int lenT, Color colores[], int lenC, Cliente clientes[], int lenCli);
int findBicicletaById(Bicicleta list[], int len, int id);
int updateBicicleta(Bicicleta list[], int len, Tipo tipos[], int lenT, Color colores[], int lenC, Cliente clientes[], int lenCli);
int modifyBicicleta(Bicicleta list[], int len, int index, Tipo tipos[], int lenT, Color colores[], int lenC, Cliente clientes[], int lenCli);
int ordenarBicicletasPorTipo(Bicicleta list[], int len);
int sortByciclesByType(Bicicleta list[], int len);

#endif // BICICLETA_H_INCLUDED
