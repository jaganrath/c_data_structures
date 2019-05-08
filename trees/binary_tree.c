/*
 *  Binary Search Tree
 *
 * Operations :
 * a. Insert Node
 * b. Inorder, Pre-order, Post-order
 * c. Search key
 * d. Delete Node
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

tnode *root;


tnode *
add_node(int data)
{
	tnode *	new_node = malloc(sizeof(tnode));
	if (!new_node) {
		printf("Insufficent memory for new node\n");
		return (NULL);
	}

	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = data;

	return (new_node);
}

int
insert_node(tnode **node, int data)
{
	if (*node == NULL) {
		*node = add_node(data);
		return (0);
	}

	if (data < (*node)->data)
		insert_node(&(*node)->left, data);
	else if (data > (*node)->data)
		insert_node(&(*node)->right, data);
	else
		printf("node data : %d already exists\n", data);

	return (0);
}

// preorder  : Root L R

void
preorder(tnode *node)
{
	if (node) {
		printf(" %d ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

// postorder : L R Root

void
postorder(tnode *node)
{
	if (node) {
		postorder(node->left);
		postorder(node->right);
		printf(" %d ", node->data);
	}
}

// inorder   : L Root Right

void
inorder(tnode *node)
{
	if (node) {
		inorder(node->left);
		printf(" %d ", node->data);
		inorder(node->right);
	}
}

tnode *
search(tnode *node, int key)
{
	if (node) {
		if (key < node->data)
			return (search(node->left, key));
		else if (key > node->data)
			return (search(node->right, key));

		printf("found : %d\n", node->data);

		return (node);
	}	

	return (NULL);
}


tnode *
get_min_value(tnode *node)
{
	tnode *cur = node;

	while (cur && cur->left)
		cur = cur->left;

	return (cur);
}

tnode *
delete(tnode *node, int key)
{
	if (!node)
		return (node);

	if (key < node->data)	
		node->left = delete(node->left, key);
	else if (key > node->data)
		node->right = delete(node->right, key);
	else {
		// case 1 : node has no left and right
		// case 2 : node has left only
		// case 3 : node has right only
		if (!node->left) {
			tnode *tmp = node->right;
			free(node);

			return (tmp);
		} else if (!node->right) {
			tnode *tmp = node->left;
			free(node);

			return (tmp);
		}
		// case 4 : node has noth left and right
		// get min value of right tree - inorder successor
		tnode *min_node = get_min_value(node->right);

		// copy data of inorder successor to current node
		node->data = min_node->data;

		// delete the inorder successor node
		node->right = delete(node->right, min_node->data);
	}

	return (node);
}

int
main(void)
{
	root = add_node(100);
	insert_node(&root, 30);
	insert_node(&root, 120);
	insert_node(&root, 10);
	insert_node(&root, 7);
	insert_node(&root, 110);
	insert_node(&root, 190);
		
	preorder(root);
	printf("\n");

	inorder(root);
	printf("\n");

	postorder(root);
	printf("\n");

	
	search(root, 30);
	search(root, 31);
	search(root, 190);
	search(root, 191);
	printf("\n");

	
	root = delete(root, 100);
	inorder(root);
	printf("\n");

	return (0);
}
