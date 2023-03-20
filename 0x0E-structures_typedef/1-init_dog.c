#include "dog.h"

/**
 * init_dog - initialize a variable of type struct dog
 * @d: a variable of struct dog
 * @name: member
 * @age: member
 * @owner: member
 * Return: nothing
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL) /* validate initialization */
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
