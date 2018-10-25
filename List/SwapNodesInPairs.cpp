/* leetcode-24 */

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
    ListNode* swapPairs(ListNode *head)
    {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* pre = dummyHead;

        while(pre->next && pre->next->next)
        {
            ListNode* first = pre->next;
            ListNode* second = first->next;

            first->next = second->next;
            pre->next = second;
            second->next = first;

            pre = first;
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};