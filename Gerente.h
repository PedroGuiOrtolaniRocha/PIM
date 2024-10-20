#ifndef GERENTE_H
#define GERENTE_H

#include<stdio.h>
#include<stdlib.h>

void menuGerente(){
    int reset = 1;
    char escolha;


    while (reset){
        
        system("cls; clear");
        
        printf("Menu do gerente\nQual função deseja usar?\n0 - Sair\n");

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