#include <stdio.h>

int main(int argc, char *argv[])
{
	int numbers[4] = {0};
	char name[4] = {'a'};

	printf("%d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("%c %c %c %c\n", name[0], name[1], name[2], name[3]);
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;
	name[0] = 'Z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = '\0';
	printf("%d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("%c %c %c %c\n", name[0], name[1], name[2], name[3]);
	printf("%s\n", name);
	char *another;
	another = "Zed";
	printf("%s\n", name);
	printf("%c %c %c %c\n", name[0], name[1], name[2], name[3]);
	return 0;
}