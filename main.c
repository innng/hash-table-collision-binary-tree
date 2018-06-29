#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hash.h"

int main(int argc, char* argv[])
{
    clock_t start_clock, end_clock;

    start_clock = clock();
    //testa o número de parâmetros passados
    if(argc != 5)
    {
        puts("Numero incorreto de parametros.");
        exit(EXIT_FAILURE);
    } else
    {
        int tamanho, tipo;

        //transforma parâmetros de string para inteiro
        tamanho = atoi (argv[3]);
        tipo = atoi (argv[4]);

        //testa se tipo de árvore foi passado corretamente
        if(tipo != 0 && tipo != 1)
        {
            puts("Tipo de arvore incorreto!");
            exit( EXIT_FAILURE );
        }

        //testa se tamanho da tabela passado é válido
        if(tamanho < 1)
        {
            puts("Tamanho da tabela invalido!");
            exit(EXIT_FAILURE);
        }

        //chama função faz-tudo
        if(leArquivo(argv[1], argv[2], tamanho, tipo) == 1)
        {
            puts("Falha ao implementar a tabela Hash!");
            exit(EXIT_FAILURE);
        }
        end_clock = clock();
    }

    printf("Tempo gasto: %f segundos.\n", (double)(end_clock - start_clock)/CLOCKS_PER_SEC);
    return 0;
}
