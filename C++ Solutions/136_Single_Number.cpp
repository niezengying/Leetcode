/* 186. Single Number

Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

// [easy]
class Solution {
public:
    int singleNumber(int A[], int n) {
		for(int i = 0; i<n-1;i++)
		{
			A[i+1] ^= A[i];
		}
		return A[n-1];        
    }
};
