#include <stdio.h>
#include <string.h>

struct Person {
	char name[20];
	int age;
	float height;
	float weight;
} joe, frank;

void Joe_create(char *name, int age, float height, float weight)
{
	
	strcpy(joe.name, name);
	joe.age = 32;
	joe.height = 1.62;
	joe.weight = 32;
}

void Frank_create(char *name, int age, float height, float weight)
{
	
	strcpy(frank.name, name);
	frank.age = age;
	frank.height = height;
	frank.weight = weight;
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d", who->age);
	printf("\tHeight: %0.2f", who->height);
	printf("\tWeight: %0.0f\n\n", who->weight);
}

int main(int argc, char *argv[])
{
	
	Joe_create("Joe Alex", 32, 1.65, 62);
	Frank_create("Frank Blank", 20, 1.70, 72.2);
	printf("Joe is at memory location: %p\n", &joe);
	Person_print(&joe);
	printf("Frank is at memory location: %p\n", &frank);
	Person_print(&frank);
	joe.age += 20;
	joe.height -= 0.2;	
	joe.weight += 40;
	Person_print(&joe);
	frank.age += 20;
	frank.weight += 20;
	Person_print(&frank);
	return 0;
}	
 
