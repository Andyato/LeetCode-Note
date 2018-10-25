/* leetcode-147 */

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
    ListNode *insertionSortList(ListNode *head)
    {
        if(!head || !head->next) return head;

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* curPre = head;
        ListNode* cur = curPre->next;

        while(cur)
        {
            ListNode* pIter = dummyHead;
            for(; pIter != cur && cur->val >= pIter->next->val; pIter=pIter->next);
            
            if(pIter != cur)
            {
                curPre->next = cur->next;
                cur->next = pIter->next;
                pIter->next = cur;
            }
            else 
                curPre = curPre->next;

            cur = curPre->next;
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;

        return res;
    }
};