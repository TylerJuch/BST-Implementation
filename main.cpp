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
	
	addNodeR(&root, 4);
	printTreeInOrderR(&root);
	if (findNodeR(root, 4) != NULL) {
		cout<<"Found node with 4"<<endl;
	}
	if (findNodeR(root, 1) == NULL) {
		cout<<"Did not find node with 11"<<endl;
	}
	
	cout<<endl;
	return 0;
}
