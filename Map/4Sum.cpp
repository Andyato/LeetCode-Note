/* leetcode-18 */
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution //待续
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> counter;
        for(int i : nums)
            ++counter[i];

        sort(nums.begin(), nums.end());
        vector<int>::iterator iter = unique(nums.begin(), nums.end());
        nums.erase(iter, nums.end());

        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i)
            for(int j = i+1; j < nums.szie(); ++j)
                for（int k = j + 1; k < nums.size(); ++k)
                {
                    if(nums[i]*4 == target && counter[nums[i]] >= 4)
                        ans.push_back({nums[i], nums[i], nums[i], nums[i]});
                    else if(nums[i]*3+nums[j] == target && counter[nums[i]] >= 3)
                }
    }   
};