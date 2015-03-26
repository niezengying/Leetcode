/* 166. Fraction to Recurring Decimal
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.

For example,
Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

class Solution {
public:
	int sgn(long long d){ 	return d<0?-1:1; }

    string fractionToDecimal(int numerator1, int denominator1) {
		string result = "", decmres;
		char factmp[64];
		vector<pair<long,long>> facrem; 
		long long fac = 0,rem = 0;
		long long numerator,denominator;
		numerator = (long long)numerator1;
		denominator = (long long)denominator1;

		if(numerator == 0) return result+"0";
		if( sgn(numerator)*sgn(denominator) == -1)	result += "-"; 
		
		numerator = abs(numerator);
		denominator = abs(denominator);
		
		fac = numerator / denominator;
		rem = numerator % denominator;

		sprintf(factmp,"%lld",fac);
		string facstr(factmp);
		result += facstr;

		if(!rem) return result;	

		result = result + ".";
		numerator = rem*10;


		while(numerator)
		{
			fac = numerator/ denominator;
			rem = numerator % denominator;
			
			pair<long,long> tmp(fac,rem);
			auto it = std::find(facrem.begin(), facrem.end(), tmp);
			if(it!=facrem.end())
			{
				int dis = distance(facrem.begin(), it);
				decmres.insert(dis,"(");
				decmres += ")";
				break;
			}
				
			facrem.push_back(tmp);
			char str = fac + '0';
			decmres = decmres + str ;
			numerator = rem*10;
		}

		result += decmres;
		return result;
    }
};