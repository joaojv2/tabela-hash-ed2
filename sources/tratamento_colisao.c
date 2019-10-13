//
// Created by joaovicttors on 10/12/19.
//

#include "../headers/tabela_hash.h"
#include "../headers/metodo_hash.h"

/**
 *
 *  @param posicao
 *  @param i
 *  @param tamanho_tabela
 *  @return
 */
int tentativa_linear(int posicao, int i, int tamanho_tabela, int j) {
    return ((posicao + i)) % tamanho_tabela;
}

/**
 *
 *  @param posicao
 *  @param i
 *  @param tamanho_tabela
 *  @return
 */
int tentativa_quadratica(int posicao, int i, int tamanho_tabela, int j) {
    posicao = posicao + (2 * i) + (5 * i * i);
    return posicao % tamanho_tabela;
}

/**
 *
 *  @param posicao
 *  @param codigo
 *  @param i
 *  @param tamanho_tabela
 *  @return
 */
int dispersao_dupla(int posicao, int i, int tamanho_tabela, int codigo) {
    int posicao_secundaria = metodo_divisao(codigo, tamanho_tabela - 1) + 1;
    return (posicao + (i * posicao_secundaria)) % tamanho_tabela;
}

/**
 *
 *  @param tabela_hash
 *  @return
 */
float calcular_fator_carga(Hash* tabela_hash) {
    return (tabela_hash->quantidade_atual * 1.0) / (tabela_hash->tamanho_tabela * 1.0);
}