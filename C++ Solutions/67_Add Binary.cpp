/* 67. Add_Binary  
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
	string addBinary(string a, string b) {
        string result;
		int alen,blen,len,tmp;
		bool flag= false;
		char ch;

		alen = a.size();
		blen = b.size();
		string tmpstr(abs(alen-blen),'0');

		if(alen>blen){
			len = alen;
			b = tmpstr+b;
		}else{
			len = blen;
			a = tmpstr+a;
		}

		for(int i = len-1;  i>=0 ; i--)
		{
			tmp = a[i]+b[i]+flag - 2*'0' ;

			if(tmp/2>0)		
				flag = true;
			else		
				flag = false;

			tmp = tmp%2;
			ch = '0'+tmp;
			result = ch+result;
		}

		if(flag)	result = '1'+result;
		return result;
    }
};
