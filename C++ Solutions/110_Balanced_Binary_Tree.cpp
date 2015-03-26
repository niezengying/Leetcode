/* 110. Balanced Binary Tree 

Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined 
as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int getH(TreeNode *p)
	{
		if(p == NULL) return 0;
		if(p->left == NULL && p->right == NULL) return 1;
		int leftH = getH(p->left);
		int rightH = getH(p->right);

		return leftH>rightH?(leftH+1):(rightH+1);
	}

    bool isBalanced(TreeNode *root) {
		if(root == NULL) return true;
		if(root->left == NULL && root->right == NULL) return 1;

		if(abs(getH(root->left) - getH(root->right)) <= 1)
			return isBalanced(root->left) && isBalanced(root->right);

		return false;
    }
};