#ifndef GERENTE_H
#define GERENTE_H

#include<stdio.h>
#include<stdlib.h>
#include "Produtos.h"
#include "Utilidade.h"

void verificaCofre(){
    system("cls; clear");
    float valor = lerEstoque("cofre.txt");
    printf("Valor atual do cofre:\nR$ %.2f\nAperte enter para continuar...\n", valor);
    getchar();
    getchar();
    return;
}

void comprarEstoque(){
    float valorCompra;
    float valorCofre = lerEstoque("cofre.txt");
    float quantia;
    struct produto aComprar = selecionaProduto();

    float estoqueAtual = lerEstoque(aComprar.arquivo);
    
    system("cls; clear");
    printf("Compra de quantos KGs? separe decimais por vírgula\nEx: 1,99\n");

    scanf("%f", &quantia);
    
    system("cls; clear");

    valorCompra = quantia * aComprar.precoCompra;

    if(valorCompra > valorCofre){
        printf("A compra custa %.2f e o cofre tem %.2f\nCompra negada!\nAperte enter para continuar...", valorCompra, valorCofre);
        getchar();
        getchar();
    }
    else{
        if(confirmar()){
            gravarEstoque("cofre.txt", valorCofre - valorCompra);
            gravarEstoque(aComprar.arquivo, estoqueAtual + quantia);
            printf("A compra custa %.2f e o cofre tem %.2f\nCompra aceita!\nNovo saldo cofre: R$ %.2f, Estoque de %s: de %.2f KGs para %.2f KGs\nAperte enter para continuar...", valorCompra, valorCofre, valorCofre - valorCompra, aComprar.nome, estoqueAtual, estoqueAtual + quantia);
            getchar();
            getchar();
        }
    }
}

void geraRelatorioGerente(){

    system("cls; clear");
    printf("Relatório do estoque:\n");

    int i;
    for(i = 0; i < 10; i++){
        printf("Estoque %s : %.2f KGs. Preço de compra: %.2f. Preço de venda: %.2f\n", produtos[i].nome, lerEstoque(produtos[i].arquivo), produtos[i].precoCompra, produtos[i].precoVenda);
    }
    printf("\nAperte enter para continuar...\n");
    getchar();
    getchar();
}

void menuGerente(){
    int reset = 1;
    char escolha;


    while (reset){
        
        system("cls; clear");

        printf("+-------------------------------+\n");
        printf("|   Bem-vindo ao Hortifruti!    |\n");
        printf("|       Menu do gerente         |\n");
        printf("+------------------------------ +\n");
        printf("\n");
        printf("Qual função deseja usar?\n1 - Verificar cofre\n2 - Relatório estoque\n3 - Comprar estoque\n0 - Sair\n");
        scanf("%c", &escolha);

        system("cls; clear");
                
        switch (escolha){
        
            case '0':
                reset = 0;
                system("cls; clear");
                break;

            case'1':
                verificaCofre();
                break;
             
            case'2':
                geraRelatorioGerente();
                break;

            case '3':
                comprarEstoque();
                break;
                       
            default:
                system("cls; clear");
                break;
        }
    } 
        
    return;
}

#endif