/*
Given a binary tree, return the preorder traversal of its nodes' values.
*/

class Solution
{
public:
    //### iterative ###//
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr || !s.empty())
        {
            while(curr)
            {
                ans.push_back(curr->val);
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top(); s.pop();
            curr = curr->right;
        }
        return ans;
    }

    //### recursive ###//
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(!root) return {};
        vector<int> ans;  
        preorderTraversal(root, ans);
        return ans;
    }

private:
    void preorderTraversal(TreeNode* root, vector<int>& ans)
    {
        if(!root) return;
        ans.push_back(root->val);
        preorderTraversal(root->left, ans);
        preorderTraversal(root->right, ans);
    }
};