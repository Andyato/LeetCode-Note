/* leetcode-404 */

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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        root->val = 0;

        return sumOfLeftLeaves1(root);
    }

  private:
    int sumOfLeftLeaves1(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        if (root->right)
            root->right->val = 0;

        if (root->left == nullptr && root->right == nullptr)
            return root->val;

        return sumOfLeftLeaves1(root->left) + sumOfLeftLeaves1(root->right);
    }
};