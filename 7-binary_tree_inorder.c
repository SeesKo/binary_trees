#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/* Recursive call for left subtree */
	binary_tree_inorder(tree->left, func);

	/* Call the function for the current node */
	func(tree->n);

	/* Recursive call for right subtree */
	binary_tree_inorder(tree->right, func);
}
