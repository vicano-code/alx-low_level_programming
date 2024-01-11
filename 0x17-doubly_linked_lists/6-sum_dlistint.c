#include "lists.h"

/**
 * sum_dlistint - the sum of all the data (n) of a dlistint_t linked list
 * @head: pointer to the head node of the list
 * Return: the sum or 0 if empty
 */
int sum_dlistint(dlistint_t *head)
{
	int list_sum = 0;

	if (head == NULL)
		return (0);
	while (head)
	{
		list_sum += head->n;
		head = head->next;
	}
	return (list_sum);
}
