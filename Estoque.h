#ifndef ESTOQUE_H
#define ESTOQUE_H

#include<stdio.h>
#include<stdlib.h>
#include "Produtos.h"
#include "ArquivoTools.h"

void consultarEstoque(){
    char fim;
    struct produto estoque = selecionaProduto();
    float quantia = lerEstoque(estoque.arquivo);
    system("cls; clear");
    printf("O estoque de %s\n%f KG`s\n%s\nAperte qualquer tecla para continuar...", estoque.nome, quantia, estoque.arquivo);

    scanf("%c", &fim);
    return;
}

void menuEstoque(){
    int reset = 1;
    char escolha;


    while (reset){
        
        //system("cls; clear");
        
        printf("Menu do estoque\nQual função deseja usar?\n1 - Cosultar estoque\n0 - Sair\n");

        scanf("%c", &escolha);

        printf("%c", escolha);
                
        switch (escolha){
        
            case '0':
                reset = 0;
                system("cls; clear");
                break;
            
            case '1':
                consultarEstoque();
                break;

            default:
                system("cls; clear");
                printf("Selcione uma opção válida!\n");
                break;
        }
    } 
    

}

#endif