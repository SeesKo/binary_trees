#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor
 * of 2 nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node,
 * or NULL if no common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	/* Checking if either node is an ancestor of the other */
	if (first == second || first == second->parent || first->parent == second)
		return ((binary_tree_t *)first);

	/* Recursively finding the common ancestor in the */
	/* ancestor chain of the first node */
	while (first != NULL)
	{
		binary_tree_t *temp = (binary_tree_t *)second;

		/* Check if the second node is an ancestor of */
		/* the current ancestor of the first node */
		while (temp != NULL)
		{
			if (first == temp)
				return ((binary_tree_t *)first);

			temp = temp->parent;
		}

		first = first->parent;
	}

	/* If no common ancestor is found, return NULL */
	return (NULL);
}
