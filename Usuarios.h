#ifndef USUARIOS_H
#define USUARIOS_H

#include <stdio.h>
#include <stdlib.h>

struct Usuario
{
    int id;
    char password[50];
   
};

struct Usuario usuarios[] = {
    {1, "gerente123"},
    {2, "estoque123"},
    {3, "caixa123"}
   
};

struct Usuario* getUsuarios() {
    return usuarios;
}


#endif