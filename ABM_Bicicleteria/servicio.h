#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    float precio;
}Servicio;

int cargarDescripcionServicio(int id, Servicio servicios[], int len, char descrip[]);
int mostrarServicios(Servicio servicios[], int len);
void mostrarServicio(Servicio unServicio);
int findServicioById(Servicio servicios[], int len, int id);

#endif // SERVICIO_H_INCLUDED
