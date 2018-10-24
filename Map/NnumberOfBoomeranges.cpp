/* leetcode-447 */
#include<unordered_map>
#include<vector>
using namespace std;

class Solution //时间O(n*n), 空间O(n)
{
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points)
    {
        int ans = 0;
        for(int i = 0; i < points.size(); ++i)
        {
            unordered_map<int, int> distRecord;
            for(int j = 0; j < points.size(); ++j)
                if(j != i)
                    ++distRecord[ dist_square(points[i], points[j]) ];

            for(auto iter = distRecord.begin(); iter != distRecord.end(); ++iter)
                ans += (iter->second)*(iter->second-1);
        }
        return ans;
    }

private:
    inline int dist_square(const pair<int, int>& a, const pair<int, int>& b) //坐标范围太大的话返回long long
    {
        return (a.first-b.first)*(a.first-b.first)+
               (a.second-b.second)*(a.second-b.second);
    }
};