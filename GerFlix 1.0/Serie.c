#include "usuario.h"
#include "serie.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#define TAM 4
#define LONG 25

void menuSerie(eSerie lista[], int tam)
{
        int opcion;
        int index;
        //int carga=0;
        int numserie;
        eUsuario listaUsuarios[TAM]= {{0}};

        do{
                printf("---MENU DE SERIES---\n\n");
                printf("1 - ALTA SERIE\n");
                printf("2 - BAJAS\n");
                printf("3 - MODIFICACIONES\n");
                printf("4 - MOSTRAR\n");
                printf("5 - ORDENAR\n");
                printf("6 - MENU USUARIOS\n\n");
                printf("9 - SALIR\n");

                opcion = IngresarOpcionMenu(1,9);

                switch(opcion){
                    case 1:
                        index=buscarLibre(lista,TAM);
                        if(index!=-1){
                            lista[index].idSerie = index+1;
                            fflush(stdin);
                            printf("\nIngrese Nombre: ");
                            gets(lista[index].nombre);
                            fflush(stdin);
                            printf("\nIngrese genero de la serie: ");
                            gets(lista[index].genero);
                            printf("\nIngrese Cantidad de Temporadas: ");
                            scanf("%d",&lista[index].canttemporadas);
                            fflush(stdin);
                            lista[index].estado = 1;

                        }else{
                            printf("No hay mas espacio para guardar series!!!");
                            getche();
                        }
                        break;
                    case 2:
                        printf("ID Serie: ");
                        scanf("%d",&numserie);
                        fflush(stdin);
                        index=buscarSerie(lista,TAM,numserie);
                        if(index!=-1){
                            lista[index].idSerie=0;
                        }else{
                            printf("Serie no encontrada!!!");

                        }
                        break;
                    case 3:
                        printf("ID Serie: ");
                        scanf("%d",&numserie);
                        fflush(stdin);
                        index=buscarSerie(lista,TAM,numserie);
                        if(index!=-1){
                            printf("\nSerie N: %d",lista[index].idSerie);
                            printf("\nModificar nombre: ");
                            gets(lista[index].nombre);
                            fflush(stdin);
                            printf("\nModificar genero: ");
                            gets(lista[index].genero);
                            printf("\nModificar temporadas: ");
                            scanf("%d",&lista[index].canttemporadas);
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
                                    printf("\nID N: %d",lista[i].idSerie);
                                    printf("\nNombre: ");
                                    puts(lista[i].nombre);
                                    printf("\nGenero: ");
                                    puts(lista[i].genero);
                                    printf("Temporadas: %d",lista[i].canttemporadas);
                                    printf("\nEstado: %d",lista[i].estado);
                                }

                            }

                            /*if (carga == 0){
                            printf("No hay series cargadas\n");
                            }*/

                            break;

                    case 6:
                    system("cls");
                    menuUsuario(listaUsuarios, lista, TAM);

                }

            printf("\n\n");
            system("pause");
            system("cls");

            }while(opcion!=9);

}


int buscarLibre(eSerie vec[],int tam)
{
    int index = -1;
    for(int i=0;i<tam;i++){
        if(vec[i].idSerie==0){
            index=i;
            break;
        }
    }
     return index;
}

int buscarSerie(eSerie vec[],int tam,int id){

    int retorno= -1;
    for(int i=0;i<tam;i++){
        if(vec[i].idSerie==id){
            retorno = i;
        }
    }
    return retorno;
}



void cargarDatosHardCode(eSerie lista[])
{

    int id[5]={100,101,102,103,104};
    char nombre[][LONG]={"TBBT","TWD","GOT","BB","LCDP"};
    char genero[][LONG]={"Comedia","Terror","Suspenso","Policial","Policial"};
    int temporadas[5]={10,9,7,5,2};
    int estado[5]={1,1,1};

    for(int i=0; i<3; i++)
    {
        lista[i].idSerie=id[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].genero, genero[i]);
        lista[i].canttemporadas=temporadas[i];
        lista[i].estado=estado[i];

    }
}

int IngresarOpcionMenu(int min, int max)
{
    int entero;

    fflush(stdin);
    scanf("%d",&entero);
    entero = validarOpcionMenu(entero, min, max);

    return entero;
}

int validarOpcionMenu (int dato, int min, int max)
{
    while(dato < min || dato > max)
    {
        fflush(stdin);
        printf("Dato no v%clido reingresar:\n", 160);
        scanf("%d", &dato);
    }
    return dato;
}
