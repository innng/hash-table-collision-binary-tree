#include <stdlib.h>
#include <string.h>

#include "aluno.h"

Aluno* criaAluno(char* n, Chave mat)
{
    Aluno* a = NULL;

    //aloca o espaço para o ponteiro Aluno
    if((a = malloc(sizeof(Aluno))) == NULL)
        return NULL;

    //aloca o espaço para o nome
    if((a->nome = malloc(sizeof(char) * (strlen(n) + 1))) == NULL)
        return NULL;

    //copia o conteúdo de n para o nome
    if(strcpy(a->nome, n) == NULL)
        return NULL;

    //define matricula igual à chave passada
    a->matricula = mat;

    return a;
} //criaAluno

void apagaAluno(Aluno* a)
{
	//libera ponteiros de nome e Aluno
    free(a->nome);
    free(a);
} //apagaAluno

void imprimeAluno(Aluno* a, FILE* f)
{
	//libera buffer (precaução) e grava no arquivo o Aluno
    fflush(f);
    fprintf(f, "(%d) %s", a->matricula, a->nome);
} //imprimeAluno