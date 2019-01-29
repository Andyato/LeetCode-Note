/* leetcode-102 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<vector<int>> ans;

        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (node->left != nullptr)
                q.push(make_pair(node->left, level + 1));
            if (node->right != nullptr)
                q.push(make_pair(node->right, level + 1));

            if (level == ans.size())
                ans.push_back({node->val});
            else
                ans[level].push_back(node->val);
        }
        return ans;
    }
};