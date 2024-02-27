#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs post-order traversal on a binary tree
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node. The value in the node
 * must be passed as a parameter to this function.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Traversing the left subtree */
	binary_tree_postorder(tree->left, func);

	/* Traversing the right subtree */
	binary_tree_postorder(tree->right, func);

	/* Calling the function on the current node*/
	func(tree->n);
}
