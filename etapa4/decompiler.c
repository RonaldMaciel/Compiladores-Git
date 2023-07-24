#include <stdio.h>
#include <stdlib.h>
#include "decompiler.h"

FILE *output;

void decompileRoot(AST *root, FILE *outputFile) {
    if (root->type != AST_PROGRAM){
        fprintf(stderr, "Error: This node is not the root node\n");
        return;
    }
    output = outputFile;

    for (int i=0; i < MAX_SONS; i++)
        decompile(root->son[i]);
    
    fclose(output);
}

void decompile(AST *node){
    if (node == 0) {
        return;
    }

    switch (node->type) {

        case AST_ATTR: 
            fprintf(output,"%s = ", node->symbol->text);
            decompile(node->son[0]);
            fprintf(output,";\n");
            break;

        case AST_DECLARAT: 
            if (node->son[0] != 0) { decompile(node->son[0]); }
            if (node->son[1] != 0) { decompile(node->son[1]); }
            break;

        case AST_DECVAR:                      
            if (node->son[0] != 0) { decompile(node->son[0]); }
            fprintf(output," %s=",node->symbol->text);
            if (node->son[1] != 0) { decompile(node->son[1]); }
            fprintf(output,";\n");
            break;    

        case AST_DECINT:
            fprintf(output, "int"); 
            break;

        case AST_DECCHAR: 
            fprintf(output, "char"); 
            break;

        case AST_DECREAL: 
            fprintf(output, "real"); 
            break;

        case AST_DECBOOL: 
            fprintf(output, "bool"); 
            break;

        case AST_DECARRAY: 
            if (node->son[0] !=0 ) { decompile(node->son[0]); } 
            fprintf(output," %s[", node->symbol->text);
            if (node->son[1] !=0 ) { decompile(node->son[1]); }
            fprintf(output, "] ");
            if (node->son[2] != 0) { decompile(node->son[2]); }
            fprintf(output, ";\n");
            break;    

        case AST_ARGVEC:        
            fprintf(output, "%s", node->symbol->text);
            break;
     
        case AST_ARR_ATTR: 
            fprintf(output,"%s[", node->symbol->text);
            decompile(node->son[0]);
            fprintf(output,"] = ");
            decompile(node->son[1]);
            fprintf(output, ";\n");        
            break;

        case AST_IF:
            fprintf(output,"if (");
            if (node->son[0] != 0) { decompile(node->son[0]); }
			fprintf(output,") ");
            if (node->son[1] != 0) { decompile(node->son[1]); }
            break;


        case AST_IFELSE:
            fprintf(output, "if (");
            if (node->son[0] != 0) { decompile(node->son[0]); }
            fprintf(output, ") ");
            if (node->son[1] != 0) { decompile(node->son[1]); }
            fprintf(output, "else\n");
            if (node->son[2] != 0) { decompile(node->son[2]); }
            break;

        case AST_IFLOOP:  
            fprintf(output, "if (");
            if (node->son[0] != 0) { decompile(node->son[0]); }
            fprintf(output, ") loop ");
            if (node->son[1] != 0) { decompile(node->son[1]); }
            break;

        case AST_INPUT: 
            fprintf(output, "input(");
            if (node->son[0] != 0) { decompile(node->son[0]); }
            fprintf(output, ")");
            break;

        case AST_OUTPUT:
            fprintf(output, "output ");
            if (node->son[0] != 0) { decompile(node->son[0]); }
            fprintf(output, ";\n");
            break;
        
		case AST_OUTPUTINIT:
            if (node->son[0] != 0 ) { decompile(node->son[0]); }
            if (node->son[1] != 0 ) { decompile(node->son[1]); }
            break;
			   
		case AST_OUTPUTLIST:
			fprintf(output, ", ");
			if (node->son[0] != 0) { decompile(node->son[0]); }
            if (node->son[1] != 0 ) { decompile(node->son[1]); }
            break;
            
        case AST_RETURN: 
            fprintf(output,"return ");
            if (node->son[0] != 0) { decompile(node->son[0]); }
            fprintf(output, ";\n");
            break;

        case AST_BLOCO: 
            fprintf(output, "\n{\n");
            if (node->son[0] != 0) { decompile(node->son[0]); }
            fprintf(output, "}\n");
            break;

       case AST_COMMANDOLIST:
            if (node->son[0] != 0 ) { decompile(node->son[0]); }
            if (node->son[1] != 0 ) { decompile(node->son[1]); }
            break;

     	case AST_PROGRAM:
            decompile(node->son[1]);
            break;

        case AST_PARENTESES:
            fprintf(output, "(");
            if (node->son[0] != 0) { decompile(node->son[0]); }
            fprintf(output, ")");
            break;

        case AST_DECFUNC:
            if (node->son[0] != 0) { decompile(node->son[0]);}
            fprintf(output, " %s(", node->symbol->text);
            if (node->son[1] != 0) { decompile(node->son[1]);}
            fprintf(output, ")");
            if (node->son[2] != 0) { decompile(node->son[2]);}
            fprintf(output, "\n");
            break;
              
		case AST_PARAMINIT:
			if (node->son[0] != 0) { decompile(node->son[0]); }
            fprintf(output, " %s", node->symbol->text);
            if (node->son[1] != 0) { decompile(node->son[1]); }
            break;
            
      	case AST_PARAMLIST:
            fprintf(output, ", ");		   
            if (node->son[0] != 0) { decompile(node->son[0]); }
            fprintf(output, " %s", node->symbol->text);
            if (node->son[1] != 0) { decompile(node->son[1]); }
            break;

      	case AST_ARR_ELEMENT:
            if (node->son[0] != 0) { decompile(node->son[0]); }
            fprintf(output, " ");
            if (node->son[1] != 0) { decompile(node->son[1]); }
            break;

        case AST_ARRAY:
            fprintf(output,"%s[",node->symbol->text);
            if (node->son[0] != 0) { decompile(node->son[0]); }            
            fprintf(output,"] ");
            break;

       case AST_FUNC_CALL:
            fprintf(output,"%s( ", node->symbol->text);
            decompile(node->son[0]);
            fprintf(output,")");
            break;
            
        case AST_ARGFUNCCALL:
            if (node->son[0] != 0) { decompile(node->son[0]); }
            if (node->son[1] != 0) { decompile(node->son[1]); }
            break;

        case AST_ARGFUNCCALLLIST:
            fprintf(output, ",");
            if (node->son[0] != 0) { decompile(node->son[0]); }
            if (node->son[1] != 0) { decompile(node->son[1]); }
            break;

       case AST_ADD: 
            decompile(node->son[0]);
            fprintf(output, " + ");
            decompile(node->son[1]);
            break;

        case AST_SUB:
            decompile(node->son[0]);
            fprintf(output, " - ");
            decompile(node->son[1]);
            break;

        case AST_MUL:
            decompile(node->son[0]);
            fprintf(output, " * ");
            decompile(node->son[1]);
            break;

        case AST_DIV:
            decompile(node->son[0]);
            fprintf(output, " / ");
            decompile(node->son[1]);
            break;
          
        case AST_AND: 
            decompile(node->son[0]);
            fprintf(output, " & ");
            decompile(node->son[1]);
            break;

        case AST_OR:
            decompile(node->son[0]);
            fprintf(output, " | ");
            decompile(node->son[1]);
            break;

        case AST_NOT:
            decompile(node->son[0]);
            fprintf(output, "~");
            decompile(node->son[1]);
            break;
           
        case AST_LESS:
            decompile(node->son[0]);
            fprintf(output, " < ");
            decompile(node->son[1]);
            break;

        case AST_GREATER:
            decompile(node->son[0]);
            fprintf(output, " > ");
            decompile(node->son[1]);
            break;

        case AST_DIF:
            decompile(node->son[0]);
            fprintf(output, " != ");
       		decompile(node->son[1]);
            break;

        case AST_EQ:
            decompile(node->son[0]);
            fprintf(output, " == ");
            decompile(node->son[1]);
            break;

        case AST_GE:
            decompile(node->son[0]);
            fprintf(output, " >= ");
            decompile(node->son[1]);
            break;

        case AST_LE:
            decompile(node->son[0]);
            fprintf(output, " <= ");
            decompile(node->son[1]);
            break;                    

        case AST_SYMBOL:
            fprintf(output, "%s", node->symbol->text);
            break;

        default: 
            fprintf(output, "<<Token nao declarado!>>"); 
            break;       
    }
    return;
}
