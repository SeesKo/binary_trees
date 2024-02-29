#include "binary_trees.h"

int get_tree_size(heap_t *root);

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t heap_size, i;
	int *sorted_array;

    if (!heap || !size)
        return (NULL);

    /* Getting the size of the heap */
    heap_size = get_tree_size(heap);

    /* Allocate memory for the array */
    sorted_array = malloc(sizeof(int) * heap_size);
    if (!sorted_array)
        return (NULL);

    /* Extract elements from the heap and store in the array */
    for (i = 0; i < heap_size; ++i)
        sorted_array[i] = heap_extract(&heap);

    /* Update the size variable */
    *size = heap_size;

    return (sorted_array);
}

/**
 * get_tree_size - Get the size of the tree.
 */
int get_tree_size(heap_t *root)
{
    int left_size, right_size;

    if (!root)
        return (0);

    left_size = get_tree_size(root->left);
    right_size = get_tree_size(root->right);

    return (1 + left_size + right_size);
}
