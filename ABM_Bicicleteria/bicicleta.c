#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "utn_validaciones.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"

/** \brief Inicializa el array (el campo isEmpty=1 indica que la posicion esta disponible)
 *
 * \param list[] Bicicleta array que sera inicializado
 * \param len int Length del array
 * \return int response=-1 (Error) response=0 (La inicializacion fue exitosa)
 *
 */
int initBicicletas(Bicicleta list[], int len)
{
    int response=-1;
    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            list[i].isEmpty=1;
        }
        response=0;
    }
    return response;
}


/** \brief Da de alta una Bicicleta en una posicion disponible del array
 *
 * \param list[] Bicicleta array que sera actualizado
 * \param len int Length del array
 * \param pCodigo int* Puntero del codigo predeterminado que sera asignado (id de Bicicleta)
 * \param tipos[] Tipo Array de Tipos
 * \param lenT int Length de Array de Tipos
 * \param colores[] Color Array de Colores
 * \param lenC int Length del Array Colores
 * \return int response=-1 (Error) response=1 (Si no hay lugar disponible) response=0 (Alta fue exitosa)
 *
 */
int addBicicleta(Bicicleta list[], int len, int* pCodigo, Tipo tipos[], int lenT, Color colores[], int lenC, Cliente clientes[], int lenCli)
{
    int response=-1;

    Bicicleta newBicicleta;
    int index;

    if(list!=NULL && len>0 && pCodigo!=NULL && tipos!=NULL && lenT>0 && colores!=NULL && lenC>0 && clientes!=NULL && lenCli>0){
        printf("\nCODIGO BICICLETA: %d\n", *pCodigo);
        index=findEmptyIndex(list,len);
        if(index==-1){
            printf("No hay lugar disponible en el sistema\n");
            response=1;
        }
        else{
            mostrarTipos(tipos, lenT);
            mostrarColores(colores, lenC);
            mostrarClientes(clientes, lenCli);

            if(!utn_getDescripcion(newBicicleta.marca,20,"\nIngrese marca: ","Error dato no valido\n",5) &&
               !utn_getNumero(&newBicicleta.idTipo, "\nIngrese ID de Tipo: ","Error dato no valido\n", 1000,1003,5) &&
               !utn_getNumero(&newBicicleta.idColor, "\nIngrese ID de Color: ","Error dato no valido\n", 5000,5004,5) &&
               !utn_getNumero(&newBicicleta.idCliente, "\nIngrese ID de Cliente: ","Error dato no valido\n", 8000,8009,5) &&
               !utn_getRodado(&newBicicleta.rodado, "\nIngrese rodado (20, 26, 27.5, 29): ","Error dato no valido\n", 20,29,5))
               {
                    newBicicleta.id=*pCodigo;
                    (*pCodigo)++;
                    newBicicleta.isEmpty=0;
                    list[index]=newBicicleta;
                    response=0;
               }
        }
    }

    return response;
}

/** \brief Busca la primera posicion libre dentro del array
 *
 * \param list[] Bicicleta array
 * \param len int Length del array
 * \return int index=-1 (Error) o index=i (Posicion encontrada si pudo hallar una posicion disponible)
 *
 */
int findEmptyIndex(Bicicleta list[], int len)
{
    int index=-1;

    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            if(list[i].isEmpty){
                index=i;
                break;
            }
        }
    }
    return index;
}

