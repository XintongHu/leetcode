/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *tmp, *current, *prev, *ptmp, *next;
        if (head == NULL) return head;
        current = head->next;
        prev = head;
        while (current != NULL) {
            tmp = head;
            next = current->next;
            ptmp = NULL;
            if (current->val >= prev->val) prev = prev->next;
            else {
                while (tmp != current) {
                    if (current->val < tmp->val) {
                        prev->next = prev->next->next;
                        current->next = tmp;
                        if (ptmp == NULL)
                            head = current;
                        else
                            ptmp->next = current;
                        break;
                    }
                    ptmp = tmp;
                    tmp = tmp->next;
                }
            }
            current = next;
        }
        return head;
    }
};