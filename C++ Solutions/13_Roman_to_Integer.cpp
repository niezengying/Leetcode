/* 13. Roman to Integer 
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

// [easy]

class Solution {
public:
	int Symbol2int( char ch )
	{
		switch(ch)
		{
		case 'M':
			return 1000;
		case 'D':
			return 500;
		case 'C':
			return 100;
		case 'L':
			return 50;
		case 'X':
			return 10;
		case 'V':
			return 5;
		case 'I':
			return 1;
		default:
			return 0;
		}
	}

    int romanToInt(string s) {
		int result = 0, len, first, second;
		len = s.size();
		if(!len) return 0;
		if(len == 1) return Symbol2int(s[0]);

		first = Symbol2int(s[0]);
        for(int i=1; i<s.size();i++)
		{
			second = Symbol2int(s[i]);
			
			if(first < second) 
				result = result-first;
			else
				result = result+first;

			first = second;
		}
		result += second;
		return result;
    }
};
