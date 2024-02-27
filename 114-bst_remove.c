#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree where the
 * node will be removed.
 * @value: Value to remove from the tree.
 *
 * Return: Pointer to the new root node of the tree after
 * removing the value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	/* If the target value is smaller than current node's value, */
	/* recursively navigate to left subtree for removal */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			/* If node has no left child, replace it with its right child */
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}
		/* Node with 2 children: Getting the in-order successor */
		/* (smallest in the right subtree) */
		bst_t *temp = root->right;

		while (temp->left != NULL)
			temp = temp->left;
		/* Copying the in-order successor's content to this node */
		root->n = temp->n;
		/* Deleting the in-order successor */
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
