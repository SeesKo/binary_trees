#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 if tree is NULL or not full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If the current node is a leaf, return 1 */
	if (!tree->left && !tree->right)
		return (1);

	/* If current node has both left and right children, */
	/* recursively check both subtrees */
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If current node has only 1 child, the tree is not full */
	return (0);
}
