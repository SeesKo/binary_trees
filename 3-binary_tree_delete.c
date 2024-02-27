#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	/* Recursive call to delete left subtree */
	binary_tree_delete(tree->left);

	/* Recursive call to delete right subtree */
	binary_tree_delete(tree->right);

	/* Deleting current node */
	free(tree);
}
