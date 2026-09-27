#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_leaf_data - recursively prints the huffman code for each leaf
 * @buffer: char buffer for writing huffman code for leaf
 * @node: node_t root of huffman subtree
 */
void print_leaf_data(char *buffer, node_t *node)
{
	char buf[256];
	char *fmt;
	char c;

	if (!node)
		return;

	if (node->left)
	{
		fmt = (buffer) ? "%s0" : "0";
		sprintf(buf, fmt, buffer);
		print_leaf_data(buf, node->left);
	}
	if (node->right)
	{
		fmt = (buffer) ? "%s1" : "1";
		sprintf(buf, fmt, buffer);
		print_leaf_data(buf, node->right);
	}
	if (!node->left && !node->right)
	{
		c = ((symbol_t *)node->data)->data;
		printf("%c: %s\n", c, buffer);
	}
}

/**
 * huffman_codes - generates and prints the Huffman codes for a dataset
 * @data: array of characters
 * @freq: array of frequencies
 * @size: size of data and freq arrays
 *
 * Return: 1 on success, 0 on failure
 */
int huffman_codes(char *data, size_t *freq, size_t size)
{
	node_t *root;

	if (!data || !freq || size == 0)
		return (0);

	root = huffman_tree(data, freq, size);
	if (!root)
		return (0);

	print_leaf_data(NULL, root);
	free_binary_tree_node(root, free);

	return (1);
}
