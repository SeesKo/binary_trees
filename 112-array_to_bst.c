#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created BST,
 * NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root_node = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	root_node = bst_insert(&root_node, array[0]);

	for (i = 0; i < size; i++)
	{
		bst_insert(&root_node, array[i]);
	}

	return (root_node);
}
