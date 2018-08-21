//################# same tree ###############//

//Define a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(s), right(nullptr), left(nullptr) {}
};

class solution
{
    public:
        bool isSame(TreeNode* p, TreeNode* q)
        {
            //Both are empty: same
            if(!p && !q) return true;
            if(!p || !q) return false;
            if(p->val != q->val) return false;
            return isSame(p->left, q->left) && isSame(p->right, q->right);
        }
};