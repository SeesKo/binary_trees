#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
		return (0);

	/* Recursive call to calculate size of left subtree */
	left_size = binary_tree_size(tree->left);

	/* Recursive call to calculate size of right subtree */
	right_size = binary_tree_size(tree->right);

	/* Return the sum of sizes of left and right */
	/* subtrees plus 1 for the current node */
	return (1 + left_size + right_size);
}
