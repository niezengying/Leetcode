/* 169. Majority Element 
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/

//Easy
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int result = 0,n;
		map<int,int> HashMap;
		n=num.size();

		for(auto it = num.begin();it!=num.end();++it)
		{
			HashMap[*it]++;
		}
		
		for(auto it = HashMap.begin();it!=HashMap.end();++it)
		{
			result = 0;
			if(it->second>n/2)
			{
				result = it->first;
				break;
			}
		}
	return result;
    }
};
