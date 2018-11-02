/* leetcode-279 */  
// related: 127,126

#include<queue>
#include<vector>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        queue< pair<int, int> > que;
        que.push( make_pair(n, 0) ); //从n到n经过0个完全平方数

        vector<bool> visited(n+1, false);
        visited[n] = true;

        while(!que.empty())
        {
            int num = que.front().first;
            int step = que.front().second;
            que.pop();

            if(num == 0)    //从n到0经过step个完全平方数
                return step;

            for(int i = 1; num - i*i >= 0; ++i)
            {
                if(visited[num-i*i] == false)
                {
                    que.push( make_pair(num-i*i, step+1) );
                    visited[num-i*i] = true;
                }
            }
        }
    }
};