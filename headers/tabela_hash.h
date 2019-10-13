//
// Created by joaovicttors on 10/12/19.
//

#ifndef TABELA_HASH_TABELA_HASH_H
#define TABELA_HASH_TABELA_HASH_H

#include "cliente.h"

typedef struct {
    int codigo_cliente;
    int jump;
} Item;

typedef struct {
    int tamanho_tabela;
    int quantidade_atual;
    Item** itens;
} Hash;

typedef int (*Tratamento)(int, int, int, int);

Hash* criar_tabela_hash(int);
void liberar_tabela_hash(Hash*);

int inserir_hash_end_aberto(Hash*, Tratamento, int, int, int*);
int remover_hash_end_aberto(Hash*, Tratamento, int);

float calcular_fator_carga(Hash*);

#endif //TABELA_HASH_TABELA_HASH_H
