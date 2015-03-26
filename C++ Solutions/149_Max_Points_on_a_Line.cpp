/* 149. Max Points on a Line 
Given n points on a 2D plane, find the maximum number 
of points that lie on the same straight line.
*/

//Hard
struct CmpByValue{
	bool operator()(const pair<int,int> &lhs,const pair<int,int> &rhs)
	{
		return lhs.second > rhs.second;
	}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
		map<float,int> hashMP;
		int equalNum;
		int len,max= 0;
		float slope;

		len = points.size();
		if(points.empty()) return 0;
		//else if(len == 1) return 1;

		for(int i=0;i<len;i++)
		{
			slope = 0;
			equalNum = 0;
			hashMP.erase(hashMP.begin(),hashMP.end());

			for(int j=0;j<len;j++)
			{
				slope = 0;
				if(points[i].x == points[j].x && points[i].y == points[j].y)
					equalNum++;
				else if(points[i].x == points[j].x)
					hashMP[INT_MAX]++;
				else	{
					slope = (points[i].y - points[j].y)*1.0 / (1.0*(points[i].x - points[j].x ));
					hashMP[slope]++;
				}
			}

			int tmpMax = 0;
			if(hashMP.empty())		tmpMax = equalNum;
			else
			{
				vector<pair<int,int>> counts(hashMP.begin(),hashMP.end());
				sort(counts.begin(),counts.end(),CmpByValue());
				tmpMax = counts.begin()->second+equalNum;
			}

			max = (tmpMax > max) ? tmpMax : max;
		}
	return max;
    }
};