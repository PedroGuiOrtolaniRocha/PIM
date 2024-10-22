#ifndef PRODUTOS_H
#define PRODUTOS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct produto {
    char nome[50];
    double precoKG;
    char arquivo[50];
    int codigo;
};

struct produto produtos[10] = {
    {"Manga", 3.79, "manga.txt",1},
    {"Maçã", 9.67, "maca.txt",2},
    {"Banana Prata", 5.31, "bananaPrata.txt", 3},
    {"Cebola", 2.21, "cebola.txt", 4},
    {"Alho", 24.02, "alho.txt", 5},
    {"Limão", 6.60, "limao.txt", 6},
    {"Alface", 23.19, "alface.txt", 7},
    {"Tomate", 3.95, "tomate.txt", 8},
    {"Maracujá", 7.16, "maracuja.txt", 9},
    {"Morango", 19.86, "morango.txt", 10}
};


struct produto selecionaProduto(){

    char escolha;
    int reset = 1; 

    while(reset){
        
        /*system("cls");
        system("clear");*/

        printf("Selecione um produto:\n");

        for(int i = 0; i < 10; i++){
            printf("%s - %d\n", produtos[i].nome, produtos[i].codigo);
        }

        scanf("%d", &escolha);

        char* fim;
        char texto[1] = {escolha};
        struct produto resultado;
       
        for(int i = 0; i < 10; i++){
            if(produtos[i].codigo == escolha){
                resultado = produtos[i];
                reset = 0;
                return resultado;
            }
        }
    }
}
#endif