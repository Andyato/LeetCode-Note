/* leetcode-1 */
//使用unordered_map的O(1)查找时间复杂度的特性

#include<vector>
#include<unordered_map>

using namespace std;

class Solution //使用查找表 O(n)
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int,int> record; 
        for(int i = 0; i < nums.size(); ++i)
        {
            int complete = target - nums[i];
            if(record.find(complete) != record.end())
            {
                vector<int> res{i, record[complete]};
                return res;
            }
            record[nums[i]] = i;
        }
    }
};

class Solution2 //使用对撞指针 O(nlogn) 超时
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        unordered_map<int,int> indexRecord;
        for(int i = 0; i < nums.size(); ++i)
            indexRecord[nums[i]] = i;

        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            if(nums[l] + nums[r] < target)
                ++l;
            else if(nums[l] + nums[r] > target)
                --r;
            else 
                res = {indexRecord[nums[l]], indexRecord[nums[r]]};
        }
        return res;
    }
};