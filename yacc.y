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

Command_I:
           T_Insert T_Into T_Name Column_List T_Values T_OpBrace Comma_Expr T_ClBrace T_Semicolon
           {
                printf("\nmydbms>>Insert command:Parsed\n");
           }

Command_D:
          T_Delete T_From T_Name Condition_Expr T_Semicolon
          {
               printf("\nmydbms>>Delete command:Parsed\n");

          }

Command_S:
           T_Select Atribute_List T_From T_Name Condition_Expr T_Semicolon
          {
             printf("\nmydbms>>Select command:Parsed\n");

          }

Command_U:
          T_Update T_Name T_Set Value_List Condition_Expr T_Semicolon
          {
           printf("\nmydbms>>Update command:Parsed\n");

          }


Command_C:
          T_Create T_Database T_Name
          |T_Create T_Table T_Name T_OpBrace Attr_List Constraints T_ClBrace T_Semicolon
          {
          printf("\nmydbms>>Create command:Parsed\n");

          }

Command_Use:
           T_Use T_Name T_Semicolon
           {
               printf("\nmydbms>>Use Command:Parsed\n");

           }

Command_Drop:
            T_Drop T_Table T_Name T_Semicolon
            {
               printf("\nmydbms>>Drop Command:Parsed\n");
            } 
Attr_List:
          T_Name Var_Type Size Null_Constraint
          |T_Name Var_Type Size Null_Constraint T_Comma Attr_List
          ;


Size:
     T_OpBrace V_Int T_ClBrace
     |
     ;

Null_Constraint:
                T_NOTNULL
                |
                ;

Var_Type:
         D_Int
         |D_Char
         |D_Boolean
         |D_Varchar
         |D_Double
         |D_String
         |D_Date
         ;


Constraints:
            Constraints T_Comma T_Constraint T_Name C_PK Column_List
            |Constraints T_Comma T_Constraint T_Name C_UQ Column_List
            |Constraints T_Comma T_Constraint T_Name C_FK Column_List C_RF T_Name Column_List
            |
            |T_Constraint T_Name C_PK Column_List
 	    |T_Constraint T_Name C_UQ Column_List
            |T_Constraint T_Name C_FK Column_List C_RF T_Name Column_List
            ;


Value_List:
	   Value_List T_Comma T_Name T_Equal V_String
           |Value_List T_Comma T_Name T_Equal V_Int
	   |Value_List T_Comma T_Name T_Equal V_Date
           |Value_List T_Comma T_Name T_Equal V_Double
           |Value_List T_Comma T_Name T_Equal V_Bool
	   |Value_List T_Comma T_Name T_Equal T_NULL
	   |T_Name T_Equal V_String
	   |T_Name T_Equal V_Int
 	   |T_Name T_Equal V_Date
           |T_Name T_Equal V_Double
           |T_Name T_Equal V_Bool
	   |T_Name T_Equal T_NULL
           ;



Atribute_List:
     T_Asterisk
     |Column_Name
     ;

Condition_Expr:
               
	       |T_Where Relationship Predicate
               ;

Relationship:
             T_Name Relation V_Date
             |T_Name Relation V_Int
             |T_Name Relation V_String
             |T_Name Relation V_Bool
             |T_Name Relation V_Double
             |T_Name T_IS T_NULL
             |T_Name T_IS T_NOTNULL
	     ;

Relation:
         T_GT
         |T_LT
         |T_GTE
         |T_LTE
         |T_NE
         |T_Equal
         ;

Predicate:
         T_And Relationship
         |
         |T_Or Relationship
         ;

Column_List:
           T_OpBrace Column_Name T_ClBrace
           |
           ;

Column_Name:
            Column_Name T_Comma T_Name
            |T_Name
            ;
Comma_Expr:
           Comma_Expr T_Comma V_String
           |Comma_Expr T_Comma V_Int
           |Comma_Expr T_Comma V_Date
           |Comma_Expr T_Comma V_Bool
           |Comma_Expr T_Comma V_Double
           |V_String
           |V_Int
           |V_Date
           |V_Bool
           |V_Double
           ;

