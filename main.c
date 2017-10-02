#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


extern int  yyparse();
extern FILE *yyin;


char query[300],attr[300],type[300],values[300],word_ctr=0;

void input();     //For taking the SQL query as input
void parse_query();    //For parsing the SQL query entered
void create_table();   //For handling the implementation of create query
void check_if_table_already_exists(char str[]);        //For checking whether the table already exists or not(Create query)
void check_primary_constraint(FILE* ptr);        //For checking whether more than one constraint is defined as primary key constraint
void attribute_entry(char tname[]);   //For entering attributes and their data types in tname_attr.txt and tname_type.txt
void initialize();                    //For initializing the character arrays with '\0'
void constraints();
void create_relation_file(char tname[]);      //For creating the relation file
void insert_values();                         //For handling the implementation of insert query
void check_relation_valid(char tname[]);      //For checking whether the relation exists before inserting values in the relation (Insert query)
void check_attribute_count(char tname[],int word_ctr);//For checking whether the number of attributes in insert and create query are same or not
void check_attr(char tname[]);                //For extracting attribute value and corresponding data type for checking
void check_value(char str[],char data_type[]);        //For matching attribute-data type pairs in insert query
void save_values();                //For saving the values after checking all flags in insert query
void delete_query();             //For handling the implementation of delete query
void delete_all();          //For deleting all tuples of relation
void select_query();             //For handling the implementation of select query
int extract_tname(char tname[]); // For extracting table name in select*  query
void select_all();                //For select * query
void select_some(int c_no,char op[],char val[],char tname[]);      //For selecting entire records based on some condition
void print(char line[]);           //For printing a record if it satisfies a condition
void temp_copy(char line[],char buf[]);    //For copying a record in buf

void drop_table();                 //For dropping a relation
int main()
{
    initialize();
    input();
    parse_query();
    return 0;
}

void change_case(char query[])
{
    int i;
    for(i=0; query[i]!='\0'; i++)
        if(isalpha(query[i]))
            query[i]=tolower(query[i]);
    return;

}
void input()
{
//    int i=0;
    // char* fname;
    FILE* fptr;
    printf("\nmydbms>>Enter the query \n");
    fgets(query,300,stdin);
    change_case(query);
    fptr=fopen("input.txt","w");      //Reading the query from stdin and saving it in file input.txt

    if(!fptr)
    {
        printf("\nCouldn't open the file for writing.");
        exit(0);
    }
    fprintf(fptr,"%s",query);
    fclose(fptr);

    return;
}

void parse_query()
{
    char str1[10];
    FILE* fptr;
    fptr=fopen("input.txt","r");
    yyin=fptr;
    if(!yyin)
    {
        printf("\nmydbms>>ERROR :couldn't open file(input.txt) for reading\n");
        exit(1);
    }

    if(yyparse()==0)                                     // parsing successful
    {
        fptr=fopen("input.txt","r");
        fscanf(fptr,"%s",str1);

        if(strcasecmp(str1,"CREATE")==0)
        {
            create_table();
        }

        else if(strcasecmp(str1,"INSERT")==0)
        {
            insert_values();
        }
        else if(strcasecmp(str1,"DELETE")==0)
        {
            delete_all();
        }
        else if(strcasecmp(str1,"SELECT")==0)
        {
            select_query();
        }
        else if(strcasecmp(str1,"DROP")==0)
        {
            drop_table();
        }
        //    fclose(fptr);
    }

    else
    {
        printf("\nERROR :Parsing error\n");
        exit(2);
    }

    fclose(yyin);
    fclose(fptr);
    return;
}
void create_table()
{

    int i=0,j=13,k=0,l=0;
    char ch,tname[30];
    ch=query[j];

    for(l=0; l<30; l++)
        tname[l]='\0';

    while(ch!='(')
    {
        if(ch!=' ')
        {

            tname[i]=ch;        //tname contains the name of the table
            i++;
            j++;
            ch=query[j];
        }
        else j++;
    }
    check_if_table_already_exists(tname);
    i=0;
    j++;                        //j is at opening brace

    i=0;

    while(query[j]!=';')           //No space is entered after '('
    {
        if(query[j]=='c')
            if(query[j+1]=='o')
                if(query[j+2]=='n')
                    if(query[j+3]=='s')
                        if(query[j+4]=='t')
                            if(query[j+5]=='r')
                                if(query[j+6]=='a')
                                    if(query[j+7]=='i')
                                        if(query[j+8]=='n')
                                            if(query[j+9]=='t')
                                            {
                                                printf("constraint aa gya!\n");
                                                constraints();
                                                break;
                                            }

        while(query[j]!=' ')
        {
            if(query[j]!=',')
            {
                attr[i]=query[j];
                i++;
                j++;
            }
            else
                j++;
        }
        attr[i]=' ';
        i++;

        while(query[j]!=',')
        {
            if(query[j]==';')
                break;
            if(query[j]!=' ')
            {
                type[k]=query[j];
                k++;
                j++;
            }
            else
                j++;
        }
        type[k]=' ';
        k++;

    }
    //attr[strlen(attr)-1]='\0';

    if(type[k-2]==')')
        type[k-2]='\0';
    type[k-1]='\0';
    attribute_entry(tname);
    create_relation_file(tname);
    return;
}
void constraints()
{
    return;
}

