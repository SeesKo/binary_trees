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
	heap_t *root = NULL;

	if (array && size > 0)
	{
		root = heap_insert(&root, array[0]);

		for (size_t i = 1; i < size; i++)
			heap_insert(&root, array[i]);
	}

	return (root);
}
