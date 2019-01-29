/* leetcode-455 */

/**
 * 思路一：从小到大排序，贪心指数最小的孩子先获得饼干，返回拿到饼干的孩子数
 * 思路二：从大到小排序，把最大的饼干分给最贪心的孩子，返回分出去的饼干数
 * 
*/

#include <vector>
using namesapce std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort( g.begin(), g.end(), greater<int>() );//从大到小排序
        sort( s.begin(), s.end(), greater<int>() );

        int gi = 0, si = 0;
        
        while( gi < g.size() && si < s.size() )
        {
            if( g[gi] <= s[si] )
            {
                ++gi; ++si;
            }
            else 
                ++gi;
        }
        return si;
    }
};