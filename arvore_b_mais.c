#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>

#include "arvore_b_mais.h"
#include "lista_pizzas.h"
#include "metadados.h"
#include "no_folha.h"
#include "no_interno.h"
#include "pizza.h"

int busca(int cod, char *nome_arquivo_metadados, char *nome_arquivo_indice, char *nome_arquivo_dados, int d)
{
	TMetadados* meta = le_arq_metadados(nome_arquivo_metadados);
    
    if(meta->raiz_folha) return meta->pont_raiz; // Se o no raiz (lido no metadado) ja for folha 
    else{
        int folha = -1; // Usando -1 pois nunca sera uma posicao dentro do arquivo
        int no_atual = meta->pont_raiz;
        FILE* arq_indices = fopen(nome_arquivo_indice, "rb");
        
        while(folha == -1){ // Enquanto folha nao for uma posicao dentro do arquivo
            fseek(arq_indices, no_atual, 0);
            TNoInterno* pagina = le_no_interno(d, arq_indices);
            int i;
            for(i = 0; cod >= pagina->chaves[i] && i < pagina->m; i++); // Apenas para conseguir mudar o i (numero para andar no interno)
            if(pagina->aponta_folha) folha = pagina->p[i]; // Se for folha, salva e termina busca
            else no_atual = pagina->p[i]; // Se nao for, continua para o proximo
        }

        fclose(arq_indices);	
        return folha;
    }
}

int insere(int cod, char *nome, char *descricao, float preco, char *nome_arquivo_metadados, char *nome_arquivo_indice, char *nome_arquivo_dados, int d)
{
	//TODO: Inserir aqui o codigo do algoritmo de insercao
    return INT_MAX;
}

int exclui(int cod, char *nome_arquivo_metadados, char *nome_arquivo_indice, char *nome_arquivo_dados, int d)
{
	//TODO: Inserir aqui o codigo do algoritmo de remocao
    return INT_MAX;
}

void carrega_dados(int d, char *nome_arquivo_entrada, char *nome_arquivo_metadados, char *nome_arquivo_indice, char *nome_arquivo_dados)
{
    //TODO: Implementar essa funcao
}