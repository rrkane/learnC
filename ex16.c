#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight) {
	struct Person *who = malloc(sizeof(struct Person));
	assert (who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who) {
	assert(who != NULL);

	free(who->name);
	free(who);
}

void Person_print(struct Person *who) {
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main (int argc, char *argv[]) {
	// make two people structures
	struct Person *alice = Person_create("Alice", 22, 66, 110);
	struct Person *bob = Person_create("Bob", 22, 72, 170);

	// print structures and memory locations
	printf("Alice is at memory location %p:\n", alice);
	Person_print(alice);
	
	printf("Bob is at memory location %p:\n", bob);
	Person_print(bob);

	// make everyone age 20 years and print them again
	alice->age += 20;
	alice->height -= 1;
	alice->weight += 20;
	Person_print(alice);

	bob->age += 20;
	bob->height -= 1;
	bob->weight += 30;
	Person_print(bob);

	// destroy both
	Person_destroy(alice);
	Person_destroy(bob);

	return 0;
}
