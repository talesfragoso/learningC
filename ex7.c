#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'C';
	char first_name[] = "Tales";
	char last_name[] = "Fragoso";

	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f levels of awesome super power.\n", super_power);
	printf("First name: %s\n", first_name);
	printf("Last name: %s\n", last_name);
	printf("Initial: %c\n", initial);
	printf("Your full name is \"%s %c. %s\"\n\n", first_name, initial, last_name);
	//double num = (double) 5 / 2;
	printf("%f\n", (double) 5 / 2); 
	return 0;
}
