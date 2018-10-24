/* leetcode-86 */
//很有意思的一道题
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode* dummyHead1 = new ListNode(-1);
        ListNode* dummyHead2 = new ListNode(-1);
        ListNode* pre1 = dummyHead1;
        ListNode* pre2 = dummyHead2;

        for(ListNode* cur = head; cur != nullptr;)
        {
            if(cur->val < x)
            {
                pre1->next = cur;
                cur = cur->next;
                pre1 = pre1->next;
                pre1->next = nullptr;
            }
            else
            {
                pre2->next = cur;
                cur = cur->next;
                pre2 = pre2->next;
                pre2->next = nullptr;
            }
        }

        pre1->next = dummyHead2->next;
        ListNode* res = dummyHead1->next;

        delete dummyHead1;
        delete dummyHead2;
        return res;
    }
};