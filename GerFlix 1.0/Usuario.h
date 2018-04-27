#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

#include "serie.h"


typedef struct
{
int idUsuario;
char nombre[LONG];
char email[25];
char Password[25];
int idSerie;
int estado;
} eUsuario;


void menuUsuario(eUsuario [], eSerie [], int tam);
int buscarUsuario(eUsuario [],int,int);
int buscarUsuarioLibre(eUsuario [],int);


void inicializarUsuariosHardCode(eUsuario[]);
void inicializarUsuariosEstado(eUsuario[], int);

/*
void mostrarListaUsuarios(eUsuario[], int);
void mostrarUsuarioConSuSerie(eUsuario[], int, eSerie[], int);
*/
#endif // FUNCIONES_H_INCLUDED
