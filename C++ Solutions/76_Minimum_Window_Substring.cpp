/* 76. Minimum Window Substring 
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
*/

class Solution {
public:
    string minWindow(string S, string T) {

		string result = "";
		map<char,int> mpS,mpT;	
		int right=0,left=0;
		int min=S.size()+1, count = 0;
		
		if(S.empty()) return result;

		for(int i= 0; i<T.size(); i++)		mpT[T[i]]++;

		while(right<S.size())  
		{
			char chr = S[right];	
			if(mpS[chr]<mpT[chr])		count++;
			mpS[chr]++;
	
			if(count == T.size())	{
				while(left<=right )
				{
					char chl = S[left];
					if(mpS[chl] > mpT[chl]){
						mpS[chl] --;
						left++;
					}
					else break;				
				}
					
				if(min > right - left +1)	{
					min = right - left +1;
					result = S.substr(left,min);
				}
			}
			right ++;
		}
		return 	result;
	}
};
