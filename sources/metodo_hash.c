//
// Created by joaovicttors on 10/12/19.
//

#include <stdio.h>

#include "../headers/metodo_hash.h"

/**
 *
 *  @param codigo_cliente
 *  @param tamanho_tabela
 *  @return
 */
int metodo_divisao(int codigo_cliente, int tamanho_tabela) {
    return codigo_cliente % tamanho_tabela;
}