#include<stdlib.h>
#include "list.h"



LinkList InitList(int length)
{
	ListNode* head;
	head = (ListNode*)malloc(sizeof(ListNode));


	if (head == NULL)
	{
		printf_s("Memory Allocation Failed\n");
	}
	else
	{
		head->val = 0;
		head->next = NULL;
		ListNode* op = head;
		for (int i = 1; i < length; i++)
		{
			ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
			tmp->val = i;

			tmp->next = op->next;
			op->next = tmp;
			op = tmp;
		}
	}
	return head;
}


void DisplayList(LinkList head)
{
	if (head == NULL)
		printf_s("The Linked List Is Empty\n");
	LinkList p = head;
	while (p)
	{
		printf_s("%d -> ", p->val);
		p = p->next;
	}
	printf_s("NULL\n");
}

