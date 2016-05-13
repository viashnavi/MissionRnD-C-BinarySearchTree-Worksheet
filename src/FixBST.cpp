/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/

#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void swap(struct node* node1, struct node* node2){
	int temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}
void fix(struct node* root, struct node** l, struct node** r, struct node** pre){
	if (root != NULL){
		fix(root->left, l, r, pre);
		if (*pre != NULL){
			if ((*pre)->data > root->data){
				if (*l == NULL)
					*l = *pre;
				*r = root;
			}
		}
		*pre = root;
		fix(root->right, l, r, pre);
	}
}
void fix_bst(struct node *root){
	if (root != NULL){
		struct node* left = NULL;
		struct node* right = NULL;
		struct node* pre = NULL;
		fix(root, &left, &right,&pre);
		swap(left, right);
	}
}
