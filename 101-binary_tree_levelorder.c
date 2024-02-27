#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using
 * level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue, *current;
	size_t front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	/* Creating a queue to perform level-order traversal */
	/* Assuming a maximum of 1024 nodes */
	queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (queue == NULL)
		return;

	/* Enqueuing the root node */
	queue[rear++] = (binary_tree_t *)tree;

	/* Performing level-order traversal using the queue */
	while (front < rear)
	{
		/* Dequeuing a node and call the function on its value */
		current = queue[front++];
		func(current->n);

		/* Enqueuing the left child if exists */
		if (current->left != NULL)
			queue[rear++] = current->left;

		/* Enqueuing the right child if exists */
		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	/* Freeing the queue */
	free(queue);
}
