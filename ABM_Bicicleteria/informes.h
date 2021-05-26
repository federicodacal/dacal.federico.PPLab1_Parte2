#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "informes.h"
#include "bicicleta.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

int listarBicicletasPorColor(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Cliente clientes[], int lenCli);
int listarBicicletasPorTipo(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Cliente clientes[], int lenCli);

int listarBicicletasMenorRodado(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Cliente clientes[], int lenCli);

int listarBicicletasPorCadaTipo(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Cliente clientes[], int lenCli);

int mostrarTrabajosBicicleta(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Trabajo trabajos[], int lenTr, Servicio servicios[], int lenS, Cliente clientes[], int lenCli);

int contarBicicletasPorColoryTipo(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT);
int mostrarColoresMasElegidos(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT);

int calcularImportePorBicicleta(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Trabajo trabajos[], int lenTr, Servicio servicios[], int lenS, Cliente clientes[], int lenCli);

int mostrarBicicletasPorServicio(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Trabajo trabajos[], int lenTr, Servicio servicios[], int lenS, Cliente clientes[], int lenCli);

int mostrarServiciosPorFecha(Bicicleta list[], int len, Color colores[], int lenC, Tipo tipos[], int lenT, Trabajo trabajos[], int lenTr, Servicio servicios[], int lenS);

int buscarTipo(int id, Tipo tipos[], int len);
int buscarColor(int id, Color colores[], int len);

#endif // INFORMES_H_INCLUDED
