/* leetcode-392 */

#include<string>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int si = 0, ti = 0;

        while( si < s.size() && ti < t.size() )
        {
            if(s[si] == t[ti])
            {
                ++si; ++ti;
            }
            else 
                ++ti;
        }
        return si == s.size();
    }
};