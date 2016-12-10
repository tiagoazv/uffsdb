/**
* estrutura do nodo da arvore b+
**/
typedef struct nodo{
	char *indice;
	struct nodo *pai, *prox, *ant;
	struct nodo **filhos;
} nodo;