/** \brief Imprime en pantalla una Bicicleta
 *
 * \param bici Bicicleta elemento del array ha ser mostrado
 * \param tipos[] Tipos array
 * \param lenT int Length array tipos
 * \param colores[] Array Colores
 * \param lenC int Length array colores
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int printBicicleta(Bicicleta bici, Tipo tipos[], int lenT, Color colores[], int lenC, Cliente clientes[], int lenCli)
{
    int response=-1;
    char tipoDescrip[20];
    char colorDescrip[20];
    char nombreDescrip[50];

    if(tipos!=NULL && lenT>0 && colores!=NULL && lenC>0 && clientes!=NULL && lenCli>0){
        if(cargarDescripcionTipo(bici.idTipo, tipos, lenT, tipoDescrip) &&
           cargarDescripcionColor(bici.idColor, colores, lenC, colorDescrip) &&
           cargarNombreCliente(bici.idCliente, clientes, lenCli, nombreDescrip)){
            printf("%d \t%-10s \t%-10s \t%-10s \t%.2f \t%-10s\n",
                       bici.id,
                       bici.marca,
                       tipoDescrip,
                       colorDescrip,
                       bici.rodado,
                       nombreDescrip);
           }
        response=0;
    }
    return response;
}

/** \brief Imprime en pantalla los elementos del array
 *
 * \param list[] Bicicleta array
 * \param len int Length array
 * \param tipos[] Tipo array tipos
 * \param lenT int Length array tipos
 * \param colores[] Color Array colores
 * \param lenC int Length array colores
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int printBicicletas(Bicicleta list[], int len, Tipo tipos[], int lenT, Color colores[], int lenC, Cliente clientes[], int lenCli)
{
    int response=-1;
    int flag=1;
    if(list!=NULL && len>0 && tipos!=NULL && lenT>0 && colores!=NULL && lenC>0 && clientes!=NULL && lenCli>0){
        printf("\n\t\t*****LISTADO DE BICICLETAS******\n");
        printf("-------------------------------------------------------------------------\n");
        printf("ID \tMarca \t\tTipo \t\tColor \t\tRodado \tCliente\n");
        for(int i=0;i<len;i++){
            if(!list[i].isEmpty){
                printBicicleta(list[i], tipos, lenT, colores, lenC, clientes, lenCli);
                flag=0;
            }
        }
        if(flag){
            printf("\n\tNo hay bicicletas que mostrar\n");
        }
        response=0;
        printf("\n\n");
    }
    return response;
}

/** \brief Permite dar de baja una bicicleta dentro del array list
 *
 * \param list[] Bicicleta array
 * \param len int Length array
 * \param tipos[] Tipo array tipos
 * \param lenT int Length array tipos
 * \param colores[] Color array colores
 * \param lenC int Length array colores
 * \return int -1 (Error) 1 (No se realiza la baja) o 0 (La baja se realiza con exito)
 *
 */
int removeBicicleta(Bicicleta list[], int len, Tipo tipos[], int lenT, Color colores[], int lenC, Cliente clientes[], int lenCli)
{
    int response=-1;
    int codigo;
    int index;
    int confirm;

    if(list!=NULL && len>0 && tipos!=NULL && lenT>0 && colores!=NULL && lenC>0 && clientes!=NULL && lenCli>0){
        printBicicletas(list,len,tipos,lenT,colores,lenC, clientes, lenCli);
        if(!utn_getNumero(&codigo,"\nIngrese ID de Bicicleta: \n","Dato no valido",2000,5000,5)){
            index=findBicicletaById(list,len,codigo);

            if(index==-1){
                printf("No hay bicicleta registrada con el ID %d\n",codigo);
            }
            else{
                printf("\n");
                printBicicleta(list[index], tipos, lenT,  colores, lenC, clientes, lenCli);
                if(!utn_getNumero(&confirm,"\n[1] Confirmar baja\n[2] Cancelar\n","\nDato no valido",1,2,10) && confirm==1){
                    list[index].isEmpty=1;
                    response=0;
                }
                else{
                    printf("\nBaja Cancelada\n");
                    response=1;
                }
            }
        }
    }
    return response;
}

/** \brief Busca en el array list un elemento por su id
 *
 * \param list[] Bicicleta
 * \param len int Length array
 * \param id int id ha comparar con el campo id de los elementos del array
 * \return int index=-1 (Error) o index=i (Si pudo hallar la posicion especificada)
 *
 */
int findBicicletaById(Bicicleta list[], int len, int id)
{
    int index=-1;

    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            if(list[i].id==id && list[i].isEmpty==0){
                index=i;
            }
        }
    }
    return index;
}

