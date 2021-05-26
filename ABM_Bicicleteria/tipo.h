#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}Tipo;

int cargarDescripcionTipo(int id, Tipo tipos[], int len, char descrip[]);
int mostrarTipos(Tipo tipos[], int len);
void mostrarTipo(Tipo unTipo);

#endif // TIPO_H_INCLUDED
