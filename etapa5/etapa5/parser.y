
/* Autor: Ronald de Souza Maciel - 00281987 */

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "ast.h"
    #include "hash.h"
    #include "tacs.h"

    int yylex();
    int yyerror();
    extern int getLineNumber();

    AST *root;
    int SemanticErrors;
%}

%union{
  HASH_NODE *symbol;
  AST *ast;
}


%token KW_CHAR           
%token KW_INT            
%token KW_REAL
%token KW_BOOL               

%token KW_IF             
%token KW_THEN          
%token KW_ELSE
%token KW_LOOP

%token KW_INPUT
%token KW_OUTPUT
%token KW_RETURN

%token OPERATOR_LE       
%token OPERATOR_GE      
%token OPERATOR_EQ       
%token OPERATOR_DIF      

%token<symbol> TK_IDENTIFIER     

%token<symbol> LIT_INT       
%token<symbol> LIT_CHAR          
%token<symbol> LIT_STRING
%token<symbol> LIT_REAL        

%token TOKEN_ERROR      

%left OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF '<' '>' 
%left '+' '-'
%left '*' '/'
%left '|' '&'
%left '%' '~'

%type<ast> program
%type<ast> declarat
%type<ast> declarations
%type<ast> func_parameters
%type<ast> end_parameters
%type<ast> tipo
%type<ast> literal
%type<ast> create_array
%type<ast> bloco
%type<ast> commands
%type<ast> commands_list
%type<ast> expr
%type<ast> arguments_list
%type<ast> arguments_list_end
%type<ast> output_list
%type<ast> end_output
%type<ast> elements_to_output

%start program

%%

program : declarat                         { $$ = astCreate(AST_PROGRAM, 0, $1, 0, 0, 0); root = $$; }
        ;


declarat : declarations declarat           { $$ = astCreate(AST_DECLARAT, 0, $1, $2, 0, 0);}
         |                                 { $$ = 0;}
         ;


declarations : tipo TK_IDENTIFIER '=' literal ';'                           { $$ = astCreate(AST_DECVAR, $2, $1, $4, 0, 0);}
             | tipo TK_IDENTIFIER '[' LIT_INT ']' create_array ';'          { $$ = astCreate(AST_DECARRAY, $2, $1, astCreate(AST_ARGVEC, $4, 0, 0, 0, 0), $6, 0);}
             | tipo TK_IDENTIFIER '(' func_parameters ')' bloco             { $$ = astCreate(AST_DECFUNC, $2, $1, $4, $6, 0);}
             ;

func_parameters : tipo TK_IDENTIFIER end_parameters        { $$ = astCreate(AST_PARAMINIT, $2, $1, $3, 0, 0); }       
                |                                          { $$ = 0;} // pode ser vazio inte main()
                ;

end_parameters : ',' tipo TK_IDENTIFIER end_parameters     { $$ = astCreate(AST_PARAMLIST, $3, $2, $4, 0, 0); }       
               |                                           { $$ = 0;} // pode ser vazio inte main()
               ;


