/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head, *fst = head;
        while (fst != NULL && fst->next != NULL && fst->next->next != NULL)
        {
            slow = slow->next;
            fst = fst->next->next;
        }

        return slow;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *cur = head, *next, *prev = NULL;

        while (cur != NULL)
        {
            next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }
        return prev;
    }

    void reorderList(ListNode *head)
    {
        ListNode *mid = findMid(head);
        ListNode *tempHead = mid->next;
        mid->next = NULL;
        tempHead = reverse(tempHead);

        // while(tempHead != NULL) {
        //     cout << tempHead->val << " ";
        //     tempHead = tempHead->next;
        // }
        // cout << endl;
        // cout << mid->val << endl;

        ListNode *temp = head, *rev = tempHead;
        while (temp != NULL && rev != NULL)
        {
            ListNode *tempNext1 = temp->next, *tempPrev1 = rev->next;

            if (tempNext1 == NULL || tempPrev1 == NULL)
            {
                temp->next = rev;
                rev->next = tempNext1;
                return;
            }
            // cout << "here" << " " << tempNext1->val << " " << tempPrev1->val << endl;
            temp->next = rev;
            rev->next = tempNext1;

            temp = tempNext1;
            rev = tempPrev1;
        }
    }
};