#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid
 * Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	static const binary_tree_t *prev;

	if (tree == NULL)
		return (1);

	/* Checking the left subtree */
	if (!binary_tree_is_bst(tree->left))
		return (0);

	/* Checking if current node's value is greater than */
	/* the value in the previous node (in-order) */
	if (prev != NULL && tree->n <= prev->n)
		return (0);

	/* Updating the previous node */
	prev = tree;

	/* Checking the right subtree */
	return (binary_tree_is_bst(tree->right));
}
