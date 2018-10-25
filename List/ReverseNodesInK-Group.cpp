/* leetcode-25 */

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int Len = len(head);
        int nIter = Len / k;

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pre = dummyHead;

        for(; nIter > 0; --nIter)
        {
            ListNode* cur = pre->next;
            for (int i = 0; i < k-1; ++i)
            {
                ListNode *move = cur->next;

                cur->next = move->next;
                move->next = pre->next;
                pre->next = move;
            }
            pre = cur;
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }

private:
    int len(ListNode* head)
    {
        int res = 0;
        while(head)
            res++, head = head->next;
        return res;
    }
};