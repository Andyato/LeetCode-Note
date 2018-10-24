/* leetcode-21 */

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* pIter = dummyHead;

        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                pIter->next = l2;
                l2 = l2->next;
                pIter = pIter->next;
            }
            else 
            {
                pIter->next = l1;
                l1 = l1->next;
                pIter = pIter->next;
            }
        }
        pIter->next = l1 ? l1 : l2;
        ListNode* res = dummyHead->next;
        delete dummyHead;

        return res;
    }
};