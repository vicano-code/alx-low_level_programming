#include "lists.h"
#include <stdlib.h>

void free_listint(listint_t *head);
void free_listint2(listint_t **head);

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to pointer to head node of list
 * Return: the head node’s data (n)
 */

int pop_listint(listint_t **head)
{
	listint_t *ptr;
	int data;

	if (*head == NULL) /* validation */
		return (0);

	ptr = *head;
	data =  ptr->n; /* extract the data of the head node */
	*head = ptr->next; /* make the next node the head */
	free(ptr);

	return (data);
}
