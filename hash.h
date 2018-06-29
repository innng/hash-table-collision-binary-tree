#ifndef HASH_H
#define HASH_H

#include "abp.h"
#include "sbb.h"

#define NAME 50             //tamanho máximo que um nome pode ter

typedef struct Hash
{
    Arvore** hash;
    ArvoreSBB** hashSBB;
    int tam;
    int nElem;
    int tipo;
}Hash;

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: funcaoHash(Hash* h, Chave c)
 * Função: aplica a função de transformação na chave c
 * Entrada: ponteiro da Hash, um inteiro
 * Saída: o valor do módulo entre a chave e o tamanho da tabela
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int funcaoHash(Hash* h, Chave c);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: criaHash(int t, int tipo)
 * Função: cria a Hash com o tamanho passado e o tipo de árvore
 * Entrada: tamanho da tabela e o tipo de árvore a ser usada
 * Saída: ponteiro da Hash
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Hash* criaHash(int t, int tipo);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: apagaHash(Hash* h)
 * Função: desaloca Hash h e seus componentes
 * Entrada: ponteiro da Hash
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void apagaHash(Hash* h);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: insereNaHash(Hash* h, Elemento* x)
 * Função: insere um Elemento na Hash
 * Entrada: ponteiro da Hash, ponteiro do Elemento
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void insereNaHash(Hash* h, Elemento* x);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: obtemDaHash(Hash* h, Chave c)
 * Função: obtem um elemento da Hash dada sua chave
 * Entrada: ponteiro da Hash, Chave do Elemento
 * Saída: ponteiro do Elemento (ou NULL)
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Elemento* obtemDaHash(Hash* h, Chave c);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: imprime(Hash* h, char* saida)
 * Função: imprime a tabela Hash h
 * Entrada: ponteiro da Hash, nome do arquivo de saída
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void imprime(Hash* h, char* saida);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 Protótipo: obtemNumElem(Hash* h)
 Função: retorna o número de elementos inseridos até o momento
 Entrada: ponteiro da Hash
 Saída: inteiro (h->nElem)
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int obtemNumElem(Hash* h);

#endif
