#include <stdio.h>


int main(int argc, char *argv[])
{
	char *words[] = {"j", "gg", "kk"};
	short int i = 0;

	/*while(i < 3)
	{
		printf("Enter a word:");
		scanf("%s", &words[i++]);
	}
	i = 0;*/
	while(i < 3)
	{
		printf("%s", words[i++]);
	}
	printf("\n%ld\n", sizeof(words[0]) * 8);
	return 0;
}	
