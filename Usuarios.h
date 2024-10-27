#ifndef USUARIOS_H
#define USUARIOS_H

#include <stdio.h>
#include <stdlib.h>

struct Usuario
{
    int id;
    char username[50];
    char password[50];
    char role[50];
};

struct Usuario usuarios[] = {
    {1, "daiane", "daiane123", "gerente"},
    {2, "pedro", "pedro123", "gerente"},
    {3, "henrique", "henrique123", "estoquista"},
    {4, "william", "william123", "estoquista"},
    {5, "maxwell", "maxwell123", "caixa"},
    {6, "julio", "julio123", "caixa"},
};

struct Usuario* getUsuarios() {
    return usuarios;
}


#endif