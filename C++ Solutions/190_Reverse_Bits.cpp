/* 190. Reverse Bits 
Reverse bits of a given 32 bits unsigned integer.
For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
return 964176192 (represented in binary as 00111001011110000010100101000000).
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		int result = 0;

		for(int i = 0; i<32;i++)
		{
			result <<= 1;
			result += (n&1);
			n >>= 1;
		}
		return result;
    }
};