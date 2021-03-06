#include <stdio.h>
#include <ctype.h>

int can_print_it(char ch);
void print_letters(char arg[]);
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

void print_letters(char arg[])
{
	short unsigned int i;

	for(i = 0; arg[i] != '\0'; i++)
	{
		if(can_print_it(arg[i]))
		{
			printf("%c: %d\n", arg[i], arg[i]);
		}
	}
}

void print_arguments(int argc, char *argv[])
{
	short unsigned int i;

	for(i = 0; i < argc; i++)
	{
		print_letters(argv[i]);
	}
}
