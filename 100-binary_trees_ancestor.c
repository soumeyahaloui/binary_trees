#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	/* Create arrays to store paths from root to each node */
	binary_tree_t *path1[1024]; /* Adjust the size as needed */
	binary_tree_t *path2[1024];
	size_t len1 = 0, len2 = 0;

	/* Find the path from root to first node */
	while (first)
	{
		path1[len1++] = (binary_tree_t *)first;
		first = first->parent;
	}

	/* Find the path from root to second node */
	while (second)
	{
		path2[len2++] = (binary_tree_t *)second;
		second = second->parent;
	}

	/* Compare the paths to find the last common node */
	while (len1 > 0 && len2 > 0 && path1[len1 - 1] == path2[len2 - 1])
	{
		len1--;
		len2--;
	}

	/* If no common ancestor was found, return NULL */
	if (len1 == 0 || len2 == 0)
		return (NULL);

	/* Return the last common ancestor */
	return (path1[len1]);
}
