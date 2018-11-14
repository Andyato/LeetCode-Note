/* leetcode-70 */

class Solution
{
private:
    vector<int> mome;

public:
    int climbStairs(int n)
    {
        mome = vector<int>(n + 1, -1);
        return climbStair(n);
    }

    int climbStair(int n)
    {
        if (n == 0 || n == 1)
            return 1;

        if (mome[n] == -1)
            mome[n] = climbStair(n - 1) + climbStair(n - 2);

        return mome[n];
    }
};

class Solution2
{
public:
    int climbStairs(int n)
    {
        if(n == 0 || n == 1) return 1;

        int first = 1;
        int second = 1;

        int cur;
        for(int i = 2; i <= n; ++i)
        {
            cur = first + second;
            first = second;
            second = cur;
        }
        return cur;
    }
};