literal : LIT_INT              { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
        | LIT_CHAR             { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
        | LIT_REAL             { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
        ; 


tipo : KW_CHAR                 { $$ = astCreate(AST_DECCHAR, 0, 0, 0, 0, 0);}
     | KW_INT                  { $$ = astCreate(AST_DECINT, 0, 0, 0, 0, 0);}
     | KW_REAL                 { $$ = astCreate(AST_DECREAL, 0, 0, 0, 0, 0);}
     | KW_BOOL                 { $$ = astCreate(AST_DECBOOL, 0, 0, 0, 0, 0);}
     ;


create_array :                             { $$ = 0;}
             | literal create_array        { $$ = astCreate(AST_ARR_ELEMENT, 0, $1, $2, 0, 0);}
             ;


bloco : '{' commands_list '}'             { $$ = astCreate(AST_BLOCO, 0, $2, 0, 0, 0); }
      ;


commands_list : commands commands_list   { $$ = astCreate(AST_COMMANDOLIST, 0, $1, $2, 0, 0); }
              |                          { $$ = 0; }
              ;


commands : bloco                                                { $$ = $1; }
         | TK_IDENTIFIER '=' expr ';'                           { $$ = astCreate(AST_ATTR, $1, $3, 0, 0, 0); }
         | TK_IDENTIFIER '[' expr ']' '=' expr ';'              { $$ = astCreate(AST_ARR_ATTR, $1, $3, $6, 0, 0); }            
         | KW_IF '(' expr ')' commands                          { $$ = astCreate(AST_IF, 0, $3, $5, 0, 0); }
         | KW_IF '(' expr ')' commands KW_ELSE commands         { $$ = astCreate(AST_IFELSE, 0, $3, $5, $7, 0); }                
         | KW_IF '(' expr ')' KW_LOOP commands                  { $$ = astCreate(AST_IFLOOP, 0, $3, $6, 0, 0); }        
         | KW_OUTPUT output_list ';'                            { $$ = astCreate(AST_OUTPUT, 0, $2, 0, 0, 0); }
         | KW_RETURN expr ';'                                   { $$ = astCreate(AST_RETURN, 0, $2, 0, 0, 0); }   
         | ';'                                                  { $$ = 0; }
         ;

output_list : elements_to_output end_output           { $$ = astCreate(AST_OUTPUTINIT, 0, $1, $2, 0, 0); }
            ;


end_output :                                        { $$ = 0; }
           | ',' elements_to_output end_output      { $$ = astCreate(AST_OUTPUTLIST, 0, $2, $3, 0, 0); }
           ;

elements_to_output : LIT_STRING              { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
                   | expr                    { $$ = $1; }
                   ;


expr : literal                                  { $$ = $1; }
     | TK_IDENTIFIER                            { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
     | TK_IDENTIFIER '[' expr ']'               { $$ = astCreate(AST_ARRAY, $1, $3, 0, 0,0); }
     | TK_IDENTIFIER '(' arguments_list ')'     { $$ = astCreate(AST_FUNC_CALL, $1, $3, 0, 0,0); } 
     | expr '+' expr                            { $$ = astCreate(AST_ADD, 0, $1, $3, 0, 0); }
     | expr '-' expr                            { $$ = astCreate(AST_SUB, 0, $1, $3, 0, 0); } 
     | expr '*' expr                            { $$ = astCreate(AST_MUL, 0, $1, $3, 0, 0); }
     | expr '/' expr                            { $$ = astCreate(AST_DIV, 0, $1, $3, 0, 0); }
     | expr '<' expr                            { $$ = astCreate(AST_LESS, 0, $1, $3, 0, 0); }
     | expr '>' expr                            { $$ = astCreate(AST_GREATER, 0, $1, $3, 0, 0); }
     | expr '&' expr                            { $$ = astCreate(AST_AND, 0, $1, $3, 0, 0); }
     | expr '|' expr                            { $$ = astCreate(AST_OR, 0, $1, $3, 0, 0); }
     | '~' expr                                 { $$ = astCreate(AST_NOT, 0, $2, 0, 0, 0); }
     | expr OPERATOR_LE expr                    { $$ = astCreate(AST_LE, 0, $1, $3, 0, 0); }        
     | expr OPERATOR_GE expr                    { $$ = astCreate(AST_GE, 0, $1, $3, 0, 0); }        
     | expr OPERATOR_EQ expr                    { $$ = astCreate(AST_EQ, 0, $1, $3, 0, 0); }        
     | expr OPERATOR_DIF expr                   { $$ = astCreate(AST_DIF, 0, $1, $3, 0, 0); }

     | KW_INPUT '(' tipo ')'                    { $$ = astCreate(AST_INPUT, 0, $3, 0, 0, 0); }
     | '(' expr ')'                             { $$ = astCreate(AST_PARENTESES, 0, $2, 0, 0, 0); }     
     ;


arguments_list : expr arguments_list_end       { $$ = astCreate(AST_ARGFUNCCALL, 0, $1, $2, 0, 0); }
               |                               { $$ = 0; }
               ;

arguments_list_end : ',' expr arguments_list_end    { $$ = astCreate(AST_ARGFUNCCALLLIST, 0, $2, $3, 0, 0); }
                   |                                { $$ = 0; }
                   ;


%%


int yyerror() {
    printf("Erro na linha %d\n\n",getLineNumber());  
    exit(3);
}

AST* getAST(){
    return root;
}

tac* getTACs(){
  return rewindTac(createTacs(root, 0));
}