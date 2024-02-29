#include "binary_trees.h"

/**
 * insert_node_avl - Recursively inserts a value into an AVL tree.
 * @root: A pointer to the root node of the AVL tree.
 * @parent: The parent node of the current node being processed.
 * @new_node: A pointer to store the new node being inserted.
 * @value: The value to be inserted.
 * Return: A pointer to the new root after insertion,
 * NULL on failure.
 */
avl_t *insert_node_avl(avl_t **root, avl_t *parent,
		avl_t **new_node, int value)
{
	int balance;

	/* If current node is NULL, create new node with the given value. */
	if (!*root)
		return (*new_node = binary_tree_node(parent, value));
	/* Recursively insert the value in the appropriate subtree. */
	if ((*root)->n > value)
	{
		(*root)->left = insert_node_avl(&(*root)->left, *root, new_node, value);
		if (!(*root)->left)
			return (NULL);
	}
	else if ((*root)->n < value)
	{
		(*root)->right = insert_node_avl(&(*root)->right, *root, new_node, value);
		if (!(*root)->right)
			return (NULL);
	}
	else
		return (*root);
	/* Updating balance factor and perform rotations if needed. */
	balance = binary_tree_balance(*root);

	if (balance > 1 && (*root)->left->n > value)
		*root = binary_tree_rotate_right(*root);
	else if (balance > 1 && (*root)->left->n < value)
	{
		(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance < -1 && (*root)->right->n < value)
		*root = binary_tree_rotate_left(*root);
	else if (balance < -1 && (*root)->right->n > value)
	{
		(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}
	return (*root);
}

/**
 * avl_insert - Inserts a value into an AVL Tree.
 *
 * @root: A double pointer to the root node of the AVL tree.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the balanced AVL Tree.
 */
avl_t *avl_insert(avl_t **root, int value)
{
	avl_t *new_node = NULL;

	/* If the tree is empty, create a new node and make it the root. */
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Calling the recursive insert function. */
	insert_node_avl(root, *root, &new_node, value);
	return (new_node);
}
