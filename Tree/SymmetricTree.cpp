/* leetcode-101 */

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
    bool isSymmetric(TreeNode *root)
    {
        if(root == nullptr)
            return true;
        
        return isMirrored(root->left, root->right);
    }

private:
    bool isMirrored(TreeNode* node1, TreeNode* node2)
    {
        if(node1 == nullptr && node2 == nullptr) return true;
        if(node1 == nullptr || node2 == nullptr) return false;

        if(node1->val == node2->val)
            return isMirrored(node1->left, node2->right) && isMirrored(node1->right, node2->left);
        else 
            return false;
    }
};