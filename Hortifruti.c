#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include "Produtos.h"
#include "Gerente.h"
#include "Caixa.h"
#include "Estoque.h"
#include "Usuarios.h"



int main(){

    int reset = 1;
    int escolha; 

    setlocale(LC_ALL, "Portuguese");

    while(reset){

        fflush(stdin);

        struct Usuario usuarioLogado = login();
        escolha = usuarioLogado.id;

        switch(escolha){
        case 1:
            menuGerente();
            break;
            
        case 2:
            menuEstoque();
            break;

        case 3:
            menuCaixa();
            break;
        
        case 0:
            reset = 0;
            break;

        default:
            break;
        }
    }

    return 0;
}
