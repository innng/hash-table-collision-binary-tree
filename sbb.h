#ifndef SBB_H
#define SBB_H

#include "aluno.h"

#define SBB_VERTICAL 0      //posições possíveis para
#define SBB_HORIZONTAL 1    //os nodos da sbb

typedef Aluno Elemento;

typedef struct ArvoreSBB
{
    Elemento* reg;
    struct ArvoreSBB* esq;
    struct ArvoreSBB* dir;
    int esqtipo;
    int dirtipo;
}ArvoreSBB;

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: criaArvoreSBB(Elemento* r)
 * Função: cria uma árvore balanceada com o elemento r sendo raiz
 * Entrada: ponteiro do Elemento a ser inserido
 * Saída: ponteiro da ArvoreSBB criada
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
ArvoreSBB* criaArvoreSBB(Elemento* r);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: pesquisaSBB(ArvoreSBB* t, Chave x)
 * Função: pesquisa na árvore o elemento com chave x
 * Entrada: ponteiro da ArvoreSBB, chave do Elemento desejado
 * Saída: ponteiro do Elemento (ou NULL, caso não encontre)
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Elemento* pesquisaSBB(ArvoreSBB *t, Chave x);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: ee(ArvoreSBB** ptr)
 * Função: rotação esquerda-esquerda para manter as propriedades da SBB
 * Entrada: ponteiro de ponteiro para a raiz da ArvoreSBB
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void ee(ArvoreSBB** ptr);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: dd(ArvoreSBB** ptr)
 * Função: rotação direita-direita para manter as propriedades da SBB
 * Entrada: ponteiro de ponteiro para a raiz da ArvoreSBB
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void dd(ArvoreSBB** ptr);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: ed(ArvoreSBB** ptr)
 * Função: rotação esquerda-direita para manter as propriedades da SBB
 * Entrada: ponteiro de ponteiro para a raiz da ArvoreSBB
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void ed(ArvoreSBB** ptr);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: de(ArvoreSBB** ptr)
 * Função: rotação direita-esquerda para manter as propriedades da ArvoreSBB
 * Entrada: ponteiro de ponteiro para a raiz da ArvoreSBB
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void de(ArvoreSBB** ptr);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: iInsere(Elemento* r, ArvoreSBB** ptr, int* incli, int* fim)
 * Função: função auxiliar utilizada pela insereElementoSBB
 * Entrada: ponteiro do Elemento, ponteiro de ponteiro para a raiz da ArvoreSBB,
 *    inclinação e flag de fim
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
 void iInsere(Elemento* r, ArvoreSBB** ptr, int *incli, int *fim);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: iInsereAqui(Elemento* r, ArvoreSBB** ptr, int* incli, int* fim)
 * Função: função auxiliar utilizada pela iInsere
 * Entrada: ponteiro do Elemento, ponteiro de ponteiro para a raiz da ArvoreSBB,
 *    inclinação e flag de fim
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void iInsereAqui(Elemento* r, ArvoreSBB** ptr, int *incli, int *fim);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: insereElementoSBB(ArvoreSBB** t, Elemento* n)
 * Função: insere elemento n na árvore t
 * Entrada: ponteiro de ponteiro para a raiz da ArvoreSBB e ponteiro
 *    do Elemento
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void insereElementoSBB(ArvoreSBB** t, Elemento* n);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: inicializa(ArvoreSBB** raiz)
 * Função: inicializa a raiz da ArvoreSBB com NULL
 * Entrada: ponteiro de ponteiro da raiz da ArvoreSBB
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void inicializa(ArvoreSBB** raiz);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: imprimeArvoreSBB(ArvoreSBB* t, FILE* f)
 * Função: imprime a ArvoresBB por caminhamento central
 * Entrada: ponteiro da ArvoreSBB, ponteiro do arquivo de saída
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void imprimeArvoreSBB(ArvoreSBB* t, FILE* f);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: apagaArvoreSBB(ArvoreSBB* t)
 * Função: desaloca a árvore t e seus componentes
 * Entrada: ponteiro da ArvoreSBB
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void apagaArvoreSBB(ArvoreSBB *t);

#endif
