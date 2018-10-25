/* leetcode-148 */
// Sort a linked list in O(n log n) time using constant space complexity.

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/// Merge Sort Bottom Up
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution
{
  public:
    ListNode *sortList(ListNode *head)
    {

        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        int sz = 1;
        while (true)
        {
            ListNode *pre = dummyHead, *cur = pre;

            while (cur->next)
            {
                cur = pre;
                for (int i = 0; i < sz && cur->next; i++, cur = cur->next)
                    ;

                if (cur->next)
                {
                    ListNode *pre2 = cur;
                    for (int i = 0; i < sz && cur->next; i++, cur = cur->next)
                        ;
                    ListNode *next = cur->next, *head2 = pre2->next;
                    pre2->next = NULL, cur->next = NULL;

                    ListNode *tail;
                    pre->next = merge(pre->next, head2, tail);

                    pre = tail;
                    pre->next = next;
                }
                else if (pre == dummyHead)
                {
                    sz = 0;
                    break;
                }
            }

            if (sz == 0)
                break;
            else
                sz *= 2;
        }

        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }

  private:
    ListNode *merge(ListNode *a, ListNode *b, ListNode *&tail)
    {

        ListNode *dummyHead = new ListNode(-1);
        ListNode *p1 = a, *p2 = b, *p = dummyHead;
        while (p1 && p2)
            if (p1->val < p2->val)
            {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
                p->next = NULL;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
                p = p->next;
                p->next = NULL;
            }
        if (p1)
            p->next = p1;
        if (p2)
            p->next = p2;

        tail = p;
        while (tail->next)
            tail = tail->next;

        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};

/// Merge Sort Top Down
/// Time Complexity: O(nlogn)
/// Space Complexity: O(logn)
class Solution
{
  public:
    ListNode *sortList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head2 = slow->next;
        slow->next = NULL;
        head = sortList(head);
        head2 = sortList(head2);
        return merge(head, head2);
    }

  private:
    ListNode *merge(ListNode *a, ListNode *b)
    {

        ListNode *dummyHead = new ListNode(-1);
        ListNode *p1 = a, *p2 = b, *p = dummyHead;
        while (p1 && p2)
            if (p1->val < p2->val)
            {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
                p->next = NULL;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
                p = p->next;
                p->next = NULL;
            }
        if (p1)
            p->next = p1;
        if (p2)
            p->next = p2;

        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};