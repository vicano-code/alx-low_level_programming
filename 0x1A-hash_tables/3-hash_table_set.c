#include "hash_tables.h"


/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	char *key_dup;
	char *value_dup;
	hash_node_t *new_node, *current;

	if (ht == NULL || (ht->array) == NULL || value ==  NULL)
		return (0);
	if (key == NULL || strlen(key) == 0)
		return (0);
	/* give the index of the key */
	idx = key_index((const unsigned char *)key, ht->size);

	key_dup = strdup(key);/*key duplicate*/
	value_dup = strdup(value); /*value duplicate*/
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = key_dup;
	new_node->value = value_dup;
	new_node->next = NULL;
	if (ht->array[idx] == NULL)
		ht->array[idx] = new_node;
	else
	{ /* check and update value of key if it exists or address collision*/
		current = ht->array[idx];
		while (current != NULL)
		{
			if (strcmp(current->key, key_dup) == 0)
			{
				current->value = (char *)value;
				return (1);
			}
			current = current->next;
		}
		/* collision: add new node at begining of list*/
		new_node->next = ht->array[idx];
		ht->array[idx] = new_node;
	}
	return (1);
}
