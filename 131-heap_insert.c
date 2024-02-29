#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	/* Create a new node with the specified value. */
	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	/* If the heap is empty, the new node becomes the root. */
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	/* Insert the new node at the end of the Heap. */
	insert_at_end(*root, new_node);

	/* Restore the Max Heap property by moving the new node up. */
	heapify_up(new_node);

	return (new_node);
}

/**
 * insert_at_end - Inserts a node at the end of the Heap.
 * @root: Pointer to the root node of the Heap.
 * @new_node: Pointer to the new node to be inserted.
 */
void insert_at_end(heap_t *root, heap_t *new_node)
{
	int node_count = count_nodes(root);

	/* Determine the insert position based on the current node count. */
	if (node_count % 2 == 0)
		find_insert_position_even(root, node_count / 2, new_node);
	else
		find_insert_position_odd(root, node_count / 2, new_node);
}

/**
 * find_insert_position_even - Finds the insert position for
 * a new node in an even level.
 * @root: Pointer to the current node.
 * @index: Index of the insert position.
 * @new_node: Pointer to the new node to be inserted.
 */
void find_insert_position_even(heap_t *root, int index, heap_t *new_node)
{
	if (!root)
		return;

	/* If index is 0, insert new node as the left or right child. */
	if (index == 0)
	{
		if (!root->left)
			root->left = new_node;
		else
			root->right = new_node;
	}
	else
	{
		find_insert_position_even(root->left, index - 1, new_node);
		find_insert_position_even(root->right, index - 1, new_node);
	}
}

/**
 * find_insert_position_odd - Finds the insert position for a new node
 * in an odd level.
 * @root: Pointer to the current node.
 * @index: Index of the insert position.
 * @new_node: Pointer to the new node to be inserted.
 */
void find_insert_position_odd(heap_t *root, int index, heap_t *new_node)
{
	if (!root)
		return;

	/* If the index is zero, insert the new node as the left or right child. */
	if (index == 0)
	{
		if (!root->left)
			root->left = new_node;
		else
			root->right = new_node;
	}
	else
	{
		find_insert_position_odd(root->left, index - 1, new_node);
		find_insert_position_odd(root->right, index - 1, new_node);
	}
}

/**
 * count_nodes - Counts the number of nodes in a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Number of nodes in the binary tree.
 */
int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* Recursively count the nodes in the left and right subtrees. */
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * heapify_up - Restores the Max Heap property after inserting a new node.
 * @node: Pointer to the newly inserted node.
 */
void heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		/* Swap values with parent until the Max Heap property is restored. */
		swap_values(node, node->parent);
		node = node->parent;
	}
}

/**
 * swap_values - Swaps the values of two nodes.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 */
void swap_values(heap_t *node1, heap_t *node2)
{
	int temp = node1->n;

	node1->n = node2->n;
	node2->n = temp;
}
