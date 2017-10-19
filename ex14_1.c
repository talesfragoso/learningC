#include <stdio.h>
#include <ctype.h>
#include <string.h>

int can_print_it(char ch);
void print_letters(char arg[], unsigned int len);
void print_arguments(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}

int can_print_it(char ch)
{
	return isalpha(ch) || isblank(ch);
}

void print_letters(char arg[], unsigned int len)
{
	unsigned int i;

	for(i = 0; i < len; i++)
	{
		if(can_print_it(arg[i]))
		{
			printf("%c: %d\n", arg[i], arg[i]);
		}
	}
}

void print_arguments(int argc, char *argv[])
{
	unsigned int i;

	for(i = 0; i < argc; i++)
	{
		print_letters(argv[i], strlen(argv[i]));
	}
}
