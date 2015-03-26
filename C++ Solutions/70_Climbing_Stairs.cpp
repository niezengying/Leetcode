/* 83. Remove Duplicates from Sorted List 
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

class Solution {
public:
    int climbStairs(int n) {
		// T(n) = T(n-1) + T(n-2)

		if(n == 1 ) return 1;
		if(n == 2) return 2;

		int step1 = 1;
		int step2 = 2;
		
		int step3;
		for(int i = n-2; i>0;i--)
		{
			step3 = step2 + step1;
			step1 = step2;
			step2 = step3;
		}
        return step3;
    }
};