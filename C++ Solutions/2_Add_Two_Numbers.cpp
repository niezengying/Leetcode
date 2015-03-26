/* 2. Add Two Numbers
	You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
*/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

		ListNode *result, *node,*tmpl;
		result = new ListNode(0);
		node = result;
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
	
		int flag = 0,tmp=0,time = 0;

		while(l1 != NULL && l2!=NULL)
		{
			tmp = l1->val +l2->val + flag;
			node->next = new ListNode(tmp%10);
			node = node->next;

			flag = tmp/10;
			l1 = l1->next;
			l2 = l2->next;
		}

		if(l1 == NULL)	tmpl=  l2; 
		else tmpl = l1;

		while (tmpl != NULL)
		{
			tmp = tmpl->val + flag;
			node->next = new ListNode(tmp%10);
			node = node->next;
			tmpl = tmpl->next;
			flag = tmp/10;
		}

		if(flag == 1)
			node->next = new ListNode(1);

		return result->next;
    }
};