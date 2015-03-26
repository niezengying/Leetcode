/* 151. Reverse Words in a String
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

class Solution {
public:
    void reverseWords(string &s) {
		int len, k =0;
		char oldch = ' ';

		for(auto it = s.begin(); it !=s.end(); it ++)
			if(*it != ' '){
				s = s.substr(it-s.begin(),s.size());
				break;
			}

		len = s.size();
		
		for(int i = len-1;  i>=0; i--)
		{
			if( oldch != ' ' && s[i] == ' '){
				s.push_back(s[i]);
				k=0;
			}
			if( oldch == ' ' && s[i] != ' '){
				s.push_back(s[i]);
				k=1;
			}
			else if( oldch != ' ' && s[i] != ' ' ) {
				s.insert(s.end()-k,s[i]);
				k++;
			}

			oldch = s[i];
			s.erase(s.begin()+i);
		}   
    }
};
