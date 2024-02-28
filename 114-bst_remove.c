#include "binary_trees.h"

/**
 * detach_child - Detaches a child node from its parent.
 * @parent: Pointer to the parent node.
 * @child: Pointer to the child node.
 * @replacement: Pointer to the replacement node.
 *
 * Return: Pointer to the new root of the tree.
 */
bst_t *detach_child(bst_t *parent, bst_t *child, bst_t *replacement)
{
	if (replacement)
		replacement->parent = parent;

	if (parent)
	{
		if (parent->left == child)
			parent->left = replacement;
		else if (parent->right == child)
			parent->right = replacement;
	}

	free(child);

	return (replacement ? NULL : replacement);
}

/**
 * delete_node - Deletes a specific node from the BST.
 * @root: Pointer to the root node of the BST.
 * @node: Pointer to the node to be deleted.
 *
 * Return: Pointer to the new root of the tree.
 */
bst_t *delete_node(bst_t *root, bst_t *node)
{
	bst_t *parent, *left_child, *right_child, *current, *new_root;

	if (!node)
		return (NULL);

	parent = node->parent;
	left_child = node->left;
	right_child = node->right;

	if (!left_child && !right_child)
		new_root = detach_child(parent, node, NULL);
	else if (!right_child)
		new_root = detach_child(parent, node, left_child);
	else
	{
		current = right_child;

		while (current->left)
			current = current->left;

		node->n = current->n;
		new_root = detach_child(current->parent, current, current->right);
	}

	return (new_root ? new_root :
			(parent || left_child || right_child) ? root : NULL);
}

/**
 * bst_remove - Removes a node with a specific value from the BST.
 * @root: Pointer to the root node of the BST.
 * @value: Value to be removed.
 *
 * Return: Pointer to the new root of the tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *current = root;

	if (!root)
		return (NULL);

	while (current)
	{
		if (value == current->n)
			return (delete_node(root, current));

		current = (value < current->n) ? current->left : current->right;
	}

	return (root);
}
