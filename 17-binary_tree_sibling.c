#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL if no sibling exists
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	binary_tree_t *sibling;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 128);
	root->left->right = binary_tree_node(root->left, 54);
	root->right->right = binary_tree_node(root->right, 402);
	root->left->left = binary_tree_node(root->left, 10);
	root->right->left = binary_tree_node(root->right, 110);
	root->right->right->left = binary_tree_node(root->right->right, 200);
	root->right->right->right = binary_tree_node(root->right->right, 512);

	binary_tree_print(root);
	sibling = binary_tree_sibling(root->left);
	printf("Sibling of %d: %d\n", root->left->n, sibling ? sibling->n : -1);
	sibling = binary_tree_sibling(root->right->left);
	printf("Sibling of %d: %d\n", root->right->left->n, sibling ? sibling->n : -1);
	sibling = binary_tree_sibling(root->left->right);
	printf("Sibling of %d: %d\n", root->left->right->n, sibling ? sibling->n : -1);
	sibling = binary_tree_sibling(root);
	printf("Sibling of %d: %p\n", root->n, (void *)sibling);
	return (0);
}
