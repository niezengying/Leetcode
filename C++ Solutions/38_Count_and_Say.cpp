/* 38. Count and Say
	The count-and-say sequence is the sequence of integers beginning as follows:
	1, 11, 21, 1211, 111221, ...

	1 is read off as "one 1" or 11.
	11 is read off as "two 1s" or 21.
	21 is read off as "one 2, then one 1" or 1211.
	Given an integer n, generate the nth sequence.

	Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
		int times = 1;
		char tmp[64];	
		string result("1");
		if(n == 1) result = "1";
		
		while(--n)
		{
			string ans(result);
			int len = ans.size();
			ans.push_back('\0');
			result.clear();

			for(int i = 0; i<len; i++)
			{
				if(ans[i] == ans[i+1])  
					times++;
				else{				
					sprintf(tmp,"%d",times);
					string timestr(tmp);

					result = result + timestr; 
					result.push_back(ans[i]);
					times = 1;
				}
			}
			cout<<ans.c_str()<<endl;
		}
        return result;
    }
};