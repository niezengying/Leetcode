/* 168. Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

//Medium
class Solution {
public:
		string convertToTitle(int n) {
			string s;
			char ch;
			while(n){
				if(n%26 == 0)
				{
					ch = 'Z';	
					n = (n-1)/26;
				}else{
					ch = n%26+'A'-1;	
					n /= 26;
				}
				s = ch+s;
				
			}
			return s;
		}
};