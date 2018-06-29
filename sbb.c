#include <stdlib.h>

#include "sbb.h"

ArvoreSBB* criaArvoreSBB(Elemento* r)
{
    ArvoreSBB *no = NULL;

    //aloca espaço para o nodo raiz
    if((no = malloc(sizeof(ArvoreSBB))) == NULL)
        return NULL;

    //preenche nodo
    no->reg = r;

    //coloca ponteiros NULL
    no->esq = NULL;
    no->dir = NULL;

    //posiciona filhos como vertical
    no->esqtipo = SBB_VERTICAL;
    no->dirtipo = SBB_VERTICAL;

    return no;
} //criaArvoreSBB

Elemento* pesquisaSBB(ArvoreSBB *t, Chave x)
{
	//árvore vazia ou não encontrou elemento
    if (t == NULL)
        return NULL;
    
    //chave menor que a do nodo atual
    else if ( x < t->reg->matricula )
        pesquisaSBB( t->esq, x ); 

    //chave maior que a do nodo atual
    else if ( x > t->reg->matricula )
        pesquisaSBB( t->dir, x ); 

    //encontrou
    else return t->reg;
} //pesquisaSBB

void ee(ArvoreSBB** ptr)
{
    ArvoreSBB *no = *ptr;
    ArvoreSBB *esq = no->esq;

    no->esq = esq->dir; //rotD(ptr)
    esq->dir = no;
    esq->esqtipo = SBB_VERTICAL;
    no->esqtipo = SBB_VERTICAL;
    *ptr = esq;
} //ee

void dd(ArvoreSBB** ptr)
{
    ArvoreSBB *no = *ptr;
    ArvoreSBB *dir = no->dir;

    no->dir = dir->esq; //rotE(ptr)
    dir->esq = no;
    dir->dirtipo = SBB_VERTICAL;
    no->dirtipo = SBB_VERTICAL;
    *ptr = dir;
} //dd

void ed(ArvoreSBB** ptr)
{
    ArvoreSBB *no = *ptr;
    ArvoreSBB *esq = no->esq;
    ArvoreSBB *dir = esq->dir;

    esq->dir = dir->esq; //rotE(&(no->esq))
    dir->esq = esq;
    no->esq = dir->dir; //rotD(ptr)
    dir->dir = no;
    esq->dirtipo = SBB_VERTICAL;
    no->esqtipo = SBB_VERTICAL;
    *ptr = dir;
} //ed

void de(ArvoreSBB** ptr)
{
    ArvoreSBB *no = *ptr;
    ArvoreSBB *dir = no->dir;
    ArvoreSBB *esq = dir->esq;

    dir->esq = esq->dir; //rotD(&(no->dir))
    esq->dir = dir;
    no->dir = esq->esq; //rotE(ptr)
    esq->esq = no;
    dir->esqtipo = SBB_VERTICAL;
    no->dirtipo = SBB_VERTICAL;
    *ptr = esq;
} //de

void iInsere(Elemento* r, ArvoreSBB** ptr, int *incli, int *fim)
{
	//insere na folha encontrada
    if(*ptr == NULL)
        iInsereAqui(r, ptr, incli, fim);

    //procura na árvore da esquerda
    else if(r->matricula < (*ptr)->reg->matricula)
    {   
        iInsere(r, &((*ptr)->esq), &((*ptr)->esqtipo), fim);
        if(*fim)
            return ;
        if((*ptr)->esqtipo == SBB_VERTICAL)
            *fim = 1;
        else if((*ptr)->esq->esqtipo == SBB_HORIZONTAL)
        {
            ee(ptr);
            *incli = SBB_HORIZONTAL;
        } else if((*ptr)->esq->dirtipo == SBB_HORIZONTAL)
        {
            ed(ptr);
            *incli = SBB_HORIZONTAL;
        }
    //procura na árvore da direita
    } else if(r->matricula > (*ptr)->reg->matricula)
    {
        iInsere(r, &((*ptr)->dir), &((*ptr)->dirtipo), fim);
        if(*fim)
            return ;
        if((*ptr)->dirtipo == SBB_VERTICAL)
            *fim = 1;
        else if((*ptr)->dir->dirtipo == SBB_HORIZONTAL)
        {
            dd(ptr);
            *incli = SBB_HORIZONTAL;
        } else if((*ptr)->dir->esqtipo == SBB_HORIZONTAL)
        {
            de(ptr);
            *incli = SBB_HORIZONTAL;
        } else  //chave já existe
        {
            return ;
            *fim = 1;
        }
    }
} //iInsere

void iInsereAqui(Elemento* r, ArvoreSBB** ptr, int *incli, int *fim)
{
    ArvoreSBB *no = NULL;

    //aloca espaço pro novo nodo
    if((no = malloc(sizeof(ArvoreSBB))) == NULL)
        return ;

    //preenche nodo
    no->reg = r;

    //coloca ponteiro como NULL
    no->esq = NULL;
    no->dir = NULL;

    //seta filhos como vertical
    no->esqtipo = SBB_VERTICAL;
    no->dirtipo = SBB_VERTICAL;

    //coloca na respectiva posição na árvore
    *ptr = no;

    //muda a posição para acertar o balanceamento da árvore 
    *incli = SBB_HORIZONTAL;

    //fim como false para fazer balanceamento
    *fim = 0;
} //iInsereAqui

void insereElementoSBB(ArvoreSBB** t, Elemento *n)
{
	//prepara a inserção do elemento
    int fim = 0;
    int inclinacao = SBB_VERTICAL;
    iInsere(n, t, &inclinacao, &fim);
} //insereElementoSBB

void inicializa(ArvoreSBB** raiz)
{
    *raiz = NULL;
} //inicializa

void imprimeArvoreSBB(ArvoreSBB* t, FILE* f)
{
    if(t == NULL)
        return ;
    imprimeArvoreSBB(t->esq, f);
    imprimeAluno(t->reg, f);
    imprimeArvoreSBB(t->dir, f);
} //imprimeArvoreSBB

void apagaArvoreSBB(ArvoreSBB *t)
{
    if(t == NULL)
        return ;
    apagaArvoreSBB(t->esq);
    apagaArvoreSBB(t->dir);
    apagaAluno(t->reg);
    free(t);
} //apagaArvoreSBB