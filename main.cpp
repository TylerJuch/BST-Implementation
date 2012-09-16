#include <stdlib.h>
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
	BSTNode* root = NULL;
	
	for (int i = 0; i < 10; i++) {
		if (addNodeR(&root, rand() % 10 + 1)==false) {
			cout<<"Memory error"<<endl;
			break;
		}
	}	
	printTreeInOrderR(&root);
	
	cout<<endl<<"Adding new node of \"4\""<<endl;
	addNodeR(&root, 4);
	printTreeInOrderR(&root);
	cout<<endl;
	
	if (findNodeR(root, 4) != NULL) {
		cout<<"Found node with 4"<<endl;
	}
	if (findNodeR(root, 1) == NULL) {
		cout<<"Did not find node with 11"<<endl;
	}
	
	cout<<"Removing node of \"4\" that was just added."<<endl;
	deleteNodeR(&root, 4);
	printTreeInOrderR(&root);
	cout<<endl;
	
	return 0;
}
