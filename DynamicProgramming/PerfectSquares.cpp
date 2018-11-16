/* leetcode-279 */  //在Graph部分有另一种解法

#include<vector>
using namespace std;

class Solution //记忆化搜索
{
public:
    int numSquares(int n)
    {
        vector<int> memo(n+1, INT_MAX);

        return numSquares(n, memo);
    }

private:
    int numSquares(int n, vector<int>& memo)
    {
        if(n == 0)
            return 0;

        if(memo[n] != INT_MAX)
            return memo[n];

        for(int i = 1; i*i <= n; ++i)
            memo[n] = min( memo[n], numSquares(n - i*i, memo) + 1 );

        return memo[n];
    }
};

class Solution //动态规划
{
public:
    int numSquares(int n)
    {
        vector<int> memo(n+1, n+1);
        memo[0] = 0;

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j*j <= i; ++j)
                memo[i] = min(memo[i-j*j] + 1, memo[i]);
        
        return memo[n];
    }
};