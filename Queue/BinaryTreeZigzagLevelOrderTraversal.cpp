/* leetcode-103 */

#include<queue>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        vector<vector<int>> ans;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level == ans.size())
                ans.push_back({node->val});
            else
                ans[level].push_back(node->val);
            
            if (node->left != nullptr)
                q.push(make_pair(node->left, level + 1));
            if (node->right != nullptr)
                q.push(make_pair(node->right, level + 1));
        }
        for(int i = 0; i < ans.size(); ++i)
            if(i & 1 == 1)
                reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
};