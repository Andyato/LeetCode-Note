/*     ********HARD*******
Given a binary tree, return the postorder traversal of its nodes' values.
*/

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
    //iterative
    vector<int> postorderTraversal(TreeNode* root)
    {
        if(!root) return {};
        deque<int> ans;         //deque is convenient to push_front
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* p = s.top(); s.pop();
            ans.push_front(p->val);
            if (p->left) s.push(p->left);
            if (p->right) s.push(p->right);
        }
        return vector<int>(ans.begin(), ans.end());
    }

    //recursive is easy
};