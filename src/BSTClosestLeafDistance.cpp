/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};


int min(int a, int b){
	if (a < b){
		return a;
	}
	return b;
}

int get_H(struct node* root){
	if (root == NULL){
		return -1;
	}
	else{
		int l = get_H(root->left);
		int r = get_H(root->right);
		if (l == -1 && r == -1){
			return 0;
		}
		else if (l == -1 && r != -1){
			return 1 + r;
		}
		else if (l != -1 && r == -1){
			return 1 + l;
		}
		else{
			return 1 + min(l, r);
		}
	}
}

int BST_CLD(struct node* root, struct node* temp, int curr){
	if (root != NULL){
		if (root->data == temp->data){
			int l = get_H(root->left);
			int r = get_H(root->right);

			if (l == -1 && r == -1){
				return 0;
			}
			else if (l == -1 && r != -1){
				return min(curr, 1 + r);
			}
			else if (l != -1 && r == -1){
				return min(curr, 1 + l);
			}
			else{
				return min(curr, 1 + min(l, r));
			}
		}
		else if (root->data < temp->data){
			int t = get_H(root->left);
			if (t == -1){
				curr++;
			}
			else{
				curr = 1 + min(curr, t + 1);
			}
			return BST_CLD(root->right, temp, curr);
		}
		else if (root->data > temp->data){
			int t = get_H(root->right);
			if (t == -1){
				curr++;
			}
			else{
				curr = 1 + min(curr, t + 1);
			}
			return BST_CLD(root->left, temp, curr);
		}
	}
	return -1;
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root != NULL && temp != NULL){
		return BST_CLD(root, temp, 65536);
	}
  return -1;
}