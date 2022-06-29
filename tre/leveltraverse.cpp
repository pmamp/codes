#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int x) : val(x), left(NULL), right(NULL) {};
};

void addNode( Node* &root, int val) {
	if (root == NULL) {
		root = new Node(val);
		return;
	}
	int cntr = 0;
	Node* ptr = root;
	bool nodeAdded = false;
	while (!nodeAdded) {
		if (val < ptr->val) {
			if (ptr->left == NULL) {
				ptr->left = new Node(val);
				nodeAdded = true;
			}
			else {
				ptr = ptr->left;
			}
		}
		else if (val == ptr->val) {
			nodeAdded = true;
		}
		else {
			if (ptr->right == NULL) {
				ptr->right = new Node(val);
				nodeAdded = true;
			}
			else {
				ptr = ptr->right;
			}
		}
	}
}


void traverse(Node* root) {
	if (!root) return;
	cout << root->val << " ";

	traverse(root->left);
	traverse(root->right);
}

void levelOdrTraversal( Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	
	while (q.size() > 1) {
		Node* top = q.front();
		q.pop();
		if (top == NULL) {
			q.push(NULL);
			cout << "\n";
			continue;
		}
		cout << " "<< top->val;
		if (top->left) {
			q.push(top->left);
		}
		if (top->right) {
			q.push(top->right);
		}
	}
}

int main() {
	int d{ 10 };
	int minv{ INT_MIN }, maxv{ INT_MAX };
	bool res = true;
	cout << "Hello Moto " << d << " \n";
	Node* head = NULL;

	addNode(head, 13);
	addNode(head, 4);
	addNode(head, 16);
	addNode(head, 3);
	addNode(head, 15);
	addNode(head, 14);
	addNode(head, 17);

	cout << "Traverse :";
	traverse(head);
	cout << "\n Level order Traversal \n";
	levelOdrTraversal(head);

	return 0;
}