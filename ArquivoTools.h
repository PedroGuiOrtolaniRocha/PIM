#ifndef ARQUIVOTOOLS_H
#define ARQUIVOTOOLS_H

#include<stdio.h>
#include<string.h>

float lerEstoque(char pathArquivo[255]){
    
    int index = 0;
    FILE *arq;
    char caracter;
    char texto[255];
    char* fim;

    arq = fopen(pathArquivo, "r");
    
    while(caracter != EOF){
        caracter = fgetc(arq);
        texto[index] = caracter;
        index++;
    }

    fclose(arq);

    float resultado = strtod(texto, &fim);

    return resultado;
}

void gravarEstoque(char pathArquivo[255], float valor){
    
    FILE *arq;
    char texto[50];

    sprintf(texto, "%f", valor); 
    arq = fopen(pathArquivo, "w");

    fputs(texto, arq);
    fclose(arq);

}

#endif