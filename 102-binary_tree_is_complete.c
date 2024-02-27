#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue, *current;
	size_t front = 0, rear = 0;

	if (tree == NULL)
		return (0);
	/* Creating a queue to perform level-order traversal */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;
	/* Performing level-order traversal using the queue */
	while (front < rear)
	{
		/* Dequeuing a node */
		current = queue[front++];
		/* If a NULL is encountered after non-NULL nodes, */
		/* then the tree is incomplete */
		if (current == NULL)
		{
			while (front < rear)
			{
				current = queue[front++];
				if (current != NULL)
				{
					free(queue);
					return (0);
				}
			}
		}
		else
		{
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}
	free(queue);
	/* If loop completes without returning, the tree is complete */
	return (1);
}
