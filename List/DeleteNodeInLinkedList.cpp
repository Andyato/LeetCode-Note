/* leetcode-237 */

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        if(node == nullptr) return;
        ListNode* pNext = node->next;

        if(pNext == nullptr)
        {   
            delete node; 
            return;
        }

        node->val = pNext->val;
        node->next = pNext->next;
        delete pNext;
    }
};