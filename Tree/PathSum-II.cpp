/* leetcode-113 */

#include<vector>
#include<string>
#include<stack>
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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> ans;

        if(root == nullptr)
            return ans;

        if(root->left == nullptr && root->right == nullptr && root->val == sum)
        {
            ans.push_back( {root->val} );
            return ans;
        }

        vector<vector<int>> leftVector = pathSum(root->left, sum - root->val);
        for(auto vec : leftVector)
        {
            vec.insert(vec.begin(), root->val);
            ans.push_back(vec);
        }

        vector<vector<int>> rightVector = pathSum(root->right, sum - root->val);
        for(auto vec : rightVector)
        {
            vec.insert(vec.begin, root->val);
            ans.push_back(vec);
        }
        return ans;
    }
};