#include<stdio.h>
#include<stdlib.h>
#include "declaration.h"

void initialize_value();
void create_symbol_table_list(symb_tab **start,int i,char * name,char def_used,int size,int value,int addr);
void display(symb_tab *start);
int  check_for_opcode(opcode *start,char *str);
void update(symb_tab *strat,char *str);
int check_for_register(char *str);
int check_in_symbol_table(symb_tab *start,char *);
void generate_error(int a,char *,int i);
void create_opcode_list(opcode **start,int num,char * name,char *name1);
void display1(opcode *start);
void insert_into_table_of_IIT(int lno,char *name);
char *ret_bin_opcode(opcode *start,char *name);
char *ret_mod_bin(int n);
char *ret_reg_bin(char *b);
int check_in_symbol_table_symbol(symb_tab *start,char *str);

int *fun(int arr[],int num,int n);

symb_tab *start;
opcode  *start1,*op1;
FILE *fp4,*fp3,*fp8;
table_of_inc_instr table;
int i=0,symbol_Count=0;
int main()
{      int lable_Flag=0, ret_flag=0;
	int arr[8],flag=0,res_stor=0,res1=0,res2=0,k=0,j=0,j1=0,sym1=0,n=8,flag4=0,flag5=0;
      
	FILE *fp,*fp1,*fp2,*fp3,*fp5,*fp6;
	int L_C=1,def_used=0,size=0,flag1=0,mem_to_reg_flag=0,reg_to_mem_flag=0;
	char str[50],buff[30][6],s[6],buff1[30][14];
	char t1[10],t2[10],t3[10],t4[15],t5[10],instruction[33]="\0",*new_t1;
       char *str1,*tok[4],saveptr[20],cmd[20];
        char d_bit[2],s_bit[2],imidiate_bit[2];
	 char *myvar;
      t5[0]='#';
      fp8=fopen("T_I_I1.txt","w");
      fp3=fopen("error1.txt","w");
     //printf("t5.............%s=",t5);
	
	myvar=(char *)&saveptr;
       
        for(i=0;i<4;i++)
              {
                // printf("\n%d\t%s\t%s",i_mode[i].no,i_mode[i].name,i_mode[i].mode);               
             }
        fp4=fopen("opcode_input.txt","r");
       if(fp4==NULL)
        {
	printf("opcode File Not Found \n");
         }
          else
          {
             fscanf(fp4,"%s%s",buff[j++],buff1[j1++]);
             while(fscanf(fp4,"%s%s",buff[j++],buff1[j1++])!=EOF);
               fclose(fp4);
                  for(k=0;k<j;k++)
                  { 
            	 create_opcode_list(&start1,k+1,buff[k],buff1[k]);
         	}
           
          display1(start1);
//printf("\n");        
   }
	
	fp2=fopen("in.c","r");
        if(fp2==NULL)
	printf("input File Not Found \n");
        
           
            
            fgets(str,20,fp2);
         while(!(strcmp(t1,"main:")==0))
	{
              L_C++;
		fgets(str,20,fp2);
		sscanf(str,"%s%s%s%s",t1,t2,t3,t4);
	        
                     
                if((strcmp("dd",t2)==0)||(strcmp("db",t2)==0))
	             {
	                flag=1;
          		def_used='D';
          		if(strcmp(t2,"dd")==0)
	           	size=4;
	          	if(strcmp(t2,"db")==0)
	           	size=1;
	      
	         symbol_Count++;
	               	create_symbol_table_list(&start,symbol_Count,t1,def_used,size,atoi(t3),L_C);
	                 
	           }
               
	           else  if((strcmp("resd",t2)==0)||(strcmp("resb",t2)==0))
	             {                                                                                       // what is size when resd and what is when resb
	      			flag=2;
	                 	def_used='U';
	          		size=0;
	         
	         	symbol_Count++;
	               		create_symbol_table_list(&start,symbol_Count,t1,def_used,atoi(t3),size,L_C);
	                 
	              }
	             if(strcmp("main:",t1)==0)
	             {
	          		def_used='D';
	              		size=0;
	        
	         		symbol_Count++;
	                       create_symbol_table_list(&start,symbol_Count,t2,def_used,size,size,L_C);
                         
	             }
                                
               
	
	        }
char  ch;
	fgets(str,20,fp2);     
//printf("\n");
	fp6=fopen("a.txt","w");
       fp6=fopen("a.txt","a"); 
    
	while(!feof(fp2))
        {
                                                             
                                                        L_C++;
					                     if((ch=fgetc(fp2))==EOF)
                                                             return;
                                           		   
							   	fgets(str,20,fp2);                                                       
							  	 sscanf(str,"%s%s%s",t1,t2,t5);
								   // printf("t1=%s\tt2=%s\t%s\n",t1,t2,t5);
                                                                        if((t1!=NULL)&&(t2!=NULL)&&(t5[0]!='#'))
                                                                        {
                								//printf("Lable Occure.....\n");
                  							lable_Flag=1;
                      								new_t1=(char *)malloc((strlen(t1)-1));	
                                                                         strncpy(new_t1,t1,(strlen(t1)-1));
                                                                        
           								//printf("...................%s\n",new_t1);
                                                                             def_used='D';
	       							       		size=0;
	        
	         							symbol_Count++;
                                                                       create_symbol_table_list(&start,symbol_Count,new_t1,def_used,size,1,L_C);
												display(start);
                                                                   strcat(instruction,"00000000000000000000000000000000");
								 
								printf("\n");
						   	   	  fprintf(fp6,"%d\t%s\n",L_C,instruction);instruction[0]='\0';		
                                                                          goto lable1;
                                                                         }

										
    								//printf("\n\n");
										  	 for (i = 0,str1=t2;;i++, str1= NULL)
							   		{
											tok[i]=NULL;
						      					tok[i] = strtok_r(str1, ",", &myvar);
							      				if (tok[i] == NULL)
								  				break;
								  			
							     		}
								   if(tok[1]==NULL){
									      flag5=1;}
							    //   puts("\n");
							   		res1=check_for_opcode(start1,t1);
							   		if(res1==1)
							   		{       
											if(t2!=NULL)
										  {
							   		         	if(check_for_register(tok[0])&&check_for_register(tok[1])==1)
										  		flag1=1;
										  	if(check_for_register(tok[0])&&check_in_symbol_table(start,tok[1])==1)
										 		 mem_to_reg_flag=1;
											if(check_in_symbol_table(start,tok[0])&&check_for_register(tok[1])==1)
										  		reg_to_mem_flag=1;
										 		
										   }
										   if(tok[1]==NULL)
										    {
											  flag4=1;
										     
										     }
									res2=0;        
										 
							  
								    if(tok[1]!=NULL&&tok[0]!=NULL)
									{
									  res2=check_for_register(tok[0]);
									 if(res2==0)                                     
										   {                                                    
												                                              
										     res2=check_in_symbol_table(start,tok[0]);
										      if(res2==0)
											{
											     generate_error(1,tok[0],L_C);         
											   insert_into_table_of_IIT(L_C,tok[0]);
											}
										   }
									     }
							    res2=0;                
							      if(tok[1]!=NULL&&tok[0]!=NULL){
									  
										res2=check_for_register(tok[1]);
										if(res2==0)     
										   {
										     res2=check_in_symbol_table(start,tok[1]);
										      if(res2==0)
											{
											    generate_error(1,tok[1],L_C) ;         
											    insert_into_table_of_IIT(L_C,tok[1]);
											}
										   }
									 }
						    res2=0;
						 if(tok[1]==NULL&&tok[0]!=NULL){
									  
										res2=check_for_register(tok[0]);
										if(res2==0)     
										   {
										     res2=check_in_symbol_table(start,tok[0]);
										      if(res2==0)
											{
											    generate_error(1,tok[0],L_C) ;         
											    insert_into_table_of_IIT(L_C,tok[0]);
											}
										   }
									 }
                                                          if(tok[1]==NULL&&tok[0]==NULL){
                                                        ret_flag=1;}
						}
							      if(res1==0)  
							      generate_error(2,t1,L_C);            
						       
							      if(flag1==1)
							      {
								strcat(instruction,"0");
								strcat(instruction,ret_bin_opcode(start1,t1));
								strcat(instruction,"1");
								strcat(instruction,"1");
								 strcat(instruction,ret_mod_bin(0));
								strcat(instruction,ret_reg_bin(tok[0]));
								strcat(instruction,ret_reg_bin(tok[1]));
								strcat(instruction,"00000000");
								
								fprintf(fp6,"%d\t%s\n",L_C,instruction);
							      }
                                                             flag1=0;
							     instruction[0]='\0';
								    if(mem_to_reg_flag==1)
							      {
								strcat(instruction,"0");
								strcat(instruction,ret_bin_opcode(start1,t1));
								strcat(instruction,"1");
								strcat(instruction,"1");
								 strcat(instruction,ret_mod_bin(2));
								strcat(instruction,ret_reg_bin(tok[0]));
								strcat(instruction,"101");        
								fprintf(fp6,"%d\t%s",L_C,instruction);
							       sym1=check_in_symbol_table_symbol(start,tok[1]);
								           
								fun(arr,sym1,n);
								for(i=0;i<n;i++)
								 fprintf(fp6,"%d",arr[i]);
							       fprintf(fp6,"\n");
							      }
						instruction[0]='\0';
							mem_to_reg_flag=0;
						       if(reg_to_mem_flag==1)
							      {
								strcat(instruction,"0");
								strcat(instruction,ret_bin_opcode(start1,t1));
								strcat(instruction,"0");  //dest is not reg
								strcat(instruction,"1");
								 strcat(instruction,ret_mod_bin(1));
								strcat(instruction,"000");          
								strcat(instruction,ret_reg_bin(tok[1]));
								
								fprintf(fp6,"%d\t%s",L_C,instruction);
							       sym1=check_in_symbol_table_symbol(start,tok[0]);
								        
								fun(arr,sym1,n);
								for(i=0;i<n;i++)
								 fprintf(fp6,"%d",arr[i]);
								fprintf(fp6,"\n");
							      }
						instruction[0]='\0';
						reg_to_mem_flag=0;
 						if( ret_flag==1){
								strcat(instruction,"0");
								strcat(instruction,ret_bin_opcode(start1,t1));	
                                                                  strcat(instruction,"0000000000000000000");
								printf("\n");
						   	   	  fprintf(fp6,"%d\t%s\n",L_C,instruction);								
							}
                                                           instruction[0]='\0';
							ret_flag=0;
							if(flag4==1)
							{
								strcat(instruction,"0");
								strcat(instruction,ret_bin_opcode(start1,t1));
								 strcat(instruction,"0");  //dest is not reg
								strcat(instruction,"000");
								strcat(instruction,"000"); 
								strcat(instruction,"000"); 
								
								printf("\n");
								fprintf(fp6,"%d\t%s",L_C,instruction);
								sym1=check_in_symbol_table_symbol(start,tok[0]);
								          
								fun(arr,sym1,n);
								for(i=0;i<n;i++)
									fprintf(fp6,"%d",arr[i]);
								fprintf(fp6,"\n"); 
						
							}
						instruction[0]='\0';
							if(flag5==1)
							{
				
								  printf("%c",0);
								  strcat(instruction,ret_bin_opcode(start1,t1));
								  strcat(instruction,"0000000000000000000");
								 
								printf("\n");
						   	   	  fprintf(fp6,"%d\t%s\n",L_C,instruction);
						} 
						instruction[0]='\0';
						  flag1=0;
						flag5=0;
						reg_to_mem_flag=0;
						mem_to_reg_flag=0;
						 
						//printf("location =%d\n",L_C);
										flag4=0;
										
										if(tok[0]==NULL&&tok[1]==NULL)
									return;       
                                                                 
                                                                
tok[0]='\0';
tok[1]='\0';  
//L_C++;      
   						}
	fclose(fp6);
lable1:;     
}      
    
