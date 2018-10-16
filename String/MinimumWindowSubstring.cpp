/* leetcode-76 */

#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        string res = "";

        vector<int> freq_t(128, 0);
        for (char c : t)
            ++freq_t[c];

        vector<int> freq_s(128, 0   );
        int sCnt = 0;

        int minLen = s.size()+1;
        int startIndex = -1;

        int l = 0, r = -1;
        while (l < s.size())
        {
            if(r+1 < s.size() && sCnt < t.size())
            {
                ++freq_s[s[++r]];
                if(freq_s[s[r]] <= freq_t[s[r]])
                    ++sCnt;
            }
            
            else
            {
                if(sCnt == t.size() && r-l+1 < minLen)
                {
                    minLen = r-l+1;
                    startIndex = l;
                }

                --freq_s[s[l]];
                if(freq_s[s[l]] < freq_t[s[l]])
                    --sCnt;
                ++l;
            }    
        }
        if (startIndex != -1)
            res = s.substr(startIndex, minLen);
        return res;
    }
};