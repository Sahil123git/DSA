/**
* Definition for singly-linked list.
 *
*int val;
*ListNode *next;
*ListNode(int x) : val(x), next(NULL){}                          *
}
*/
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *orgA = headA, *orgB = headB;

        while (headA != NULL || headB != NULL)
        {
            if (headA == NULL)
            {
                headA = orgB;
            }

            if (headB == NULL)
            {
                headB = orgA;
            }

            if (headA == headB)
            {
                return headA;
            }

            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};