/* leetcode-78 */ //related:90、401

#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if(nums.empty()) return {{}};

        vector<vector<int>> ans;
        vector<int> v;

        for(int i = 0; i <= nums.size(); ++i)
            subsets(nums, 0, i, v, ans);

        return ans;
    }

    void subsets(vector<int>& nums, int start, int count, vector<int>& v, vector<vector<int>>& ans)
    {
        if (count == 0)
        {
            ans.push_back(v);
            return;
        }

        for(int j = start; j < nums.size(); ++j)
        {
            v.push_back(nums[j]);
            subsets(nums, j+1, count-1, v, ans);
            v.pop_back();
        }
    }
};