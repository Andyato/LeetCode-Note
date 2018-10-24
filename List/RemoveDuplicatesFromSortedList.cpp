/* leetcode-83 */

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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head) return head;

        ListNode* pIter = head;
        while(pIter->next)
        {
            ListNode* pNext = pIter->next;
            if(pIter->val == pNext->val)
            {
                pIter->next = pNext->next;
                delete pNext;
            }
            else
                pIter = pIter->next;
        }  
        return head;  
    }
};