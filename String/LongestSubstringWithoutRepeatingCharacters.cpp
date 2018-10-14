/* leetcode-3 */
//滑动窗口

#include<string>

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0, r = -1;
        int maxLength = 0;
        int record[128] = {0};

        while (l < s.size())
        {
            if ( r+1 < s.size() && record[ s[r+1] ] == 0 )
                ++record[ s[++r] ];
            else 
                --record[ s[l++] ];

            maxLength = max( maxLength, r-l+1 );
        }
        return maxLength;
    }
};

int main()
{
    return 0;
}