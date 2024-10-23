#ifndef ARQUIVOTOOLS_H
#define ARQUIVOTOOLS_H

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

    float resultado = resultado = strtof(texto, &fim);

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

#endif