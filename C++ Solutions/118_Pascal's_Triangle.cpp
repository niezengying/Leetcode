/* 118. Pascal's Triangle 
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
		vector<vector<int> > generate(int numRows) {
		vector<vector<int> > result;
		if(numRows == 0) return result;

		vector<int> A(1,1);
		result.push_back(A);
        for(int i = 1;  i < numRows ; i++)
		{
			vector<int> current(1,1);

			for(int j = 1; j < i  ; j++){
				int tmp;
				tmp= result[i-1][j-1] + result[i-1][j] ;
				current.push_back(tmp);
			}

			current.push_back(1);
			result.push_back(current);
		}
		return result;
    }
};
