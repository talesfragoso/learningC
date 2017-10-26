#include <stdio.h>

int main(int argc, char *argv[])
{
	int ages[] = {23, 43, 12, 89};
	char *names[] = {"Alan", "Franck", "Mary", "John", "Lisa"};
	int *cur_age;
	char **cur_name;
	unsigned int cont, i;

	
	cont = sizeof(ages) / sizeof(int);
	for(i = 0; i < cont; i++)
	{
		printf("Name: %s, Age: %d\n", names[i], ages[i]);
	}
	cur_age = ages;
	cur_name = names;	
	for(i = 0; i < cont; i++)
	{
		printf("Name: %s, Age: %d\n", *(cur_name + i), *(cur_age + i));
	}
	return 0;
}
