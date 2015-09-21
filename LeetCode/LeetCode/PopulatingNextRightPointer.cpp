#include <iostream>

using namespace std;


/// note ע�������������ݵĿ����ԣ�����root = nullʱ����ʾû�������룡������������������

//Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;

		if (root->left != NULL)
		{
			connect(root->left);
		}
		else
			return;
		if (root->right != NULL)
		{
			connect(root->right);
		}
		else
			return;

		root->left->next = root->right;

		struct TreeLinkNode* tempLeft = root->left;
		struct TreeLinkNode* tempRight = root->right;

		while (tempLeft->right !=NULL)
		{
			tempLeft->right->next = tempRight->left;
			tempLeft = tempLeft->right;
			tempRight = tempRight->left;
		}
	}
};