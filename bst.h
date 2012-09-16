#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct S_BSTNode {
	int number;
	S_BSTNode* left;
	S_BSTNode* right;
} BSTNode;

bool addNodeR(BSTNode** root, int number) {
	if (*root == NULL) {
		BSTNode *newNode = new BSTNode;
		if (!newNode) {
			return false;
		}
		newNode->number = number;
		*root = newNode;
		return true;
	}
	else if ((*root)->number > number) {
		return addNodeR(&(*root)->left, number);
	}
	else {
		return addNodeR(&(*root)->right, number);
	}
}


/*BSTNode* deleteNode(BSTNode** root, int number) {
	
	return NULL;
}*/

BSTNode* findNodeR(BSTNode* root, int number) {
	if (root != NULL) {
		if (number == root->number) {
			return root;
		}
		else if (number < root->number ) {
			return findNodeR(root->left, number);
		}
		else {
			return findNodeR(root->right, number);
		}
	}
	else {
		return NULL;
	}
}

void printTreeInOrderR(BSTNode** root) {
	if (*root != NULL) {
		printTreeInOrderR(&(*root)->left);
		cout<<(*root)->number<<" ";
		printTreeInOrderR(&(*root)->right);
	}
	
}