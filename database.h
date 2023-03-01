struct aPatient{
  char name[25];
  int age;
  char DNI[10];
  int fever;
  int cough;
  char symptom;
};

void p_register(struct aPatient *table, int *number);

void p_discharge(struct aPatient *table, int *number);

void p_list(struct aPatient *table, int number);

void p_search(struct aPatient *table, int number);

void p_mark(struct aPatient *table, int number);

int p_exit(struct aPatient *table, int number, FILE *file);
