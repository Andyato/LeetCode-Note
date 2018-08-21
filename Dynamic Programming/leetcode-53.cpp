/*
    nums: [-2,1,-3,4,-1,2,1,-5,4]
    f:    [-2,1,-2,4, 3,5,6, 1,5]

    f[i]  //maxSubArray(0...i)
    f[i] = f[i-1] > 0 ? nums[i] + f[i-1] : nums[i];
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            sum = max(sum + nums[i], nums[i]);
            if (sum > ans)
                ans = sum;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution *solu;
    int res = solu->maxSubArray(nums);
    cout<<res<<endl;
}