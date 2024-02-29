#include "binary_trees.h"

/**
 * heapify_down - Heapify down to maintain max heap property.
 * @root: Pointer to the root node of the Heap.
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	/* Find the largest node among root, left, and right. */
	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	/* Swap values if the largest node is not the root. */
	if (largest != root)
	{
		int temp = root->n;

		root->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * get_last_node - Get the last node in the last level-order of the heap.
 * @root: Pointer to the root node of the Heap.
 * @height: Height of the tree.
 * @level: Current level while traversing.
 * Return: Pointer to the last node in the last level-order.
 */
heap_t *get_last_node(heap_t *root, int height, int level)
{
	if (!root)
		return (NULL);

	if (height == 1)
		return (root);

	/* If we are at the last level, return the left or right child. */
	if (level == height - 1)
	{
		if (root->left)
			return (root->left);
		else
			return (root->right);
	}

	heap_t *left = get_last_node(root->left, height - 1, level);
	heap_t *right = get_last_node(root->right, height - 1, level);

	return (right ? right : left);
}

/**
 * get_tree_height - Get the height of the tree.
 * @root: Pointer to the root node of the Heap.
 * Return: Height of the tree.
 */
int get_tree_height(heap_t *root)
{
	int left_height, right_height;

	if (!root)
		return (0);

	/* Recursively find the height of the left and right subtrees. */
	left_height = get_tree_height(root->left);
	right_height = get_tree_height(root->right);

	/* Return the maximum height plus one. */
	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * heap_extract - Extract the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * Return: Value of the extracted root node.
 */
int heap_extract(heap_t **root)
{
	int value, height;

	if (!root || !*root)
		return (0);

	/* Get the value of the root node. */
	value = (*root)->n;

	/* Get the last node in the last level-order. */
	height = get_tree_height(*root);
	heap_t *last_node = get_last_node(*root, height, height);

	/* Replace root with last node. */
	(*root)->n = last_node->n;

	/* Remove last node. */
	if (last_node->parent)
	{
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
	}

	/* Heapify down to maintain the max heap property. */
	heapify_down(*root);

	free(last_node);

	/* Return the value of the extracted root node. */
	return (value);
}
