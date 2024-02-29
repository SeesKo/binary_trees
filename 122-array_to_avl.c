#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: Pointer to the first element of the array
 * to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree,
 * NULL if it fails.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t a;
	avl_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (a = 0; a < size; a++)
	{
		/* Handling insertion failure, if needed */
		if (avl_insert(&root, array[a]) == NULL)
			return (NULL);
	}

	return (root);
}
