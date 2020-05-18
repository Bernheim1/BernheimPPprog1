#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char procesador[51];
    char marca[51];
    float precio;
} eNotebook;

#define TAM 6

float aplicarDescuento(float precio);
int contarCaracteres(char cadena[],char letra);
void ordenarNotebooks(eNotebook x[],int tam);

int main()
{
    float precioDescuento;
    int cantidadCaractes;
    eNotebook listaNotebooks[TAM] ={
    {0,"Intel","Acer",100.00},
    {1,"AMD","BGH",120.00},
    {2,"Intel","Acer",250.00},
    {3,"AMD","BGH",200.00},
    {4,"Intel","Asus",500.00},
    {5,"Intel","HP",300.00},

    };

    precioDescuento = aplicarDescuento(10);

    printf("El precio con descuento es: %.2f\n\n",precioDescuento);

    cantidadCaractes = contarCaracteres("aasssaa",'a');

    printf("La cantidad de caracteres son: %d \n\n",cantidadCaractes);

    ordenarNotebooks(listaNotebooks,TAM);

    printf(" ID      PROCESADOR       MARCA    PRECIO\n");
    for(int i = 0;i<TAM;i++)
    {
        printf(" %d    %10s    %10s    $%.2f \n",listaNotebooks[i].id,listaNotebooks[i].procesador,listaNotebooks[i].marca,listaNotebooks[i].precio);
    }

    return 0;
}


float aplicarDescuento(float precio)
{
    float precioDescuento;
    float descuento=5;

    descuento=precio*descuento/100;

    precioDescuento=precio-descuento;


    return precioDescuento;
}
int contarCaracteres(char cadena[],char letra)
{
    int repeticiones=0;

    for(int i = 0;cadena[i]!='\0';i++)
    {
        if(cadena[i]==letra)
        {
            repeticiones++;
        }
    }


    return repeticiones;
}
void ordenarNotebooks(eNotebook x[],int tam)
{
    eNotebook auxNotebook;

    for(int i = 0;i<tam-1;i++)
    {
        for(int j = i+1;j<tam;j++)
        {
            if(strcmp(x[i].marca,x[j].marca)>0)
            {
                auxNotebook=x[i];
                x[i]=x[j];
                x[j]=auxNotebook;
            }
            else
            {
                if(strcmp(x[i].marca,x[j].marca)==0 && x[i].precio<x[j].precio)
                {
                    auxNotebook=x[i];
                    x[i]=x[j];
                    x[j]=auxNotebook;
                }
            }
        }
    }
}



