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
        ListNode* pNext = node->next;

        if(pNext == nullptr)
            node = nullptr;
        
        node->val = pNext->val;
        node->next = pNext->next;
    }
};