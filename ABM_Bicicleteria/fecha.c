#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"

/** \brief Compara dos fechas recibidas
 *
 * \param f1 Fecha
 * \param f2 Fecha
 * \return int 0 (No son iguales) 1 (Son iguales)
 *
 */
int compararFechas(Fecha f1, Fecha f2)
{
    int esIgual=0;

    if(f1.dia==f2.dia && f1.mes==f2.mes && f1.anio==f2.anio){
        esIgual=1;
    }
    return esIgual;
}
