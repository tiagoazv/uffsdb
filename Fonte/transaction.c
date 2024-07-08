#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FMACROS // garante que macros.h não seja reincluída
   #include "macros.h"
#endif
///
#ifndef FTYPES // garante que types.h não seja reincluída
  #include "types.h"
#endif
#ifndef FUTILITY
   #include "Utility.h"
#endif
#ifndef FPARSER
    #include "interface/parser.h"
#endif
#ifndef FDICTIONARY
    #include "dictionary.h"
#endif
#include "transaction.h"
#include "btree.h"

void copy_data(rc_insert *data, rc_insert *copy){

    //Alocando memória
    copy->objName = malloc(sizeof(data->objName));
    copy->columnName = malloc(data->N);
    copy->values = malloc(data->N);
    copy->type = malloc(sizeof(data->type));
    copy->attribute = malloc(sizeof(int));
    copy->fkTable = malloc(data->N);
    copy->fkColumn = malloc(data->N);

    //Copiando valores
    copy->N = data->N;
    copy->attribute = data->attribute;
    printf("%d\n", *copy->attribute);

    strcpy(copy->objName, data->objName);
    strcpy(copy->type, data->type);

    for(int i=0; i<data->N; i++){

        if(data->columnName){
            copy->columnName[i] = malloc(sizeof(data->columnName[i]));
            strcpy(copy->columnName[i], data->columnName[i]);
        }
        if(data->values){
            copy->values[i] = malloc(sizeof(data->values[i]));
            strcpy(copy->values[i], data->values[i]);
        }
        if(data->fkTable){
            copy->fkTable[i] = malloc(sizeof(data->fkTable[i]));
            strcpy(copy->fkTable[i], data->fkTable[i]);
        }
        if(data->fkColumn){
            copy->fkColumn[i] = malloc(sizeof(data->fkColumn[i]));
            strcpy(copy->fkColumn[i], data->fkColumn[i]);
        }
    }

}


void add_op(Pilha *stack_log, int op, rc_insert* data){

    log_op *new = malloc(sizeof(log_op));

    rc_insert copy;
    copy_data(data, &copy);

    new->op = op;
    new->data = copy;

    push(stack_log, new);

}

