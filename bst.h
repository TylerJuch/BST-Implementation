#include <stdlib.h>
#include <iostream>

using namespace std;

struct BSTNode {
	int number;
	BSTNode* left;
	BSTNode* right;
};

bool addNodeR(BSTNode** root, int number);
bool deleteNodeR(BSTNode** root, int number);
BSTNode* promoteNode(BSTNode** root);
BSTNode* findNodeR(BSTNode* root, int number);
void printTreeInOrderR(BSTNode** root);

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


bool deleteNodeR(BSTNode** root, int number) {
	if (root == NULL) {
		return NULL;
	}
	else {
		if ((*root)->number == number) {
			BSTNode* tempRoot = *root;
			promoteNode(root);
			delete tempRoot;
		}
		else if ((*root)->number > number ) {
			deleteNodeR(&(*root)->left, number);
		}
		else {
			deleteNodeR(&(*root)->right, number);
		}
	}
}

BSTNode* promoteNode(BSTNode** root) {
	if ((*root)->left != NULL ) {
		BSTNode* tempRight = (*root)->right;
		*root = (*root)->left;
		(*root)->left = promoteNode(&(*root)->left);
		(*root)->right = tempRight;
	}
	else if ((*root)->right != NULL ) {
		BSTNode* tempLeft = (*root)->left;
		*root = (*root)->right;
		(*root)->right = promoteNode(&(*root)->right);
		(*root)->left = tempLeft;
	}
	else {
		return NULL;
	}
}

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