void initialize()
{
    int z;
    for(z=0; z<300; z++)
    {
        query[z]='\0';
        attr[z]='\0';
        type[z]='\0';
        values[z]='\0';
    }
    return;
}
void check_if_table_already_exists(char tname[])
{

    char str[50];
    int k;
    FILE* temp;
    for(k=0; k<50; k++)
        str[k]='\0';
    strcat(str,tname);
    strcat(str,".txt");                      //str now contains the name of the relation file
    temp=fopen(str,"r");
    if(temp!=NULL)
    {
        printf("\nmydbms>>Relation exists.");
        fclose(temp);
        exit(5);
    }

    return;
}

void check_primary_constraint(FILE* ptr)
{

    return;
}

void attribute_entry(char tname[])
{
    int k=0;
    FILE* attr_ptr;
    FILE* type_ptr;
    char str1[30],str2[30];
    for(k=0; k<30; k++)
        str1[k]=str2[k]='\0';

    strcat(str1,tname);
    strcat(str1,"_attr.txt");         //Attribute file name is tname_attr.txt

    strcat(str2,tname);
    strcat(str2,"_type.txt");         //Data type file name is tname_type.txt

    attr_ptr=fopen(str1,"w");
    type_ptr=fopen(str2,"w");

    if(!attr_ptr || !type_ptr)
    {
        printf("\nmydbms>>Error opening attribute file or data type file.");
        exit(6);
    }
    fprintf(attr_ptr,"%s",attr);         //Entering attributes in tname_attr.txt
    fprintf(type_ptr,"%s",type);         //Entering data types in tname_type.txt
    fclose(attr_ptr);
    fclose(type_ptr);


    return;
}

void create_relation_file(char tname[])
{

    char str[50];
    FILE* ptr;
    strcpy(str,tname);
    strcat(str,".txt");
    ptr=fopen(str,"w");
    if(!ptr)
    {
        printf("\nmydbms>>Unable to create the file : %s",str);
        exit(7);
    }
    printf("\nmydbms>>Table created successfully.\n\n");
    fclose(ptr);
    return;
}
void insert_values()
{
    //printf("\nIn insert_values function ");
    char tname[50];
    int i,k=0;
    for(i=0; i<50; i++)
        tname[i]='\0';

    for(i=12; query[i]!=' '; i++)
        tname[i-12]=query[i];


    // printf("\nTname is : %s",tname);
    check_relation_valid(tname);
    while(query[i]!='(')
        i++;

    i++;                      //i is now at the index from where attribute values start


    while(query[i]!=')')
    {
        if(query[i]!=',')
            values[k]=query[i];
        else
        {
            values[k]=' ';
            word_ctr++;
        }
        i++;
        k++;

    }    //End of while
    //values array contains the data to be entered.

    word_ctr++;       //For the last word

    check_attribute_count(tname,word_ctr);


    check_attr(tname);
    // printf("\nValues are to be written to the file now.checking complete.");
    save_values();
    return;
}

