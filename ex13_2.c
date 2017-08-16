#include <stdio.h>

int main(int argc, char *argv[])
{
	short unsigned int i;
	char states[4][30];
	char *cities[] = {"Rio de Janeiro", "Niterói", "Curitiba", "Porto Alegre"};

	for(i = 1; i < argc; i++)
	{
		printf("%s\t", argv[i]);
	}
	puts(" ");
	for(i = 0; i < 4; i++)
	{
		printf("Estate %d: ", i + 1);		
		scanf("%s", states[i]);
	}
	puts(" ");	
	for(i = 0; i < 4; i++)
	{
		printf("%s\t", states[i]);		
		
	}
	printf("\n\nCities: " );
	for(i = 0; i < 4; i++)
	{
		printf("%s\t", cities[i]);		
		
	}
	puts(" ");
	return 0;
}
	

