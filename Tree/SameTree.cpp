//################# leetcode-100 ###############//

//Define a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(s), right(nullptr), left(nullptr) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;

        if(p->val != q->val)
            return false;
        else 
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};