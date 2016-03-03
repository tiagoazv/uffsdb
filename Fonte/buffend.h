
/************************************************************************************************
 ************************************************************************************************/


/************************************************************************************************
 ************************************************************************************************/



/************************************************************************************************
 ************************************************************************************************/



/************************************************************************************************
 ************************************************************************************************/

/************************************************************************************************
 ************************************************************************************************/


/************************************************************************************************
 ************************************************************************************************/



/************************************************************************************************
 ************************************************************************************************/



/************************************************************************************************
 ************************************************************************************************/



/************************************************************************************************
 ************************************************************************************************/


/************************************************************************************************
 ************************************************************************************************/



/************************************************************************************************
 ************************************************************************************************/



/************************************************************************************************
 ************************************************************************************************/

int finalizaInsert(char *nome, column *c);
/*
    Esta função finaliza a inserção de valores em uma tabela. Assume que o usuário entrou com todos
    os campos de uma tupla completa.
    Retorna:
        -> ERRO_ABRIR_ARQUIVO, quando ocorreu um erro ao abrir o arquivo fs_object.dat ou fs_schema.dat;
        -> ERRO_NO_TAMANHO_STRING, quando ocorreu um erro no tamanho da string inserida;
        -> ERRO_NOME_CAMPO, quando o nome do campo passado na estrutura;
        -> ERRO_NO_TIPO_INTEIRO, quando o valor passado não é um inteiro;
        -> ERRO_NO_TIPO_DOUBLE, quando o valor passado não é um double;
        -> ERRO_NO_TIPO_CHAR, quando o valor passado é maior que 1byte;
        -> SUCCESS, quando a função teve sucesso em sua operação de inserção na tabela.
    *nome - Nome da tabela que vai ser inserido os valores da estrutura *c.
    *c - Estrutura com o valores que vão ser inseridos na tabela *nome.
*/

/************************************************************************************************
 ************************************************************************************************/


/************************************************************************************************
/  Natan J. Mai, Ricardo Zanuzzo e Rogério Torchelsen                                          */

void imprime(char nomeTabela[] );
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Utilizada para impressão de tabelas.
    Parametros: Nome da tabela (char).
    Retorno:    void.
   ---------------------------------------------------------------------------------------------*/

int excluirTabela(char *nomeTabela);
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Função para exclusão de tabelas.
    Parametros: Nome da tabela (char).
    Retorno:    INT
                SUCCESS,
                ERRO_REMOVER_ARQUIVO_OBJECT,
                ERRO_REMOVER_ARQUIVO_SCHEMA,
                ERRO_LEITURA_DADOS.
   ---------------------------------------------------------------------------------------------*/


//TrocaArquivosObj:



//procuraSchemaArquivo:
int procuraSchemaArquivo(struct fs_objects objeto);
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Copia todas as informações menos a tabela do objeto, que será removida.
    Parametros: Objeto que será removido do schema.
    Retorno:    INT
                SUCCESS,
                ERRO_REMOVER_ARQUIVO_SCHEMA
   ---------------------------------------------------------------------------------------------*/

int verificaChaveFK(char *nomeTabela, column *c, char *nomeCampo, char *valorCampo, char *tabelaApt, char *attApt);
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Gera as verificações em relação a chave FK.
    Parametros: Nome da Tabela, Coluna C, Nome do Campo, Valor do Campo, Tabela Apontada e Atributo Apontado.
    Retorno:    INT
                SUCCESS,
                ERRO_DE_PARAMETRO,
                ERRO_CHAVE_ESTRANGEIRA
   ---------------------------------------------------------------------------------------------*/

int verificaChavePK(char *nomeTabela, column *c, char *nomeCampo, char *valorCampo);
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Gera as verificações em relação a chave pK.
    Parametros: Nome da Tabela, Coluna C, Nome do Campo, Valor do Campo
    Retorno:    INT
                SUCCESS,
                ERRO_DE_PARAMETRO,
                ERRO_CHAVE_PRIMARIA
   ---------------------------------------------------------------------------------------------*/

int iniciaAtributos(struct fs_objects *objeto, tp_table **tabela, tp_buffer **bufferpoll, char *nomeT);
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Inicializa os atributos necessários para a verificação de FK e PK.
    Parametros: Objeto da tabela, Tabela, Buffer e nome da tabela.
    Retorno:    INT
                SUCCESS,
                ERRO_DE_PARAMETRO,
   ---------------------------------------------------------------------------------------------*/

//função que
tp_table *abreTabela(char *nomeTabela, struct fs_objects *objeto, tp_table **tabela);
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Recebe o nome de uma tabela e engloba as funções leObjeto() e leSchema().
    Parametros: Nome da Tabela, Objeto da Tabela e tabela.
    Retorno:    tp_table
   ---------------------------------------------------------------------------------------------*/


int retornaTamanhoValorCampo(char *nomeCampo, table  *tab);

void cria_campo(int tam, int header, char *val, int x);


double convertD(char u[]);

char retornaTamanhoTipoDoCampo(char *nomeCampo, table  *tab);



/*------------------------------------------------------------------------------------ */
/* ----------------- Igor Beilner, Eliton Traverssini, Régis T. Feyh ----------------- */
/*------------------------------------------------------------------------------------ */
/* insert: Recebe uma estrutura rc_insert e valida os tokens encontrados pela interface().
 *         Se os valores forem válidos, insere um novo valor.
 */
void insert(rc_insert *nomeTabela);



/* printTable: Imprime a list de tabelas quando o usuário enviar o comando \d
 *             ou imprime a list de atributos da tabela quando o usuário informar
 *             \dt <Nome da tabela>
 */
void printTable(char *tbl);

/* help: Ajuda do programa
 *
 *
/* objcmp: Recebe o nome de um objeto e a entrada do usuário e
 *         verifica se são iguais sem diferenciar caracteres
 *         maiúsculos e minúsculos.
 */

/* strcpylower: Recebe duas strings dest e src,
 *              copia src para dest em minúsculo
 */
/* strncpylower: Recebe duas strings dest e src e o tamanho de src,
 *               copia src para dest em minúsculo no tamanho length
 */
/* createTable: Recebe uma estrutura contendo os parâmetros do CREATE TABLE
 *              e cria uma tabela no banco corrente
 */
void createTable(rc_insert *t);




/* clear: limpa o shell do SGBD
 *
 */
void clear();


void freeTp_table(tp_table **tabela, int n);
void freeTable(table *tabela);
void freeColumn(column *colunas);
