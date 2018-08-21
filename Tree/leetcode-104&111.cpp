//######### Maximum/Minimum Depth of Binary Tree############//

//Definition for a binary tree node.
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution  //minimum
{
public:
    int minDepth(TreeNode* root)
    {
        if (!root) return 0;
        if (!root->left) return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

class Solution //maximum
{
  public:
    int maxDepth(TreeNode *root)
    {
        if (!root) return 0;
        return max(maxDepth(root->left) h, maxDepth(root->right)) + 1;
    }
};