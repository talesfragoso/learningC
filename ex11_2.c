#include <stdio.h>

int main(int argc, char *argv[])
{
	int numbers[4] = {0};
	char name[6] = {"Tales"};
	typedef char microint;
	microint i;

	printf("%d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("%s\n", name);
	for(i = 0; i < 5 && name[i] != '\0'; i++)
	{
		printf("%c", name[i]);
	} 
	name[0] = 'T';
	name[1] = 'a';
	name[2] = 'l';
	name[3] = 'e';
	name[4] = 's';
	name[5] = '\0';
	i = 0;
	do
	{
		fputc(name[i], stdout);
		i++;
	} while(i < 5); 
	return 0;
}
	
