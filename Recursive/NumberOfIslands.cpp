/* leetcode-200 */

#include<vector>
using namespace std;

class Solution
{
private:
    int d[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int m, n;
    vector<vector<bool>> visited;

    bool inGrid(int x, int y)
    {
        return x>=0 && x<m && y>=0 && y<n;
    }

    void DFS(const vector<vector<char>>& grid, int startx, int starty)
    {
        if(grid[startx][starty] == '0' || visited[startx][starty])
            return;

        visited[startx][starty] = true;
        for(int i = 0; i < 4; ++i)
        {
            int x = startx + d[i][0];
            int y = starty + d[i][1];
            if( inGrid(x, y) )
                DFS(grid, x, y);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        if(m == 0) return 0;
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        int count = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    count++;
                    DFS(grid, i, j);  //标记连通域
                }    

        return count;
    }
}; 