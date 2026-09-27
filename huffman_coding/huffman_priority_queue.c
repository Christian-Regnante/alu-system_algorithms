#include <stdlib.h>
#include "huffman.h"

/**
 * sym_cmp - compares two symbols
 * @p1: first pointer
 * @p2: second pointer
 *
 * Return: difference between the two frequencies
 */
int sym_cmp(void *p1, void *p2)
{
	symbol_t *s1, *s2;
	node_t *n1, *n2;

	n1 = (node_t *)p1;
	n2 = (node_t *)p2;
	s1 = (symbol_t *)n1->data;
	s2 = (symbol_t *)n2->data;

	return (s1->freq - s2->freq);
}

/**
 * huffman_priority_queue - allocates a priority queue for
 *                          the Huffman coding algorithm
 * @data: char array
 * @freq: freq array
 * @size: size_t length of @data and @freq
 *
 * Return: heap_t pointer to allocated priority queue, or NULL on failure
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *q;
	size_t i;
	symbol_t *s;
	node_t *n;

	if (!data || !freq || !size)
		return (NULL);

	q = heap_create(sym_cmp);
	if (!q)
		return (NULL);

	for (i = 0; i < size; ++i)
	{
		s = symbol_create(data[i], freq[i]);
		if (!s)
			return (NULL);

		n = binary_tree_node(NULL, s);
		if (!n)
		{
			free(s);
			return (NULL);
		}

		if (heap_insert(q, n) == NULL)
			return (NULL);
	}

	return (q);
}
