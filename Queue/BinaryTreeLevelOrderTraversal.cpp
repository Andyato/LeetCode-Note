/* leetoce-102 */

#include<queue>
#include<vector>
using namespace std;

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
        // return BFS(root);

        vector<vector<int>> ans;
        DFS(root, 0, ans);
        return ans;

    }

private:
    void DFS(TreeNode *root, int depth, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        //work with pre/in/post order
        while (ans.size() <= depth)
            ans.push_back({}); //if true, add one row
        DFS(root->left, depth + 1, ans);
        DFS(root->right, depth + 1, ans);
        ans[depth].push_back(root->val); //post-order, append to the tail of the depth row
    }
};

class Solution2
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if(root == nullptr) return {};
        vector<vector<int>> ans;

        queue< pair<TreeNode*, int> > q;
        q.push( make_pair(root, 0) );

        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level == ans.size())
                ans.push_back({node->val});
            else
                ans[level].push_back(node->val);

            if(node->left != nullptr)
                q.push( make_pair(node->left, level+1) );
            if(node->right != nullptr)
                q.push( make_pair(node->right, level+1) );
        }
        return ans;
    }
};