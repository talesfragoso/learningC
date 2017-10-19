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


