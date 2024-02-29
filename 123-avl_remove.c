#include "binary_trees.h"

/**
 * avl_find_min - Finds the node with the minimum value in the AVL tree.
 * @node: A pointer to the root node of the AVL tree.
 * Return: A pointer to the node with the minimum value.
 */
avl_t *avl_find_min(avl_t *node)
{
	while (node->left)
		node = node->left;
	return (node);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: A pointer to the root node of the AVL tree.
 * @value: The value to be removed from the AVL tree.
 * Return: A pointer to the root node of the AVL tree after removal.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	int balance;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			avl_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			avl_t *temp = root->left;

			free(root);
			return (temp);
		}
		avl_t *temp = avl_find_min(root->right);

		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}
	balance = binary_tree_balance(root);
	if (balance > 1)
	{
		if (binary_tree_balance(root->left) >= 0)
			return (binary_tree_rotate_right(root));
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1)
	{
		if (binary_tree_balance(root->right) <= 0)
			return (binary_tree_rotate_left(root));
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}
