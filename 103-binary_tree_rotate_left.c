#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	/* Setting new root to the right child of the current root */
	new_root = tree->right;

	/* Updating the right child of the current root */
	/* to be the left child of the new root */
	tree->right = new_root->left;

	/* Updating parent of the new root to be */
	/* the parent of the current root */
	if (new_root->left != NULL)
		new_root->left->parent = tree;

	/* Update the parent of the current root to be the new root */
	new_root->parent = tree->parent;

	/* If current root was root of the entire tree, update the tree's root */
	if (tree->parent == NULL)
		tree->parent = new_root;
	else if (tree == tree->parent->left)
		tree->parent->left = new_root;
	else
		tree->parent->right = new_root;

	/* Set the left child of the new root to be the current root */
	new_root->left = tree;

	/* Update the parent of the current root to be the new root */
	tree->parent = new_root;

	return (new_root);
}
