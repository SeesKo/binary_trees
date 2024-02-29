#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	int temp;

	if (!root)
		return (NULL);

	/* Allocating memory for the new node. */
	new_node = malloc(sizeof(heap_t));
	if (!new_node)
		return (NULL);

	/* Initializing the new node with the given value. */
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	/* If the heap is empty, the new node becomes the root. */
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	/* Find the parent for the new node. */
	parent = find_parent(*root);

	/* Insert the new node as the left or right child of the parent. */
	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	/* Maintain the Max Heap property by swapping values with the parent. */
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		temp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = temp;

		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * find_parent - Finds the parent for the new node in Max Binary Heap.
 * @root: Pointer to the root node of the Heap.
 * Return: Pointer to the parent node.
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *parent;

	if (!root)
		return (NULL);

	/* If the root has an empty left or right child, return the root. */
	if (!root->left || !root->right)
		return (root);

	/* Recursively find the parent in the left subtree. */
	parent = find_parent(root->left);

	/* If the left subtree is not full, return the current parent. */
	if (!parent || !parent->left || !parent->right)
		return (parent);

	/* If the left subtree is full, continue searching in the right subtree. */
	return (find_parent(root->right));
}