int *fun(int arr[],int num,int n)
{
int m=0;
m=n;
int i=0,j=0,k=0,j1=0;

  while(num!=0)
    {
      j=(num%2);
     
      arr[--n]=j;
      num=num/2;
      j1++;
    }
k=m-j1;  
while(k!=0)
{
arr[--k]=0;
}


}
char *ret_bin_opcode(opcode *start,char *name)
{
   opcode *tmp1,*tmp2,*tmp3;
  for(tmp1=start;tmp1!=NULL;tmp1=tmp1->next)
  {
    if(strcmp(tmp1->op_name,name)==0)
    {
 
      return tmp1->bin;
     }
   }   

}

char *ret_reg_bin(char *str)
{
        for(i=0;i<7;i++)
	{
	 if(strcmp(reg_tab_32[i].reg_name,str)==0)
                return (reg_tab_32[i].bin);
        }
}

char *ret_mod_bin(int no)
{
for(i=0;i<4;i++)
	{
	 if(i_mode[i].no==no)
                return (i_mode[i].mode);
        }
}

void insert_into_table_of_IIT(int lno,char *name)
{
table.line_no=lno;
strcpy(table.name,name);
fp8=fopen("T_I_I1.txt","a");
if(fp8==NULL)
printf("Unable to open T_I_I\n");
fprintf(fp8,"%d\t%s\n",table.line_no,table.name);
fclose(fp8);
return;
}

