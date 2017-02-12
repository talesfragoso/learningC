#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	
	if(argc < 1) 
	{
		puts("You have to enter at least one argument.");
		return 1;
	}
	if(argc == 1)
	{
		puts("Just one argument?!");
	} 
	else if(argc > 1 && argc < 4)
	{
		printf("Here's your arguments: ");
		for(i = 1; i < argc; i++)
		{
			printf("\"%s\" ", argv[i]);
		}
		printf("\n");
	}
	else puts("Too many arguments!");
	return 0;
}

