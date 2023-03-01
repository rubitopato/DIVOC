

int  yes_or_no(char *prompt);

void stripe(char b);

void headline(char b, char *c);

void get_string(char *prompt,int min,int max,char *my_string);

int get_integer( char *prompt, int min, int max);

char get_character(char *prompt, char *check);

void display_patient(struct aPatient info);

int verify_DNI(char dni[9]);
