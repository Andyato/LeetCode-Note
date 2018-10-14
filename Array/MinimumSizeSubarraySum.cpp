// 滑动窗口
/* leetcode-209 */

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int l = 0, r = -1;
        int sum = 0;
        int minLength = nums.size() + 1;

        while (l < nums.size())
        {
            if(sum < s && r+1 < nums.size())
                sum += nums[++r];
            else
                sum -= nums[l++];

            if(sum >= s)
                minLength = min(minLength, r-l+1);
        }
        if (minLength == nums.size() + 1)
            return 0;
        return minLength;
    }
};

int main()
{
    return 0;
}