/* leetcode-343 */

class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> memo(n+1, 0);
        memo[1] = 1;

        integerBreak(n, memo);

        return memo[n];
    }

private:
    void integerBreak(int n, vector<int>& memo)
    {
        if(n == 1)
            return;
        
        for(int i = 1; i < n; ++i)
        {
            if(memo[n-i] == 0)
                integerBreak(n-i, memo);

            memo[n] = max( memo[n], max(i*(n-i), i * memo[n-i]) ); // i*(n-i)是一个特殊case
        }
    }
};

class Solution2 //动态规划
{
  public:
    int integerBreak(int n)
    {
        vector<int> memo(n+1, 0);

        memo[1] = 1;
        for(int i = 2; i<= n; ++i)
            for(int j = 1; j <= i-1; ++j)
                memo[i] = max( memo[i], max(j*(i-j), j*memo[i-j]) );

        return memo[n];
    }
};