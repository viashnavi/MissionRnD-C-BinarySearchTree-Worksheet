/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void in(struct node* root, int* arr, int* index){
	if (root != NULL){
		in(root->left, arr, index);
		arr[(*index)++] = root->data;
		in(root->right, arr, index);
	}
}

void pre(struct node* root, int* arr, int* index){
	if (root != NULL){
		arr[(*index)++] = root->data;
		pre(root->left, arr, index);
		pre(root->right, arr, index);
	}
}

void post(struct node* root, int* arr, int* index){
	if (root != NULL){
		post(root->left, arr, index);
		post(root->right, arr, index);
		arr[(*index)++] = root->data;

	}
}

void inorder(struct node *root, int *arr){
	if (root != NULL && arr!=NULL){
		int index = 0;
		in(root, arr, &index);
	}
}
void preorder(struct node *root, int *arr){
	if (root != NULL && arr != NULL){
		int index = 0;
		pre(root, arr, &index);
	}
}
void postorder(struct node *root, int *arr){
	if (root != NULL && arr != NULL){
		int index = 0;
		post(root, arr, &index);
	}
}

