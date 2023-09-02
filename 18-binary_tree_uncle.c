#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if no uncle exists
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	else
		return (node->parent->parent->left);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	binary_tree_t *uncle;

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
	uncle = binary_tree_uncle(root->right->left);
	printf("Uncle of %d: %d\n", root->right->left->n, uncle ? uncle->n : -1);
	uncle = binary_tree_uncle(root->left->right);
	printf("Uncle of %d: %d\n", root->left->right->n, uncle ? uncle->n : -1);
	uncle = binary_tree_uncle(root->left);
	printf("Uncle of %d: %p\n", root->left->n, (void *)uncle);
	return (0);
}
