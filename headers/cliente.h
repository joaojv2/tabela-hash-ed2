//
// Created by joaovicttors on 10/12/19.
//

#ifndef TABELA_HASH_CLIENTE_H
#define TABELA_HASH_CLIENTE_H

#include <stdio.h>

typedef struct {
    int codigo;
    char nome[20];
    char data_aniversario[20];
} Cliente;

int inserir_cliente(FILE*, Cliente*);
int buscar_cliente(FILE*, Cliente*);
int procurar_cliente(FILE*, Cliente*, int);

#endif //TABELA_HASH_CLIENTE_H
