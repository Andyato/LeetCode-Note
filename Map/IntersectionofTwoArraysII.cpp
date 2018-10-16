/* leetcode-350 */

#include<unordered_map>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int,int> record;
        for(int e : nums1)
            record[e]++;

        vector<int> res;
        for(int e : nums2)
        {
            if(record[e] > 0)
            {
                res.push_back(e);
                record[e]--;
            }
        }
        return res;
    }
};