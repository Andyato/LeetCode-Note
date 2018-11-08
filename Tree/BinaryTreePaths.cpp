/* leetcode-257 */

#include<vector>
#include<string>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;

        if(root == nullptr)
            return ans;

        if(root->left == nullptr && root->right == nullptr)
        {
            ans.push_back( to_string(root->val) );
            return ans;
        }

            vector<string> leftString = binaryTreePaths(root->left);
        for(auto str : leftString)
            ans.push_back( to_string(root->val) + "->" + str );

        vector<string> rightString = binaryTreePaths(root->right);
        for (auto str : rightString)
            ans.push_back(to_string(root->val) + "->" + str);

        return ans;
    }
};