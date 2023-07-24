/* Autor: Ronald de Souza Maciel - 00281987*/

%{
	#include "tokens.h"
	#include "hash.h"

	int running = 1;
	int lineNumber = 1;
%}

%x COMMENT
%x ONELINECOMMENT

%%
char					   { return KW_CHAR;      }
int                        { return KW_INT;       }
real                       { return KW_REAL;      }
bool                       { return KW_BOOL;      }
if                         { return KW_IF;        }
then                       { return KW_THEN;      }
else                       { return KW_ELSE;      }
loop                       { return KW_LOOP;      }
input                      { return KW_INPUT;     }
output                     { return KW_OUTPUT;    }
return                     { return KW_RETURN;    }

"<="                       { return OPERATOR_LE;  }
">="                       { return OPERATOR_GE;  }
"=="                       { return OPERATOR_EQ;  }
"!="                       { return OPERATOR_DIF; }

[-,;()\[\]{}=+*/%<>&|~]    { return yytext[0];    }

[a-zA-Z_.]+                { hashInsert(yytext, TK_IDENTIFIER);  return TK_IDENTIFIER; }
[0-9]+                     { hashInsert(yytext, LIT_INT);        return LIT_INT;       } 
\'.\'                      { hashInsert(yytext, LIT_CHAR);       return LIT_CHAR;      } 
[0-9]+\.[0-9]+             { hashInsert(yytext, LIT_REAL);       return LIT_REAL;      }
\"(\\.|[^"])*\"            { hashInsert(yytext, LIT_STRING);     return LIT_STRING;    }

\n                         { lineNumber++;        }
[ \t\s]                    { }

"\\\\\\"                   { BEGIN(COMMENT); }
<COMMENT>"///"             { BEGIN(INITIAL); }
<COMMENT>"\n"              { lineNumber++; }
<COMMENT>.                 { }

"\\\\"                     { BEGIN(ONELINECOMMENT); }
<ONELINECOMMENT>.          { }
<ONELINECOMMENT>"\n"       { lineNumber++; BEGIN(INITIAL); } 

.                          { return TOKEN_ERROR;  }

%%

int getLineNumber(void){
	return lineNumber;
}

int isRunning(void){
	return running;
}

int yywrap(){
    running = 0;
    return 1;
}

void initMe(void){
	hashInit();
}


