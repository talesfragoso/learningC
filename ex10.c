#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	char letter;

	if(argc != 2)
	{
		puts("You need one argument!");
		return 1;
	}
	for(i = 0; argv[1][i] != '\0'; i++)
	{
		letter = argv[1][i];		
		switch(letter)
		{
			
