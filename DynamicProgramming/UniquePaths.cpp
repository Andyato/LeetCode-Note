#include<iostream>
#include<vector>
#include<unordered_map>

/*
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Input: m = 7, n = 3
Output: 28

*/

using namespace std;

class Solution1
{
    private:
        unordered_map<int, unordered_map<int, int>> f;
    public:
        //Solution 1 带记忆的递归
        int uniquePaths(int m, int n)
        {
            if (m < 0 || n < 0) return 0;
            if (m == 1 && n == 1) return 1;
            if (f[m][n] > 0) return f[m][n];
            int left_paths = uniquePaths(m - 1, n);
            int top_paths = uniquePaths(m, n-1);
            // remember the solution
            f[m][n] = left_paths + top_paths;

            return f[m][n];
        }
};

class Solution2
{
    public:
        //Solution 2   递推
        int uniquePaths(int m, int n)
        {
            if (m < 0 || n < 0)
                return 0;

            auto f = vector<vector<int>>(m+1, vector<int>(n+1, 0));
            f[1][1] = 1;

            for (int y = 1; y <= m; ++y)
                for (int x = 1; x <= n; ++x)
                {
                    if (x==1 && y==1) 
                        continue;
                    else
                        f[y][x] = f[y-1][x] + f[y][x-1];
                }
            return f[m][n];
        }
};

int main()
{
    Solution1 solu1;
    Solution2 solu2;
    cout<< solu1.uniquePaths(7, 3) <<endl;
    cout<< solu2.uniquePaths(7, 3) <<endl;
}