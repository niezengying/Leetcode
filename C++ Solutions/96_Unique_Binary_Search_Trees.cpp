/* 96. Unique Binary Search Trees
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

// [easy]
class Solution {
public:
    int numTrees(int n) {
		int *F = new int[n+1];
		int result;

        if(n == 0) return 0;
		if(n == 1) return 1;

		F[0] = 1;
		F[1] = 1;
		F[2] = 2;
		
		for(int m = 3;m<=n;m++){
			result = 0;
			for(int i = 0;i < m ;i++)
			{
				result += F[i]*F[m-i-1];			
			}
			F[m] = result;
		}
		result = F[n];
		delete[] F;
		return result;

    }
};
