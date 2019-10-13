//
// Created by joaovicttors on 10/12/19.
//

#include <stdio.h>

#include "../headers/cliente.h"

/**
 *
 *  @param arquivo
 *  @param cliente
 *  @return
 */
int inserir_cliente(FILE* arquivo, Cliente* cliente) {
    if (fwrite(cliente, sizeof(Cliente), 1, arquivo)) {
        return 1;
    }

    return 0;
}

/**
 *
 *  @param arquivo
 *  @param cliente
 *  @param jump
 *  @return
 */
int buscar_cliente(FILE* arquivo, Cliente* cliente) {
    if (fread(cliente, sizeof(Cliente), 1, arquivo)) {
        return 1;
    }

    return 0;
}

/**
 *
 *  @param arquivo
 *  @param cliente
 *  @return
 */
int procurar_cliente(FILE* arquivo, Cliente* cliente, int jump) {
    fseek(arquivo, jump, SEEK_SET);

    if (fread(cliente, sizeof(Cliente), 1, arquivo)) {
        return 1;
    }

    return 0;
}