#include <stdio.h>

int main(int argc, char *argv[])
{
	int numbers[4] = {0};
	char name[6] = {"Tales"};
	typedef char microint;
	microint i;

	printf("%d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("%s\n", name);
	for(i = 0; i < 5; i++)
	{
		printf("%c", name[i]);
	} 
	return 0;
}
	