void check_relation_valid(char tname[])
{
//	printf("\nIn relation valid ");
    char str[50];
    int k;
    FILE* temp;
    for(k=0; k<50; k++)
        str[k]='\0';

    strcat(str,tname);
    strcat(str,".txt");                    //str now contains the name of the relation file
    temp=fopen(str,"r");
    if(temp==NULL)
    {
        printf("\nmydbms>>Query tried to access a table which doesn't exists..Error");
        exit(11);
    }
    fclose(temp);
    // printf("\nValid relation name");
    return;
}

void check_attribute_count(char tname[],int word_ctr)
{
//	printf("\n In check_attribute_Count array ");
    FILE* fptr;
    int ctr=0,i;
    char str[30];
    for(i=0; i<30; i++)
        str[i]='\0';

    strcat(str,tname);
    strcat(str,"_attr.txt");

    fptr=fopen(str,"r");
    if(!fptr)
    {
        printf("\nmydbms>>Error opening file : %s",str);
        exit(12);
    }



    while(!feof(fptr))
    {
        fscanf(fptr,"%s",str);
        // printf("\nstr : %30s",str);
        ctr++;
    }
    if(word_ctr!=ctr-1)                               //ctr-1 because the last word in the file is read twice
    {
        printf("\nmydbms>>Inconsistency in number of attributes specified...Error");
        exit(13);
    }

    return;
}

void check_attr(char tname[])
{
    FILE* fptr;
    int i=0,j,k;
    char str[30],data_type[200],temp[20];                                // Maximum word length in insert query is 29
    strcat(tname,"_type.txt");
    fptr=fopen(tname,"r");

    for(j=0; j<200; j++)
        data_type[j]='\0';


    if(fptr==NULL)
    {
        printf("\nmydbms>>Error opening the file : %s",tname);
        exit(14);
    }
    fgets(data_type,200,fptr);
    data_type[strlen(data_type)]='\0';
    k=0;
    while(values[i+1]!='\0')
    {
        for(j=0; j<30; j++)
            str[j]='\0';

        j=0;
        while(values[i]!=' ')
        {
            if(values[i]=='\0')
                break;

            str[j]=values[i];
            //    printf("\n Values[%d] : %d \tstr[%d] : %d",i,values[i],j,str[j]);
            j++;
            i++;
        }
        i++;       //For the space character

        //str now contains the attribute value to be checked further
        for(j=0; j<20; j++)
            temp[j]='\0';
        j=0;

        while(data_type[k]!=' ')
        {
            if(data_type[k]=='\0')
                break;

            temp[j]=data_type[k];
            j++;
            k++;
        }
        k++;
        //data_type now contains the corresponding data type saved in the file for the relation


//fscanf(fptr,"%s",data_type);
        check_value(str,temp);
    }

    fclose(fptr);
    return;
}

void save_values()
{
    FILE* fptr;
    char str[40];
    int i;

    for(i=0; i<40; i++)
        str[i]='\0';
    for(i=12; query[i]!=' '; i++)
        str[i-12]=query[i];

    strcat(str,".txt");
//	printf("\n Table name : %s",str);
    fptr=fopen(str,"r");
    if(fptr==NULL)
    {
        printf("\nmydbms>>Error opening the file : %s",str);
        exit(15);
    }
    fclose(fptr);
    fptr=fopen(str,"a+");
    strcat(values," \n");
    fprintf(fptr,"%s",values);
    printf("\nmydbms>>Data inserted successfully.\n");
    fclose(fptr);
    return;

}
void check_value(char str[],char data_type[])
{
    int i=0,flag=0,size=0,k=0;
    char n[3]= {'\0','\0','\0'};
    if(strcmp(data_type,"varchar")>0)
    {

        for(i=0; data_type[i]!='('; i++);

        i++;
        while(data_type[i]!=')')
            n[k++]=data_type[i++];

        size=atoi(n);                    //For converting the number into decimal equivalent
        if(strlen(str)>size)
        {
            flag=1;
        }

    }

    else if(strcmp(data_type,"int")==0)
    {
        for(i=0; str[i]!='\0'; i++)
        {
            if(!isdigit(str[i]))
            {
                flag=1;
                break;
            }

        }
    }
    else if(strcmp(data_type,"boolean")==0)
    {
        //if((strcmp(atoi(str),"1")!=0) || (strcmp(str,"0")!=0))
        if(atoi(str)!=1 && atoi(str)!=0)
        {
            flag=1;
        }

    }
    else if(strcmp(data_type,"double")==0);

    else if(strcmp(data_type,"date")==0)
        ;

    else if(strcmp(data_type,"char")==0)
    {
        if(strlen(str)>1)
        {
            flag=1;
        }
    }

    if(flag==1)
    {
        printf("\nmydbms>>One or more data-type mismatch error..Insert command unsuccessful .\n");
        exit(14);
    }
    return;
}

