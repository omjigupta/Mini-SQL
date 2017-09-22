Letter [A-Za-z]
Digit  [0-9]

%{
 #include "y.tab.h"
%}

%%
[Cc][Rr][Ee][Aa][Tt][Ee]         return T_Create;

[Uu][Ss][Ee]			 return T_Use;

[Dd][Ee][Ll][Ee][Tt][Ee]         return T_Delete;

[Ff][Rr][Oo][Mm]                 return T_From;

[Tt][Aa][Bb][Ll][Ee]             return T_Table;

[Dd][Aa][Tt][Aa][Bb][Aa][Ss][Ee] return T_Database;

[*] return T_Asterisk;

[Ss][Ee][Ll][Ee][Cc][Tt] return T_Select;

[Ii][Nn][Ss][Ee][Rr][Tt] return T_Insert;

[Vv][Aa][Ll][Uu][Ee][Ss] return T_Values;

[Ww][Hh][Ee][Rr][Ee]     return T_Where;

[Dd][Rr][Oo][Pp] return T_Drop;

[Uu][Pp][Dd][Aa][Tt][Ee] return T_Update;

[Ss][Ee][Tt] return T_Set;

[']({Letter}|{Digit})({Letter}|{Digit})*[']  return V_String;



[Ii][Nn][Tt][Oo]             return T_Into;

[Ii][Nn][Tt]		     return D_Int;

[Cc][Hh][Aa][Rr]	     return D_Char;

[Vv][Aa][Rr][Cc][Hh][Aa][Rr]  return D_Varchar;

[Dd][Oo][Uu][Bb][Ll][Ee]      return D_Double;

[Bb][Oo][Oo][Ll][Ee][Aa][Nn]  return D_Boolean;

[Ss][Tt][Rr][Ii][Nn][Gg]      return D_String;

[Dd][Aa][Tt][Ee]	      return D_Date;

({Digit})({Digit})*           return V_Int;


\(			       return T_OpBrace;

\)			       return T_ClBrace;

\,			       return T_Comma;

\;			       return T_Semicolon;

\'			       return T_Quote;

\=			       return T_Equal;

\>			       return T_GT;

\<			       return T_LT;

\>=				return T_GTE;

\<=				return T_LTE;

\<>				return T_NE;

[Ii][Ss]                        return T_IS;

[Cc][Oo][Nn][Ss][Tt][Rr][Aa][Ii][Nn][Tt]   return T_Constraint;	

[Pp][Rr][Ii][Mm][Aa][Rr][Yy][ ][Kk][Ee][Yy] return C_PK;

[Ff][Oo][Rr][Ee][Ii][Gg][Nn][ ][Kk][Ee][Yy] return C_FK;

[Rr][Ee][Ff][Ee][Rr][Ee][Nn][Cc][Ee][Ss]    return C_RF;

[Nn][Oo][Tt][ ][Nn][Uu][Ll][Ll]	 return T_NOTNULL;

[Nn][Uu][Ll][Ll] 		return T_NULL;

[Uu][Nn][Ii][Qq][Uu][Ee]	return C_UQ;

[Aa][Nn][Dd]			return T_And;

[Oo][Rr]			return T_Or;

[Nn][Oo][Tt]			return T_Not;

[\t]+				;

[\n\t]+                         ;

[ ]+                            ;

{Letter}({Letter}|{Digit})*     return T_Name;

[']{Digit}+[-]{Digit}({Digit})*[-][1-9]{Digit}{Digit}{Digit}[']     return V_Date;

{Digit}*[.]{Digit}+            return V_Double;
%%

int yywrap(void)
{
 return 1;
}




