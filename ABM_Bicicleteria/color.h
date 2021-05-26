#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];
}Color;

int cargarDescripcionColor(int id, Color colores[], int len, char descrip[]);
int mostrarColores(Color colores[], int len);
void mostrarColor(Color unColor);

#endif // COLOR_H_INCLUDED
