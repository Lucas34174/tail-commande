#ifndef FONCTION_H
#define FONCTION_H

int count_ligne(FILE *file);
void tail(FILE *file,int nligne,int option);
void all_option(int nligne,int argc,char *argv[],FILE *fic);
FILE *open_file(char *filename,char *option);
void close_file(FILE *file);
void sup_option(char *argv[]);


#endif 
