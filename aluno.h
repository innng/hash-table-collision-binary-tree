#ifndef ALUNOS_H
#define ALUNOS_H

#include <stdio.h>

typedef int Chave;

typedef struct Aluno
{
    char* nome;
    Chave matricula;
}Aluno;

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: criaAluno(char* n, Chave mat)
 * Função: cria aluno, dado seu nome e sua matrícula
 * Entrada: string literal, um inteiro
 * Saída: ponteiro do Aluno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Aluno* criaAluno(char* n, Chave mat);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: apagaAluno(Aluno* a)
 * Função: desaloca ponteiro Aluno e seus dados
 * Entrada: ponteiro do Aluno
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void apagaAluno(Aluno* a);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Protótipo: imprimeAluno(Aluno* a, FILE* f)
 * Função: grava os dados do aluno a no formato: (matricula) nome
 * Entrada: ponteiro do Aluno, ponteiro do arquivo de saída
 * Saída: sem retorno
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void imprimeAluno(Aluno* a, FILE* f);

#endif
