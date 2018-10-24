/* leetcode-82 */

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(!head || !head->next) return head;

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        
        ListNode* pre = dummyHead;
        int dupVal = pre->next->val - 1;
        while(pre->next)
        {
            ListNode* cur = pre->next;
            if( (cur->next && cur->val == cur->next->val) || cur->val == dupVal)
            {
                dupVal = cur->val;
                pre->next = cur->next;
                delete cur;
            }
            else
                pre = pre->next;
        }
        return dummyHead->next;
    }
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (head)
        {
            ListNode* cur = head->next;
            bool duplicate = false;

            while (cur && cur->val == head->val)
            {
                cur = cur->next;
                duplicate = true;
            }
            if (!duplicate)
            {
                tail->next = head;
                tail = tail->next;
            }
            head = cur;
        }

        tail->next = nullptr;

        return dummy.next;
    }
};