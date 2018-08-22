/*
Given a binary tree, return the inorder traversal of its nodes' values.
*/

class Solution
{
    public:
        //### ITERATIVE ###//
        vector<int> inorderTraversal(TreeNode* root)
        {
            if(!root) return {};
            vector<int> ans;
            stack<TreeNode*> s;
            TreeNode* curr = root;
            while (curr || !s.empty())
            {
                while (curr)
                {
                    s.push(curr);
                    curr = curr->left;
                }

                curr = s.top(); s.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
            return ans;
        }

        //### RECURSIVE ###//

        vector<int> inorderTraversal(TreeNode* root)
        {
            if(!root) return {};
            vector<int> ans;
            inorderTraversal(root, ans);
            return ans;
        }
    private:
        void inorderTraversal(TreeNode* root, vector<int>& ans)
        {
            if(!root) return;
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
};