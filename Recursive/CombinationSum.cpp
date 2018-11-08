/* leetcode-39 */   //related: 40、216

#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        if(candidates.empty()) return {};

        vector<vector<int>> ans;
        vector<int> v;
        combinationSum(candidates, target, v, ans);
        return ans;
    }

    void combinationSum(vector<int>& nums, int target, vector<int>& v, vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(v);
            return;
        }
        if(target < 0)
            return;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(!v.empty() && nums[i] < v.back())
                continue;
            v.push_back(nums[i]);
            combinationSum(nums, target-nums[i], v, ans);
            v.pop_back();
        }
    }
};