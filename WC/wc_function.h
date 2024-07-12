#ifndef  WC_FUNCTION_H
#define  WC_FUNCTION_H


FILE *open_file(char *filename,char *option);
void sup_option(char *argv[]);
int line_number(FILE *fic);
void close_file(FILE *file);
int word_number(FILE *fic);
int max(FILE *fic);
int charactere_number(FILE *fic);
void wc(int line,int word,int charactere,int max_line_length,int argc,char *argv[]);


#endif
