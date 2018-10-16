/* leetcode-1 */
//使用unordered_map的O(1)查找时间复杂度的特性

#include<vector>
#include<unordered_map>

using namespace std;

class Solution
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