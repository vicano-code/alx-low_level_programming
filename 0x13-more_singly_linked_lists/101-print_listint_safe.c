#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head node of list
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *fast = head, *slow = head;
	size_t count = 0;
	int is_loop = 0;

	while (fast && slow && fast->next)
	{
		if (!(fast->next->next))
			break;
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			slow = slow->next;
			is_loop = 1;
			break;
		}
	}
	if (!is_loop)
	{
		while (head)
		{
			count++;
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		return (count);
	}
	while (head)
	{
		count++;
		if (head == slow)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			printf("-> [%p] %d\n", (void *)head, head->next->n);
			exit(98);
		}
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	return (count);
}
