#include <iostream>
#include <climits>
using namespace std;

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

 The Node struct is defined as follows:
 struct Node {
 int data;
 Node* left;
 Node* right;
 }
 */

struct Node {
	int data;
	Node* left;
	Node* right;
	Node() {
		data = 0;
		left = right = 0;
	}
};

bool checkBST(Node* root, int min_data, int max_data) {
	if (root == 0)
		return true;

	if (root->data <= min_data || root->data >= max_data)
		return false;

	return checkBST(root->left, min_data, root->data)
			&& checkBST(root->right, root->data, max_data);
}

bool checkBST(Node* root) {
	return checkBST(root, INT_MIN, INT_MAX);
}

int main() {
	/*
	 Node* root = new Node;
	 root->data = 0;
	 root->left = root->right = 0;
	 cout << checkBST(root) << endl;

	 root->right = new Node;
	 root->right->data = -1;
	 root->right->left = root->right->right = 0;
	 cout << checkBST(root) << endl;*/
	/*
	 * __4
	 __2 6
	 _1 3 5 7
	 */
	Node* root = new Node;
	root->data = 4;
	root->left = new Node;
	root->left->data = 2;
	root->right = new Node;
	root->right->data = 6;

	root->left->left = new Node;
	root->left->left->data = 1;
	root->left->right = new Node;
	root->left->right->data = 3;
	/*
	 root->right->left = new Node;
	 root->right->left->data = 5;
	 root->right->right = new Node;
	 root->right->right->data = 7;
	 */
	cout << checkBST(root) << endl;
	return 0;
}
