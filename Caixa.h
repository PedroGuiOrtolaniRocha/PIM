#ifndef CAIXA_H
#define CAIXA_H

#include <stdio.h>
#include <stdlib.h>
#include "Produtos.h"
#include "Utilidade.h" 

void calculaTroco(){
    float preco; 
    float valor;

    printf("Digite o valor da compra, separe os centavos por virgula\nEx: 1,99");
    scanf("%f", &preco);

    printf("Digite o valor do pagamento, separe os centavos por virgula\nEx: 1,99");
    scanf("%f", &valor);

    printf("O valor do troco é: %.2f\n", valor - preco);
    enterParaContinuar();
}

void estoqueEPrecos(){
    system("cls; clear");
    printf("Estoques e preços:\n");

    int i;
    for(i = 0; i < 10; i++){
        printf("Estoque %s : %.2f KGs. Preço: %.2f\n", produtos[i].nome, lerEstoque(produtos[i].arquivo), produtos[i].precoVenda);
    }
    enterParaContinuar();
}

void exibirRecibo(struct produto produtos[], float pesos[], int count) {
    float estoque[count];
    float cofre = lerEstoque("cofre.txt");

    if(!confirmar()){
        printf("Compra cancrelada!\n");
        enterParaContinuar();
        return;
    }

    printf("\nRecibo:\n");
    printf("-------------------------------\n");
    float total = 0;
    int i;

    for (i = 0; i < count; i++) {
        float subtotal = produtos[i].precoVenda * pesos[i];
        printf("%s (R$ %.2f/kg) x %.2f kg = R$ %.2f\n", produtos[i].nome, produtos[i].precoVenda, pesos[i], subtotal);
        total += subtotal;
        estoque[i] = lerEstoque(produtos[i].arquivo);
        gravarEstoque(produtos[i].arquivo, estoque[i] - pesos[i]);
    }

    printf("-------------------------------\n");
    printf("Total: R$ %.2f\n", total);

    cofre = lerEstoque("cofre.txt") + total;
    gravarEstoque("cofre.txt", cofre);
    printf("A compra de R$ %.2f foi confirmada!\n", total);
    enterParaContinuar();
    return;
    
}

void atualizaCarrinho(struct produto carrinho[], float pesos[], int *count){
    struct produto p = selecionaProduto();
    float peso;
    
    if(*count > sizeof(carrinho)){
        system("cls; clear;");
        printf("Você atingiu o limite do carrinho\n");
        enterParaContinuar();
        return;
    }

    printf("Informe o peso (KGs) do produto %s, use virgula para separar decimais:\nEx: 1,99\n", p.nome);
    scanf("%f", &peso);
    
    if(peso > lerEstoque(p.arquivo)){
        system("cls; clear;");
        printf("Não é possivel comprar %.2f KGs de %s, pois o estoque tem apenas %.2f KGs\n", peso, p.nome, lerEstoque(p.arquivo));
        enterParaContinuar();
        return;
    }
    
    carrinho[*count] = p;
    pesos[*count] = peso;
    *count += 1;
    system("cls; clear;");
}

void registrarVenda(){
    struct produto carrinho[10];
    float pesos[50];
    int count = 0;
    int reset = 1;
    char escolha = '1';

            while (reset){
                system("cls; clear;");
                printf("Deseja adicionar produtos ao carrinho?\n1 - Adicionar produto\n0 - Finalizar compra\n");
                scanf(" %c", &escolha);
                
                switch (escolha)
                {
                case '1':
                    atualizaCarrinho(carrinho, pesos, &count);
                    break;
                
                case '0':
                    reset = 0;
                    break;
                
                default:
                    break;
                }
                

                system("cls; clear;");
            } 
            exibirRecibo(carrinho, pesos, count); 
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
        printf("1 - Registrar venda\n");
        printf("2 - Consultar preços e estoque\n");
        printf("3 - Calcular troco\n");
        printf("0 - Sair\n");

        scanf(" %c", &escolha); 

        switch (escolha) {
            case '1': 
                registrarVenda();
                break;
            
            case '2': 
                estoqueEPrecos();
                break;
            
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