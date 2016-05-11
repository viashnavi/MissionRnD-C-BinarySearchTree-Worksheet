/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};


struct node* A_to_BST(struct node* res,int* arr, int min, int max){
	if (arr != NULL && (min<=max)){
		res = (struct node*)malloc(sizeof(struct node));
		int mid = (min + max) / 2;
		int val = arr[mid];
		res->data = val;
		res->left = A_to_BST(res->left, arr, min, mid - 1);
		res->right = A_to_BST(res->right, arr, mid + 1, max);
		return res;
	}
	return NULL;
}

struct node * convert_array_to_bst(int *arr, int len){
	if (arr != NULL){
		struct node* res = NULL;
		res = A_to_BST(res,arr, 0 ,len-1);
		return res;
	}
	return NULL;
}

