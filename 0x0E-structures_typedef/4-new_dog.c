#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - compute string length
 * @s: the string
 * Return: result
 */

int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;

	return (len);
}

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 * Return: copy of original source
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i <= _strlen(src); i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * new_dog -  creates new instance of dog
 * @name: member
 * @age: member
 * @owner: member
 * Return: new_dog instance
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *mydog;
	char *copy_of_name;
	char *copy_of_owner;

	/* allocate memory for mydog and validate */
	mydog = malloc(sizeof(dog_t));
	if (mydog == NULL)
		return (NULL);

	if (name == NULL)
	{
		return (NULL);
	}
	copy_of_name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (copy_of_name == NULL)
	{
		free(mydog);
		return (NULL);
	}
	mydog->name = _strcpy(copy_of_name, name);

	mydog->age = age;

	if (owner == NULL)
	{
		return (NULL);
	}
	copy_of_owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if (copy_of_owner == NULL)
	{
		free(copy_of_name);
		free(mydog);
		return (NULL);
	}
	mydog->owner = _strcpy(copy_of_owner, owner);

	return (mydog);
}

