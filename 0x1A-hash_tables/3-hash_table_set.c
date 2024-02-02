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
	const char *value_dup;
	hash_node_t *node;

	if (ht == NULL || (ht->array) == NULL || value ==  NULL)
		return (0);
	if (key == NULL || strlen(key) == 0)
		return (0);
	value_dup = strdup(value);
	/* give the index of the key */
	idx = key_index(key, size);
	
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return 0;
	value_dup = strdup(value);
	key_dup = strdup(key);
	node->key = key_dup;
	node->value = value_dup;
	node->next = NULL;
	while (idx < ht->size)
	{	
		if (ht->array[idx] == NULL)
			ht->array[idx] = node;
		else 
			add_to_front(ht, node, idx);
		idx++;
	}
	return (1);
}
