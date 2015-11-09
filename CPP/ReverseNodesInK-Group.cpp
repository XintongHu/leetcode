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
    ListNode* reverseList(ListNode *head, int k) {
        ListNode *prev, *current, *next, *tail;
        current = head, prev = NULL, tail = head;
        int cnt = 0;
        while (current != NULL) {
            if (cnt > k)
                break;
            current = current->next;
            cnt++;
        }
        if (cnt < k)
            return head;
        cnt = 0;
        current = head;
        while (cnt < k && current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            cnt++;
        }
        if (current != NULL)
            tail->next = reverseList(current, k);
        return prev;
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseList(head, k);
    }
};