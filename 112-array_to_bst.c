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
	bst_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	/* Inserting each element from the array into the BST */
	for (i = 0; i < size; i++)
	{
		/* Using the bst_insert function to insert each element */
		if (bst_insert(&root, array[i]) == NULL)
			break;
	}

	/* Checking if loop ended prematurely (insertion failure) */
	if (i < size)
	{
		/* Cleaning up and returning NULL on failure */
		while (root != NULL)
		{
			bst_t *temp = root;

			root = (array[i] < root->n) ? root->left : root->right;
			free(temp);
		}

		return (NULL);
	}

	return (root);
}
