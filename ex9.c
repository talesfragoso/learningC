#include <stdio.h>

int main(int argc, char *argv[])
{
	short int i = 0, cicles;

	printf("Number of iterations: ");	
	scanf("%hd", &cicles);
	while(i < cicles)
	{
		printf("%d\n", i);
		i++;
	}
	return 0;
} 
