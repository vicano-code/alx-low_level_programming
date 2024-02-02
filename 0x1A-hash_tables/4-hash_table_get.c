#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table
 * @key: the key
 * Return: the value or NULL if key couldn’t be found/
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;

	if (ht == NULL || key == NULL)
		return (NULL);

	idx = key_index(key, ht->size);
	return (ht->array[idx]->value);
}
