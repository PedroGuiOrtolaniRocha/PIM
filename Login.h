#ifndef LOGIN_H
#define LOGIN_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Usuarios.h"


struct Usuario* login()
{
   int id [50];
    char password[50];

    struct Usuario* usuarios = getUsuarios();
    struct Usuario usuarioLogado;

    int encontrado = 0; // Flag para indicar se o login foi bem-sucedido

 
    printf("Digite o seu nome de Usuario: ");
    fflush(stdin);
    scanf("%d", &id);

    printf("Digite a sua Senha de Login: ");
    fflush(stdin);
    scanf("%s", password);

    int i; // Declare a variável antes do loop
    for (i = 0; i < sizeof(usuarios); i++)
    {
        if(strcmp(id, usuarios[i].id) == 0 && strcmp(password, usuarios[i].password) == 0) {
            struct Usuario usuarioLogado = usuarios[i];
            printf("Login bem sucedido! Bem vindo(a) %s", usuarios[i].id);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario ou senha incorretos.\n");
        return NULL; // Retorna NULL se não encontrar o usuário
    } else {
        return &usuarioLogado; // Retorna o ponteiro para o usuário logado
    }

}

#endif