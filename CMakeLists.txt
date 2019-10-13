cmake_minimum_required(VERSION 3.14)
project(tabela_hash C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -lm")

add_executable(tabela_hash sources/main.c headers/tabela_hash.h sources/tabela_hash.c headers/cliente.h sources/cliente.c headers/tratamento_colisao.h sources/tratamento_colisao.c headers/metodo_hash.h sources/metodo_hash.c headers/arquivo.h sources/arquivo.c)

target_link_libraries(tabela_hash m)
