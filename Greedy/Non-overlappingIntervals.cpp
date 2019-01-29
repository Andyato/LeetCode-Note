/* leetcode-435 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include<vector>
using namespace std;

class Solution
{
  public:
    int eraseOverlapIntervals(vector<Interval> &intervals)
    {
        int n = intervals.size();
        if(n == 0)
            return 0;

        sort( intervals.begin(), intervals.end(), cmp );

        int res = 1;   //保证没有重合区间的前提下，最多可以保留多少区间
        int pre = 0;
        for(int i = 1; i < n; ++i)
            if(intervals[i].start >= intervals[pre].end)
            {
                ++res;
                pre = i;
            }

        return n - res;
    }

private:
    static bool cmp(const Interval& a, const Interval& b)
    {
        if( a.end != b.end )
            return a.end < b.end;
        return a.start < b.start;
    }
};