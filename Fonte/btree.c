/**
* estrutura do nodo da arvore b+
**/
typedef struct nodo{
	char **data
	char **indice;
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

insere_indice(char* inidice, char* nomeTabela, char* endereco){
	nodo *aux;
	aux = constroi_b+(nomeTabela);// retorna raiz
	aux = busca_insere(aux,inidice,endereco); // retorna inicio da lista dos folhas
	if(aux == NULL) aux = criaNodo(indice,endereco);
	insere_arquivo(aux);
	destroi_arvore(aux);
}
