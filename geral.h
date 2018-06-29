#ifndef GERAL_H
#define GERAL_H

#include "hash.h"

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: LeArquivo(char* entrada, char* saida, int tam, int tipo)
 * Função: lê os dados do arquivo e chama as funções da Hash
 * Entrada: nome do arquivo de entrada, nome do arquivo de saída,
 *    tamanho da tabela, tipo de árvore a ser usada
 * Saída: 0 se funciona corretamente, 1 se há falhas
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int leArquivo(char* entrada, char* saida, int tam, int tipo);

#endif