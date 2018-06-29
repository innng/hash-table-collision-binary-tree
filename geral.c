#include <stdlib.h>

#include "geral.h"

int leArquivo(char* entrada, char* saida, int tam, int tipo)
{
    FILE* f = NULL;

    //abre arquivo de entrada
    if((f = fopen(entrada, "r")) == NULL)
    {
        perror(entrada);
        exit(EXIT_FAILURE);
    } else
    {
    	//declara tipos importantes
        Hash* h = NULL;
        Aluno* a = NULL;
        char* aux_nome = NULL;
        int i = 0, aux_mat = 0;

        //cria a tabela Hash
        h = criaHash(tam, tipo);

        //aloca espaço para a auxiliar de leitura dos nomes
        if((aux_nome = malloc(sizeof(char) * NAME)) == NULL)
            return 1;

        //percorre arquivo
        while((i = fgetc(f)) != EOF)
        {
        	//retoma caracter perdido no fgetc
            ungetc(i, f);

            //lê a matrícula
            fscanf(f, "%d\n", &aux_mat);

            //lê nome
            fgets(aux_nome, "[^\n]", f);

            //cria aluno
            a = criaAluno(aux_nome, aux_mat);

            //insere aluno na tabela
            insereNaHash(h, a);

        }

        //grava Hash no arquivo depois de pronta
        imprime(h, saida);

        printf("\n%d elementos inseridos.\n", h->nElem);

        //libera auxiliar e Hash
        free(aux_nome);
        apagaHash(h);
    }

    //fecha arquivo de entrada
    fclose(f);

    //retorna 0 se tudo ocorrer corretamente
    return 0;
} //funcaoHash
