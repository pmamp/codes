#include <stdio.h>
#include <stdlib.h>

struct Node {
	int val;
	struct Node* left;
	struct Node* right;
};

struct Node* addNode(int x) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->val = x;
	node->left = NULL;
	node->right = NULL;
}

void traverse(struct Node* root) {
	if (!root) return;
	printf(" %d ", root->val);
	traverse(root->left);
	traverse(root->right);
}

void checkB(struct Node* root, int minv, int maxv, int* res) {
	if (!root || !(*res)) return;
	
	if (!(root->val > minv) || !(root->val < maxv)) {
		*res = 0;
		return;
	}
	checkB(root->left, minv, root->val, res);
	checkB(root->right, root->val, maxv, res);
}

int main() {
	int res = 1, maxv = 9999, minv = 0;
	struct Node* head = NULL;
	head = addNode(13);
	head->left = addNode(4);
	head->right = addNode(16);
	head->left->left = addNode(3);
	head->left->right = addNode(5);
	head->right->left = addNode(14);
	head->right->right = addNode(17);
	traverse(head);

	checkB(head, minv, maxv, &res);
	if (res) {
		printf("\n BST ");
	}
	else {
		printf("\n Not BST ");
	}
	return 0;
}