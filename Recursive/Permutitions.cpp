/* leetcode-46*/

#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        if (n <=0 || k <= 0 || n < k)
            return {};

        vector<vector<int>> ans;
        vector<int> v;
        combine(n, 1, k, ans, v);
        return ans;
    }

private:
    void combine(int n, int start, int k, vector<vector<int>> &ans, vector<int> &v)
    {
        if (v.size() == k)
        {
            ans.push_back(v);
            return;
        }

        //已经组合了v.size()个元素，还需要(k-v.size())个元素，添加剪枝
        for (int i = start; i <= n; ++i)
        {
            if(n-start+1 < k-v.size()) //剪枝
                return;

            v.push_back(i);
            combine(n, i+1, k, ans, v);
            v.pop_back();
        }
    }
};