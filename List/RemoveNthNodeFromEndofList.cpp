/* leetcode-19 */

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* prior = dummyHead;
        ListNode* later = dummyHead;

        for(int i = 0; i < n+1; ++i)
            prior = prior->next;
        
        while(prior != nullptr)
        {
            later = later->next;
            prior = prior->next;    
        }

        ListNode* delNode = later->next;
        later->next = delNode->next;
        delete delNode;

        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};