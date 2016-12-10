#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ordem 2

/**
* estrutura do nodo da arvore b+
**/
typedef struct nodo{
	char **data;
	int *endereco;
	struct nodo *pai, *prox, *ant;
	struct nodo **filhos;
	int quant_data;
} nodo;

//quando o usuário cria uma tabela, está função deve ser chamada para criar o arquivo de indice.
int inicializa_indice(char* nomeTabela){
	
	FILE * new_indice = NULL;
	new_indice = fopen(nomeTabela,"a");
	if(new_indice == NULL)return 0;
	fclose(new_indice);
	return 1;	
}

//cria novo nodo e insere os valores
nodo* criaNodo(char* ind,int end){
	nodo * novo = NULL;
	novo = (nodo*)malloc(sizeof(nodo));
	novo->quant_data = 0;
	novo->data = (char**)malloc(ordem * sizeof(char));
	novo->data[novo->quant_data] = (char *)malloc((strlen(ind)+1) * sizeof(char));
	novo->endereco = (int*)malloc(ordem * sizeof(int));
	novo->data[novo->quant_data] = ind;
	novo->endereco[novo->quant_data] = end;
	novo->quant_data++;	
	return novo;

}

nodo* constroi_bplus(char* NomeTabela);
nodo* busca_insere(nodo* raiz, char* ind, int end);
void insere_arquivo(nodo*inicio);
void destroi_arvore(nodo*inicio);

//insere o indice e o endereço no arquivo de indices
void insere_indice(char* ind, char* nomeTabela, int end){
	nodo *aux;
	aux = constroi_bplus(nomeTabela);// retorna raiz
	aux = busca_insere(aux,ind,end); // retorna inicio da lista dos folhas
	if(aux == NULL) aux = criaNodo(ind,end);//arvore vazia
	insere_arquivo(aux);
	destroi_arvore(aux);
}
