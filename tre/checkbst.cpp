#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node( int x) : val(x), left(NULL), right(NULL) {}
};

void traverse( Node* root) {
	if (!root) return;
	cout << root->val<< " ";

	traverse(root->left);
	traverse(root->right);
}

void checkB( Node* root, int minv, int maxv, bool& res) {
	if (!root || !res) return;
	cout << " i am at " << root->val << " res " << res <<" \n";
	
	if ( !(root->val > minv) || !(root->val < maxv) ) {
		res = false;
		return;
	}
	cout << " i am at " << root->val << " \n";
	checkB(root->left, minv, root->val, res);
	checkB(root->right, root->val, maxv, res);
}

int main() {
	int d{10};
	int minv{ INT_MIN }, maxv{ INT_MAX };
	bool res = true;
	cout << "Hello Moto " << d << " ";
	struct Node* head = NULL;
	head = new Node(13);
	head->left = new Node(4);
	head->right = new Node(16);
	head->left->left = new Node(3);
	head->left->right = new Node(15);
	head->right->left = new Node(14);
	head->right->right = new Node(17);
	cout << "\n";
	traverse(head);

	checkB(head, minv, maxv, res);
	if (res) cout << " BST ";
	else cout << " Not BST ";
	return 0;
}