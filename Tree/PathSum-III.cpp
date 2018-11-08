/* leetcode-437 */

#include <vector>
#include <string>
#include <stack>
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
    int pathSum(TreeNode *root, int sum)
    {
        if(root == nullptr) return 0;

        int count = pathCounter(root, sum);

        count += pathSum(root->left, sum);
        count += pathSum(root->right, sum);

        return count;
    }

private:
    int pathCounter(TreeNode* node, int sum)
    {
        int count = 0;
        if(node->val == sum)
            count++;
        else    
            {
                if(node->left)
                    count += pathCounter(node->left, sum-node->val);
                if(node->right)
                    count += pathCounter(node->right, sum-node->val);
            }
        return count;
    }
};