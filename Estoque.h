#ifndef ESTOQUE_H
#define ESTOQUE_H

#include<stdio.h>
#include<stdlib.h>
#include "Produtos.h"
#include "ArquivoTools.h"

void consultarEstoque(){
    struct produto estoque = selecionaProduto();
    float quantia = lerEstoque(estoque.arquivo);
    system("cls; clear");
    printf("O estoque de %s\n%.2f KG`s\nAperte qualquer tecla para continuar...\n", estoque.nome, quantia);
    getchar();
    getchar();
    return;
}

void menuEstoque(){
    int reset = 1;

    fflush(stdin);
    char escolhaEstq;


    while (reset){
        char fim;

        system("cls; clear");
        
        printf("Menu do estoque\nQual função deseja usar?\n1 - Cosultar estoque\n0 - Sair\n");

        scanf("%c", &escolhaEstq);
        
        switch (escolhaEstq){
        
            case '0':
                reset = 0;
                system("cls; clear");
                break;
            
            case '1':
                consultarEstoque();    
                break;

            default:
                system("cls; clear");
                break;
        }
    } 
    

}

#endif