/* 8. String to Integer (atoi) 
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

class Solution {
public:
	int atoi(string str) {
		
		int i=0 , sign = 1,n;
		int sum = 0;
		n = str.size();
		cout<<n<<endl;

		if(n==0) return 0;
		while( str[i] ==' ' && i <n)  i++;
		if(i >= n) return 0;

		if(str[i] == '+') { 
			sign = 1;
			i++;
		}else if (str[i] == '-') {
			sign = -1;
			i++;
		}else if (str[i]<'0' || str[i] > '9') return 0;
		
		for( ; i <n ; i++){
			
			if( str[i]<'0'||str[i]>'9')	break;
			if(sum>INT_MAX/10 || (sum == INT_MAX/10  && (str[i] - '0') > INT_MAX % 10) )  
				return sign == -1 ? INT_MIN : INT_MAX;
			sum = sum*10 + str[i] - '0';

		}
		return sign*sum;
	}
};
