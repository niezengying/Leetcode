/* 50. Pow(x, n) 
Implement pow(x, n)
*/

class Solution {
public:
    double pow(double x, int n) {

		if(abs(x) <1E-15) return 0;
		if(n == 0) return 1;
		if(n == 1) return x;

		double result = 1;
		double tmp = x;

		if(n > 0){
			int w = (int)floor(log((double)n) / log((double)2))+1;  
			if(n&1) result = x;
			for(int i=0;i<w;i++)
			{
				n>>=1;
				tmp= tmp * tmp;
				if(n&1) result*=tmp;
			}
		}

		if(n < 0) {
			if(n==INT_MIN){
				result = pow(1.0/x,INT_MAX);
				result *= (1.0/x);
			}
			else result = pow(1.0/x,-n);
		}
		return result;
    }
};