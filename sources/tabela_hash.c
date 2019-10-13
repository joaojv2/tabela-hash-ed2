//
// Created by joaovicttors on 10/12/19.
//

#include <stdio.h>
#include <stdlib.h>

#include "../headers/tabela_hash.h"
#include "../headers/metodo_hash.h"

/**
 *  Essa função cria a tabela hash setando seu tamanho, quantidade
 *  de itens inseridos e criando um array de clientes.
 *
 *  @param tamanho_tabela tamanho do array de clientes da tabela.
 */
Hash* criar_tabela_hash(int tamanho_tabela) {
    Hash* tabela_hash = (Hash*) malloc(sizeof(Hash));

    if (tabela_hash != NULL) {
        tabela_hash->tamanho_tabela = tamanho_tabela;
        tabela_hash->quantidade_atual = 0;

        tabela_hash->itens = (Item**) malloc(tamanho_tabela * sizeof(Item*));
        if (tabela_hash->itens == NULL) {
            free(tabela_hash);
        }

        for (int i = 0; i < tabela_hash->tamanho_tabela; i ++) {
            tabela_hash->itens[i] = NULL;
        }
    }

    return tabela_hash;
}

/**
 *  Essa função libera o espaço onde a tabela hash tinha sido inserida,
 *  liberando tanto a tabela quanto os itens nela inseridos.
 *
 *  @param tabela_hash o ponteiro da tabela hash.
 */
void liberar_tabela_hash(Hash* tabela_hash) {
    if (tabela_hash != NULL) {
        for (int i = 0; i < tabela_hash->tamanho_tabela; i ++) {
            if (tabela_hash->itens[i] != NULL) {
                free(tabela_hash->itens[i]);
            }
        }

        free(tabela_hash->itens);
        free(tabela_hash);
    }
}

/**
 *
 *  @param tabela_hash ponteiro da tabela hash.
 *  @param tratamento metodo de tratamento de colisão.
 *  @return 1 se foi inserido e 0 se der algum erro.
 */
int inserir_hash_end_aberto(Hash* tabela_hash, Tratamento tratamento, int codigo_cliente, int jump_seek, int* colisoes) {
    if (tabela_hash == NULL || tabela_hash->quantidade_atual == tabela_hash->tamanho_tabela) {
        return 0;
    }

    int posicao = metodo_divisao(codigo_cliente, tabela_hash->tamanho_tabela);

    for (int i = 0; i < tabela_hash->tamanho_tabela; i ++) {
        int nova_posicao = tratamento(posicao, i, tabela_hash->tamanho_tabela, codigo_cliente);

        if (tabela_hash->itens[nova_posicao] == NULL) {
            Item* novo_item = (Item*) malloc(sizeof(Item));

            novo_item->codigo_cliente = codigo_cliente;
            novo_item->jump = jump_seek;

            tabela_hash->itens[nova_posicao] = novo_item;
            tabela_hash->quantidade_atual ++;

            *colisoes += i;

            return 1;
        }
    }

    *colisoes += tabela_hash->tamanho_tabela;
    return  0;
}

/**
 *
 *  @param tabela_hash ponteiro da tabela hash.
 *  @param codigo_cliente codigo do cliente a ser buscado.
 *  @param tratamento metodo de tratamento de colisão.
 *  @return 1 se achar o cliente e 0 se não achar ou der erro.
 */
int remover_hash_end_aberto(Hash* tabela_hash, Tratamento tratamento, int codigo_cliente) {
    if (tabela_hash == NULL) {
        return 0;
    }

    int posicao = metodo_divisao(codigo_cliente, tabela_hash->tamanho_tabela);

    for (int i = 0; i < tabela_hash->tamanho_tabela; i ++) {
        int nova_posicao = tratamento(posicao, i, tabela_hash->tamanho_tabela, codigo_cliente);

        if (tabela_hash->itens[nova_posicao] == NULL) {
            return 0;
        }

        if (tabela_hash->itens[nova_posicao]->codigo_cliente == codigo_cliente) {
            tabela_hash->itens[nova_posicao] = NULL;
            return 1;
        }
    }

    return 0;
}
