#include <stdio.h>
#include <string.h>

void print_str(char *str2)
{
	printf("Variable str2 has %ld bytes\n", sizeof(str2));
    printf("str2: %s\n", str2); 
}

int main(void)
{
	//char str0[] = {'O', 'i', '\0'};
	char str0[3];
	char str1[3];

	printf("Type OI");
	scanf("%s", str0);	
	printf("str0: %s\n", str0);	
	printf("Variable str0 has %ld bytes\n", sizeof(str0));	
	strcpy(str1, str0);	
	printf("Variable str1 has %ld bytes\n", sizeof(str1));	
	printf("str1: %s\n\n\n", str1); 
	print_str(str1);
	return 0;
}
