#include <stdlib.h>
#include "huffman.h"

/**
 * symbol_create - allocates a symbol_t with a char and its frequency
 * @data: ascii-sized character
 * @freq: size_t frequency of @data in corpus
 *
 * Return: pointer to new symbol_t or NULL on failure
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *sym;

	sym = malloc(sizeof(*sym));
	if (sym == NULL)
		return (NULL);

	sym->data = data;
	sym->freq = freq;

	return (sym);
}
