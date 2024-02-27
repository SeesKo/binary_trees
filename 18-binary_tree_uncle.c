#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if node is NULL,
 *         node has no parent or the parent has no sibling
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
			node->parent->parent == NULL)
		return (NULL);

	/* If node's parent is the left child of its parent's parent, */
	/*  return the right child of the parent's parent (if exists) */
	if (node->parent == node->parent->parent->left &&
			node->parent->parent->right != NULL)
		return (node->parent->parent->right);

	/* If node's parent is the right child of its parent's parent, */
	/* return the left child of the parent's parent (if exists) */
	if (node->parent == node->parent->parent->right &&
			node->parent->parent->left != NULL)
		return (node->parent->parent->left);

	/* If node has no uncle, return NULL */
	return (NULL);
}
