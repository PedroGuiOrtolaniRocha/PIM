#ifndef USUARIOS_H
#define USUARIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Usuario
{
    int id;
    char password[50];
};

struct Usuario usuarios[] = {
    {1, "gerente123"},
    {2, "estoque123"},
    {3, "caixa123"},
    {0, ""}
};

struct Usuario login()
{
    char id [2];
    char password[50];
    int reset = 1;

    struct Usuario usuarioLogado;

    char* fim;

    while(reset){
        system("cls; clear");
        printf("+-------------------------------+\n");
        printf("|   Bem-vindo ao Hortifruti!    |\n");
        printf("|                               |\n");
        printf("+------------------------------ +\n");
        printf("\n");
        printf("Selecione o usuário:\n1 - Gerente\n2 - Estoque\n3 - Caixa\n0 - Sair\n");

        fflush(stdin);
        scanf("%s", &id);
        system("cls; clear");

        if(id == "0"){
            return usuarios[3];
        }

        fflush(stdin);

        printf("Digite a sua Senha de Login: ");
        scanf("%s", password);

        fflush(stdin);
        system("cls; clear");

        int i; 
        for (i = 0; i < sizeof(usuarios); i++)
        {
            if(strtol(id, &fim, 10) == usuarios[i].id && strcmp(password, usuarios[i].password) == 0) {
    
                printf("Login bem sucedido! %s", usuarios[i].password);
                return usuarios[i];
                reset = 0;
                break;
            }
    }

    printf("usuário e/ou senha inválidos\n");
    
    }

}


#endif