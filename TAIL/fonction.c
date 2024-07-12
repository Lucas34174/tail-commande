#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

FILE *open_file(char *filename,char *option)
{
	FILE *fic=fopen(filename,option);
	if(fic==NULL)
	{
		printf(" Any File is open\n");
		exit (1);
	}
	return (fic);
}


int count_ligne(FILE *fic)
{
	char help;
	int  nligne=0;
	while((help=fgetc(fic))!=EOF)
	{
		if(help=='\n')
			nligne+=1;
	}
	return (nligne);
}

void tail(FILE *fic,int nligne,int option)
{
	char help;
	int n=0;
	while((help=fgetc(fic))!=EOF)
	{
		if(help=='\n')
		{
			n++;
		}
		if(n>=nligne-option)
		{
			printf("%c",help);
		}
	}
}

void all_option(int nligne,int argc,char *argv[],FILE *fic)
{
	char foption[10];
	char *p;
	int number_ligne,option;
	strcpy(foption,argv[1]);
	int option_lenght=strlen(argv[1]);
	if(argc>2)
	{
		if(foption[0]=='-')
		{
			if(foption[1]=='n')
			{
				if(option_lenght<=2)
				{
					option=atoi(argv[2]);
				}
				else
				{
					p=&foption[2];
					option=atoi(p);
				}
				tail(fic,nligne,option);
			}
			else if(foption[1]=='f'||foption[1]=='F')
			{
				FILE *file;
				option=10;
				int ligne,aligne;
				file=open_file(argv[argc-1],"r");
				ligne=count_ligne(file);
				rewind(file);
				aligne=ligne;	
				tail(file,ligne,option);
				do
				{
					file=fopen(argv[argc-1],"r");
					ligne=count_ligne(file);
					rewind(file);	
					if(ligne != aligne)
					{
						tail(file,ligne,ligne-aligne);
						aligne=ligne;
					}
					fclose(file);
				}while(1);
			}
			else if(foption[1]=='v'||strcmp(argv[1],"--verbose")==0)
			{
				option=10;
				printf("\t\t\t\"%s\"\n",argv[argc-1]);
				tail(fic,nligne,option);
			}
			else if(foption[1]=='c')
			{
				char phrase;
				if(option_lenght<=2)
				{
					option=-1-atoi(argv[2]);
				}
				else
				{
					p=&foption[2];
					option=-1-atoi(p);
				}
				fseek(fic,option,SEEK_END);
				while((phrase=fgetc(fic))!=EOF)
				{
					printf("%c",phrase);
				}
			}
			else if(foption[1]=='q'||strcmp(argv[1],"--quiet")==0||strcmp(argv[1],"--silent")==0)
			{
				tail(fic,nligne,option);
			}
			else if(foption[1]=='z'||strcmp(argv[1],"--zero-terminated")==0)
			{
				char lettre;
				rewind(fic);
				while((lettre=fgetc(fic))!=EOF)
				{
					printf("%c",lettre);
				}
			}
			else
			{
				option=-atoi(argv[1]);
				tail(fic,nligne,option);
			}
		}
		else{
			printf("Option invalid : %s \n",argv[1]);
			exit (1);
		}
	}
	else
	{
		option=10;
		tail(fic,nligne,option);
	}
}

void sup_option(char *argv[])
{
	if(strcmp(argv[1],"--version")==0)
	{
			printf("liat \nversion simplifié de la commande \"tail(GNU Coreutils) 8.32\"\n"
					"ecrit par HARITSARA Mendrika Ny Avo Fiderana Lucas\n12- 07 -2024\n");
	}
	else if(strcmp(argv[1],"--help")==0)
	{
			printf(	"Utilisation : tail [OPTION]... [FICHIER]...\n"\
					"-n:afficher les N dernières lignes, au lieu des 10\n"
					"-f ou -F: afficher les données ajoutées au fur et à mesure que le fichier grandit \n"
					"-z ou --zero-terminated: le délimiteur de lignes est l'octet NUL au lieu du saut de ligne\n"
					"-q ou --quiet ou --silent: ne jamais afficher l'en-tête donnant les noms de fichiers\n"
					"-c :afficher les N derniers octets\n"
					"-v  ou --verbose:afficher toujours les en-têtes des noms de fichier\n"
					"--help:afficher l'aide et quitter\n"
					"--version:afficher des informations de version et quitter\n");			
	}
}

void close_file(FILE *file)
{
	if(file!=NULL)
	{
		fclose(file);
	}
}
