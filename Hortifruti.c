#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#include "ArquivoTools.h"
#include "Gerente.h"
#include "Caixa.h"
#include "Estoque.h"
#include "Produtos.h"

int main(){
    int reset = 1;
    char escolha;
    
    setlocale(LC_ALL, "Portuguese");

    while (reset){
        
        printf("Selecione o usuário\n1 - Gerente\n2 - Estoque\n3 - Caixa\n0 - Sair\n");

        scanf("%c", &escolha);
                
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
                system("cls; clear");
                break;
        }
    }

    return 0;
}
