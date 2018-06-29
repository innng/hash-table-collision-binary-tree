#ifndef ABP_H
#define ABP_H

#include "aluno.h"

typedef Aluno Elemento;

typedef struct Arvore
{
    struct Arvore* esq;
    struct Arvore* dir;
    Elemento* reg;
}Arvore;

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: criaArvore(Elemento* r)
 * Função: cria uma árvore com o elemento r sendo raiz
 * Entrada: ponteiro do Elemento
 * Saída: ponteiro da Arvore criada
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Arvore* criaArvore(Elemento* r);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: pesquisa(Arvore* t, Chave x)
 * Função: pesquisa na árvore o elemento com chave x
 * Entrada: ponteiro da Arvore, chave do Elemento buscado
 * Saída: ponteiro do Elemento (ou NULL, caso não seja encontrado)
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Elemento* pesquisa(Arvore *t, Chave x);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: insereElemento(Arvore* t, Elemento* n)
 * Função: insere elemento n na árvore t
 * Entrada: ponteiro da Arvore, ponteiro do Elemento
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void insereElemento(Arvore* t, Elemento* n);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: removeDaArvore(Arvore* t, Chave c)
 * Função: remove o elemento de chave c da árvore t
 * Entrada: ponteiro da Arvore, chave do Elemento a ser removido
 * Saída: ponteiro da Arvore depois da alteração
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Arvore* removeDaArvore(Arvore* t, Chave c);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: achaMenor(Arvore* t)
 * Função: encontra o menor elemento da árvore t
 * Entrada: ponteiro da Arvore
 * Saída: ponteiro do nodo da Arvore
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Arvore* achaMenor(Arvore* t);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: imprimeArvore(Arvore* t, FILE* f)
 * Função: imprime a árvore por caminhamento central
 * Entrada: ponteiro da Arvore, ponteiro do arquivo de saída
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void imprimeArvore(Arvore *t, FILE* f);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: apagaArvore(Arvore* t)
 * Função: desaloca a árvore t e seus componentes
 * Entrada: ponteiro da Arvore
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void apagaArvore(Arvore *t);

#endif
