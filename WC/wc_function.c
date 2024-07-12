#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc_function.h"

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

int word_number(FILE *fic)
{
	char letter,letter1;
	int word=0;
	rewind(fic);
	while((letter=fgetc(fic))!=EOF)
	{
		if((letter==' '||letter=='\n')&&(letter1!=' '&&letter1!='\n'))
		{
			word++;
		}
		letter1=letter;
	}
	return (word);
}


int charactere_number(FILE *fic)
{
	char letter;
	int charactere=0;
	rewind(fic);
	while((letter=fgetc(fic))!=EOF)
	{
		charactere++;
	}
	return (charactere);
}	

int max(FILE *fic)
{
	int max=0,n=0;
	char letter;
	rewind(fic);
	while((letter=fgetc(fic))!=EOF)
	{
		if(letter=='\n')
		{
			n=0;
		}
		n++;
		if(n>max)
		{
			max=n;
		}
	}
	return (max-1);
}

void close_file(FILE *file)
{
	if(file!=NULL)
	{
		fclose(file);
	}
}


int line_number(FILE *fic)
{
	char letter;
	int line=0;
	rewind(fic);
	while((letter=fgetc(fic))!=EOF)
	{
		if(letter=='\n'){
			line++;
		}
	}
	return (line);
}

void wc(int line,int word,int charactere,int max_line_length,int argc,char *argv[])
{
	int i,j;
	char option[10];
	if(argc==1)
	{
		printf("Argument missing\n");
		exit (1);
	}
	else if(argc==2)
	{
		printf("\t\t%s\n",argv[argc-1]);
		printf("line: %d \nword: %d\ncharactere: %d\n",line,word,charactere);
	
	}
	else if(argc>2)
	{
		printf("\t\t%s\n",argv[argc-1]);
		for(j=1;j<argc-1;j++)
		{
		strcpy(option,argv[j]);
			for(i=0;i<strlen(option);i++)
			{
				if(option[0]=='-')
				{
					if(option[i]=='l'||strcmp(option,"--lines")==0)
					{
						printf("line: %d\n",line);
					}
					else if(option[i]=='w'||strcmp(option,"--words")==0)
					{
						printf("word: %d\n",word);
					}
					else if(option[i]=='c'||strcmp(option,"--chars")==0)
					{
						printf("charactere: %d \n",charactere);
					}
					else if(option[i]=='L'||strcmp(option,"--max-line_length")==0)
					{
						printf("max-line_length: %d \n",max_line_length);
					}
				}
				else
				{
					printf("Invalid option  : %c\n",option[i]);
				}
			}
		}
	}
}

void sup_option(char *argv[])
{
	if(strcmp(argv[1],"--version")==0)
	{
			printf("wc \nversion simplifié de la commande \"wc(GNU Coreutils) 8.32\"\n"
					"ecrit par HARITSARA Mendrika Ny Avo Fiderana Lucas\n12- 07 -2024\n");
	}
	else if(strcmp(argv[1],"--help")==0)
	{
			printf(	"Utilisation : wc [OPTION]... [FICHIER]...\n"\
					"-l ou --lines:afficher le nombre de ligne\n"
					"-w ou --words: afficher le nombre de mot\n"
					"-c ou --chars: afficher le nombre de caractere\n"
					"-L  ou max-line_length:afficher la largeur maximale d'affichage\n"
					"--help:afficher l'aide et quitter\n"
					"--version:afficher des informations de version et quitter\n");			
	}
}

