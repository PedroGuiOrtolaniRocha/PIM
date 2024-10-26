#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#include "Utilidade.h"
#include "Gerente.h"
#include "Caixa.h"
#include "Estoque.h"
#include "Produtos.h"

int main(){

    int reset = 1;
    char escolha;
    
    setlocale(LC_ALL, "Portuguese");

    while (reset){
        system("cls; clear");

        fflush(stdin);
        printf("Selecione o usuário\n1 - Gerente\n2 - Estoque\n3 - Caixa\n0 - Sair\n");

        scanf("%c", &escolha);
        system("cls; clear");

        switch (escolha){
        
            case '1':
                menuGerente();
                break;
            
            case '2':
                menuEstoque();
                break;
            
            case '3':
                menuCaixa();
                break;
            
            case '0':
                reset = 0;
                system("cls; clear");
                break;
            
            default:
                break;
        }
    }

    return 0;
}
