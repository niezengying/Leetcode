/* 171. Excel Sheet Column Number

Related to question Excel Sheet Column Title
Given a column title as appear in an Excel sheet, return its corresponding column number.
*/

//Easy
class Solution {
public:
    int titleToNumber(string s) {
        
		int n,sum = 0;
		n = s.size();
		for(int i=0;i<n;i++)
		{
			sum = sum * 26 + (s[i]-'A'+1);
		}
		return sum;
    }
};