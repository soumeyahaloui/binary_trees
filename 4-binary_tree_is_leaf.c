#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* Check if the node is not NULL and has no children */
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);  /* It's a leaf node */
	else
		return (0);  /* It's not a leaf node */
}