/** \brief Muestra los elementos cargados y permite realizar la busqueda de un elemento en el array por el codigo
 *
 * \param list[] Bicicleta array
 * \param len int Length array
 * \param tipos[] Tipo array tipos
 * \param lenT int Length array tipos
 * \param colores[] Color array colores
 * \param lenC int Length array colores
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int updateBicicleta(Bicicleta list[], int len, Tipo tipos[], int lenT, Color colores[], int lenC, Cliente clientes[], int lenCli)
{
    int response=-1;
    int codigo;
    int index;

    if(list!=NULL && len>0 && tipos!=NULL && lenT>0 && colores!=NULL && lenC>0 && clientes!=NULL && lenCli>0){
        printBicicletas(list,len, tipos, lenT, colores, lenC, clientes, lenCli);
        if(!utn_getNumero(&codigo,"Ingrese codigo del cliente: \n","Dato no valido",2000,5000,5)){
            index=findBicicletaById(list,len,codigo);
            if(index==-1){
                printf("\nNo hay cliente registrado con el codigo %d\n",codigo);
            }
            else{
                if(!modifyBicicleta(list,len,index, tipos, lenT, colores, lenC, clientes, lenCli)){
                    printf("\nDatos Actualizados:\n");
                    printf("ID \tMarca \t\tTipo \tColor \tRodado\n");
                    printBicicleta(list[index], tipos, lenT, colores, lenC, clientes, lenCli);
                    printf("---------------------------------------------------------------\n\n");
                    response=0;
                }
            }
        }
    }
    return response;
}

/** \brief Permite modificar los campos del elemento del array seleccionado
 *
 * \param list[] Bicicleta array
 * \param len int Length array
 * \param index int posicion en la que se encuentra el elemento seleccionado
 * \param tipos[] Tipo array tipos
 * \param lenT int Length array tipos
 * \param colores[] Color array colores
 * \param lenC int Length array colores
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int modifyBicicleta(Bicicleta list[], int len, int index, Tipo tipos[], int lenT, Color colores[], int lenC, Cliente clientes[], int lenCli)
{
    int response=-1;
    Bicicleta auxBicicleta;
    int option;

    if(list!=NULL && len>0 && tipos!=NULL && lenT>0 && colores!=NULL && lenC>0){
        do{
            system("cls");
            printf("\n");
            mostrarTipos(tipos, lenT);
            mostrarColores(colores, lenC);
            mostrarClientes(clientes, lenCli);
            printf("***** BICICLETA SELECCIONADA: *****\n");
            printBicicleta(list[index], tipos, lenT, colores, lenC, clientes, lenCli);
            printf("\nSeleccione el campo que desea modificar o 5 para Terminar:\n");
            if(!utn_getNumero(&option,"\n[1] Marca - [2] ID Tipo - [3] ID Color - [4] Rodados - [5] - ID Cliente - [6] Terminar Modificacion\n","\nDato no valido",1,6,10)){
                switch(option){
                    case 1:
                        if(!utn_getDescripcion(auxBicicleta.marca,20,"\nIngrese Marca: ","\nError dato no valido",5)){
                            strcpy(list[index].marca,auxBicicleta.marca);
                            printf("Informacion Actualizada. Nuevo marca: %s\n\n",auxBicicleta.marca);
                            system("pause");
                        }
                        break;
                    case 2:
                        if(!utn_getNumero(&auxBicicleta.idTipo,"\nIngrese ID Tipo: ","\nError dato no valido",1000,1003,5)){
                            list[index].idTipo=auxBicicleta.idTipo;
                            printf("Informacion Actualizada. Nuevo ID Tipo: %d\n\n",auxBicicleta.idTipo);
                            system("pause");
                        }
                        break;
                    case 3:
                        if(!utn_getNumero(&auxBicicleta.idColor,"\nIngrese ID de Color: ","\nError dato no valido", 5000,5004,5)){
                            list[index].idColor=auxBicicleta.idColor;
                            printf("Informacion Actualizada. Nuevo ID Color: %d\n\n",auxBicicleta.idColor);
                            system("pause");
                        }
                        break;
                    case 4:
                        if(!utn_getRodado(&auxBicicleta.rodado, "\nIngrese rodado (20, 26, 27.5, 29): ","Error dato no valido\n", 20,29,5)){
                            list[index].rodado=auxBicicleta.rodado;
                            printf("Informacion Actualizada. Nuevo rodado: %.2f\n\n",auxBicicleta.rodado);
                            system("pause");
                        }
                        break;
                    case 5:
                        if(!utn_getNumero(&auxBicicleta.idCliente,"\nIngrese ID de Cliente: ","\nError dato no valido", 8000,8009,5)){
                            list[index].idCliente=auxBicicleta.idCliente;
                            printf("Informacion Actualizada. Nuevo ID Cliente: %d\n\n",auxBicicleta.idCliente);
                            system("pause");
                        }
                        break;
                    }
                }
        }while(option!=6);

        response=0;
    }
    return response;
}

/** \brief Ordena los elementos por idTipo (menor a mayor) y en caso de coincidir por rodado (menor a mayor)
 *
 * \param list[] Bicicleta array
 * \param len int Length array
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int sortByciclesByType(Bicicleta list[], int len)
{
    int response=-1;
    int flag;
    int newLen;
    Bicicleta auxBicicleta;

    if(list!=NULL && len>0){
        newLen=len-1;
        do{
            flag=0;
            for(int i=0;i<newLen;i++){
                if(list[i].idTipo>list[i+1].idTipo || (list[i].idTipo==list[i+1].idTipo && list[i].rodado>list[i+1].rodado)){
                    flag=1;
                    auxBicicleta=list[i];
                    list[i]=list[i+1];
                    list[i+1]=auxBicicleta;
                }
            }
            newLen--;
        }while(flag);
        response=0;
    }
    return response;
}
