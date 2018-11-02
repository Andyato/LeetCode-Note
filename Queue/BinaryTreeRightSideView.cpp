/* leetcode-199 */

#include<vector>
#include<queue>
using namesapce std;

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if(!root) return {};

        vector<int> ans;
        queue< pair<TreeNode*, int> > q;
        q.push( make_pair(root, 0) );

        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level == ans.size())
                ans.push_back(node->val);
            else 
                ans[level] = node->val;           

            if(node->left != nullptr)
                q.push( make_pair(node->left, level+1) );
            if(node->right != nullptr)
                q.push( make_pair(node->right, level+1) );
        }
        return ans;
    }
};