
/* Autor: Ronald de Souza Maciel - 00281987 */

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

%token TK_IDENTIFIER     

%token LIT_INT       
%token LIT_CHAR          
%token LIT_STRING
%token LIT_REAL        

%token TOKEN_ERROR      

%left OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF '<' '>' 
%left '+' '-'
%left '*' '/'
%left '|' '&'
%left '%' '~'


%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "hash.h"

    int yylex();
    int yyerror();
    extern int getLineNumber();
%}


%%
program : declarat
        ;


declarat : declarations declarat
         | func_declaration declarat
         |
         ;


declarations : tipo TK_IDENTIFIER '=' literal ';'
             | tipo TK_IDENTIFIER '[' LIT_INT ']' create_array ';'
             ;


func_declaration : tipo TK_IDENTIFIER '(' func_parameters ')' bloco
                 ;

func_parameters : tipo TK_IDENTIFIER end_parameters
                | 
                ;

end_parameters : ',' tipo TK_IDENTIFIER end_parameters
               | 
               ;


literal : LIT_INT
        | LIT_CHAR    
        | LIT_REAL
        ; 


tipo : KW_CHAR
     | KW_INT
     | KW_REAL
     | KW_BOOL
     ;


create_array : 
             | literal create_array
             ;


bloco : '{' commands_list '}'
      | '{' '}'
      ;


commands_list : commands commands_list
              |
              ;


commands : bloco
         | TK_IDENTIFIER '=' expr ';'
         | TK_IDENTIFIER '[' expr ']' '=' expr ';'
         | KW_IF '(' expr ')' commands
         | KW_IF '(' expr ')' commands KW_ELSE commands
         | KW_IF '(' expr ')' KW_LOOP commands
         | KW_OUTPUT output_list ';'
         | KW_RETURN expr ';'
         | ';'
         ;

output_list : elements_to_output end_output
            ;


elements_to_output : LIT_STRING
                   | expr
                   ;

end_output : ',' elements_to_output end_output 
           | 
           ;


expr : literal 
     | TK_IDENTIFIER
     | TK_IDENTIFIER '[' expr ']'
     | TK_IDENTIFIER '(' arguments_list ')'
     | expr '+' expr
     | expr '-' expr
     | expr '*' expr
     | expr '/' expr
     | expr '<' expr
     | expr '>' expr
     | expr '&' expr
     | expr '|' expr
     | '~' expr
     | expr OPERATOR_LE expr
     | expr OPERATOR_GE expr
     | expr OPERATOR_EQ expr  
     | expr OPERATOR_DIF expr
     | '(' expr ')' 
     | KW_INPUT '(' tipo ')'
     ;


arguments_list : expr arguments_list_end
               |
               ;

arguments_list_end : ',' expr arguments_list_end
                   | 
                   ;


%%


int yyerror() {
    printf("Erro na linha %d\n\n",getLineNumber());  
    exit(3);
}