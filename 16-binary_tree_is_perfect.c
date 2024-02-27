#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	/* Recursive call for left subtree */
	left_height = binary_tree_height(tree->left);

	/* Recursive call for right subtree */
	right_height = binary_tree_height(tree->right);

	/* Return the maximum height between left and right */
	/* subtrees, plus 1 for the current node */
	return (1 + (left_height > right_height ? left_height : right_height));
}

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

	/* Return the sum of sizes of left and right subtrees, */
	/* plus 1 for the current node */
	return (1 + left_size + right_size);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size;

	if (tree == NULL)
		return (0);

	/* Calculate the height and size of the tree */
	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	/* Check if the tree is perfect based on the height and size */
	return (size == (size_t)((1 << height) - 1));
}
