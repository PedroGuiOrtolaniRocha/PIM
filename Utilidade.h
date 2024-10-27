#ifndef UTILIDADE_H
#define UTILIDADE_H

#include<stdio.h>
#include<string.h>

float lerEstoque(char pathArquivo[]){
    
    int index = 0;
    FILE *arq;
    char caracter;
    char texto[255];
    char* fim;

    arq = fopen(pathArquivo, "r");

    fgets(texto, sizeof(texto), arq);
    fclose(arq);

    float resultado = strtof(texto, &fim);

    return resultado;
}

void gravarEstoque(char pathArquivo[], float valor){
    
    FILE *arq;
    char texto[50];

    sprintf(texto, "%f", valor); 
    arq = fopen(pathArquivo, "w");

    fputs(texto, arq);
    fclose(arq);

}

int confirmar(){
    int decisao;

    system("cls; clear");
    printf("Confirmar operação?\n1 - Sim\n0 - Não\n");

    scanf("%d", &decisao);
    system("cls; clear");

    return decisao;
}

#endif