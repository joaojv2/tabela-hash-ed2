//
// Created by joaovicttors on 10/13/19.
//

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/arquivo.h"
#include "../headers/cliente.h"

#define ESCRITA "w+b"
#define LEITURA "a+b"

#define DEFAULT_NAME "test"
#define DEFAULT_BIRTHDAY "01/01/01"

#define MINIMO 1
#define MAXIMO 200

/**
 *
 *  @param nome_arquivo
 *  @param modo_abertura
 *  @return
 */
FILE* abrir_arquivo(char* nome_arquivo, char* modo_abertura) {
    FILE* arquivo;

    if ((arquivo = fopen(nome_arquivo, modo_abertura)) == NULL) {
        return NULL;
    }

    return arquivo;
}

/**
 *
 *  @param minimo
 *  @param maximo
 *  @return
 */
int gerar_codigo_cliente(int minimo, int maximo) {
    return rand() % ((maximo + 1) - minimo) + minimo;
}

/**
 *
 *  @param nome_arquivo
 *  @param tamanho
 */
void gerar_arquivo_teste(char* nome_arquivo, int tamanho) {
    srand(time(NULL));

    FILE* arquivo = abrir_arquivo(nome_arquivo, ESCRITA);
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));

    for (int i = 0; i < tamanho; i ++) {
        cliente->codigo = gerar_codigo_cliente(MINIMO, MAXIMO);

        strcpy(cliente->nome, DEFAULT_NAME);
        strcpy(cliente->data_aniversario, DEFAULT_BIRTHDAY);

        inserir_cliente(arquivo, cliente);
    }

    free(cliente);
    fclose(arquivo);
}