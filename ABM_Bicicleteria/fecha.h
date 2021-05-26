#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

int compararFechas(Fecha f1, Fecha f2);

#endif // FECHA_H_INCLUDED
