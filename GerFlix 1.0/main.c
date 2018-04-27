#include "usuario.h"
#include "serie.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAMSERIE 20
#define TAMUSUARIO 100
#define TAM 4
#define LONG 25

/*  cambiar int lanzamiento por char genero
    int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;
*/

int main()
{
    eSerie listaSerie[TAM]= {{0}};
    cargarDatosHardCode(listaSerie);

    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);*/

    menuSerie(listaSerie, TAM);

    return 0;
}

/*
1.    mostrarListaSeries(listaDeSeries, TAMSERIE);
2.    mostrarListaUsuarios(listaDeUsuarios, TAMUSUARIO);
3.    mostrarUsuarioConSuSerie(listaDeUsuarios, TAMUSUARIO, listaDeSeries, TAMSERIE);
*/
