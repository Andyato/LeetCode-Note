/* leetcode-198 */

#include<vector>
using namespace std;

class Solution  //记忆化搜索
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> memo(n, -1);

        return rob(nums, 0, memo);
    }
private:
    int rob(vector<int> &nums, int start, vector<int> &memo)
    {
        if (start >= nums.size())
            return 0;

        if (memo[start] != -1)
            return memo[start];

        int ans = 0;
        for (int i = start; i < nums.size(); ++i)
            ans = max(rob(nums, i + 2, memo) + nums[i], ans);
        memo[start] = ans;

        return ans;
    }
};

class Solution //动态规划
{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 0)
            return 0;

        vector<int> memo(n, -1);
        memo[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; --i)
            for(int j = i; j < n; ++j)
                memo[i] = max( memo[i], nums[j] + (j+2<n ? memo[j+2] : 0) );

        return memo[0];
    }           
};