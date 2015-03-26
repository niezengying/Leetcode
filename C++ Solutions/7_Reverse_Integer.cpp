/* 7. Reverse Integer 
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x) {

		long long result, sign = 1;
		long long tmpx = (long long)x;
		char tmpres[64];
		
		if(tmpx<0) sign = -1;
		tmpx = abs(tmpx);

		sprintf(tmpres,"%lld",tmpx);
		string tmp(tmpres);

		std::reverse(tmp.begin(), tmp.end());
		result = stoll(tmp, 0,10) * sign;

		if(result > INT_MAX || result < INT_MIN) return 0;
		else return (int)result;
    }
};