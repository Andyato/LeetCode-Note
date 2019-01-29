/* leetcode-79 */

#include<vector>
#include<string>
using namespace std;

class Solution
{
private:
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int m, n;
    vector<vector<bool>> visited;

    bool inBoard(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool searchWord(const vector<vector<char>>& board, const string& word, int index, int startx, int starty)
    {
        if(word[index] != board[startx][starty])
            return false;

        if(index == word.size()-1)
            return true;

        visited[startx][starty] = true;
        for(int i = 0; i < 4; ++i)
        {
            int x = startx + d[i][0];
            int y = starty + d[i][1];
            if( inBoard(x, y) && !visited[x][y] && searchWord(board, word, index+1, x, y))
                return true;
        }
        visited[startx][starty] = false;

        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        if(m == 0) return false;
        n = board[0].size();
        visited = vector<vector<bool>>( m, vector<bool>(n, false) );

        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[i].size(); ++j)
                if( searchWord(board, word, 0, i, j) )
                    return true;

        return false;
    }
};