#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_bst(tree) &&
	    is_balanced(tree, INT_MIN, INT_MAX))
		return (1);
	return (0);
}

/**
 * is_balanced - Checks if a binary tree is balanced.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum value a node can have.
 * @max: The maximum value a node can have.
 *
 * Return: 1 if the tree is balanced, 0 otherwise.
 */
int is_balanced(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	balance_factor = left_height - right_height;

	if (balance_factor > 1 || balance_factor < -1)
		return (0);

	return (is_balanced(tree->left, min, tree->n) &&
			is_balanced(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_helper(tree, NULL, NULL));
}

/**
 * is_bst_helper - Helper function to check if a tree is a valid BST.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum value a node can have.
 * @max: The maximum value a node can have.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst_helper(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if ((min != NULL && tree->n <= min->n) ||
	    (max != NULL && tree->n >= max->n))
		return (0);

	return (is_bst_helper(tree->left, min, tree) &&
			is_bst_helper(tree->right, tree, max));
}

/**
 * binary_tree_height - Computes the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}