int extract_tname(char tname[])
{
    int i=0,j=14;
    while(isalnum(query[j]))
    {
        tname[i]=query[j];
        i++;
        j++;
    }
    return j;
}
void drop_table()
{
    int i,j=11,ret;
    char tname[30],attr_typ[30],attr_file[30];
    FILE *fptr1,*fptr2,*fptr3;
    for(i=0; i<30; i++)
    {
        tname[i]='\0';
        attr_typ[i]='\0';
        attr_file[i]='\0';
    }

    i=0;
    while(isalnum(query[j]))
    {
        tname[i]=query[j];
        i++;
        j++;
    }
    strcpy(attr_typ,tname);
    strcpy(attr_file,tname);
    strcat(tname,".txt");
    strcat(attr_typ,"_type.txt");
    strcat(attr_file,"_attr.txt");

    fptr1=fopen(tname,"r");
    fptr2=fopen(attr_typ,"r");
    fptr3=fopen(attr_file,"r");

    if(!fptr1 || !fptr2 || !fptr3)
    {
        printf("\nmydbms>>Relation doesn't exist.");
        exit(15);
    }
    else
    {
        fclose(fptr1);
        fclose(fptr2);
        fclose(fptr3);
        ret=remove(tname);
        ret=ret || remove(attr_typ) || remove(attr_file);

        if(ret==0)
            printf("\nmydbms>>Relation dropped successfully");
        else
            printf("\nmydbms>>Error in dropping the relation");
    }

    return;
}


void delete_query()
{
    char from[4];
    int i=0;
    for(i=0; i<4; i++)
        from[i]='\0';
    for(i=0; i<4; i++)
        from[i]=query[i+7];
    printf("\n From array : %s",from);
    if(strcasecmp(from,"from")==0)
        delete_all();

    return;
}

void delete_all()
{
    int i,j=12;
    char tname[30];
    FILE *fptr;
    for(i=0; i<30; i++)
        tname[i]='\0';
    i=0;

    while(isalnum(query[j]))
    {
        tname[i]=query[j];
        i++;
        j++;
    }
    strcat(tname,".txt");
    fptr=fopen(tname,"w");
    if(!fptr)
    {
        printf("\nmydbms>>Error in emptying up all the tuples of relation");
        exit(15);
    }
    printf("\nmydbms>>Delete query executed successfully");
    fclose(fptr);
    return;
}

void select_query()
{
    char ch;
    ch=query[7];

    if(ch=='*')
        select_all();
    printf("\nmydbms>>Select query executed successfully\n");
    return;
}

