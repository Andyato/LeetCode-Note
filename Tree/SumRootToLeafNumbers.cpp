/* leetcode-129 */

#include<vector>
#include<string>
using namespace std;

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
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        if(root == nullptr)
            return sum;

        dfs(root, 0, sum);

        return sum;
    }
private:
    void dfs(TreeNode* node, int r2lNum, int& sum)
    {
        r2lNum = r2lNum * 10 + node->val;
        
        if(node->left == nullptr && node->right == nullptr)
            sum += r2lNum;

        if(node->left)
            dfs(node->left, r2lNum, sum);
        if(node->right)
            dfs(node->right, r2lNum, sum);
    }
};