#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 * Return: A pointer to the root node of the created AVL tree,
 * NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl_tree(array, 0, size - 1, NULL));
}

/**
 * build_avl_tree - Recursively builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array.
 * @start: Index of the start of the current subarray.
 * @end: Index of the end of the current subarray.
 * @parent: Pointer to the parent node.
 * Return: A pointer to the root node of the created AVL tree,
 * NULL on failure.
 */
avl_t *build_avl_tree(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *new_node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	new_node = binary_tree_node(parent, array[mid]);
	if (!new_node)
		return (NULL);

	new_node->left = build_avl_tree(array, start, mid - 1, new_node);
	new_node->right = build_avl_tree(array, mid + 1, end, new_node);

	return (new_node);
}
