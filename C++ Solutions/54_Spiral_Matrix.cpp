/*54. Spiral Matrix 
	Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
	For example,
	Given the following matrix:

	[
	 [ 1, 2, 3 ],
	 [ 4, 5, 6 ],
	 [ 7, 8, 9 ]
	]
	You should return [1,2,3,6,9,8,7,4,5].
*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> result;
		vector<int> A(2,0),B(2,0);
		int row,col,time=0;

		if(matrix.empty()) return result;

		row = matrix.size();
		col = matrix[0].size();

//		time = row<col?row:col;

		for(int i=0; (A[0]<=B[0] ||A[1] <= B[1]) ;i++)
		{
			A[0] = i; B[0] = row - i - 1;
			A[1] = i; B[1] = col - i - 1;

			if( A[0]==B[0] && A[1] == B[1] &&time<row*col)
			{
				result.push_back(matrix[A[0]][A[1] ]);
				time++;
				break;
			}

			for(int j = A[1] ; j<B[1]&&time<row*col;j++)
			{
				result.push_back(matrix[A[0]][j]);
				time++;
			}

			for(int k = A[0] ; k<B[0]&&time<row*col; k++)
			{
				result.push_back(matrix[k][B[1]]);
				time++;
			}

			for(int j = B[1]; j>A[1]&&time<row*col; j--)
			{	
				result.push_back(matrix[B[0]][j]);
				time++;
			}

			for(int k = B[0] ; k>A[0]&&time<row*col; k--)
			{
				result.push_back(matrix[k][A[1]]);
				time++;
			}

		}
        return result;
    }
};