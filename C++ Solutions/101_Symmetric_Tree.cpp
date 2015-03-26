/* 101.Symmetric Tree 
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/


 // Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isMirror(TreeNode *p, TreeNode *q)
	{
		if(p == NULL && q == NULL) return true;
		if(p == NULL || q== NULL) return false;
		
		if(p->val == q->val && isMirror(p->left,q->right) && isMirror(p->right,q->left))
			return true;
		else return false;
	}

    bool isSymmetric(TreeNode *root) {
       return isMirror(root, root);
    }
};