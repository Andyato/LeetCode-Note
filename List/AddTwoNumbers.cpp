/* leetcode-2 */
//很多小细节
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
/*
Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int len1 = len(l1), len2 = len(l2);
        ListNode* p1 = len1 > len2 ? l1 : l2;
        ListNode* p2 = len1 > len2 ? l2 : l1;

        ListNode* pre = nullptr;
        int carry = 0;

        while(p1)
        {
            int a = p1->val;
            int b = p2 ? p2->val : 0;
            
            int sum = a + b + carry;
            p1->val = sum % 10;
            carry = sum / 10;

            pre = p1;
            p1 = p1->next;
            p2 = p2 ? p2->next : nullptr;
        }

        pre->next = carry ? new ListNode(1) : nullptr;
        return len1 > len2 ? l1 : l2;
    }

private:
    int len(ListNode* head) //这里的head只是临时指针，并不会影响l1, l2；
    {
        int res = 0;
        while(head)
            res++, head = head->next;
        return res;
    }
};

class Solution2
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        int sum = 0;
        while (l1 || l2 || sum)
        {
            sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            tail->next = new ListNode(sum % 10);
            sum /= 10;
            tail = tail->next;
        }
        return dummy.next;
    }
};