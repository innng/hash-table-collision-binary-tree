#include <stdlib.h>

#include "abp.h"

Arvore* criaArvore(Elemento* r)
{
    Arvore *novo;

    //aloca espaço para nodo raiz da árvore
    if((novo = malloc(sizeof(Arvore))) == NULL)
        return NULL;

    //coloca NULL nos ponteiros
    novo->esq = NULL;
    novo->dir = NULL;

    //preenche o nodo
    novo->reg = r;

    return novo;
} //criaArvore

Elemento* pesquisa(Arvore *t, Chave x)
{
    //árvore vazia ou elemento não encontrado
    if (t == NULL)
        return NULL;

    //busca no filho esquerdo
    else if (x < t->reg->matricula)
        pesquisa(t->esq, x); 

	//busca no filho direito
    else if (x > t->reg->matricula)
        pesquisa(t->dir, x);

    //encontrou chave desejada 
    else return t->reg;
} //pesquisa

void insereElemento(Arvore* t, Elemento *n)
{
	//chave menor que a do nodo atual
    if(n->matricula < t->reg->matricula)
    { 
        if (t->esq)
            insereElemento(t->esq, n);
        else
        { //achou local de inserção
            Arvore *novo = criaArvore(n);
            t->esq = novo;
        }
    } else //chave maior ou igual ao nodo atual
    { 
        if (t->dir)
            insereElemento(t->dir, n);
        else
        { //insere nessa posição
            Arvore *novo = criaArvore(n);
            t->dir = novo;
        }
    }
} //insereElemento

Arvore* removeDaArvore(Arvore* t, Chave c)
{
    Arvore* aux = NULL;

    //não encontrou elemento
    if(t == NULL)
        return NULL;

    //chave menor que a do nodo atual
    else if(c < t->reg->matricula)
        t->esq = removeDaArvore(t->esq, c);

    //chave maior que a do nodo atual
    else if(c > t->reg->matricula)
        t->dir = removeDaArvore(t->dir, c);

    //encontrou elemento 
    //confere se é folha
    else if(t->esq == NULL && t->dir == NULL)
    {
        free(t);
        return NULL; 

    //possui filho na direita
    } else if(t->esq == NULL)
    {
        aux = t->dir;
        free(t);
        return aux; 

    //possui filho na esquerda
    } else if(t->dir == NULL)
    {
        aux = t->esq;
        free(t);
        return aux; 

    //possui os dois filhos
    } else
    { 
        Arvore *suc = achaMenor(t->dir);
        t->reg = suc->reg;
        t->dir = removeDaArvore(t->dir, suc->reg->matricula);
        return t;
    } return t;
} //removeDaArvore

Arvore* achaMenor(Arvore* t)
{
	//procura a folha mais à esquerda
    if(t->esq == NULL)
        return t;

    return achaMenor(t->esq);
} //achaMenor

void imprimeArvore(Arvore *t, FILE* f)
{
    if(t == NULL)
        return ;

    imprimeArvore(t->esq, f);
    imprimeAluno(t->reg, f);
    imprimeArvore(t->dir, f);
} //imprimeArvore

void apagaArvore(Arvore *t)
{
    if(t == NULL)
        return ;
    apagaArvore(t->esq);
    apagaArvore(t->dir);
    apagaAluno(t->reg);
    free(t);
} //apagaArvore