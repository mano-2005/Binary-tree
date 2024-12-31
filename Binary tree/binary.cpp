#include <iostream>
#include <string>
#include <stack>
using namespace std;
class TreeNode {
public:
	char data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}
};
bool isAlphanumeric(char c) {
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <=
		'Z');
}
TreeNode* constructTree(const string& postfix) {
	stack<TreeNode*> nodeStack;
	for (char symbol : postfix) {
		TreeNode* currNode = new TreeNode(symbol);
		if (isAlphanumeric(symbol)) {
			nodeStack.push(currNode);
		}
		else {
			if (!nodeStack.empty()) {
				currNode->right = nodeStack.top();
				nodeStack.pop();
			}
			if (!nodeStack.empty()) {
				currNode->left = nodeStack.top();
				nodeStack.pop();
			}
			nodeStack.push(currNode);
		}
	}
	return nodeStack.top();
}
void postOrderTraversal(TreeNode* root) {
	if (root) {
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		cout << root->data;
	}
}
int main() {
	string postfix1 = "ab+ef*g*-";
	TreeNode* root1 = constructTree(postfix1);
	cout << "\nPost order traversal:- \n";
	postOrderTraversal(root1);
	cout << endl;
	return 0;

