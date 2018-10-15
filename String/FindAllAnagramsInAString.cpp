/* leetcode-438 */
//滑动窗口

#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        if (s.size() < p.size()) 
            return res;

        vector<int> freq_p(26, 0);
        for (char c : p)
            ++freq_p[c-'a'];
        vector<int> freq_s(26, 0);
        int l = 0, r = -1;

        while (r+1 < s.size())
        {
            freq_s[s[++r] - 'a']++;
            if (r-l+1 > p.size())
                --freq_s[s[l++]-'a'];
            
            if (r-l+1 == p.size() && freq_s == freq_p)
                res.push_back(l);
        }
        return res;
    }
};