int check_for_register(char *str)
{       
      int i;
       	for(i=0;i<7;i++)
	{
	 if(strcmp(reg_tab_32[i].reg_name,str)==0)
         return 1;
         if(strcmp(reg_tab_16[i].reg_name,str)==0)
         return 2;
	}

   return 0;
}

void generate_error(int a,char *str,int k)
{
        int i;
      fp3=fopen("error1.txt","a");
                 if(fp3==NULL)
                {
                  printf("Unable To Open File\n");
                   return;
                }
	for(i=0;i<7;i++)
	{

          if(err_tab[i].error_code==a)
          {
                
               fprintf(fp3,"%d\t%s\t%s\n",k,err_tab[i].error_name,str);
                fclose(fp3);
                return;
           }

         }
       

}
void update(symb_tab *start,char *str)
{
  symb_tab *tmp1,*tmp2,*tmp3;
  for(tmp1=start;tmp1!=NULL;tmp1=tmp1->next)
  {
 tmp1->def_used='U';
 return; 
}

}
int check_for_opcode(opcode *start,char *str)
{
  opcode *tmp1,*tmp2,*tmp3;
  for(tmp1=start;tmp1!=NULL;tmp1=tmp1->next)
  {
    if(strcmp(tmp1->op_name,str)==0)
    {
      return 1;
     }
    //printf("%s\t",tmp1->op_name);
   }   
 return 0;
}

