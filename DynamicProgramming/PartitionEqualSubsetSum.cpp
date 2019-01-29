/* leetcode-416 */

#include<vector>
using namespace std;

class Solution // 利用背包解决(效率比下面的解法慢很多，大概一个量级)
{
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for(int i : nums)
            sum += i;
        if(sum % 2 != 0) 
            return false;

        int n = nums.size();
        int c = sum / 2;
        vector<bool> memo(c+1, false);

        for(int i = 0; i < n; ++i)
            memo[i] = (nums[0] == i);

        for(int i = 1; i < n; ++i)
            for(int j = c; j >= nums[i]; --j)
                memo[j] = memo[j] || memo[j-nums[i]];

        return memo[c];
    }
};

class Solution
{
  public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;

        return _hasSum(nums, sum / 2);
    }

  private:
    vector<bool> used;
    vector<int> memo;

    bool _hasSum(vector<int> &nums, int sum)
    {
        used = vector<bool>(nums.size(), false);
        memo = vector<int>(sum + 1, -1);

        return hasSum(nums, sum);
    }

    bool hasSum(vector<int> &nums, int sum)
    {
        if (sum == 0)
            return true;
        if (sum < 0)
            return false;

        if (memo[sum] != -1)
            return memo[sum] == 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!used[i])
            {
                used[i] = true;
                memo[sum] = hasSum(nums, sum - nums[i]) ? 1 : 0;
                if (memo[sum])
                    return true;
                used[i] = false;
            }
        }
        return false;
    }
};