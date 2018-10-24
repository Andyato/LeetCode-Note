/* leetcode-219 */
//滑动窗口
#include<vector>
#include<unordered_set>
using namespace std;

class Solution //时间O(n),空间O(k)
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> record;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(record.find(nums[i]) == record.end())
            {
                record.insert(nums[i]);
                if(record.size() == k+1)
                    record.erase(nums[i-k]);
            }
            else
                return true;           
        }
        return false;
    }
};