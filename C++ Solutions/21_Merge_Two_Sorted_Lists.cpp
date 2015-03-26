/* 21.Merge Two Sorted Lists 
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
	int AsorDes(ListNode *p)
	{
		if(p == NULL) return 0;
		if(p->next == NULL) return 0;

		while(p ->next != NULL && p->val == p->next->val)
			p = p->next;
		
		if(p->next == NULL) return 0;
		if(p->val > p->next->val) return 1;
		if(p->val < p->next->val) return -1;
	}

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

		ListNode *p = l1,*q = l2;
		ListNode *head=NULL,*node = NULL,*tmp=NULL;

		if(p == NULL)	return q;
		if(q == NULL)   return p;
		
		int k = AsorDes(l1) ;
		if(k== 0)	k = AsorDes(l2) ;
		if(k == 0) k = -1;

		while(p != NULL && q != NULL)
		{
			tmp = new ListNode(0);
			if( k* (p->val - q->val) > 0){
				tmp = p;
				p = p->next;
			}else {
				tmp = q;
				q = q->next;
			}

			if(head == NULL)	{
				head = new ListNode(0);
				head -> val = tmp ->val;
				node = head;
			}
			else{
				node -> next = tmp;
				node = node->next;	
			}
		}

		if(p == NULL) tmp = q;
		else tmp = p;

		while(tmp!=NULL)
		{
			node -> next = tmp;
			node = node->next;			
			tmp = tmp->next;
		}

		return head;
    }
};