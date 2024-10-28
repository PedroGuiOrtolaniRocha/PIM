#ifndef CAIXA_H
#define CAIXA_H

#include <stdio.h>
#include <stdlib.h>
#include "produtos.h" 

void exibirRecibo(struct produto produtos[], float pesos[], int count) {
    printf("\nRecibo:\n");
    printf("-------------------------------\n");
    float total = 0;
    int i;

    for (i = 0; i < count; i++) {
        float subtotal = produtos[i].precoVenda * pesos[i]/1000;
        printf("%s (R$ %.2f/kg) x %.2f kg = R$ %.2f\n", produtos[i].nome, produtos[i].precoVenda, pesos[i], subtotal);
        total += subtotal;
    }

    printf("-------------------------------\n");
    printf("Total: R$ %.2f\n", total);
}

void menuCaixa() {
    int reset = 1;
    char escolha;

    while (reset) {
        system("cls; clear");
        printf("+-------------------------------+\n");
        printf("|   Bem-vindo ao Hortifruti!    |\n");
        printf("|         Menu do Caixa         |\n");
        printf("+------------------------------ +\n");
        printf("\n");
        
        printf("Qual função deseja usar?\n");
        printf("1 - Selecionar produtos\n");
        printf("0 - Sair\n");

        scanf(" %c", &escolha); 

        switch (escolha) {
            case '1': {
                struct produto produtosSelecionados[10];
                float pesos[10];
                int count = 0;
                char continuar;

                do {
                    struct produto p = selecionaProduto();
                    produtosSelecionados[count] = p;

                    printf("Informe o peso (em gramas) do produto %s: ", p.nome);
                    scanf("%f", &pesos[count]);

                    count++;

                    printf("Deseja adicionar mais produtos? (s/n): ");
                    scanf(" %c", &continuar);
                } while (continuar == 's' || continuar == 'S');

                 exibirRecibo(produtosSelecionados, pesos, count); 
                printf("Pressione qualquer tecla para continuar...\n");
                getchar(); 
                getchar(); 
                break;
            }
            case '0':
                reset = 0;
                system("cls; clear");
                break;
            default:
                system("cls; clear");
                printf("Selecione uma opção válida!\n");
                break;
        }
    } 
}

#endif