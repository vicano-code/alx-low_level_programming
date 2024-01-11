#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: pointer to head node of list
 * Return: Nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *ptr;

	if (head == NULL)
		return;

	while (head)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
}
