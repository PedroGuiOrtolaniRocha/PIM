#ifndef CAIXA_H
#define CAIXA_H

#include<stdio.h>
#include<stdlib.h>

void menuCaixa(){
    int reset = 1;
    char escolha;

    while (reset){
        
        system("cls; clear");
        
        printf("Menu do caixa\nQual função deseja usar?\n0 - Sair\n");

        scanf("%c", &escolha);

        printf("%c", escolha);
                
        switch (escolha){
        
            case '0':
                reset = 0;
                system("cls; clear");
                break;
            
            default:
                system("cls; clear");
                printf("Selcione uma opção válida!\n");
                break;
        }
    } 
        

}

#endif