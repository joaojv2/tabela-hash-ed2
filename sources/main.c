#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/cliente.h"
#include "../headers/metodo_hash.h"
#include "../headers/tabela_hash.h"
#include "../headers/tratamento_colisao.h"
#include "../headers/arquivo.h"

#define DIRETORIO "../data/data.dat"

#define ESCRITA "w+b"
#define LEITURA "a+b"

void cenario_teste_1();
void cenario_teste_2();
void cenario_teste_3();

void teste(Hash*, Tratamento, float);

int main() {

    //gerar_arquivo_teste(DIRETORIO, 1009);

    cenario_teste_1();
    cenario_teste_2();
    cenario_teste_3();

    return 0;
}

void cenario_teste_1() {
    int tamanho_tabela = 61;
    Hash* tabela_hash;

    printf("TAMANHO DA TABELA ------------------> %i\n\n", tamanho_tabela);

    ///////////////////////// FATOR CARGA 0.7 ////////////////////////////////////
    printf("TENTATIVE LINEAR -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_linear, 0.7);
    liberar_tabela_hash(tabela_hash);

    printf("TENTATIVE QUADRATICA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_quadratica, 0.7);
    liberar_tabela_hash(tabela_hash);

    printf("DISPERSAO DUPLA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, dispersao_dupla, 0.7);
    liberar_tabela_hash(tabela_hash);

    printf("\n");

    ///////////////////////// FATOR CARGA 0.8 ////////////////////////////////////
    printf("TENTATIVE LINEAR -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_linear, 0.8);
    liberar_tabela_hash(tabela_hash);

    printf("TENTATIVE QUADRATICA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_quadratica, 0.8);
    liberar_tabela_hash(tabela_hash);

    printf("DISPERSAO DUPLA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, dispersao_dupla, 0.8);
    liberar_tabela_hash(tabela_hash);

    printf("\n");

    ///////////////////////// FATOR CARGA 0.9 ////////////////////////////////////
    printf("TENTATIVE LINEAR -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_linear, 0.9);
    liberar_tabela_hash(tabela_hash);

    printf("TENTATIVE QUADRATICA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_quadratica, 0.9);
    liberar_tabela_hash(tabela_hash);

    printf("DISPERSAO DUPLA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, dispersao_dupla, 0.9);
    liberar_tabela_hash(tabela_hash);

    printf("\n\n\n");
}

void cenario_teste_2() {
    int tamanho_tabela = 283 ;
    Hash* tabela_hash;

    printf("TAMANHO DA TABELA ------------------> %i\n\n", tamanho_tabela);

    ///////////////////////// FATOR CARGA 0.7 ////////////////////////////////////
    printf("TENTATIVE LINEAR -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_linear, 0.7);
    liberar_tabela_hash(tabela_hash);

    printf("TENTATIVE QUADRATICA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_quadratica, 0.7);
    liberar_tabela_hash(tabela_hash);

    printf("DISPERSAO DUPLA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, dispersao_dupla, 0.7);
    liberar_tabela_hash(tabela_hash);

    printf("\n");

    ///////////////////////// FATOR CARGA 0.8 ////////////////////////////////////
    printf("TENTATIVE LINEAR -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_linear, 0.8);
    liberar_tabela_hash(tabela_hash);

    printf("TENTATIVE QUADRATICA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_quadratica, 0.8);
    liberar_tabela_hash(tabela_hash);

    printf("DISPERSAO DUPLA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, dispersao_dupla, 0.8);
    liberar_tabela_hash(tabela_hash);

    printf("\n");

    ///////////////////////// FATOR CARGA 0.9 ////////////////////////////////////
    printf("TENTATIVE LINEAR -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_linear, 0.9);
    liberar_tabela_hash(tabela_hash);

    printf("TENTATIVE QUADRATICA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_quadratica, 0.9);
    liberar_tabela_hash(tabela_hash);

    printf("DISPERSAO DUPLA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, dispersao_dupla, 0.9);
    liberar_tabela_hash(tabela_hash);

    printf("\n\n\n");
}

void cenario_teste_3() {
    int tamanho_tabela = 1009;
    Hash* tabela_hash;

    printf("TAMANHO DA TABELA ------------------> %i\n\n", tamanho_tabela);

    ///////////////////////// FATOR CARGA 0.7 ////////////////////////////////////
    printf("TENTATIVE LINEAR -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_linear, 0.7);
    liberar_tabela_hash(tabela_hash);

    printf("TENTATIVE QUADRATICA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_quadratica, 0.7);
    liberar_tabela_hash(tabela_hash);

    printf("DISPERSAO DUPLA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, dispersao_dupla, 0.7);
    liberar_tabela_hash(tabela_hash);

    printf("\n");

    ///////////////////////// FATOR CARGA 0.8 ////////////////////////////////////
    printf("TENTATIVE LINEAR -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_linear, 0.8);
    liberar_tabela_hash(tabela_hash);

    printf("TENTATIVE QUADRATICA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_quadratica, 0.8);
    liberar_tabela_hash(tabela_hash);

    printf("DISPERSAO DUPLA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, dispersao_dupla, 0.8);
    liberar_tabela_hash(tabela_hash);

    printf("\n");

    ///////////////////////// FATOR CARGA 0.9 ////////////////////////////////////
    printf("TENTATIVE LINEAR -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_linear, 0.9);
    liberar_tabela_hash(tabela_hash);

    printf("TENTATIVE QUADRATICA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, tentativa_quadratica, 0.9);
    liberar_tabela_hash(tabela_hash);

    printf("DISPERSAO DUPLA -----> ");
    tabela_hash = criar_tabela_hash(tamanho_tabela);
    teste(tabela_hash, dispersao_dupla, 0.9);
    liberar_tabela_hash(tabela_hash);

    printf("\n\n\n");
}

void teste(Hash* tabela_hash, Tratamento tratamento, float fator_carga) {
    int contador = 0, jump = 0, total_colisoes = 0;

    clock_t time;
    double  tempo_remocao = 0;

    FILE* arquivo_leitura = abrir_arquivo(DIRETORIO, LEITURA);
    FILE* arquivo_busca = abrir_arquivo(DIRETORIO, LEITURA);

    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));

    while (calcular_fator_carga(tabela_hash) <= fator_carga) {
        contador ++;
        jump = ((contador - 1) * sizeof(Cliente));

        buscar_cliente(arquivo_leitura, cliente);
        inserir_hash_end_aberto(tabela_hash, tratamento, cliente->codigo, jump, &total_colisoes);
        contador ++;
    }

    for (int i = 0; i < 20; i ++) {
        buscar_cliente(arquivo_busca, cliente);

        time = clock();
        remover_hash_end_aberto(tabela_hash, tratamento, cliente->codigo);
        time = clock() - time;

        tempo_remocao += ((double) time);
    }

    printf("TOTAL COLISOES -> %i || TEMPO BUSCA -> %fms || FATOR DE CARGA -> %f\n", total_colisoes, (tempo_remocao / 10.0), fator_carga);

    fclose(arquivo_leitura);
}