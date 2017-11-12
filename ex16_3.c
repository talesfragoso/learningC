#include <stdio.h>
#include <string.h>

struct Person {
	char name[20];
	int age;
	float height;
	float weight;
};

struct Person Person_create(char *name, int age, float height, float weight)
{
	struct Person who;

	strcpy(who.name, name);
	who.age = age;
	who.height = height;
	who.weight = weight;
	return who;
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
	struct Person joe, frank;
	
	joe = Person_create("Joe Alex", 32, 1.65, 62);
	printf("Joe is at memory location: %p\n", &joe);
	Person_print(&joe);
	frank = Person_create("Frank Blank", 20, 1.70, 72.2);	
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
 
