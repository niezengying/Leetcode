/* 189. Rotate Array 

Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

//easy
class Solution {
public:
    void rotate(int nums[], int n, int k) {

		int tmp_o,tmp_n;
		int old_idx=0,new_idx=0;

		int time=0,start = 0;
		for(int i = 0; time<n;i++)
		{
			start = i;
			old_idx = i;
			tmp_o = nums[old_idx];
			do{		
				new_idx = (old_idx+k)%n;
				tmp_n = nums[new_idx];
				nums[new_idx]=tmp_o;

				old_idx = new_idx;
				tmp_o = tmp_n;

				time++;
			}while(old_idx!=start);

		}
	}
};