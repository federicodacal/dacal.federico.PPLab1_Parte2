#include "Bicicleta.h"
#include "fecha.h"
#include "trabajo.h"

#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

int hcodeBicicletas(Bicicleta list[], int len, int qty, int* pId);
int hcodeTrabajos(Trabajo trabajos[], int len, int cant, int* pId);

#endif // DATAWAREHOUSE_H_INCLUDED
