#include <stdio.h>

int main(int argc, char *argv[])
{
	int areas[] = {10, 12, 13, 14, 20};
	char name[] = {"Tales"};
	char full_name[] = {'T', 'a', 'l', 'e', 's', ' ', 'C', '.', ' ','F', 'r', 'a', 'g', 'o', 's', 'o','\0'};
	short int i = 0;
	
	printf("Areas: "); 	
	while(i < 5)
	{
		printf("%d ", areas[i]);
		i++;
	}	
	printf("\nThe size of an int: %ld bits.\n", sizeof(int) * 8);
	printf("The size of array \"areas\": %ld bits\n\n", sizeof(areas) * 8);
	printf("Name: %s\n", name);
	printf("The size of a char: %ld bits.\n", sizeof(char) * 8);
	printf("The size of array \"name\": %ld bits.\n", sizeof(name) * 8);
	printf("Full Name: %s\n", full_name);
	printf("The size of array \"full_name\": %ld bits.\n\n", sizeof(full_name) * 8);
	return 0;
}
	
	
	


