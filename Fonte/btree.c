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
	new_indice = fopen(strcat(nomeTabela, ".dat"),"a");
	if(new_indice == NULL)return 0;
	fclose(new_indice);
	return 1;
}

/* Insere os valores da chave (ind) e do endereço da tupla no arquivo de dados
 * (end) em um nodo (n) */
nodo* insereChaveEmNodo(char* ind, int end, nodo* n){
	n->data = (char**)malloc(ordem * sizeof(char));
	n->data[novo->quant_data] = (char *)malloc((strlen(ind)+1) * sizeof(char));
	n->endereco = (int*)malloc(ordem * sizeof(int));
	n->data[novo->quant_data] = ind;
	n->endereco[novo->quant_data] = end;
	n->quant_data++;
	return n;
}

//cria novo nodo vazio
nodo* criaNodo() {
	nodo * novo = NULL;
	novo = (nodo*)malloc(sizeof(nodo));
	novo->filhos = novo->pai = novo->prox = novo->ant = NULL;
	novo->data = novo->endereco = NULL;
	novo->quant_data = 0;
	return novo;
}

nodo* busca_insere(nodo* raiz, char* ind, int end);
void destroi_arvore(nodo*inicio);

nodo* constroi_bplus(char* nomeTabela){
	FILE * new = NULL;
	char le;
	int le2 = 1;
	int numero = 0;
	char*palavra;
	int cont = 0;

	new = fopen(nomeTabela,"r");
	if(!new){
		printf("Erro de abertura de arquivo\n");
		fclose(new);
		return NULL;
	}
	if(fread(&le, sizeof(char),1,new) == 0){
		fclose(new);
		return NULL;
	}
	fseek(new,0,SEEK_SET);
	palavra = (char*)malloc(sizeof(char));

	while(!feof(new)){
		while(le != '$'){
			fread(&le, sizeof(char),1,new);
			if(le != '$') {
				palavra = (char *) realloc(palavra, (++cont) * sizeof(char));
				palavra[cont-1] = le;
			}
		}
		cont = 0;

		while(le2 != '#'){
			fread(&le2, sizeof(int),1,new);
			if(le2 != '#') {
				numero = le2;
			}
		}
	}
}

// insere os dados do nodo folha no arquivo de indices Da tabela
void insere_arquivo(nodo*inicio,char* nomeTabela){
	int i;
	nodo*aux = NULL;
	aux = inicio;
	FILE * new = NULL;

	new = fopen(strcat(nomeTabela, ".dat"),"w");
	if(!new){
		printf("Erro de abertura de arquivo\n");
		return;
	}
	fseek(new,0,SEEK_SET);

	while(aux){
		i=0;
		while(i < aux->quant_data){
			fprintf(new,"%s",aux->data[aux->quant_data]);
			fprintf(new,"%c",'$');
			fprintf(new,"%d",aux->endereco[aux->quant_data]);
			fprintf(new,"%c",'#');
		}
		if(aux->prox == NULL) break;
		aux = aux->prox;
	}
	fclose(new);
}

//insere o indice e o endereço no arquivo de indices
void insere_indice(char* ind, char* nomeTabela, int end){
	nodo *aux;
	aux = constroi_bplus(nomeTabela);// retorna raiz
	aux = busca_insere(aux,ind,end); // retorna inicio da lista dos folhas
	if(aux == NULL) aux = criaNodo(ind,end);//arvore vazia
	insere_arquivo(aux,nomeTabela);
	destroi_arvore(aux);
}
