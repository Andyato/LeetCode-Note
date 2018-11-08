/* leetcode-17 */

#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if(digits.size() == 0)
            return {};

        vector<string> ans;
        findCombination(digits, 0, "", ans);
        return ans;
    }

private:
    const string letter[10] = 
    {
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };

    void findCombination(const string& digits, int index, const string& s, vector<string>& ans)
    { // 对于第三个参数，c++中临时变量不能作为非const的引用参数
        if( index == digits.size() )
        {
            ans.push_back(s);
            return;
        }

        char c = digits[index];
        for(auto x : letter[c-'0'])
            findCombination( digits, index+1, s+x, ans );
    }
};