#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* Check for the complete tree property */
	if (!is_complete(tree, 0, count_nodes(tree)))
		return (0);

	/* Check for the Max Binary Heap property */
	return (is_max_heap(tree));
}

/**
 * is_complete - Checks if a binary tree is a complete tree.
 * @tree: Pointer to the root node of the tree.
 * @index: Current index in the complete binary tree representation.
 * @node_count: Total number of nodes in the binary tree.
 * Return: 1 if tree is a complete binary tree, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, int index, int node_count)
{
	if (!tree)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, node_count) &&
		is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * count_nodes - Counts the number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: The number of nodes in the binary tree.
 */
int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_max_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree.
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}
