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
// postorder : L R Root
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
		
	inorder(root);
	printf("\n");

	return (0);
}
