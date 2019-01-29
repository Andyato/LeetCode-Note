//#########Binary Tree Level Order Traversal##########//

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // return BFS(root);

        vector<vector<int>> ans;
        DFS(root, 0, ans);
        return ans;
    }
private:
    //递归
    void BFS(TreeNode *root, int depth, vector<vector<int>>& ans)
    {
        if(!root) return;
        //work with pre/in/post order
        while(ans.size() <= depth) ans.push_back( {} );  //if true, add one row
        BFS(root->left, depth+1, ans);
        BFS(root->right, depth+1, ans);
        ans[depth].push_back(root->val);    //post-order, append to the tail of the depth row
    }

    //递推
    vector<vector<int>> BFS(TreeNode* root)
    {
        if (!root) return {};
        
        vector<vector<int>> ans;
        vector<TreeNode*> curr, next;
        curr.push_back(root);
        while (!curr.empty())
        {
            ans.push_back({});
            for(TreeNode* node : curr)
            {
                ans.back().push_back(node->val);
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }
            curr.swap(next);
            next.clear();
        }
        return ans;
    }


};

int main()
{

}
