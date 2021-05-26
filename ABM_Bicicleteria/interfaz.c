#include "interfaz.h"

/** \brief Menu principal ABM
 *
 * \return int -1 (Error) o opcion elegida (Exito)
 *
 */
int menu()
{
    int response=-1;;
    int optionAux;

    system("cls");
    printf("\n*****ADMINISTRACION DE BICICLETERIA*****\n");
    printf("------------------------------------------\n");
    printf("[1] ALTA BICICLETA\n");
    printf("[2] MODIFICAR BICICLETA\n");
    printf("[3] BAJA BICICLETA\n");
    printf("[4] LISTAR BICICLETAS\n");
    printf("[5] LISTAR TIPOS\n");
    printf("[6] LISTAR COLORES\n");
    printf("[7] LISTAR SERVICIOS\n");
    printf("[8] ALTA TRABAJO\n");
    printf("[9] LISTAR TRABAJOS\n");
    printf("[10] INFORMES\n");
    printf("------------------------------------------\n");
    printf("[11] Salir\n");

    if(utn_getNumero(&optionAux,"\nIngrese opcion:\n","\nDato ingresado no valido.",1,11,10)==0){
        response=optionAux;
    }

    return response;
}

int submenuInformes()
{
    int response=-1;;
    int optionAux;

    printf("\t1. Filtrar Bicicletas por Color \n");
    printf("\t2. Filtrar Bicicletas por Tipo \n");
    printf("\t3. Filtrar Bicicletas por Menor Rodado \n");
    printf("\t4. Filtrar Bicicletas por Cada Tipo \n");
    printf("\t5. Cantidad de Bicicletas por Color y Tipo \n");
    printf("\t6. Color/es mas elegidos \n");
    printf("\t7. Informar Trabajos por Bicicleta \n");
    printf("\t8. Informar Importe por Bicicleta\n");
    printf("\t9. Filtrar por Servicio\n");
    printf("\t10. Filtrar Servicios por Fecha\n");
    printf("------------------------------------------------\n");
    printf("\t11. Volver al Menu\n");

    if(utn_getNumero(&optionAux,"\nIngrese opcion:\n","\nDato ingresado no valido.",1,11,5)==0){
        response=optionAux;
    }

    return response;
}
