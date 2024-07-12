#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc_function.h"

int main(int argc,char *argv[])
{
	FILE *fic;
	int line,word,charactere,max_line_length;
	sup_option(argv);
	fic=open_file(argv[argc-1],"r");
	line=line_number(fic);
	word=word_number(fic);
	charactere=charactere_number(fic);
	max_line_length=max(fic);
	wc(line,word,charactere,max_line_length,argc,argv);
	close_file(fic);
	return (0);
}


