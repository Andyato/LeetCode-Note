//########## Balanced Binary Tree############//

#include <algorithm>
using namespace std;

//Define a binary tree node
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(s), right(nullptr), left(nullptr){}
};

class solution1 // O(nlogn)
{
    public:
        bool isBalanced(TreeNode* root)
        {
            if(!root) return true;
            int hleft = height(root->left);
            int hright = height(root_right);
            return (abs(hleft - hright) <= 1) && isBalanced(root->left) && isBalanced(root->right);
        }
    private:
        int height(TreeNode* root)
        {
            if(!root) return 0;
            return max(height(root->left), height(root->right))+1;
        }
}

class Solution2  //O(n)
{
    public:
        bool isBalanced(TreeNode* root)
        {
            if(!root) return true;
            bool balanced = true;
            height(root, balanced);
            return balanced;
        }

    private:
        int height(TreeNode* root, bool& balanced)
        {
            if(!root) return 0;
            int left_h = height(root->left, balanced);
            if(!balanced) return -1;
            int right_h = height(root->right, balanced);
            if(!balanced) return -1;
            if(abs(left_h - right_h)>1)
            {
                balanced = false;
                return -1;
            }
            return max(left_h, right_h)+1;
        }

};

int main()
{

}
