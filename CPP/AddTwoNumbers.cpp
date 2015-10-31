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
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *ret, *tmp;
		int i, c = 0, sum;
		ret = new ListNode(0);
		tmp = ret;
		while (l1 != NULL && l2 != NULL) {
			sum = l1->val + l2->val + c;
			if (sum >= 10) {
				c = 1;
				sum -= 10;
			}
			else
				c = 0;
			l1 = l1->next;
			l2 = l2->next;
			tmp->next = new ListNode(sum);
			tmp = tmp->next;
		}
		while (l1 != NULL) {
			sum = l1->val + c;
			if (sum >= 10) {
				c = 1;
				sum -= 10;
			}
			else
				c = 0;
			tmp->next = new ListNode(sum);
			tmp = tmp->next;
			l1 = l1->next;
		}
		while (l2 != NULL) {
			sum = l2->val + c;
			if (sum >= 10) {
				c = 1;
				sum -= 10;
			}
			else
				c = 0;
			tmp->next = new ListNode(sum);
			tmp = tmp->next;
			l2 = l2->next;
		}
		if (c != 0) {
			tmp->next = new ListNode(c);
			c = 0;
		}
		return ret->next;
	}
};
