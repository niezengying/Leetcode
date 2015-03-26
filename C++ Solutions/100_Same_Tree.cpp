/* 100. Same Tree 
Write a function that takes an unsigned integer and returns 
the number of ¡¯1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ¡¯11' has binary representation 
00000000000000000000000000001011, so the function should return 3.
*/

// [easy]
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
    bool isSameTree(TreeNode *p, TreeNode *q) {

        if(p==NULL && q== NULL) return true;
        if(p==NULL || q== NULL) return false;
        
        if(p->val == q->val && 
            isSameTree(p->left,q->left) &&  
                isSameTree(p->right,q->right))
                return true;
                
        else return false;
            
    }
};
