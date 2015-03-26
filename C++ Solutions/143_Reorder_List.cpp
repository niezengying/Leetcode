/* 143. Reorder List
	Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
	reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

	You must do this in-place without altering the nodes' values.

	For example,
	Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/


// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void reorderList(ListNode *head) {

		ListNode * head1,*head2,*tmp,*tmp2;
		if(!head || !(head->next))  return ;

		head1 = head;
		head2 = head->next;  

		//for finding the last key of list1 && the middle point
		while(head2!=NULL && head2->next!=NULL)
		{
			head1 = head1->next;
			head2 = head2->next->next;
		}

		//reverse the list2
		head2= head1->next;
		head1->next = NULL;
		tmp = NULL;

		while (head2 != NULL)
		{
			tmp2 = head2->next;
			head2->next = tmp;
			tmp = head2;
			head2 = tmp2;
		}

		//merge lists
		head2 = tmp;
		head1 = head;
        while(head2)
        {
            tmp = head1->next;
            head1 = head1->next = head2;
            head2 = tmp;
        }
    }
};
