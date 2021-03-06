#include <stdio.h>

int main(int argc, char *argv[])
{
	int areas[] = {10, 12, 13, 14, 20};
	char name[] = "Zed";
	char full_name[] = {'Z','e', 'd', ' ', 'A', '.', 'S', 'h', 'a', 'w', '\0'};

	printf("The size of an int: %ld bits.\n", sizeof(int) * 8);
	printf("The size of areas: %ld bits.\n", sizeof(areas) * 8);
	printf("The number of ints in area %ld \n", sizeof(areas) / sizeof(int));
	printf("The first area (int[]) is %d and the second is %d\n", areas[0], areas[1]);
	printf("The size of a char is %ld bits.\n", sizeof(char) * 8);
	printf("The size of name (char[]) is %ld bits.\n", sizeof(name) * 8);
	printf("The numbers of chars in name (char[]) is %ld bits.\n", sizeof(name) / sizeof(char));
	printf("The size of full_name (char[]) is %ld bits.\n", sizeof(full_name) * 8);
	printf("Full name: %s\n", full_name);	
	return 0;
}

