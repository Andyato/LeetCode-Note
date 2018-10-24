/* leetcode-328 */

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
    ListNode* oddEvenList(ListNode *head)
    {
        if(!head || !head->next || !head->next->next)
            return head;

        ListNode* oddHead = new ListNode(-1);
        ListNode* evenHead = new ListNode(-1);
        ListNode* pOdd = oddHead;
        ListNode* pEven = evenHead;

        ListNode* cur = head;
        for(int i = 1; cur != nullptr; ++i)
        {
            if(i % 2 == 1)
            {
                pOdd->next = cur;
                cur = cur->next;
                pOdd = pOdd->next;
                pOdd->next = nullptr;
            }
            else 
            {
                pEven->next = cur;
                cur = cur->next;
                pEven = pEven->next;
                pEven->next = nullptr;
            }
        }

        pOdd->next = evenHead->next;
        ListNode* res = oddHead->next;

        delete oddHead;
        delete evenHead;
        return res;
    }
};