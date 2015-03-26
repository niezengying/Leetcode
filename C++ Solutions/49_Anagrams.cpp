/* 49. Anagrams
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution {
public:

	size_t hashValue(string str){

		int value = 0,len;
		sort(str.begin(),str.end());
		len = str.size();

		for(int i=0;i<len;i++){
			value = value*26 + str[i]-'a'+1;
		}
		return value;
	}

    vector<string> anagrams(vector<string> &strs) {

		vector<string> result;
		map<size_t, vector<string>> HashMap;
		vector<bool> flagstr;
		
		int len;
		bool flag = false;
		len = strs.size();

		for(int i=0;i<len;i++)
		{
			size_t value = hashValue(strs[i]);
			HashMap[value].push_back(strs[i]);
		}

		for (auto it = HashMap.begin(); it != HashMap.end(); ++it) {
			if (it->second.size() >= 2 ) {
					for(int i=0;i<it->second.size();i++)
					{
						string s = it->second[i];
						result.push_back(s);
					}
			}
		}
		return result;
	}
};