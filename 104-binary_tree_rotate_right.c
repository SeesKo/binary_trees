#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	/* Setting new root to the left child of the current root */
	new_root = tree->left;

	/* Updating left child of current root to be right child of the new root */
	tree->left = new_root->right;

	/* Updating parent of the new root to be parent of the current root */
	if (new_root->right != NULL)
		new_root->right->parent = tree;

	/* Updating parent of the current root to be the new root */
	new_root->parent = tree->parent;

	/* If current root was root of the entire tree, update the tree's root */
	if (tree->parent == NULL)
		tree->parent = new_root;
	else if (tree == tree->parent->left)
		tree->parent->left = new_root;
	else
		tree->parent->right = new_root;

	/* Setting the right child of the new root to be the current root */
	new_root->right = tree;

	/* Updating parent of current root to be the new root */
	tree->parent = new_root;

	return (new_root);
}
