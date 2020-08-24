#include<iostream>
#include<queue>
using namespace std;

struct BST {
	int data;
	BST* left;
	BST* right;
};

BST* getNewNode(int data) {
	BST* newNode = new BST();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
BST* insert(BST* root, int data) {
	if (root == NULL) {
		root = getNewNode(data);
		return root;
	}
	else if (data <= root->data) 
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);
	return root;
}
bool search(BST* root, int data) {
	if (!root)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root->data)
		return search(root->left, data);
	else
		return search(root->right, data);
}
void levelOrder(BST* root) {
	if (!root) 
		return;
	queue<BST*> Q;
	Q.push(root);
	while (!Q.empty()) {
		BST* current = Q.front();
		cout << current->data << " ";
		if (current->left)
			Q.push(current->left);
		if (current->right)
			Q.push(current->right);
		Q.pop();
	}
}
void preOrder(BST* root) {
	if (!root)
		return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(BST* root) {
	if (!root)
		return;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}
void postOrder(BST* root) {
	if (!root)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";

}

int findMin(BST* root) {
	if (!root) {
		cout << "ERROR! Tree is Empty\n";
		return -999;
	}
	else if (!root->left)
		return root->data;
	return findMin(root->left);
}
int findMax(BST* root) {
	if (!root) {
		cout << "ERROR! Tree is Empty\n";
		return -999;
	}
	else if (!root->right)
		return root->data;
	return findMax(root->right);
}
BST* remove(BST* root, int data) {
	if (!root)
		return root;
	else if (data < root->data)
		root->left = remove(root->left, data);
	else if (data > root->data)
		root->right = remove(root->right, data);
	else {
		// Case 1: NO Child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		// Case 2: One Child
		else if (root->left == NULL) {
			BST* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			BST* temp = root;
			root = root->left;
			delete temp;
		}
		// Case 3: Two Childern
		else {
			int min = findMin(root->right);
			root->data = min;
			root->right = remove(root->right, min);
		}
	}
	return root;
}

BST* findNode(BST* root,int data) {
	if (!root)
		return root;
	else if (root->data == data)
		return root;
	else if (data <= root->data)
		return findNode(root->left, data);
	else
		return findNode(root->right, data);
}
int getSuccessor(BST* root, int data) {
	BST* current = findNode(root, data);
	if (!current)
		return NULL;
	if (current->right != NULL)
		return findMin(current->right);
	if (current->data == findMax(root))
		return current->data;
	else {
		BST* successor = NULL;
		BST* ancestor = root;
		while(ancestor!=current) {
			if (current->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor->data;
	}
}
int getPredecessor(BST* root, int data) {
	BST* current = findNode(root, data);
	if (!current)
		return NULL;
	if (current->left != NULL)
		return findMax(current->left);
	if (current->data == findMin(root))
		return current->data;
	else {
		BST* predecessor = NULL;
		BST* ancestor = root;
		while (ancestor != current) {
			if (current->data > ancestor->data) {
				predecessor = ancestor;
				ancestor = ancestor->right;
			}
			else
				ancestor = ancestor->left;
		}
		return predecessor->data;
	}
}

int main() {
	BST* root = NULL;
	int number;
	root = insert(root, 16);
	root = insert(root, 9);
	root = insert(root, 28);
	root = insert(root, 18);
	root = insert(root, 55);
	root = insert(root, 25);
	root = insert(root, 47);
	root = insert(root, 20);
	root = insert(root, 31);
	root = insert(root, 3);
	root = insert(root, 32);
	root = insert(root, 5);

	cout << "In Order Traversal: ";
	inOrder(root);
	
	//Testing other functions below :

	/*cout << "Minimum value is: " <<findMin(root)  << endl;
	root = remove(root, 5);
	inOrder(root);
	
	cout << "Maximum value is: " << findMax(root) << endl;*/
	
	//cout << "SUCCESSOR OF 3:" << getSuccessor(root, 3) << endl;
	
	/*cout << "PREDECESSOR OF 10:" << getPredecessor(root, 10) << endl;
	if (findNode(root, 20))
		cout << "Number Searched: " << findNode(root, 20) << endl;
	else
		cout << "Not found" << endl;
	levelOrder(root);
	cout << endl;
	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;

	cout << "Enter the number you want to search:";
	cin >> number;
	if(search(root,number))
		cout<<"Found!\n";
	else
		cout << "NOT Found!\n";*/

	system("pause");
	return 0;
}