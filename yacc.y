%{
#include "stdio.h"
extern FILE *yyin;

int yylex();

void yyerror(char* str)
{
    fprintf(stderr,"%s\n",str);
}


%}

%token  T_Create T_Delete T_From T_Table T_Database T_Asterisk T_Select T_Insert T_Values T_Into
%token  T_Where T_Drop T_Update T_Set V_Int V_String T_Use
%token  D_Int D_Char D_Varchar D_Double D_Boolean D_String D_Date T_OpBrace T_ClBrace
%token  T_Comma T_Semicolon T_Quote T_Equal T_And T_Or T_Not T_Name V_Date V_Bool V_Double
%token  T_GT T_LT T_GTE T_LTE T_NE C_PK C_FK C_RF C_UQ T_IS T_NULL T_NOTNULL T_Constraint

%%

Success:
        Command_I
        |Command_D
        |Command_S
        |Command_U
        |Command_C
        |Command_Use
        |Command_Drop
        ;


