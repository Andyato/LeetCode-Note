/* leetcode-300 */

/**
 * LIS(i) 表示以第i个数字为结尾的最长上升子序列的长度, 即：
 * LIS(i) 表示[0...i]的范围内，选择数字nums[i]可以获得的最长上升子序列的长度
 * LIS(i) = max{ 1 + LIS(j) if nums[j] < nums[i] | j < i };
 **/

#include<vector>
using namespace std;

class Solution //O(n**2)
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> memo(n, 1);

        for(int i = 1; i < n; ++i)
            for(int j = 0; j < i; ++j)
                if(nums[j] < nums[i])
                    memo[i] = max( memo[i], 1 + memo[j] );

        return *max_element(memo.begin(), memo.end());
    }
};