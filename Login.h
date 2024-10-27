#ifndef LOGIN_H
#define LOGIN_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Usuarios.h"


struct Usuario* login()
{
    struct Usuario* usuarios = getUsuarios();
    static struct Usuario usuarioLogado;

    int encontrado = 0; // Flag para indicar se o login foi bem-sucedido

    char* username = "pedro";
    char* password = "pedro123";

    // printf("Digite o seu nome de Usuario: ");
    // fflush(stdin);
    // scanf("%c", &username);

    // printf("Digite a sua Senha de Login: ");
    // fflush(stdin);
    // scanf("%c", &password);

    int i; // Declare a variável antes do loop
    for (i = 0; i < sizeof(usuarios); i++)
    {
        if(strcmp(username, usuarios[i].username) == 0 && strcmp(password, usuarios[i].password) == 0) {
            struct Usuario usuarioLogado = usuarios[i];
            printf("Login bem sucedido! Bem vindo(a) %s", usuarios[i].username);
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