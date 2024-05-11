#include "search_algos.h"

/**
 * jump_list -  searches for a value in a sorted list of integers using
 * the Jump search algorithm
 * @list: pointer to the head of the list
 * @size:  number of nodes in list
 * @value:  value to search for
 * Return: pointer to the first node where value is located or NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t low = 0;
	size_t high = step;
	listint_t *tmp, *current;

	if (list == NULL || size == 0)
		return (NULL);
	current = list;
	while (high <= size)
	{
		tmp = current;
		while (current->index <= high)
		{
			if (current->index == high)
			{
				printf("Value checked at index[%lu]\
					= [%d]\n", low, current->n);
				if (current->n == value)
					return (current);
				else if (current->n < value)
				{
					low = high + 1;
					high += step;
				}
				else
				{
					printf("Value found between indexes\
						[%lu] and [%lu]\n", low, high);
					while (tmp != current)
					{
						if (tmp->n != value)
							tmp = tmp->next;
						else
							return(current);
					}
				}
			}
			current = current->next;
		}
	}
	return (NULL);
}
