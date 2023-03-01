#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "database.h"
#include "inout.h"





int main(){

  char q;
  char pat[150];
  struct aPatient thePatients[100];
  int numPatients=0;
  FILE *file;
   file=fopen("patients.txt","r");
  
   if(file!=NULL){
    while(fgets(pat,sizeof(pat),file)!=NULL){

    sscanf(pat,"%s %s %d %d %d %c",thePatients[numPatients].name,thePatients[numPatients].DNI,&thePatients[numPatients].age,&thePatients[numPatients].fever,&thePatients[numPatients].cough,&thePatients[numPatients].symptom);
    numPatients++;
    }
    fclose(file);
   }//take the values in the file and create the list
 
   
  stripe('-');
  headline('|',"DIVOC_");
  stripe('-');
    
     //the header
  
  
  do { //void that repeats if the user decides not to exit
    do { //void of the switch until 'X'

    printf("\nR) Register a patient\n");
      printf("S) Search for a patient\n");
      printf("D) Discharge a patient\n");
      printf("L) List patients by age\n");
      printf("P) Mark positive\n");
      printf("X) Exit the program\n");

      
    	q=get_character("\nChoose an option","RSDLPX");


  
      switch(q) {
    case 'R':
      p_register(thePatients,&numPatients);
      break;
  case 'S':
    p_search(thePatients,numPatients);
      break;
    case 'L':
      p_list(thePatients,numPatients);
      break;
    case 'D':
      p_discharge(thePatients,&numPatients);
      break;
    case 'P':
      p_mark(thePatients,numPatients);
      break;
    case 'X':
     
      break;
    default:
   
      break;

      }
   
  }while (q!='X');//repeat until the answer is 'X'

  }while(p_exit(thePatients,numPatients,file)==0);//repeat until it answer "yes"


  
  
  return 0;
}//int main
 
  
 
 