void select_all()
{
    FILE *fptr,*fptr1;
    char tname[30],line[128],att_name[30];
    int i,ctr=0;
    for(i=0; i<30; i++)
    {
        tname[i]='\0';
        att_name[i]='\0';
    }
    i=extract_tname(tname);       //i contains the index of the next location after table name
    strcpy(att_name,tname);
    strcat(att_name,"_attr.txt");    //att_name now contains the name of attribute file wrt tname
    strcat(tname,".txt");

    fptr=fopen(tname,"r");
    fptr1=fopen(att_name,"r");

    if(!fptr || !fptr1)
    {
        printf("\nmydbms>>Relation doesn't exist.Exit 16\n");
        exit(16);
    }
    fclose(fptr);
    fclose(fptr1);
    if(query[i]==';' || query[i+1]==';')               //Select all tuples of the relation (without where clause)
    {
        fptr=fopen(tname,"r");
        if(!fptr)
        {
            printf("\nmydbms>>Unable to open the relation file.Exit 17\n");
            exit(17);
        }
        while(fgets(line,sizeof line,fptr)!=NULL)
            fputs(line,stdout);
        fclose(fptr);
    }

    else                                            //Select entire records which satisfy a condition
    {

        fptr1=fopen(att_name,"r");
        if(!fptr1)
        {
            printf("\nmydbms>>Unable to open the attribute file of relation.Exit 18\n");
            exit(18);
        }
        fgets(line,sizeof line,fptr1);                   //line contains the name of the attributes of the relation
        fclose(fptr1);
        //printf("\nline is : %s",line);
        //i is at the index just before 'where' keyword is used in t
        i=i+7;        //i is at the index where attribute name for comparison starts
        char a_name[30],val[30];
        int j,match=0;
        const char* delim=" ";
        char op[3],*token;        //contains the operator
        for(j=0; j<30; j++)
        {
            a_name[j]='\0';
            val[j]='\0';
        }
        for(j=0; j<3; j++)
            op[j]='\0';
        j=0;
        while(isalnum(query[i]))
            a_name[j++]=query[i++];


        j=0;
        while(query[i]=='<' || query[i]=='>' || query[i]=='=')
            op[j++]=query[i++];


        j=0;
        while(query[i]!=';' && query[i]!='\0')
        {
            while(query[i]==' ')
                i++;

            if(query[i]!=';')
                val[j]=query[i];
            j++;
            i++;
        }


        token=strtok(line,delim);

        while(token!=NULL)
        {
            if(strcmp(a_name,token)==0)
            {
                ctr++;
                match=1;
                break;
            }
            ctr++;
            token=strtok(NULL,delim);
        }

        if(!match)
        {
            printf("\nmydbms>>Attribute name specified in select query is wrong.Exit 19\n");
            exit(19);
        }
        select_some(ctr,op,val,tname);
    }    //end of else

    return;
}
void select_some(int c_no,char op[],char val[],char tname[])
{
    // printf("\nIn select some function with : %d %s %s %s",c_no,op,val,tname);
    int i=0,j,k;
    char line[128],token[30],buffer[128];
    FILE* fptr;
    const char* delim=" ";
    fptr=fopen(tname,"r");
    if(!fptr)
    {
        printf("\nmydbms>>Unable to open relation file\n");
        exit(20);
    }
    for(j=0; j<128; j++)
        line[j]='\0';

    while(fgets(line,sizeof line,fptr)!=NULL)
    {
        j=0;
        temp_copy(line,buffer);
        for(i=0; i<c_no; i++)
        {
            for(k=0; k<30; k++)
                token[k]='\0';
            k=0;
            while(line[j]!=' ')
            {
                if(line[j]=='\0')
                    break;
                token[k++]=line[j++];
            }
            j++;
            //token=strtok(line,delim);

        }
        //  printf("\ntoken :%s",token);
        if(strcmp(op,">")==0)
        {
            if(strcmp(token,val)>0)
                print(buffer);                      //function to print a line
        }
        else if(strcmp(op,"<")==0)
        {
            if(strcmp(token,val)<0)
                print(buffer);                      //function to print a line
        }
        else if(strcmp(op,"=")==0)
        {
            if(strcmp(token,val)==0)
                print(buffer);                      //function to print a line
        }
        else if(strcmp(op,">=")==0)
        {
            if(strcmp(token,val)>=0)
                print(buffer);                      //function to print a line
        }
        else if(strcmp(op,"<=")==0)
        {
            if(strcmp(token,val)<=0)
                print(buffer);                      //function to print a line
        }

        else if(strcmp(op,"<>")==0)
        {
            if((strcmp(token,val)>0) || (strcmp(token,val)<0))
                print(buffer);                      //function to print a line
        }
    }
    fclose(fptr);
    return;
}
void temp_copy(char line[],char buf[])
{
    int i;
    for(i=0; i<sizeof(buf); i++)
        buf[i]='\0';

    strcpy(buf,line);
    return;
}
void print(char line[])
{
    int i=0;
    for(i=0; i<strlen(line); i++)
        printf("%c",line[i]);
    return;
}


