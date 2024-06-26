#include<iostream>
using namespace std;


class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int dat)
	{
		data = dat;
		left = nullptr;
		right = nullptr;
	}

	static void inOrderTraversal(Node* key)
	{
		if (key == nullptr)
			return;
		inOrderTraversal(key->left);
		cout << key->data << "\t";
		inOrderTraversal(key->right);
	}

	static void preOrderTraversal(Node* key)
	{
		if (key == nullptr)
			return;
		cout << key->data << "\t";
		preOrderTraversal(key->left);
		preOrderTraversal(key->right);
	}

	static void postOrderTraversal(Node* key)
	{
		if (key == nullptr)
			return;
		postOrderTraversal(key->left);
		postOrderTraversal(key->right);
		cout << key->data << "\t";
	}

	Node* create_Node(int val)
	{
		Node* newNode = new Node(val);
		if (newNode == nullptr)
		{
			cout << "Space not allocated" << endl;
		}
		else
		{
			newNode->data = val;
			return newNode;
		}
	}


	static Node* arrayToBinaryTree(int arr[], int start, int size)
	{
		if (start > size)
		{
			return nullptr;
		}

		int mid = (start + size) / 2;
		Node* root = new Node(arr[mid]);
		root->left = arrayToBinaryTree(arr, start, mid - 1);
		root->right = arrayToBinaryTree(arr, mid + 1, size);

		return root; // Return the root of the binary tree.
	}

};

int main()
{
		// Example array: {1, 2, 3, 4, 5}
		int arr[] = { 1, 2, 3, 4, 5 };
		int size = sizeof(arr) / sizeof(arr[0]);

		// Convert array to binary tree
		Node* root = Node::arrayToBinaryTree(arr, 0, size - 1);

		// Perform traversals
		cout << "In-order traversal: ";
		Node::inOrderTraversal(root);
		cout << endl;

		cout << "Pre-order traversal: ";
		Node::preOrderTraversal(root);
		cout << endl;

		cout << "Post-order traversal: ";
		Node::postOrderTraversal(root);
		cout << endl;


		return 0;
	
}