void debug_stack_log(Pilha *stack_log){


    if(stack_log->topo == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("DEBUGGING:\n\n");

    while(stack_log->tam > 0){

        log_op *log = pop(stack_log);
        rc_insert *aux = &log->data;

        switch(log->op){
            
            case OP_CREATE_TABLE:
                printf("Create Table: %s\n", aux->objName);
            break;
            case OP_DROP_TABLE:
                printf("Drop Table: %s\n", aux->objName);
            break;
            case OP_INSERT:
                printf("Insert Table: %s\n", aux->objName);
            break;
            case OP_CREATE_INDEX:
                printf("Create Index: %s\n", aux->objName);
            break;
            default: break;

        }
    }
}

void rollback(Pilha* stack_log){
    printf("Starting rollback...\n");
    printf("Stack size: %d \n", stack_log->tam);
    while(stack_log->tam > 0){

        log_op *log = pop(stack_log);
        rc_insert *aux = &log->data;

        switch(log->op){
            
            case OP_CREATE_TABLE:
                //drop table
                printf("Create Table: %s\n", aux->objName);
            break;
            
            case OP_DROP_TABLE:
                //voltar a tabela
                printf("Drop Table: %s\n", aux->objName);
            break;

            case OP_INSERT:
                //remover inserção?
                printf("Insert Table: %s\n", aux->objName);
            break;

            case OP_CREATE_INDEX:
                printf("rollback log\n");
                drop_index(aux);
                
                printf("Create Index: %s\n", aux->objName);
            break;

            default: break;

        }
    }
}

void drop_index(rc_insert *aux) {
    char*  nomeTabela = aux->objName;
    char*  nomeColuna = "id";//aux->columnName[0]
    printf("%s", nomeColuna);
    //desfaz as alterações de inicializa_indice()
    printf("File Delete:"); 
    rb_inicializa_indice(nomeTabela, nomeColuna);


    //printf("Index decrement:");
    //desfaz as alterações de incrementaQtdIndice()
    //rb_incrementaQtdIndice(nomeTabela);
    //printf("Remove BT from scheme:");
    //desfaz alterações de adicionaBT()
    //rb_adicionaBT(nomeTabela, aux->columnName[0]);
    
}

void rb_inicializa_indice(char* nomeTabela, char* nomeColuna){
    char dir[TAMANHO_NOME_TABELA + TAMANHO_NOME_ARQUIVO + TAMANHO_NOME_CAMPO + TAMANHO_NOME_INDICE];
    strcpy(dir, connected.db_directory);
    strcat(dir, nomeTabela);
    strcat(dir, nomeColuna);
    strcat(dir, ".dat");
    printf("Removendo arquivo em %s", dir);
    //remove(dir); // Remove o arquivo de índice criado
 
    printf("\nArquivo removido.");
    return;
}

void rb_incrementaQtdIndice(char* nomeTabela){
    FILE *dicionario = NULL;
    char tupla[TAMANHO_NOME_TABELA];
    memset(tupla, '\0', TAMANHO_NOME_TABELA);
    int qt = 0, offset = 0;

    char directory[LEN_DB_NAME_IO];
    strcpy(directory, connected.db_directory);
    strcat(directory, "fs_object.dat");

    if ((dicionario = fopen(directory,"r+b")) == NULL) {
        printf("Erro ao abrir dicionário de dados.\n");
        return;
    }

    while (fgetc(dicionario) != EOF) {
        fseek(dicionario, -1, 1);

        fread(tupla, sizeof(char), TAMANHO_NOME_TABELA, dicionario);
        if (strcmp(tupla, nomeTabela) == 0) {
            fseek(dicionario, sizeof(int), SEEK_CUR); // Pula o código da tabela
            fseek(dicionario, sizeof(char) * TAMANHO_NOME_ARQUIVO, SEEK_CUR); // Pula o nome do arquivo da tabela
            fseek(dicionario, sizeof(int), SEEK_CUR); // Pula a quantidade de campos da tabela
            offset = ftell(dicionario); // Guarda a posição atual do ponteiro
            fread(&qt, sizeof(int), 1, dicionario); // Lê a quantidade de índices
            qt--; // Decrementa o contador de índices
            fseek(dicionario, offset, SEEK_SET); // Move o ponteiro de volta para a posição original
            fwrite(&qt, sizeof(int), 1, dicionario); // Escreve o valor decrementado de volta no arquivo
            fclose(dicionario); // Fecha o arquivo
            return;
        }
        fseek(dicionario, 32, 1);
    }
    printf("Erro ao atualizar dicionário de dados.\n");

}

void rb_adicionaBT(char* nomeTabela, char* nomeColuna){
    int cod;
    char directory[LEN_DB_NAME_IO];
    strcpy(directory, connected.db_directory); // Copia o diretório do banco de dados para 'directory'
    strcat(directory, "fs_schema.dat"); // Adiciona o nome do arquivo ao diretório

    char atrib[TAMANHO_NOME_CAMPO];
    memset(atrib, '\0', TAMANHO_NOME_CAMPO); // Inicializa 'atrib' com zeros

    FILE *schema = fopen(directory, "r+b"); // Abre o arquivo 'fs_schema.dat' em modo leitura/escrita binário

    if (schema == NULL) {
        printf("Erro ao abrir esquema da tabela.\n");
        return;
    }

    struct fs_objects objeto = leObjeto(nomeTabela); // Lê os dados do objeto da tabela

    // Percorre o arquivo até o final
    while (fgetc(schema) != EOF) {
        fseek(schema, -1, 1); // Move o ponteiro de volta uma posição

        if (fread(&cod, sizeof(int), 1, schema)) { // Lê o código da tabela
            if (cod == objeto.cod) { // Verifica se o código da tabela corresponde ao código do objeto
                fread(atrib, sizeof(char), TAMANHO_NOME_CAMPO, schema); // Lê o nome do campo
                if (strcmp(atrib, nomeColuna) == 0) { // Verifica se o nome do campo corresponde ao nome do atributo
                    fseek(schema, 5, SEEK_CUR); // Pula 1 byte do tipo e 4 bytes do tamanho
                    int chave = 0; // Valor original da chave (assumindo que 0 é o valor padrão)
                    fwrite(&chave, sizeof(int), 1, schema); // Escreve o valor original da chave
                    fclose(schema); // Fecha o arquivo
                    return;
                } else {
                    fseek(schema, 69, SEEK_CUR); // Pula para a próxima entrada (69 bytes)
                }
            } else {
                fseek(schema, 109, 1); // Pula para a próxima entrada (109 bytes)
            }
        }
    }

    printf("Erro ao abrir o esquema da tabela \"%s\".\n", nomeTabela);
}