#include <stdlib.h>
#include "huffman.h"

/**
 * huffman_extract_and_insert - extracts two nodes and inserts parent back
 * @priority_queue: pointer to the heap representing the priority queue
 *
 * Return: 1 on success, 0 on failure
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	node_t *nl, *nr, *n;
	symbol_t *sl, *sr, *s;
	size_t freq;

	if (!priority_queue || priority_queue->size < 2)
		return (0);

	nl = (node_t *)heap_extract(priority_queue);
	nr = (node_t *)heap_extract(priority_queue);
	if (!nl || !nr)
		return (0);

	sl = (symbol_t *)nl->data;
	sr = (symbol_t *)nr->data;
	freq = sl->freq + sr->freq;

	s = symbol_create(-1, freq);
	if (!s)
		return (0);

	n = binary_tree_node(NULL, s);
	if (!n)
	{
		free(s);
		return (0);
	}

	nl->parent = n;
	nr->parent = n;
	n->left = nl;
	n->right = nr;

	if (!heap_insert(priority_queue, n))
		return (0);

	return (1);
}

