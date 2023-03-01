#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "database.h"
#include "inout.h"

void get_string (char *prompt, int min,int max,char *my_string){
  int i;
  int ok =0;
  int x;
  char line [256];
  char extra [256];
  char cad[256];
  do{
    ok=0;
    printf("%s ",prompt);
    printf("(%d-%d char):", min, max);
    fgets(line,sizeof(line),stdin);//reads a line from the keyboard
    x=sscanf(line,"%s%s",cad,extra); // si x es 1 es pq le asigna valores a cad y no a extra
    if (x==1){
    i=strlen(cad);
    if(i>=min && i<=max){
      ok=1;
    }//second if
    }//first if
  }while(ok==0);
    strcpy(my_string,cad);
    
}

int get_integer(char *prompt, int min, int max){
  char line[256];
  char extra [256];
  int ok=0;
  int x;
  int num;
  do{
    ok=0;
    fprintf(stdout,"%s", prompt);
    printf(" [%d-%d]:",min,max);
    fgets(line,sizeof(line),stdin); // el stdin es que lo lees del teclado.
    x= sscanf(line,"%d%s",&num,extra);
    if (x==1){
      if(num>=min && num<=max){
	ok=1;
      }
    }
  }while(ok==0);
    return num;
}

char get_character(char *prompt, char *check){

  int ok=0;
  char line[256];
  int x;
   char extra [256];
    char cad;
    char k;
    do{
      ok=0;
      do{
      printf("%s ",prompt);
      printf("(%s):",check);
    fgets(line,sizeof(line),stdin);
    x=sscanf(line,"%c%s",&cad,extra); // si x es 1 es pq le asigna valores a cad y no a extra
    if (x==1){
 
      ok=1;
    }
    
      }while(ok==0);//second do
   
    
    cad=toupper(cad);
    
    }while(strchr(check,cad)==NULL);//first do, repeats while the given char does not match with any of the check prompt
    k=*strchr(check,cad);//returns the adress of the letter that matches	   	   
  return k;
}	   	   
int yes_or_no(char *prompt) {
 int ok=0;
  char line[256];
  int x;
   char extra [256];
  
  char decision;
  do {
    ok=0;
    do{
    printf("%s",prompt);
 
    fgets(line,sizeof(line),stdin);
    x=sscanf(line,"%c%s",&decision,extra); // si x es 1 es pq le asigna valores a cad y no a extra
    if (x==1){
 
      ok=1;
    }
    
    }while(ok==0);
   
    
    
}while ((toupper(decision)!='Y')&&(toupper(decision)!='N'));

  if (toupper(decision)=='Y')
    return 1;
  else
    return 0;
}

 void display_patient(struct aPatient info){// necesito saber el nombre de la struct
   printf(">            ");
   printf("%s;",info.name);
   printf("%s;",info.DNI);
   printf("%d;",info.age);
   printf("%d;",info.fever);
   printf("%d;",info.cough);
   printf("%c;\n",info.symptom);
 }

 int verify_DNI(char *dni){
   char sum[9];
   int i,cad;
   int index;
   char word[23]="TRWAGMYFPDXBNJZSQVHLCKE";
   sscanf(dni,"%8s",sum);
   for(i=0;i<8;i++){//check if every char is a digit in sum, 0 is bad 1 is ok
     if(isdigit(sum[i])==0){
       return 0;//invalid dni
     }
   }
   cad=atoi(sum);//atoi change string sum to int cad
   index=cad%23;
   
   if (dni[8]==word[index]){
     return 1;
   }//if
   
   else return 0;
   
 }
 // preguntar atoi
void headline(char b, char *c) {
  int i;
  printf("%c", b);
  for (i=0;i<21;i++)
    printf(" ");
  printf("%s", c);
  for (i=0;i<21;i++)
    printf(" ");
  printf("%c", b);
  printf("\n");
  
  return;
}

void stripe(char b){
  int i;
  for (i=0;i<50;i++)
    printf("%c", b);
  printf("\n");
  return;
}
	   




