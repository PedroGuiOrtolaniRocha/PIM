#ifndef PRODUTOS_H
#define PRODUTOS_H
#include<stdio.h>
#include<stdlib.h>

struct produto {
    char nome[50];
    double precoKG;
    int codigo;
};

struct produto manga = {"Manga", 3.79, 1};
struct produto maca = {"Maçã", 9.67, 2};
struct produto bananaPrata = {"Banana Prata", 5.31, 3};
struct produto cebola = {"Cebola", 2.21, 4};
struct produto alho = {"Alho", 24.02, 5};
struct produto limao = {"Limão", 6.60, 6};
struct produto alface = {"Alface", 23.19, 7};
struct produto tomate = {"Tomate", 3.95, 8};
struct produto maracuja = {"Maracujá", 7.16, 9};
struct produto morango = {"Morango", 19.86, 10};

#endif