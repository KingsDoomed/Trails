#include <stdlib.h>
#include <stdio.h>


//--- Definition for singly-linked list.
struct ListNode {
	int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	
	int sum = 0, carry = 0, n1 = 0, n2 = 0;
    ListNode* sol = NULL;
    ListNode* tail = NULL;
#if (1)
	if (l1 != NULL)
		printf("%d\n", l1->val);
	else
		printf("EMPTY!!!\n");
#else    
    //--- init conditions
    sol = new ListNode;
	sum = (l1->val + l2->val);
	carry = sum/10;
	sol->val = sum%10;
	sol->next = NULL;
	tail = sol;

    while ((l1 != NULL) || (l2 != NULL)) {
    	
    	//--- clear
    	n1 = 0; n2 = 0;
    	
		if (l1 != NULL) {
			n1 = l1->val;
		}
		
		if (l2 != NULL) {
			n2 = l2->val;
		}
	
		ListNode* tmp = new ListNode;	
		sum = (n1 + n2 + carry);
		carry = sum/10;
		tmp->val = sum%10;
		tmp->next = NULL;
		
		tail->next = tmp;
		tail = tail->next;
	}
#endif
    return sol;
}



int main() {
	
	int const l1Len = 4;
	int const l2Len = 4;
	int i, j, cnt = 0;
	
    //--- create
    ListNode* Tail = NULL;
    ListNode* sol = NULL;
    ListNode* l1 = new ListNode;
    l1->val = 0; l1->next = NULL;
    
	ListNode* l2 = new ListNode;
	l2->val = 9; l2->next = NULL;
    
    Tail = l1;
    for (i = 1; i <l1Len; i++) {
    	ListNode* tmp = new ListNode;
    	tmp->val = i;
    	tmp->next = NULL;
    	
    	Tail->next = tmp;
    	Tail = Tail->next;
	}
	
    Tail = l2;
    for (i = 1; i < l2Len; i++) {
    	ListNode* tmp = new ListNode;
    	tmp->val = 9;
    	tmp->next = NULL;
    	
    	Tail->next = tmp;
    	Tail = Tail->next;
	}
		
    //--- Debug Output
    for (cnt = 0; l1 != NULL; cnt++, l1 = l1->next) {
    	printf("l1[%d] = %d\n", cnt, l1->val);
	}
    for (cnt = 0; l2 != NULL; cnt++, l2 = l2->next) {
    	printf("l2[%d] = %d\n", cnt, l2->val);
	}
	
	//--- run
    sol = addTwoNumbers(l1, l2);
    for (cnt = 0; sol != NULL; cnt++, sol = sol->next) {
    	printf("sol[%d] = %d\n", cnt, sol->val);
	}
	
    //--- destroy
    while (l1 != NULL) {
    	if (l1->next != NULL) {
    		Tail = l1;
    		l1 = l1->next;
			delete Tail;
		}
		else {
			delete l1;
			l1 = NULL;
		}
	}
	
    while (l2 != NULL) {
    	if (l2->next != NULL) {
    		Tail = l2;
    		l2 = l2->next;
			delete Tail;
		}
		else {
			delete l2;
			l2 = NULL;
		}
	}

    while (sol != NULL) {
    	if (sol->next != NULL) {
    		Tail = sol;
    		sol = sol->next;
			delete Tail;
		}
		else {
			delete sol;
		}
	}
	
	if (l1 != NULL) {
		printf("l1 NOT EMPTY!!!\n");
	}
		
	if (l2 != NULL) {
		printf("l2 NOT EMPTY!!!\n");
	}
    
	system("pause");
	return 0;
}
