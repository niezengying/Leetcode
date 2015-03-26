/*66. Plus One  
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		vector<int> result;
		bool flag = true;
		int tmp;

		for(int i=digits.size()-1;i>=0;i--)
		{
			tmp = digits[i]+flag ;
			if(tmp == 10)
			{
				result.insert( result.begin(), 0 );    
				flag = true;
			}else{
				result.insert( result.begin(), tmp );    
				flag = false;
			}	    
		}
		if(flag)	result.insert( result.begin(), 1 );    
        return result;
    }
};
