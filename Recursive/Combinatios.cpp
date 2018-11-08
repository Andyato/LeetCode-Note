/* leetcode-77 */

#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        if(n < k) return {};

        vector<int> nums;
        for(int i = 1; i <= n; ++i)
            nums.push_back(i);

        if(n == k)
            return {nums};

        vector<vector<int>> ans;
        vector<int> v;
        vector<bool> used(n+1, false);
        combine(nums, 1, k, ans, v, used);
        return ans;
    }

private:
    void combine(const vector<int>& nums, int index, int k, vector<vector<int>>& ans, vector<int>& v, vector<bool>& used)
    {
        if(v.size() == k)
        {
            ans.push_back(v);
            return;
        }

        for(int i = 0; i < nums.size()-k+1; ++i)
        {
            if(used[i] == false)
            {
                v.push_back(nums[i]);
                used[i] = true;
                combine(nums, i+1, k, ans, v, used);
                v.pop_back();
            }
        }
    }
};