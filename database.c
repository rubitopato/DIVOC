#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "database.h"
#include "inout.h"



void p_register(struct aPatient *table,int *number){
  char s[25];
  char d[10];
  printf("\nRegister\n");
  get_string("\nName",1,24,s);
  strcpy(table[*number].name,s);
  

  do{
  get_string("\nDNI",9,9,d);
  if(verify_DNI(d)==0){//returns 0 if incorrect
    printf("\nInvalid DNI");
  }
  }while(verify_DNI(d)==0);

  strcpy(table[*number].DNI,d);
 
  table[*number].age=get_integer("\nDate",1900,2020);
 
   table[*number].fever=yes_or_no("\nFever (y/n):");
  
    table[*number].cough=yes_or_no("\nCough (y/n):");
  
    table[*number].symptom=get_character("\nSymptom","FSTMN");
 
   
    printf("\nNew patient:\n");
    display_patient(table[*number]);
    
    (*number)++;

    return;
}
void p_discharge(struct aPatient *table, int *number){
  char s[10];
  int i=0;
  printf("\nDischarge\n");
   if(*number==0){
    printf("\nNo patients yet\n");
  }
   else{
     get_string("\nDNI",9,9,s);
    while(strcmp(s,table[i].DNI)!=0 && i<*number){//returns 0 if it is the same
      i++;
    }
    if(i!=*number){
      for(int c=i;c<(*number)-1;c++){
	table[c]=table[c+1];
	}

	printf("\nDischarged patient\n");
	(*number)--;
    }
    
      else{
	printf("\nUnknown patient\n");
      }
  

   
   
   }//first else

  return;
}//void
   
void p_list(struct aPatient *table, int number){
  int n;
  printf("\nList\n");
  if(number==0)
  printf("\nNo patients yet\n");
  else{
   n= get_integer("\nDate",1900,2020);
    printf("\nPatients born before %d:\n",n);
    for(int i=0;i<number;i++){
      if(table[i].age<=n){
	display_patient(table[i]);//aqui display_patient
      }
    }

  }




  
  return;
  
  }
void p_search (struct aPatient *table,int number){
 
  char s[10];
  int i=0;

  printf("\nSearch\n");
  
  
   if(number==0){
    printf("\nNo patients yet\n");
  }
  else{
    get_string("\nDNI",9,9,s);
    ///////////////
    while(strcmp(s,table[i].DNI)!=0 && i<number){//devuelve 0 si coinciden
      i++;
    }
    if(i!=number){
      	printf("\nPatient data:\n");
        display_patient(table[i]);
    }
      if(i==number){
	printf("\nUnknown patient\n");
      }
      ///////////////
  }//first else
  return;
}


void p_mark(struct aPatient *table,int number){

  printf("\nPositives\n");
  if(number==0)
    printf("No patients yet\n");
  else{
    printf("\nPositive patients:\n");
    for(int i=0;i<number;i++){
      if(table[i].fever==1 && table[i].cough==1 && table[i].symptom!='N'){
         display_patient(table[i]);
      }
    }
  }
  return;
}

int p_exit(struct aPatient *table, int number, FILE *file){

  printf("\nExit\n");
  
  if(yes_or_no("\nAre you sure you want to exit the program? (y/n): ")==1){
     file=fopen("patients.txt","w");
  if(file==NULL){
    printf("\nThe file could not be opened\n");
  }
  else{
  for(int i=0;i<number;i++){
    fprintf(file,"%s %s %d %d %d %c\n",table[i].name,table[i].DNI,table[i].age,table[i].fever,table[i].cough,table[i].symptom);
  }//for
  }//else
  fclose(file);
  return 1;//end the program
  }//if of the yes and no
  else{
    return 0;//returns to the menu
  }
}
