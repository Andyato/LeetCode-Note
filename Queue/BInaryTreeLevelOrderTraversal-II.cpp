/* leetcode-107 */

#include <queue>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if(!root) return {};

        vector<vector<int>> ans;
        stack<vector<int>> stk;
        queue< pair<TreeNode*, int> > q;
        q.push( make_pair(root, 0) );
        
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level == stk.size())
                stk.push({node->val});
            else
                stk.top().push_back(node->val);

            if(node->left != nullptr)
                q.push( make_pair(node->left, level+1) );
            if(node->right != nullptr)
                q.push( make_pair(node->right, level+1) );
        }
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};