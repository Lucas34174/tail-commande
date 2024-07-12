#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int main(int argc,char *argv[])
{
	int nligne;
	int option;
	FILE *fic;
	char type_option;
	sup_option(argv);
	fic=open_file(argv[argc-1],"r");
	nligne=count_ligne(fic);
	rewind(fic);
	all_option(nligne,argc,argv,fic);
	close_file(fic);
	return (0);
}
