/**
 * 用栈模拟递归调用过程，从而实现二叉树的非递归版本的前序遍历
 * 改为中序后续也非常简单，和递归版本类似
 * 另一种非递归版本在<Tree>部分实现
**/

#include<stack>
#include<string>
#include<vector>
using namespace std;

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if(root == nullptr) return res;

        stack<Command> st;
        st.push( Command("go", root) );
        while(!st.empty())
        {
            Command cm = st.top();
            st.pop();

            if(cm.d == "take")
                res.push_back(cm.node->val);
            else   //"go"
            {
                if(cm.node->right)
                    st.push(Command("go", cm.node->right));
                if(cm.node->left)
                    st.push(Command("go", cm.node->left));
                st.push(Command("take", cm.node));
            }
        }
        return res; 
    }
private:
    struct Command
    {
        string d; //direction:"go" for execute; "take" for take val.
        TreeNode* node;
        Command(string d, TreeNode* node):d(d), node(node) {}
    };
};

