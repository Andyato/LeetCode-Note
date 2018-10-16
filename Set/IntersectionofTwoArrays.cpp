/* leetcode-349 */

#include<set>

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());

        vector<int> res;

        for(int e : set2)
            if(set1.find(e) != set1.end())
                resultSet.push_back(e);

        return res;
    }
};