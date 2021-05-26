#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int id;
    char nombre[40];
    char sexo[20];
    int isEmpty;
}Cliente;

int cargarNombreCliente(int id, Cliente clientes[], int len, char descrip[]);
int mostrarClientes(Cliente clientes[], int len);
int findEmptyIndexCliente(Cliente clientes[], int len);
int initClientes(Cliente clientes[], int len);
void mostrarCliente(Cliente unCliente);

#endif // CLIENTE_H_INCLUDED