int check_in_symbol_table(symb_tab *start,char *str)
{
  symb_tab *tmp1,*tmp2,*tmp3;
  for(tmp1=start;tmp1!=NULL;tmp1=tmp1->next)
  {
    if(strcmp(tmp1->sym_name,str)==0)
    {
      return 1;
     }
   }   
 return 0;
}

int check_in_symbol_table_symbol(symb_tab *start,char *str)
{
  symb_tab *tmp1,*tmp2,*tmp3;
  for(tmp1=start;tmp1!=NULL;tmp1=tmp1->next)
  {
    if(strcmp(tmp1->sym_name,str)==0)
    {
      return tmp1->value;
     }
   }   
 return 0;
}
void create_symbol_table_list(symb_tab **start,int i,char * name,char def_used,int size,int value,int addr)
{
symb_tab *tmp1,*tmp2,*tmp3;

	if(*start==NULL)
	{
		
		tmp1=(symb_tab *)malloc(sizeof(symb_tab));
		tmp1->index=i;
		strcpy(tmp1->sym_name,name);
                tmp1->def_used=def_used;
                tmp1->size=size;
                tmp1->value=value;
                tmp1->addr=addr;
                tmp1->next=NULL;
                *start=tmp1;
                
             
	}
        else
       {	
            tmp2=*start;
            while(tmp2->next!=NULL)
             {
            tmp2=tmp2->next;
              }  
             tmp3=(symb_tab *)malloc(sizeof(symb_tab));
	        
                 tmp3->index=i;
		strcpy(tmp3->sym_name,name);
                tmp3->def_used=def_used;
                tmp3->size=size;
                tmp3->value=value;
                tmp3->addr=addr;
                tmp3->next=NULL;
             tmp2->next=tmp3;
	}
}

void display(symb_tab *start)
{
	symb_tab *tmp1;
	tmp1=start;
        printf("index\tsym_name D/U\tsize\tvalue\taddr\n");
	while(tmp1!=NULL)
	{	
		printf(" | %d \t| %s \t| %c \t| %d \t| %d \t| %d \t|",tmp1->index,tmp1->sym_name,tmp1->def_used,tmp1->size,
		tmp1->value,tmp1->addr);	
		tmp1=tmp1->next;	
         printf("\n");
	}
}

void create_opcode_list(opcode **start,int num,char name[],char name1[])
{
opcode *tmp1,*tmp2,*tmp3;

	if(*start==NULL)
	{
		//tmp1=*start;
		tmp1=(opcode *)malloc(sizeof(opcode));
		tmp1->op_no=num;
		strcpy(tmp1->op_name,name);
                strcpy(tmp1->bin,name1);
                tmp1->next=NULL;
                *start=tmp1;
                
                return;      
	}
        else
       {	
            tmp2=*start;
            while(tmp2->next!=NULL)
             {
            tmp2=tmp2->next;
              }  
             tmp3=(opcode *)malloc(sizeof(opcode));
	     tmp3->op_no=num;
	     strcpy(tmp3->op_name,name);
             strcpy(tmp3->bin,name1);
             tmp3->next=NULL;
             tmp2->next=tmp3;
	}

  return;
}

void display1(opcode *start)
{
opcode *tmp1;
tmp1=start;
	while(tmp1!=NULL)
	{	
		//printf("\n%d<=>%s<=>%s",tmp1->op_no,tmp1->op_name,tmp1->bin);	
		tmp1=tmp1->next;	

	}
}

	
										
