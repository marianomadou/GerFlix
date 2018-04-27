#include "usuario.h"
#include "serie.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#define TAM 4
#define LONG 25

void menuUsuario(eUsuario lista[], eSerie listaserie[], int tam)
{
        int opcion;
        int index;
        //int carga=0;
        int numusuario;

        do{

                printf("---MENU DE USUARIO---\n\n");
                printf("1 - ALTA USUARIO\n");
                printf("2 - BAJAS\n");
                printf("3 - MODIFICACIONES\n");
                printf("4 - MOSTRAR\n");
                printf("5 - ORDENAR\n");
                printf("6 - MENU SERIES\n\n");
                printf("9 - SALIR\n");

                opcion = IngresarOpcionMenu(1,9);

                switch(opcion){
                    case 1:
                        index=buscarUsuarioLibre(lista,TAM);
                        if(index!=-1){
                            lista[index].idUsuario = index+1;
                            printf("\nIngrese nombre: ");
                            gets(lista[index].nombre);
                            fflush(stdin);
                            printf("\nIngrese email: ");
                            gets(lista[index].email);
                            fflush(stdin);
                            printf("\nIngrese password: ");
                            gets(lista[index].Password);
                            lista[index].estado = 1;


                            printf("\nQue serie que desea ver? Ingresar ID: \n");


                            for(int i=0;i<TAM;i++){
                                if(listaserie[i].estado==1){
                                    printf("\n---------------------");
                                    printf("\nID N: %d",listaserie[i].idSerie);
                                    printf(" Nombre: ");
                                    puts(listaserie[i].nombre);
                                    printf(" Genero: ");
                                    puts(listaserie[i].genero);
                                    printf(" Temporadas: %d\n",listaserie[i].canttemporadas);
                                }
                            }

                            scanf("%d",&lista[index].idSerie);

                        }else{
                            printf("No hay mas espacio para guardar usuarios!!!");
                            getche();
                        }
                        break;
                    case 2:
                        printf("ID Serie: ");
                        scanf("%d",&numusuario);
                        fflush(stdin);
                        index=buscarUsuario(lista,TAM,numusuario);
                        if(index!=-1){
                            lista[index].idUsuario=0;
                        }else{
                            printf("Usuario no encontrado!!!");

                        }
                        break;
                    case 3:
                        printf("ID Serie: ");
                        scanf("%d",&numusuario);
                        fflush(stdin);
                        index=buscarUsuario(lista,TAM,numusuario);
                        if(index!=-1){
                            printf("\nSerie N: %d",lista[index].idUsuario);
                            printf("\nModificar Nombre: ");
                            gets(lista[index].nombre);
                            fflush(stdin);
                            printf("\nModificar email: ");
                            gets(lista[index].email);
                            fflush(stdin);
                            printf("\nModificar temporadas: ");
                            gets(lista[index].Password);
                            fflush(stdin);
                            printf("\nModificar Serie: ");
                            scanf("%d",&lista[index].idSerie);
                            fflush(stdin);
                            printf("\nModificar Estado: ");
                            scanf("%d",&lista[index].estado);


                        }else{
                            printf("Serie no encontrada!!!");
                            getche();
                        }
                        break;

                        case 4:
                            for(int i=0;i<TAM;i++){
                                if(lista[i].estado==1){
                                    printf("\n---------------------");
                                    printf("\nID N: %d",lista[i].idUsuario);
                                    printf("\nNombre: ");
                                    puts(lista[i].nombre);
                                    printf("\nEmail: ");
                                    puts(lista[i].email);
                                    printf("Pass: %s",lista[i].Password);
                                    printf("\nSerie: %d",lista[i].idSerie);
                                    printf("\nEstado: %d",lista[i].estado);
                                }

                            }

                            /*if (carga == 0){
                            printf("No hay series cargadas\n");
                            }*/

                            break;

                    /*case 6:

                    getchar();
                    int main();*/

   }

            printf("\n\n");
            system("pause");
            system("cls");

            }while(opcion!=9);

}

int buscarUsuarioLibre(eUsuario vec[],int tam)
{
    int index = -1;

    for(int i=0;i<tam;i++){
        if(vec[i].idUsuario==0){
            index=i;
            break;
        }
    }

     return index;
}

int buscarUsuario(eUsuario vec[],int tam,int id){

    int retorno= -1;
    for(int i=0;i<tam;i++){
        if(vec[i].idUsuario==id){
            retorno = i;
        }
    }
    return retorno;
}


void inicializarUsuariosEstado(eUsuario usuarios[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        usuarios[i].estado = 0;
    }
}

void inicializarUsuariosHardCode(eUsuario usuarios[])
{
    int id[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};
    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,101,100,100,101};

    int i;

    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);
    }
}
/*
void mostrarUsuarioConSuSerie(eUsuario usuarios[], int cantU, eSerie series[], int cantS)
{
    int i;
    int j;

    for(i=0; i<cantU; i++)
    {
        if(usuarios[i].estado==1)
        {
            printf("%3d %10s ", usuarios[i].idUsuario, usuarios[i].nombre);
            for(j=0; j<cantS; j++)
        {

        if(series[j].estado == 1 && usuarios[i].idSerie == series[j].idSerie)
        {
            printf("%s", series[j].nombre);
            break;
        }
        }
            printf("\n");
        }
    }
}
void mostrarListaUsuarios(eUsuario usuarios[], int t)
{
        printf("\n--LISTA DE USUARIOS--\n");

        for(int i=0;i<t;i++)
        {
        if(usuarios[i].estado==1)
        {
        printf("%d %s\n", usuarios[i].idUsuario, usuarios[i].nombre);
        }
    }
}
*/
