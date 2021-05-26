#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

char marcas[20][20]={
    "Cannondale",
    "Felt",
    "Fuji",
    "Fuji",
    "Top Mega",
    "Master Bici",
    "Master Bici",
    "Raleigh",
    "Trek",
    "Trek",
    "Cannondale",
    "Venzo",
    "Olmo",
    "Master Bici",
    "Top Mega",
    "Olmo",
    "Cannondale",
    "Trinx",
    "Felt",
    "Felt"
};


float rodados[20]={20,26,26,29,26,27.5,20,27.5,26,26,26,27.5,27.5,29,27.5,26,29,20,20,20};

int idTipos[20]={1000,1001,1002,1003,1003,1002,1002,1001,1000,1000,1003,1002,1001,1003,1000,1001,1002,1003,1002,1000};

int idColores[20]={5000,5001,5002,5003,5004,5000,5000,5000,5004,5003,5002,5004,5003,5002,5003,5004,5001,5001,5002,5003};

    int id;
    int idBicicleta;
    int idServicio;
    Fecha fechaTrabajo;
    int isEmpty;

int idBicicletas[20]={2000,2003,2001,2004,2000,2005,2010,2007,2008,2000,2003,2006,2010,2009,2010,2007,2008,2000,2003,2006};

int idServicios[20]={20000,20000,20000,20001,20002,20003,20003,20001,20002,20002,20001,20003,20000,20000,20003,20001,20002,20003,20000,20001};

int idClientes[20]={8001,8000,8009,8008,8007,8003,8004,8005,8007,8001,8002,8003,8000,8009,8002,8001,8000,8009,8008,8007};

Fecha fechasTrabajo[20]={
    {1,3,2021},
    {1,3,2021},
    {1,3,2021},
    {2,3,2021},
    {2,3,2021},
    {2,3,2021},
    {3,3,2021},
    {4,3,2021},
    {4,3,2021},
    {4,3,2021},
    {5,3,2021},
    {5,3,2021},
    {5,3,2021},
    {6,3,2021},
    {7,3,2021},
    {8,3,2021},
    {9,3,2021},
    {10,3,2021},
    {10,3,2021},
    {11,3,2021}
};


/** \brief Carga una lista predeterminada a lista de bicicletas
 *
 * \param list[] Bicicleta
 * \param len int
 * \param qty int
 * \param pId int*
 * \return int Lugares ocupados
 *
 */
int hcodeBicicletas(Bicicleta list[], int len, int qty, int* pId)
{
    int places=0;

    if(list!=NULL && len>0 && qty>=0 && qty<=len && pId!=NULL){
        for(int i=0;i<qty;i++){
            list[i].id=*pId;
            (*pId)++;
            strncpy(list[i].marca, marcas[i],sizeof(list[i].marca));
            list[i].idTipo=idTipos[i];
            list[i].idColor=idColores[i];
            list[i].idCliente=idClientes[i];
            list[i].rodado=rodados[i];
            list[i].isEmpty=0;
            places++;
        }
    }

    return places;
}

/** \brief Carga una lista predeterminada a lista de trabajos
 *
 * \param list[] Trabajo
 * \param len int
 * \param qty int
 * \param pId int*
 * \return int Cantidad ocupada
 *
 */
int hcodeTrabajos(Trabajo trabajos[], int len, int qty, int* pId)
{
    int cantidad=0;

    if(trabajos!=NULL && len>0 && qty>=0 && qty <=len && pId!=NULL){
        for(int i=0;i<qty;i++){
            trabajos[i].id=*pId;
            (*pId)++;
            trabajos[i].idBicicleta=idBicicletas[i];
            trabajos[i].idServicio=idServicios[i];
            trabajos[i].fechaTrabajo=fechasTrabajo[i];
            trabajos[i].isEmpty=0;
            cantidad++;
        }
    }

    return cantidad;
}
