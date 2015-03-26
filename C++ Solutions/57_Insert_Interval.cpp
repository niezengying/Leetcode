/* 57. Insert Interval 
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {

		int start_idx,end_idx,len;
		vector<Interval> result(intervals);
		Interval First(INT_MIN,INT_MIN),Last(INT_MAX,INT_MAX);
		
		result.insert(result.begin(),First);
		result.insert(result.end(),Last);
		len = result.size();

		for(int i = 0;i<len;i++)
		{//newInterval.start < intervals[i].end  
			if(newInterval.start<=result[i].end)	{
				start_idx = i;
				break;
			}
		}

		for(int j = len-1;j>=0;j--)
		{	//newInterval.end > intervals[j].start;
			if(newInterval.end>=result[j].start){
				end_idx = j;
				break;
			}
		}

		if(start_idx > end_idx)
			result.insert(result.begin()+start_idx,newInterval);
		else
		{
			int new_start=0,new_end=0;
			new_start = result[start_idx].start > newInterval.start ? newInterval.start : result[start_idx].start;
			new_end = result[end_idx].end > newInterval.end ? result[end_idx].end : newInterval.end;

			result.erase(result.begin()+start_idx,result.begin()+end_idx+1);
			result.insert(result.begin()+start_idx,Interval(new_start,new_end));
			
		}

		result.erase(result.begin());
		result.erase(result.end()-1);

		return result;
    }
};