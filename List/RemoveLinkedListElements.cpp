/* leetcode-203 */

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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next)
        {
            if(cur->next->val != val)
            {
                cur = cur->next;
                continue;
            }

            ListNode* delNode = cur->next;
            cur->next = delNode->next;
            delete delNode;
        }
        
        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};