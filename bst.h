#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct S_BSTNode {
	int number;
	S_BSTNode* left;
	S_BSTNode* right;
} BSTNode;

int addNode(BSTNode* root, int number) {
	BSTNode* newNode = new BSTNode;
	if (newNode == NULL) {
		return 0;
	}

	newNode->number = number;	
	
	if (root == NULL) {
		root = newNode;
	}
	else if ( number < root->number ) {
		addNode(root->left, number);
	}
	else {
		addNode(root->right, number);
	}
	return 1;
}

BSTNode* deleteNode(BSTNode* root, int number) {
	
	return NULL;
}

BSTNode* findNode(BSTNode* root, int number) {
	if (root != NULL) {
		if (number == root->number) {
			return root;
		}
		else if (number < root->number ) {
			return findNode(root->left, number);
		}
		else {
			return findNode(root->right, number);
		}
	}
	else {
		return NULL;
	}
}

void printTreePreOrder(BSTNode* root) {
	if (root != NULL ) {
		cout << root->number << " ";
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
}

void printTreeInOrder(BSTNode* root) {
	if (root != NULL) {
		printTreeInOrder(root->left);
		cout << root->number << " ";
		printTreeInOrder(root->right);
	}
}

void printTreePostOrder(BSTNode* root) {
	if (root != NULL) {
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		cout << root->number << " ";
	}
}

