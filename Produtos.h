#ifndef PRODUTOS_H
#define PRODUTOS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct produto {
    char nome[50];
    float precoCompra;
    float precoVenda;
    char arquivo[50];
    int codigo;
};


struct produto produtos[10] = {
    {"Manga", 3.79, 5.31, "manga.txt", 1},
    {"Maçã", 9.67, 13.54, "maca.txt", 2},
    {"Banana Prata", 5.31, 7.43, "bananaPrata.txt", 3},
    {"Cebola", 2.21, 3.09, "cebola.txt", 4},
    {"Alho", 24.02, 33.63, "alho.txt", 5},
    {"Limão", 6.60, 9.24, "limao.txt", 6},
    {"Laranja", 23.19, 32.47, "laranja.txt", 7},
    {"Tomate", 3.95, 5.53, "tomate.txt", 8},
    {"Maracujá", 7.16, 10.02, "maracuja.txt", 9},
    {"Morango", 19.86, 27.80, "morango.txt", 10}
};

struct produto selecionaProduto(){
    fflush(stdin);

    char escolha[2];
    int reset = 1; 
    int i;

    while(reset){
        
        system("cls; clear");

        printf("Selecione um produto:\n");

        int i;
        for(i = 0; i < 10; i++){
            printf("%s - %d\n", produtos[i].nome, produtos[i].codigo);
        }

        scanf("%s", escolha);

        char* fim;
        int escolhaInt = strtol(escolha, &fim, 10);
        struct produto resultado;

        
        for(i = 0; i < 10; i++){
            if(produtos[i].codigo == escolhaInt){
                resultado = produtos[i];
                reset = 0;
                return resultado;
            }
        }

        system("cls; clear");
    }
}
#endif