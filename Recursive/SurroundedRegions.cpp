/* leetcode-130 */

#include<vector>
using namespace std;

class Solution
{
private:
    int m, n;
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<bool>> visited;

    bool inBoard(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool BFS(const vector<vector<char>>& board, queue<pair<int,int>>& q, int startx, int starty)
    {
        if(board[startx][starty] == 'X')
            return true;
        if(!inBoard(startx, starty))
            return false;

        q.push( make_pair(startx, starty) );
        visited[startx][starty] = true;
        for(int i = 0; i < 4; ++i)
        {
            int x = startx + d[i][0];
            int y = starty + d[i][1];

            if(inBoard(x, y))
                BFS(board, q, x, y);
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        if(m == 0) return;
        n = board[0].size();
        if(n == 0) return;

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                queue< pair<int,int> > q;
                bool flag = false;

                if( board[i][j] == 'O' && !visited[i][j] )
                    flag = BFS(board, q, i, j);
                
            }
    }
};