#ifndef ESTOQUE_H
#define ESTOQUE_H

#include<stdio.h>
#include<stdlib.h>
#include "Produtos.h"
#include "Utilidade.h"

void consultarEstoque(){
    
    struct produto estoque = selecionaProduto();
    system("cls; clear");
    float quantia = lerEstoque(estoque.arquivo);
    printf("O estoque de %s\n%.2f KG`s\nAperte enter para continuar...\n", estoque.nome, quantia);
    getchar();
    getchar();
    return;
}

void atualizarEstoque(){

    struct produto estoque = selecionaProduto();
    float quantia = lerEstoque(estoque.arquivo);
    float valor;
    
    system("cls; clear");
    printf("Quantos KGs o estoque tem? separe decimais por vírgula\nEx: 1,99\n");
    scanf("%f", &valor);

    system("cls; clear");

    if (valor < 0){
        printf("O estoque de nunca pode ficar abaixo de 0!\nAperte enter para continuar...\n");
    }
    
    else{
        if(confirmar()){
            printf("O estoque de %s atualizado para %.2f KG`s\nAperte enter para continuar...\n", estoque.nome, valor);
            gravarEstoque(estoque.arquivo, valor);
            getchar();
            getchar();
        }
        
    }


    return;
}

void geraRelatorio(){

    system("cls; clear");
    printf("Relatório do estoque:\n");
    for(int i = 0; i < 10; i++){
        printf("%s - %.2f KGs\n", produtos[i].nome, lerEstoque(produtos[i].arquivo));
    }

    printf("\nAperte enter para continuar...\n");
    getchar();
    getchar();
}


void menuEstoque(){
    int reset = 1;

    fflush(stdin);
    char escolhaEstq;


    while (reset){
        char fim;

        system("cls; clear");
        
        printf("Menu do estoque\nQual função deseja usar?\n1 - Cosultar estoque\n2 - Atualizar estoque\n3 - Gerar relatório do estoque\n0 - Sair\n");

        scanf("%c", &escolhaEstq);
    
        system("cls; clear");

        switch (escolhaEstq){
        
            case '0':
                reset = 0;
                system("cls; clear");
                break;
            
            case '1':
                consultarEstoque();    
                break;
            
            case '2':
                atualizarEstoque();    
                break;

            case '3':
                geraRelatorio();
                break;

            default:
                system("cls; clear");
                break;
        }
    } 
}

#endif