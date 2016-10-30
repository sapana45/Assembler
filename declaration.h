#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
int op_no;
char op_name[6];
char bin[14];
struct node *next;
}opcode;

struct table1
{
char def_name[5];
int size;                                                            //This is for define table content between data section and .bss section
char size_in_words[10];
}define_tab[]={{"db",1,"byte"},{"dd",4,"word"}};


//define_tab obj[2]={{"db",1,"byte"},{"dd",4,"word"}};  // data section content

 struct error_table
{
  int error_code;
  int line_no;
  char error_name[100];
}err_tab[]={
    				{1,0, "Error : Undefined Reference to...."},
    				{2,0, "Error :Invalid opcode....."},                        // initialization of error table
    				{3,0, "Error:Symbol define but not used....."},
    				{4,0, "Error:Redefinition of Symbol......"},
    	                        {5,0, "Instruction Expected..."},
                                {6 ,0, "Duplicate Lable..."}
                      };


//char res_word[6][8]={"section","data","text","lable","global"};    //reseve word

/*err_tab err_obj[]={
    				{1,0, "Error : Undefined Reference to...."},
    				{2,0, "Error :Invalid opcode....."},                        // initialization of error table
    				{3,0, "Error:Symbol define but not used....."},
    				{4,0, "Error:Redefinition of Symbol......"},
    	                        {5,0, "Instruction Expected..."},
                                {6 ,0, "Duplicate Lable..."}
                      };*/

 struct register_32_bit
{
  int reg_no;
  char reg_name[4];
  char bin[4];
}reg_tab_32[]={   { 0 , "eax","001" },            // initialization of register table
   					 { 1 , "ebx","010" },
    					 { 2 , "ecx" ,"011"},
    					 { 3 , "edx" ,"100"},
    					 { 4 , "esp","101" },
    					 { 5 , "ebp","110"},
    					 { 6 , "esi","111"},
    					 //{ 7 , "edi" ,"111"},
                                          
   				};

/*reg_tab_32 register_32[]=  { 
    				         { 0 , "eax" },            // initialization of register table
   					 { 1 , "ebx" },
    					 { 2 , "ecx" },
    					 { 3 , "edx" },
    					 { 4 , "esp" },
    					 { 5 , "ebp"},
    					 { 6 , "esi"},
    					 { 7 , "edi" },
   				};

*/
struct register_16_bit
{
  int reg_no;
  char reg_name[4];
}reg_tab_16[]= { 
    				         { 0 , "ax" },            // initialization of register table
   					 { 1 , "bx" },
    					 { 2 , "cx" },
    					 { 3 , "dx" },
    					 { 4 , "sp" },
    					 { 5 , "bp"},
    					 { 6 , "si"},
    					 { 7 , "di" },
   				};

/*reg_tab_16 register_16[]=  { 
    				         { 0 , "ax" },            // initialization of register table
   					 { 1 , "bx" },
    					 { 2 , "cx" },
    					 { 3 , "dx" },
    					 { 4 , "sp" },
    					 { 5 , "bp"},
    					 { 6 , "si"},
    					 { 7 , "di" },
   				};*/

typedef struct symbol_tab
{
int index;
char sym_name[10];
char def_used;                          //state of symbol means whether used or defined
int size;                                    // size means whether symbol byte or double
int value;                                // size means value of symbol
int addr;     
struct symbol_tab *next;                             // addrress of symbol
}symb_tab;


typedef struct table_of_inc_instr1
{
int line_no;
char name[10];
}table_of_inc_instr;

struct mode
{
int no;
char name[3];
char mode[3];
}i_mode[]={{0,"rr","00"},{1,"rm","01"},{2,"mr","10"},{3,"ir","11"}};




