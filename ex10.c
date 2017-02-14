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
			case 'a':
			case 'A':
				printf("A: %d\n", 'A');
				break;
			case 'e':
			case 'E':
				printf("E: %d\n", 'E');
				break;
			case 'i':
			case 'I':
				printf("I: %d\n", 'I');
				break;
			case 'o':
			case 'O':
				printf("O: %d\n", 'O');
				break;
			case 'u':
			case 'U':
				printf("U: %d\n", 'U');
				break;
			default:
				printf("%c: not a vowel.\n", letter);
		}
	}
	return 0;
} 
			
				
