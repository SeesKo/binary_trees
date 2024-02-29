#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Return: Pointer to the root node of the created Binary Heap,
 * NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *root_node = NULL;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		/* Handle failure, free any allocated memory if necessary */
		if (heap_insert(&root_node, array[i]) == NULL)
			return (NULL);
	}

	return (root_node);
}
