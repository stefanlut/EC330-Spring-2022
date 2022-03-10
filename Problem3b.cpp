#include "ListNode.h"
// your includes here
#include <iostream>
using namespace std;
DListNode* twowayBubble(DListNode* head) {

	// your implementation goes here
	DListNode* curr = new DListNode(head->val);
	//DListNode* tempnode;
	curr->next = head->next;
	int min, max = 0, temp;
	while(curr != NULL) //identifying max & mins
	{
		if(curr->val < min) min = curr->val;
		else if(curr->val > max) max = curr->val;
		curr = curr->next;
	}
	curr = head; //reset
	while(curr->next != nullptr) // Forward pass
	{
	    curr->prev = curr;
		curr = curr->next;
		if(curr->val != max)
		{
			continue;
		} 
		temp = curr->next->val;
		curr->next->val = max;
		curr->val = temp;
		
	}
	//curr = curr->prev;
	while(curr != NULL) // Backwards pass
	{
		if(curr->val != min)
		{
			curr = curr->prev;
			continue;
		} 
		temp = curr->prev->val;
		curr->prev->val = min;
		curr->val = temp;
		curr = curr->prev;
	}
	return head; // don't forget to change this
}
int main()
{
    DListNode* head = new DListNode(5);
    head->next = new DListNode(3);
    head->next->next = new DListNode(2);
    head->next->next->next = new DListNode(1);
    DListNode* result = twowayBubble(head);
    return 0;
}