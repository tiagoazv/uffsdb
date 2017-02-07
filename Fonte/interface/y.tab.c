/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "interface/yacc.y"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#ifndef FMACROS
   #include "../macros.h"
#endif
#ifndef FTYPES
   #include "../types.h"
#endif
#ifndef FMISC
   #include "../misc.h"
#endif
#ifndef FDICTIONARY
   #include "../dictionary.h"
#endif
#ifndef FSQLCOMMANDS
   #include "../sqlcommands.h"
#endif
#ifndef FDATABASE
   #include "../database.h"
#endif
#ifndef FPARSER
   #include "parser.h"
#endif

extern char* yytext[];
extern FILE * yyin;
extern FILE* outFile_p;

int yywrap() {
    return 1;
}

#line 38 "interface/yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int intval;
    double floatval;
    int subtok;
    char *strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 70 "interface/y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INSERT 257
#define INTO 258
#define VALUES 259
#define SELECT 260
#define FROM 261
#define CREATE 262
#define TABLE 263
#define INTEGER 264
#define VARCHAR 265
#define DOUBLE 266
#define CHAR 267
#define PRIMARY 268
#define KEY 269
#define REFERENCES 270
#define DATABASE 271
#define DROP 272
#define OBJECT 273
#define NUMBER 274
#define VALUE 275
#define QUIT 276
#define LIST_TABLES 277
#define LIST_TABLE 278
#define CONNECT 279
#define HELP 280
#define LIST_DBASES 281
#define CLEAR 282
#define CONTR 283
#define WHERE 284
#define OPERADOR 285
#define RELACIONAL 286
#define LOGICO 287
#define ASTERISCO 288
#define SINAL 289
#define FECHA_P 290
#define ABRE_P 291
#define STRING 292
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    9,   16,   10,
   14,   17,   18,    7,    8,   13,   12,   15,   20,    1,
   11,   19,   21,   21,   23,   23,   24,   22,   22,   25,
   25,   25,   26,    3,   27,   27,   29,   31,   32,   29,
   29,   29,   28,   30,   30,   30,   33,   34,   35,   36,
    5,   37,   38,    4,   39,   40,    6,   42,    2,   43,
   41,   46,   41,   47,   41,   45,   48,   45,   44,   44,
   49,   53,   49,   52,   51,   54,   51,   56,   50,   55,
   55,   59,   55,   60,   55,   58,   58,   61,   61,   61,
   62,   62,   57,   57,   57,   57,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    0,    2,    1,    1,
    1,    1,    1,    2,    1,    1,    1,    1,    0,   10,
    1,    1,    0,    3,    1,    3,    1,    1,    3,    1,
    1,    1,    0,    8,    3,    5,    1,    0,    0,    6,
    1,    1,    1,    0,    2,    5,    1,    1,    0,    0,
    6,    0,    0,    6,    0,    0,    6,    0,    7,    1,
    1,    0,    3,    0,    5,    0,    0,    4,    0,    2,
    2,    0,    5,    1,    0,    0,    3,    0,    4,    1,
    2,    0,    3,    0,    5,    0,    2,    1,    1,    1,
    1,    1,    2,    2,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,   68,    0,    0,   19,   20,   25,    0,    0,   27,
   26,   21,   28,   31,    0,    1,    2,    3,    4,    5,
    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
   16,   29,    0,   43,   62,   59,   65,   24,   18,    0,
   72,   71,    0,    0,    0,    0,    0,    0,   32,    0,
    0,   74,    0,    0,   63,   60,   66,   22,    0,    0,
    0,   73,    0,   70,    0,    0,    0,    0,    0,   37,
    0,    0,    0,   77,    0,    0,    0,   53,    0,    0,
   64,   61,   67,   23,   34,    0,    0,    0,   75,   92,
  106,  105,   84,   90,  101,  102,   80,    0,    0,    0,
    0,    0,   69,    0,   47,   48,   51,   52,    0,   36,
   41,   40,   42,    0,    0,   78,    0,   86,   81,    0,
    0,   88,   99,   98,   91,    0,  100,  104,  103,   44,
    0,    0,    0,    0,    0,    0,   93,    0,   82,    0,
    0,    0,   97,    0,   55,   57,    0,    0,   30,   39,
   87,    0,    0,   89,   94,   49,    0,   46,   83,   95,
    0,   58,    0,   50,   56,
};
static const YYINT yydgoto[] = {                         15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
   26,   27,   28,   29,   30,   31,   59,   85,   50,   40,
   60,  114,   71,   72,  115,   45,   79,   80,  109,  134,
  131,  161,  147,  163,   47,   68,   46,   67,   48,   69,
   44,   33,   65,   77,   62,   51,   63,   88,   97,   98,
  119,   99,  152,  138,  100,  141,  101,  125,  117,  140,
  126,  102,
};
static const YYINT yysindex[] = {                       -18,
 -233,    0, -241, -240,    0,    0,    0, -239, -234,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -256,    0,    0,    0,    0,    0,    0, -229,
    0,    0, -226, -232, -229, -223, -221, -219,    0, -230,
   18,    0, -210, -230,    0,    0,    0,    0, -208, -193,
 -206,    0,   18,    0, -216, -204,   11,   11,   11,    0,
 -218,   27, -230,    0, -217,  -43,   11,    0, -218, -207,
    0,    0,    0,    0,    0, -208, -254,   18,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -213,  -43, -211,
  -42, -238,    0,   11,    0,    0,    0,    0, -244,    0,
    0,    0,    0, -218,   32,    0,  -42,    0,    0, -212,
 -211,    0,    0,    0,    0,  -43,    0,    0,    0,    0,
 -230, -190, -192,   36,   11, -254,    0,  -43,    0, -203,
  -43,  -43,    0, -191,    0,    0, -209, -204,    0,    0,
    0, -213,  -42,    0,    0,    0, -189,    0,    0,    0,
 -218,    0, -202,    0,    0,
};
static const YYINT yyrindex[] = {                        86,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -169,
 -170,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -198,    0,   34,    0,    0,    0,    0,    0,
    0, -196,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -245,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -54,    0,    0,
  -53,    0,    0,    0,    0,    0,    0,    0,  -40,    0,
    0,    0,    0,    0, -195,    0,  -53,    0,    0,    0,
 -194,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -188,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -54,  -53,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -58,    0,    0,    0,    0,    0,  -46,  -72,   52,    0,
    0,  -38,   13,    0,    0,    0,  -48,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -45,    0,    0,    0,  -85,    0,
  -51,  -93,    0,    0,  -86,    0,    0, -102,    0,    0,
    0,  -89,
};
#define YYTABLESIZE 265
static const YYINT yytable[] = {                         96,
   96,   95,   95,   54,   85,   96,  104,   66,   81,   82,
   83,  127,  121,  120,  137,   76,   41,   75,  103,  111,
  112,   34,   36,  132,   32,  133,   87,  127,   53,   35,
   37,   42,  142,   38,   43,  128,  129,  113,   39,  143,
   14,  135,  116,   49,   76,  130,   52,  142,  142,   55,
  160,   56,  151,   57,  154,  155,  105,  106,  107,  108,
   58,   61,   64,  127,   70,   73,   74,   76,   78,   14,
   86,   84,   89,  118,  122,  136,  149,  139,  145,  148,
  146,  157,  156,  162,  144,   17,  153,  165,  164,   33,
   76,   76,   79,   35,   38,   94,   54,  150,  110,  158,
  159,   45,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   90,
   91,   92,   96,   96,    0,   85,   96,    0,    1,    0,
    0,    2,  123,    3,    0,  124,    0,   93,   94,   54,
    0,    0,    0,    4,    5,    0,    0,    6,    7,    8,
    9,   10,   11,   12,   13,
};
static const YYINT yycheck[] = {                         43,
   43,   45,   45,   44,   59,   59,   79,   54,   67,   68,
   69,  101,   99,   99,  117,  261,  273,   63,   77,  274,
  275,  263,  263,  268,  258,  270,   73,  117,  261,  271,
  271,  288,  126,  273,  291,  274,  275,  292,  273,  126,
   59,  114,   88,  273,  290,  104,  273,  141,  142,  273,
  153,  273,  138,  273,  141,  142,  264,  265,  266,  267,
  291,   44,  273,  153,  273,  259,  273,  284,  273,   59,
   44,  290,  290,  287,  286,   44,  135,  290,  269,   44,
  273,  291,  274,  273,  131,    0,  290,  290,  161,  259,
  261,  290,   59,  290,  290,  290,   45,  136,   86,  148,
  152,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  273,
  274,  275,  286,  287,   -1,  290,  290,   -1,  257,   -1,
   -1,  260,  285,  262,   -1,  288,   -1,  291,  292,  290,
   -1,   -1,   -1,  272,  273,   -1,   -1,  276,  277,  278,
  279,  280,  281,  282,  283,
};
#define YYFINAL 15
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#define YYUNDFTOKEN 357
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'+'","','","'-'",0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INSERT","INTO",
"VALUES","SELECT","FROM","CREATE","TABLE","INTEGER","VARCHAR","DOUBLE","CHAR",
"PRIMARY","KEY","REFERENCES","DATABASE","DROP","OBJECT","NUMBER","VALUE","QUIT",
"LIST_TABLES","LIST_TABLE","CONNECT","HELP","LIST_DBASES","CLEAR","CONTR",
"WHERE","OPERADOR","RELACIONAL","LOGICO","ASTERISCO","SINAL","FECHA_P","ABRE_P",
"STRING",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : insert",
"start : select",
"start : create_table",
"start : create_database",
"start : drop_table",
"start : drop_database",
"start : table_attr",
"start : list_tables",
"start : connection",
"start : exit_program",
"start : semicolon",
"start : help_pls",
"start : list_databases",
"start : clear",
"start : contributors",
"start : qualquer_coisa",
"start :",
"connection : CONNECT OBJECT",
"qualquer_coisa : OBJECT",
"exit_program : QUIT",
"clear : CLEAR",
"parentesis_open : ABRE_P",
"parentesis_close : FECHA_P",
"table_attr : LIST_TABLE OBJECT",
"list_tables : LIST_TABLES",
"list_databases : LIST_DBASES",
"help_pls : HELP",
"contributors : CONTR",
"$$1 :",
"insert : INSERT INTO $$1 table opt_column_list VALUES parentesis_open value_list parentesis_close semicolon",
"semicolon : ';'",
"table : OBJECT",
"opt_column_list :",
"opt_column_list : parentesis_open column_list parentesis_close",
"column_list : column",
"column_list : column ',' column_list",
"column : OBJECT",
"value_list : value",
"value_list : value ',' value_list",
"value : VALUE",
"value : NUMBER",
"value : STRING",
"$$2 :",
"create_table : CREATE TABLE $$2 table parentesis_open table_column_attr parentesis_close semicolon",
"table_column_attr : column_create type attribute",
"table_column_attr : column_create type attribute ',' table_column_attr",
"type : INTEGER",
"$$3 :",
"$$4 :",
"type : VARCHAR $$3 parentesis_open NUMBER $$4 parentesis_close",
"type : DOUBLE",
"type : CHAR",
"column_create : OBJECT",
"attribute :",
"attribute : PRIMARY KEY",
"attribute : REFERENCES table_fk ABRE_P column_fk FECHA_P",
"table_fk : OBJECT",
"column_fk : OBJECT",
"$$5 :",
"$$6 :",
"drop_table : DROP TABLE $$5 OBJECT $$6 semicolon",
"$$7 :",
"$$8 :",
"create_database : CREATE DATABASE $$7 OBJECT $$8 semicolon",
"$$9 :",
"$$10 :",
"drop_database : DROP DATABASE $$9 OBJECT $$10 semicolon",
"$$11 :",
"select : SELECT $$11 projecao FROM table_select where semicolon",
"table_select : OBJECT",
"projecao : ASTERISCO",
"$$12 :",
"projecao : OBJECT $$12 projecao2",
"$$13 :",
"projecao : ABRE_P OBJECT $$13 projecao2 FECHA_P",
"projecao2 :",
"$$14 :",
"projecao2 : ',' OBJECT $$14 projecao2",
"where :",
"where : WHERE logicos",
"logicos : relacoes repLogicos",
"$$15 :",
"logicos : adc_abre_p logicos FECHA_P $$15 repLogicos",
"adc_abre_p : ABRE_P",
"repLogicos :",
"$$16 :",
"repLogicos : LOGICO $$16 logicos",
"$$17 :",
"relacoes : operacao RELACIONAL $$17 operacao",
"operacao : STRING",
"operacao : operando operacao2",
"$$18 :",
"operacao : OBJECT $$18 operacao2",
"$$19 :",
"operacao : adc_abre_p operacao $$19 FECHA_P operacao2",
"operacao2 :",
"operacao2 : operador operacao",
"operador : ASTERISCO",
"operador : OPERADOR",
"operador : sinal",
"sinal : '-'",
"sinal : '+'",
"operando : sinal VALUE",
"operando : sinal NUMBER",
"operando : VALUE",
"operando : NUMBER",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 11:
#line 55 "interface/yacc.y"
	{GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 18:
#line 64 "interface/yacc.y"
	{connect(*yytext); GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 19:
#line 66 "interface/yacc.y"
	{GLOBAL_PARSER.consoleFlag = 1; GLOBAL_PARSER.noerror = 0; return 0;}
break;
case 20:
#line 69 "interface/yacc.y"
	{exit(0);}
break;
case 21:
#line 71 "interface/yacc.y"
	{clear(); GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 22:
#line 73 "interface/yacc.y"
	{GLOBAL_PARSER.parentesis++;}
break;
case 23:
#line 75 "interface/yacc.y"
	{GLOBAL_PARSER.parentesis--;}
break;
case 24:
#line 78 "interface/yacc.y"
	{
    if(connected.conn_active) {
        printTable(yylval.strval);
        GLOBAL_PARSER.consoleFlag = 1;
    } else
        notConnected();
    return 0;
}
break;
case 25:
#line 88 "interface/yacc.y"
	{
    if(connected.conn_active) {
        printTable(NULL);
        GLOBAL_PARSER.consoleFlag = 1;
    } else
        notConnected();
    return 0;
}
break;
case 26:
#line 98 "interface/yacc.y"
	{
    showDB();
    GLOBAL_PARSER.consoleFlag = 1;
    return 0;
}
break;
case 27:
#line 105 "interface/yacc.y"
	{help(); GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 28:
#line 108 "interface/yacc.y"
	{contr(); GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 29:
#line 115 "interface/yacc.y"
	{setMode(OP_INSERT);}
break;
case 30:
#line 115 "interface/yacc.y"
	{
    if (GLOBAL_PARSER.col_count == GLOBAL_PARSER.val_count || GLOBAL_DATA.columnName == NULL)
        GLOBAL_DATA.N = GLOBAL_PARSER.val_count;
    else {
        printf("ERROR: The column counter doesn't match the value counter.\n");
        GLOBAL_PARSER.noerror=0;
    }
    return 0;
}
break;
case 32:
#line 127 "interface/yacc.y"
	{setObjName(yytext);}
break;
case 37:
#line 133 "interface/yacc.y"
	{setColumnInsert(yytext);}
break;
case 40:
#line 137 "interface/yacc.y"
	{setValueInsert(yylval.strval, 'D');}
break;
case 41:
#line 138 "interface/yacc.y"
	{setValueInsert(yylval.strval, 'I');}
break;
case 42:
#line 139 "interface/yacc.y"
	{setValueInsert(yylval.strval, 'S');}
break;
case 43:
#line 142 "interface/yacc.y"
	{setMode(OP_CREATE_TABLE);}
break;
case 44:
#line 142 "interface/yacc.y"
	{
    GLOBAL_DATA.N = GLOBAL_PARSER.col_count;
    return 0;
}
break;
case 47:
#line 149 "interface/yacc.y"
	{setColumnTypeCreate('I');}
break;
case 48:
#line 150 "interface/yacc.y"
	{setColumnTypeCreate('S');}
break;
case 49:
#line 150 "interface/yacc.y"
	{setColumnSizeCreate(yylval.strval);}
break;
case 51:
#line 151 "interface/yacc.y"
	{setColumnTypeCreate('D');}
break;
case 52:
#line 152 "interface/yacc.y"
	{setColumnTypeCreate('C');}
break;
case 53:
#line 154 "interface/yacc.y"
	{setColumnCreate(yytext);}
break;
case 55:
#line 157 "interface/yacc.y"
	{setColumnPKCreate();}
break;
case 57:
#line 160 "interface/yacc.y"
	{setColumnFKTableCreate(yytext);}
break;
case 58:
#line 162 "interface/yacc.y"
	{setColumnFKColumnCreate(yytext);}
break;
case 59:
#line 165 "interface/yacc.y"
	{setMode(OP_DROP_TABLE);}
break;
case 60:
#line 165 "interface/yacc.y"
	{setObjName(yytext);}
break;
case 61:
#line 165 "interface/yacc.y"
	{return 0;}
break;
case 62:
#line 168 "interface/yacc.y"
	{setMode(OP_CREATE_DATABASE);}
break;
case 63:
#line 168 "interface/yacc.y"
	{setObjName(yytext);}
break;
case 64:
#line 168 "interface/yacc.y"
	{return 0;}
break;
case 65:
#line 171 "interface/yacc.y"
	{setMode(OP_DROP_DATABASE);}
break;
case 66:
#line 171 "interface/yacc.y"
	{setObjName(yytext);}
break;
case 67:
#line 171 "interface/yacc.y"
	{return 0;}
break;
case 68:
#line 174 "interface/yacc.y"
	{setMode(OP_SELECT); resetSelect();}
break;
case 69:
#line 175 "interface/yacc.y"
	{return 0;}
break;
case 70:
#line 177 "interface/yacc.y"
	{adcTabelaSelect(yylval.strval);}
break;
case 71:
#line 179 "interface/yacc.y"
	{adcProjSelect(yylval.strval);}
break;
case 72:
#line 180 "interface/yacc.y"
	{adcProjSelect(yylval.strval);}
break;
case 74:
#line 181 "interface/yacc.y"
	{adcProjSelect(yylval.strval);}
break;
case 77:
#line 184 "interface/yacc.y"
	{adcProjSelect(yylval.strval);}
break;
case 82:
#line 190 "interface/yacc.y"
	{adcTokenWhere(yylval.strval,6);}
break;
case 84:
#line 192 "interface/yacc.y"
	{adcTokenWhere(yylval.strval,5);}
break;
case 86:
#line 195 "interface/yacc.y"
	{adcTokenWhere(*yytext,1);}
break;
case 88:
#line 197 "interface/yacc.y"
	{adcTokenWhere(yylval.strval,2);}
break;
case 90:
#line 199 "interface/yacc.y"
	{adcTokenWhere(yylval.strval,7);}
break;
case 92:
#line 201 "interface/yacc.y"
	{adcTokenWhere(yylval.strval,8);}
break;
case 94:
#line 202 "interface/yacc.y"
	{adcTokenWhere(yylval.strval,6);}
break;
case 98:
#line 207 "interface/yacc.y"
	{adcTokenWhere(yylval.strval,4);}
break;
case 99:
#line 208 "interface/yacc.y"
	{adcTokenWhere(yylval.strval,4);}
break;
case 101:
#line 211 "interface/yacc.y"
	{adcTokenWhere(*yytext,3);}
break;
case 102:
#line 211 "interface/yacc.y"
	{adcTokenWhere(*yytext,3);}
break;
case 103:
#line 213 "interface/yacc.y"
	{adcTokenWhere(yylval.strval,9);}
break;
case 104:
#line 213 "interface/yacc.y"
	{adcTokenWhere(yylval.strval,9);}
break;
case 105:
#line 214 "interface/yacc.y"
	{adcTokenWhere(yylval.strval,9);}
break;
case 106:
#line 214 "interface/yacc.y"
	{adcTokenWhere(yylval.strval,9);}
break;
#line 944 "interface/y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
