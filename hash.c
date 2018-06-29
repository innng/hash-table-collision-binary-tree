#include <string.h>
#include <stdlib.h>

#include "hash.h"
#include "abp.h"
#include "sbb.h"

int funcaoHash(Hash* h, Chave c)
{
    return (c % h->tam);
} //funcaoHash

Hash* criaHash(int t, int tipo)
{
	//declara nova Hash
    Hash *h = NULL;
	int i;

	//aloca espaço para a Hash
	if((h = malloc(sizeof(Hash))) == NULL)
		return NULL;

	//define o número de elementos inciais, o tamanho da tabela
	//e o tipo de árvore a ser usada
	h->nElem = 0;
	h->tam = t;
	h->tipo = tipo;

	//tipo = árvore sem balanceamento
	if(tipo == 0)
	{
		//aloca espaço para as árvores
	    if((h->hash = malloc(sizeof(Arvore) * t)) == NULL)
            return NULL;
        //inicializa as árvores com NULL
        for(i = 0; i < t; i++)
            h->hash[i] = NULL;

    //tipo = árvore SBB
	} else
	{
		//aloca espaço para as árvores
        if((h->hashSBB = malloc(sizeof(ArvoreSBB) * t)) == NULL)
            return NULL;
        //inicializa as árvores com NULL
        for(i = 0; i < t; i++)
            inicializa(&h->hashSBB[i]);
	}

	return h;
} //criaHash

void apagaHash(Hash* h)
{
	//apaga as árvores de acordo com o tipo definido
	//e libera o ponteiro da estrutura Hash
    int i;

    if(h->tipo == 0)
    {
        for(i = 0; i < h->tam; i++)
            apagaArvore(h->hash[i]);

        free(h->hash);
    } else
    {
        for(i = 0; i < h->tam; i++)
            apagaArvoreSBB(h->hashSBB[i]);

        free(h->hashSBB);
    }

    //libera ponteiro da tabela
    free(h);
} //apagaHash

void insereNaHash(Hash* h, Elemento* x)
{
	//função de transformação
    int i = funcaoHash(h, x->matricula);

    //procura elemento na Hash
    if(obtemDaHash(h, x->matricula) == NULL)
    {
        if(h->tipo == 0)
            if(h-> hash[i] == NULL)
            	//árvores nula, cria a árvore
                h->hash[i] = criaArvore(x);

            //insere elemento na árvore já existente
            else insereElemento(h->hash[i], x);

        else if(h-> hashSBB[i] == NULL)
                //árvore nula, cria a árvore
                h->hashSBB[i] = criaArvoreSBB(x);

            //insere na árvore já existente
            else insereElementoSBB(&(h->hashSBB[i]), x);

        //incrementa o número de elementos
    	h->nElem++;

    //elemento já existe na tabela
    } else  return ;
} //insereNaHash

Elemento * obtemDaHash(Hash* h, Chave c)
{
    Elemento* Ap = NULL;
    int i = 0;

    i = funcaoHash(h, c);

    //escolhe o tipo de árvore
    if( h->tipo == 0)
    {
        if (h->hash[i] == NULL)
        	//árvore vazia
            return NULL;
        else
        {
        	//pesquisa elemento
            Ap = pesquisa(h->hash[i], c);

            //descobre se encontrou de fato o elemento
            if (Ap != NULL)
                return Ap;
            else return NULL;
        }
    } else
    {
        if (h->hashSBB[i] == NULL)
        	//árvore vazia
            return NULL;
        else
        {
        	//pesquisa na árvore
            Ap = pesquisaSBB(h->hashSBB[i], c);
            //descobre se encontrou o elemento
            if ( Ap != NULL)
                return Ap;
            else return NULL;
        }
    }
} //obtemDaHash

void imprime(Hash* h, char* saida )
{
    FILE* f = NULL;

    //abre arquivo de saída
    if((f = fopen(saida, "w")) == NULL)
    {
        perror(saida);
        exit(EXIT_FAILURE);
    } else
    {
        int i;

        //escolhe tipo de árvore
        if(h->tipo == 0)
            for( i = 0; i < h->tam; i++ )
            	//se a árvore está vazia, apenas pula
                if(h->hash[i] == NULL)
                    continue;
                //printa a árvore
                else
                {
                    fprintf(f, "%d:\n", i);
                    imprimeArvore(h->hash[i], f);
                }

        else for(i = 0; i < h->tam; i++)
        		//pula árvores vazias
                if(h->hashSBB[i] == NULL)
                    continue;
                //imprime restante
                else
                {
                    fprintf(f, "%d:\n", i);
                    imprimeArvoreSBB( h->hashSBB[i], f );
                }
    }
    fclose( f );
} //imprime

int obtemNumElem(Hash* h)
{
	//retorna quantidade de elementos
    return h->nElem;
} //obtemNumElem
